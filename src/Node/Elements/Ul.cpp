#include "Ul.h"

Ul::Ul(htmlNodePtr node) : BlockElementNode(node) {
    ("block");
}

std::string Ul::getClassName() {
    std::string className("Ul");
    return className;
};