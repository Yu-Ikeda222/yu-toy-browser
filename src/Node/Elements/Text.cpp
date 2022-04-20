#include "Text.h"

Text::Text(htmlNodePtr node) : ElementNode(node) {
    setDisplayType("inline");
}

std::string Text::getClassName() {
    std::string className("Text");
    return className;
};

