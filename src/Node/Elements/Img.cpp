#include "Img.h"

Img::Img(htmlNodePtr node) : InlineElementNode(node) {

}

std::string Img::getClassName() {
    std::string className("Img");
    return className;
};
