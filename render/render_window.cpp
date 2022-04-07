#include "render_window.hpp"
#include "../parse/parseHTML.hpp"
#include <algorithm>

GLuint program;
GLint attribute_coord;
GLint uniform_tex;
GLint uniform_color;
GLuint vbo;
FT_Library ft;
FT_Face face;

void render_window_opneGL(ElementNode* root_node){
    char* WindowTitle = set_window_title(_root_node);
    glutCreateWindow(WindowTitle);
    init_resources();
    glutDisplayFunc(Display);
    Init();
    glutMainLoop();
    free();
}

void Init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glOrtho(0, WIDTH, HEIGHT, 0, -1, 1);
}

int init_resources() {
    
    if (FT_Init_FreeType(&ft)) {
        fprintf(stderr, "Could not init freetype library\n");
        return 0;
    }
    
    //shaderのパス汚い。
    if (FT_New_Face(ft, "/Users/ikedayu/Library/Fonts/851MkPOP_100.ttf", 0, &face)) {
        //        fprintf(stderr, "Could not open font %s\n", fontfilename);
        return 0;
    }
    
    GLenum glew_status = glewInit();
    if (GLEW_OK != glew_status) {
        fprintf(stderr, "Error: %s\n", glewGetErrorString(glew_status));
    }
    program = create_program("/Users/ikedayu/yu_browser/yu_browser/utils/shader/text.v.glsl", "/Users/ikedayu/yu_browser/yu_browser/utils/shader/text.f.glsl");
    if(program == 0)
        return 0;

    attribute_coord = get_attrib(program, "coord");
    uniform_tex = get_uniform(program, "tex");
    uniform_color = get_uniform(program, "color");
    
    if(attribute_coord == -1 || uniform_tex == -1 || uniform_color == -1)
        return 0;
    
    // Create the vertex buffer object
    glGenBuffers(1, &vbo);
    
    return 1;
}

void render_text(const char *text, const char* tag_name, float x, float y, float sx, float sy) {
    FT_GlyphSlot g = face->glyph;
    
//     Create a texture that will be used to hold one "glyph"
    GLuint tex;
    
    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glUniform1i(uniform_tex, 0);
    
//     We require 1 byte alignment when uploading texture data
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    
//     Clamping to edges is important to prevent artifacts when scaling
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
//     Linear filtering usually looks best for text
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
//     Set up the VBO for our vertex data
    glEnableVertexAttribArray(attribute_coord);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(attribute_coord, 4, GL_FLOAT, GL_FALSE, 0, 0);
    
//    日本語対応
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
    std::u32string str = converter.from_bytes((std::string)(text));
    
    for (int i = 0; str[i] != '\0'; i++) {
        
        TextSizeFactory* text_size_factory = new TextSizeFactory();
        int text_size = text_size_factory->get_text_size(tag_name);
        FT_Set_Pixel_Sizes(face, 0, text_size);

        if(FT_Get_Char_Index(face, str[i]) == 0)
        {
            continue;
        }
        
//         Try to load and render the character
        if (FT_Load_Glyph(face, FT_Get_Char_Index(face, str[i]), FT_LOAD_RENDER))
            continue;
//         Upload the "bitmap", which contains an 8-bit grayscale image, as an alpha texture
        glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, g->bitmap.width, g->bitmap.rows, 0, GL_ALPHA, GL_UNSIGNED_BYTE, g->bitmap.buffer);
        
//         Calculate the vertex and texture coordinates
//        ここの基準がわからない。画面サイズに応じて改行するときにここを読まないといけない
        float x2 = x + g->bitmap_left * sx;
        float y2 = -y - g->bitmap_top * sy;
        float w = g->bitmap.width * sx;
        float h = g->bitmap.rows * sy;
        
        point box[4] = {
            {x2, -y2, 0, 0},
            {x2 + w, -y2, 1, 0},
            {x2, -y2 - h, 0, 1},
            {x2 + w, -y2 - h, 1, 1},
        };
        
//         Draw the character on the screen
        glBufferData(GL_ARRAY_BUFFER, sizeof box, box, GL_DYNAMIC_DRAW);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        
//         Advance the cursor to the start of the next character
        x += (g->advance.x >> 6) * sx;
        y += (g->advance.y >> 6) * sy;
    }
    
    glDisableVertexAttribArray(attribute_coord);
    glDeleteTextures(1, &tex);
}

void Display() {
    glUseProgram(program);
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    
//     Enable blending, necessary for our alpha texture
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
//    ここもconstants的な感じで別にファイルに切り出したほうがいいのかな
    GLfloat black[4] = { 0, 0, 0, 1 };
    GLfloat red[4] = { 1, 0, 0, 1 };
    GLfloat transparent_green[4] = { 0, 1, 0, 0.5 };
    
    glUniform4fv(uniform_color, 1, black);
    render();
    glFlush();
}

//これ今バグっている
void Square2D(int x1,int y1,int x2, int y2,float size) {
    //        glLineWidth(size);
    //        glBegin(GL_LINE_LOOP);
    //        glVertex2i(x1,y1);
    //        glVertex2i(x2,y1);
    //        glVertex2i(x2,y2);
    //        glVertex2i(x1,y2);
    //        glEnd();
}

void render() {
    ElementNode* node = _root_node;
    for(int i=0; i < node->get_children_size(); ++i){
        std::vector<Node*> children = node->get_children();
        if(strcmp((char*)(children[i]->get_node()->name), "body") == 0) {
            children[i]->operation(Square2D, render_text);
            break;
        }
    }
    
}

//すごい冗長な気がする。Nodeからさわれないものが多すぎるからこうなる。Templateとかなのかな
char* set_window_title(ElementNode* root_node) {
    char* WindowTitle = nullptr;
    ElementNode* node = root_node;
    std::vector<Node*> children = node->get_children();
    for(int i=0; i < node->get_children_size(); ++i){
        if(strcmp((char*)(children[i]->get_node()->name), "head") == 0) {
            std::vector<Node*> grand_children = children[i]->get_children();
            for(int j=0; j < children[i]->get_children_size(); ++j){
                if(strcmp((char*)(grand_children[j]->get_node()->name), "title") == 0) {
                    WindowTitle = (char*)(grand_children[j]->get_children()[0]->get_node()->content);
//                strcpy(WindowTitle, (char*)(grand_children[j]->get_children()[0]->get_node()->content));
                    break;
                }
            }
        }
    }
    return  WindowTitle;
    
}

void free(){
    xmlFreeDoc(_doc);
    _doc = NULL;
    xmlCleanupParser();
    xmlCleanupCharEncodingHandlers();
}


