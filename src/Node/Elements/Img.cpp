#include "Img.h"

Img::Img(htmlNodePtr node) : ElementNode(node) {
    setDisplayType("block");
}

std::string Img::getClassName() {
    std::string className("img");
    return className;
};
