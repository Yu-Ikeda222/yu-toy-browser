#include "Body.h"

Body::Body(htmlNodePtr node) : BlockElementNode(node) {

}

std::string Body::getClassName() {
    std::string className("Body");
    return className;
};