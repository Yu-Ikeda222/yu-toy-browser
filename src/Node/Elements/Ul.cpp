#include "Ul.h"

Ul::Ul(htmlNodePtr node) : ElementNode(node) {
    setDisplayType("block");
}

std::string Ul::getClassName() {
    std::string className("Ul");
    return className;
};