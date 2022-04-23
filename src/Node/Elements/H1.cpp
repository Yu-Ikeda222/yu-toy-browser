#include "H1.h"

H1::H1(htmlNodePtr node) : BlockElementNode(node) {

}

std::string H1::getClassName() {
    std::string className("H1");
    return className;
}
