#include "TextNode.h"

TextNode::TextNode(htmlNodePtr node) : Node(node) {
    //多分無駄が多い
    _text = trim((char *) (node->content));
    printf("%s\n", _text.c_str());
}

int TextNode::getWidth() {
    unsigned long textLength = 0;
    Node *parent = getParent();
    if (strcmp((char *) (parent->getNode()->name), "h1") == 0) {
        textLength = _text.size();
        return (int) (textLength * 32);
    } else if (strcmp((char *) (parent->getNode()->name), "h2") == 0) {
        textLength = _text.size();
        return (int) (textLength * 24);
    } else {
        textLength = _text.size();
        return (int) (textLength * 16);
    }
}

int TextNode::getHeight() {
    Node *parent = getParent();
    if (strcmp((char *) (parent->getNode()->name), "title") == 0) {
        return 0;
    } else if (strcmp((char *) (parent->getNode()->name), "h1") == 0) {
        return 32;
    } else if (strcmp((char *) (parent->getNode()->name), "h2") == 0) {
        return 24;
    } else if (strcmp((char *) (parent->getNode()->name), "text") == 0) {
        //計算コスト
        if (getWidth() > 0) {
            return 16;
        } else {
            return 0;
        }

    } else {
        return 16;
    }
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
