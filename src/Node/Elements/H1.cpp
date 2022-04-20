#include "H1.h"

H1::H1(htmlNodePtr node) : ElementNode(node) {
    setDisplayType("block");
}

std::string H1::getClassName() {
    std::string className("H1");
    return className;
}
