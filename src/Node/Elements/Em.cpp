#include "Em.h"

Em::Em(htmlNodePtr node) : ElementNode(node) {
    setDisplayType("inline");
}

std::string Em::getClassName() {
    std::string className("em");
    return className;
}
