#include "A.h"

A::A(htmlNodePtr node) : InlineElementNode(node) {

}

std::string A::getClassName() {
    std::string className("A");
    return className;
};
