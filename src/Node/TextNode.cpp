#include "TextNode.h"

TextNode::TextNode(htmlNodePtr node) : Node(node) {
    //多分無駄が多い
    _text = trim((char *) (node->content));
}

//faceが設定されてないとダメなのがなんかどうなんだろう間はある
int TextNode::getWidth() {
    int textWidth = 0;
    int minWidth = 0;
    int spaceCounter = 0;
    FT_Face face = getFace();
//    printf("tagName %s %s\n", (const char *) (getParent()->getNode()->name), _text.c_str());
    for (int i = 0; i < _text.size(); ++i) {
        TextSizeFactory *textSizeFactory = new TextSizeFactory();
        int textSize = textSizeFactory->getTextSize((const char *) (getParent()->getNode()->name));
        FT_Set_Pixel_Sizes(face, 0, textSize);
        if (FT_Get_Char_Index(face, _text[i]) == 0) {
            continue;
        }
        if (FT_Load_Glyph(face, FT_Get_Char_Index(face, _text[i]), FT_LOAD_RENDER))
            continue;

        int width = face->glyph->bitmap.width;

        if (minWidth == 0 || minWidth > width) {
            minWidth = width;
        }
        //スペースに対する暫定処理
        if (width == 0) {
            spaceCounter += 1;
        }
        textWidth += width;
    }

    //スペースに対する処理
    textWidth += minWidth * spaceCounter;
    return textWidth;
}

int TextNode::getHeight() {
    TextSizeFactory *textSizeFactory = new TextSizeFactory();
    int textHeight = textSizeFactory->getTextSize((const char *) (getParent()->getNode()->name));

    return textHeight;
}

int TextNode::getXPosition() {
    Node *parent = getParent();
    return parent->getXPosition();
}

int TextNode::getYPosition() {
    Node *parent = getParent();
    std::string displayName = parent->getDisplayType();
    int yPosition = parent->getHeight() + parent->getYPosition();
    return yPosition;
}


void TextNode::operation(renderTextFunc renderTextFunc) {
    Node *parent = getParent();
//    int renderBufferWidth, renderBufferHeight;
//    glfwGetFramebufferSize(window, &renderBufferWidth, &renderBufferHeight);
//    float sx = 2.0 / renderBufferWidth;
//    float sy = 2.0 / renderBufferHeight;
    float sx = 2.0 / 1024;
    float sy = 2.0 / 1024;
//    printf("%s text\n", _text.c_str());
//    場所の計算の仕方の明確なルールがよくわかっていない
//    renderTextFunc(_text.c_str(), (const char *) (parent->getNode()->name), -1 + (8 + getXPosition()) * sx,
//                   1 - (getYPosition()) * sy, sx, sy);
}

void TextNode::layout(Rect rect) {

}

std::string TextNode::trim(const std::string &string, const char *trimCharacterList) {
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
