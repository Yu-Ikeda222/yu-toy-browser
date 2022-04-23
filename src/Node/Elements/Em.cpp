#include "Em.h"

Em::Em(htmlNodePtr node) : InlineElementNode(node) {
}

std::string Em::getClassName() {
    std::string className("em");
    return className;
}
