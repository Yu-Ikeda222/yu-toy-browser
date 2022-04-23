#include "P.h"

P::P(htmlNodePtr node) : BlockElementNode(node) {

}

std::string P::getClassName() {
    std::string className("p");
    return className;
};
