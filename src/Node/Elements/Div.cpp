#include "Div.h"

Div::Div(htmlNodePtr node) : ElementNode(node) {
    setDisplayType("block");
}

std::string Div::getClassName() {
    std::string className("Div");
    return className;
};
