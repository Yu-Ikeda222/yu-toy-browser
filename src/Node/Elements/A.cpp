#include "A.h"

A::A(htmlNodePtr node) : ElementNode(node) {
    setDisplayType("inline");
}

std::string A::getClassName() {
    std::string className("A");
    return className;
};
