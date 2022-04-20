#include "H2.h"

H2::H2(htmlNodePtr node) : ElementNode(node) {
    setDisplayType("block");
}

std::string H2::getClassName() {
    std::string className("H2");
    return className;
}
