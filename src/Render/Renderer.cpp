#include "Renderer.h"

Renderer::Renderer() {

}

Renderer::~Renderer() {

}

void Renderer::render(Window *window, Node *node) {
    if (node->getClassName() == "TextNode") {
        int renderBufferWidth, renderBufferHeight;
        glfwGetFramebufferSize(window->getWindow(), &renderBufferWidth, &renderBufferHeight);
        float sx = 2.0 / renderBufferWidth;
        float sy = 2.0 / renderBufferHeight;

        renderText(window, (trim((char *) (node->getNode()->content))).c_str(),
                   (const char *) (node->getParent()->getNode()->name), -1 + (8 + node->getXPosition()) * sx,
                   1 - (node->getYPosition()) * sy, sx, sy);
    }

    for (auto child: node->getChildren()) {
        //少し気持ち悪い
        child->setPrev();
        render(window, child);
    }
}

void Renderer::renderText(Window *window, const char *text, const char *tagName, float x, float y, float sx, float sy) {
    FT_GlyphSlot g = window->face->glyph;
//     Create a texture that will be used to hold one "glyph"
    GLuint tex;
    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glUniform1i(window->uniformTex, 0);
//     We require 1 byte alignment when uploading texture data
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//     Clamping to Edges is important to prevent artifacts when scaling
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//     Linear filtering usually looks best for text
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//     Set up the VBO for our vertex data
    glEnableVertexAttribArray(window->attributeCoord);
    glBindBuffer(GL_ARRAY_BUFFER, window->vbo);
    glVertexAttribPointer(window->attributeCoord, 4, GL_FLOAT, GL_FALSE, 0, 0);

//    日本語対応
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
    std::u32string str = converter.from_bytes((std::string) (text));
    for (int i = 0; str[i] != '\0'; i++) {
        TextSizeFactory *textSizeFactory = new TextSizeFactory();
        int textSize = textSizeFactory->getTextSize(tagName);
        FT_Set_Pixel_Sizes(window->face, 0, textSize);
        if (FT_Get_Char_Index(window->face, str[i]) == 0) {
            continue;
        }
//         Try to load and Render the character
        if (FT_Load_Glyph(window->face, FT_Get_Char_Index(window->face, str[i]), FT_LOAD_RENDER))
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
    glDisableVertexAttribArray(window->attributeCoord);
    glDeleteTextures(1, &tex);
}

//TextNode.cppにもある。冗長
std::string Renderer::trim(const std::string &string, const char *trimCharacterList) {
    std::string result;
    std::string reducedString;
    std::string::size_type left = string.find_first_not_of(trimCharacterList);
    if (left != std::string::npos) {
        std::string::size_type right = string.find_last_not_of(trimCharacterList);
        reducedString = string.substr(left, right - left + 1);
    }

    for (int i = 0; i < reducedString.size(); ++i) {
        if ((!isspace(reducedString[i]) || (isspace(reducedString[i]) && !isspace(reducedString[i + 1]))) &&
            reducedString[i] != '\n') {
            result.push_back(reducedString[i]);
        }
    }
    return result;
}

