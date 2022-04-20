#include "render_functions.h"
#include "../Parse/parseHTML.h"
#include <algorithm>

GLuint program;
GLint attributeCoord;
GLint uniformTex;
GLint uniformColor;
GLuint vbo;
FT_Library ft;
FT_Face face;

void windowLoop(ElementNode *rootNode) {
    char *windowTitle = setWindowTitle(rootNode);
    if (glfwInit() == GL_FALSE) {
        std::cerr << "Can't initialize GLFW" << std::endl;
        return;
    }
    GLFWwindow *const window(glfwCreateWindow(WIDTH, HEIGHT, windowTitle, NULL, NULL));
    if (window == NULL) {
        std::cerr << "Can't create GLFW window." << std::endl;
        glfwTerminate();
        return;
    }
    // 作成したウィンドウを OpenGL の処理
    glfwMakeContextCurrent(window);
    initResources();

    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    while (glfwWindowShouldClose(window) == GL_FALSE) {
        glClear(GL_COLOR_BUFFER_BIT);
        //
        // ここで描画処理を行う
        display(rootNode);
        //
        // カラーバッファを入れ替える
        glfwSwapBuffers(window);
        // イベントを取り出す
        glfwWaitEvents();
    }
}

int initResources() {
    if (FT_Init_FreeType(&ft)) {
        fprintf(stderr, "Could not init freetype library\n");
        return 0;
    }
    //shaderのパス汚い。
    if (FT_New_Face(ft, "/Users/ikedayu/Library/Fonts/851MkPOP_100.ttf", 0, &face)) {
        return 0;
    }
    GLenum glewStatus = glewInit();
    if (GLEW_OK != glewStatus) {
        fprintf(stderr, "Error: %s\n", glewGetErrorString(glewStatus));
        return 0;
    }
    program = createProgram("/Users/ikedayu/yu_browser/yu_browser/utils/shader/text.v.glsl",
                            "/Users/ikedayu/yu_browser/yu_browser/utils/shader/text.f.glsl");
    if (program == 0)
        return 0;
    attributeCoord = getAttrib(program, "coord");
    uniformTex = getUniform(program, "tex");
    uniformColor = getUniform(program, "color");
    if (attributeCoord == -1 || uniformTex == -1 || uniformColor == -1)
        return 0;
    // Create the vertex buffer object
    glGenBuffers(1, &vbo);
    return 1;
}

void renderText(const char *text, const char *tagName, float x, float y, float sx, float sy) {
    FT_GlyphSlot g = face->glyph;
//     Create a texture that will be used to hold one "glyph"
    GLuint tex;
    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glUniform1i(uniformTex, 0);
//     We require 1 byte alignment when uploading texture data
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//     Clamping to edges is important to prevent artifacts when scaling
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//     Linear filtering usually looks best for text
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//     Set up the VBO for our vertex data
    glEnableVertexAttribArray(attributeCoord);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(attributeCoord, 4, GL_FLOAT, GL_FALSE, 0, 0);

//    日本語対応
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
    std::u32string str = converter.from_bytes((std::string) (text));
    for (int i = 0; str[i] != '\0'; i++) {
        TextSizeFactory *textSizeFactory = new TextSizeFactory();
        int textSize = textSizeFactory->getTextSize(tagName);
        FT_Set_Pixel_Sizes(face, 0, textSize);
        if (FT_Get_Char_Index(face, str[i]) == 0) {
            continue;
        }
//         Try to load and Render the character
        if (FT_Load_Glyph(face, FT_Get_Char_Index(face, str[i]), FT_LOAD_RENDER))
            continue;

//         Upload the "bitmap", which contains an 8-bit grayscale image, as an alpha texture
        glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, g->bitmap.width, g->bitmap.rows, 0, GL_ALPHA, GL_UNSIGNED_BYTE,
                     g->bitmap.buffer);
//         Calculate the vertex and texture coordinates
//        ここの基準がわからない。画面サイズに応じて改行するときにここを読まないといけない
        float x2 = x + g->bitmap_left * sx;
        float y2 = -y - g->bitmap_top * sy;
        float w = g->bitmap.width * sx;
        float h = g->bitmap.rows * sy;
        Point box[4] = {
                {x2,     -y2,     0, 0},
                {x2 + w, -y2,     1, 0},
                {x2,     -y2 - h, 0, 1},
                {x2 + w, -y2 - h, 1, 1},
        };
//         Draw the character on the screen
        glBufferData(GL_ARRAY_BUFFER, sizeof box, box, GL_DYNAMIC_DRAW);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
//         Advance the cursor to the start of the next character
        x += (g->advance.x >> 6) * sx;
        y += (g->advance.y >> 6) * sy;
    }
    glDisableVertexAttribArray(attributeCoord);
    glDeleteTextures(1, &tex);
}

void display(ElementNode *rootNode) {
    glUseProgram(program);
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
//     Enable blending, necessary for our alpha texture
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//    ここもconstants的な感じで別にファイルに切り出したほうがいいのかな
    GLfloat black[4] = {0, 0, 0, 1};
    GLfloat red[4] = {1, 0, 0, 1};
    GLfloat transparentGreen[4] = {0, 1, 0, 0.5};
    glUniform4fv(uniformColor, 1, black);
//    render(rootNode);
//    rootNode->operation(square2D, renderText);
    glFlush();
}

//これ今バグっているGlewを使っているのにGlutの書き方をしているからだと思われる
void square2D(int x1, int y1, int x2, int y2, float size) {
    //        glLineWidth(size);
    //        glBegin(GL_LINE_LOOP);
    //        glVertex2i(x1,y1);
    //        glVertex2i(x2,y1);
    //        glVertex2i(x2,y2);
    //        glVertex2i(x1,y2);
    //        glEnd();
}

void render(ElementNode *rootNode) {
    ElementNode *node = rootNode;
    for (int i = 0; i < node->getChildrenSize(); ++i) {
        std::vector<Node *> children = node->getChildren();
//        if(strcmp((char*)(children[i]->getNode()->name), "body") == 0) {
        children[i]->operation(renderText);
//            break;
//        }
    }
}

//すごい冗長な気がする。Nodeからさわれないものが多すぎるからこうなる。Templateとかなのかな
char *setWindowTitle(ElementNode *rootNode) {
    char *windowTitle = nullptr;
    ElementNode *node = rootNode;
    std::vector<Node *> children = node->getChildren();
    for (int i = 0; i < node->getChildrenSize(); ++i) {
        if (strcmp((char *) (children[i]->getNode()->name), "head") == 0) {
            std::vector<Node *> grandChildren = children[i]->getChildren();
            for (int j = 0; j < children[i]->getChildrenSize(); ++j) {
                if (strcmp((char *) (grandChildren[j]->getNode()->name), "title") == 0) {
                    windowTitle = (char *) (grandChildren[j]->getChildren()[0]->getNode()->content);
                    break;
                }
            }
        }
    }
    return windowTitle;
}




