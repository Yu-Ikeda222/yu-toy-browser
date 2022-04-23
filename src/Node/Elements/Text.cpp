#include "Text.h"

Text::Text(htmlNodePtr node) : InlineElementNode(node) {

}

std::string Text::getClassName() {
    std::string className("Text");
    return className;
};

