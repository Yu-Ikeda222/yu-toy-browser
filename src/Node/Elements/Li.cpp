#include "Li.h"

Li::Li(htmlNodePtr node) : ElementNode(node) {
    setDisplayType("block");
}

std::string Li::getClassName() {
    std::string className("Li");
    return className;
};
