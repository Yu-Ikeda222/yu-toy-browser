#include "P.h"

P::P(htmlNodePtr node) : ElementNode(node) {
    setDisplayType("block");
}

std::string P::getClassName() {
    std::string className("p");
    return className;
};
