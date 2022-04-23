#include "Div.h"

Div::Div(htmlNodePtr node) : BlockElementNode(node) {
}

std::string Div::getClassName() {
    std::string className("Div");
    return className;
};
