#include "Li.h"

Li::Li(htmlNodePtr node) : BlockElementNode(node) {

}

std::string Li::getClassName() {
    std::string className("Li");
    return className;
};
