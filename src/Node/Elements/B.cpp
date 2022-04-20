#include "B.h"

B::B(htmlNodePtr node) : ElementNode(node) {
    setDisplayType("inline");
}

std::string B::getClassName() {
    std::string className("B");
    return className;
};
