#include "B.h"

B::B(htmlNodePtr node) : InlineElementNode(node) {
}

std::string B::getClassName() {
    std::string className("B");
    return className;
};
