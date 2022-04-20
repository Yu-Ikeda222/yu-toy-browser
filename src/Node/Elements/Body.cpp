#include "Body.h"

Body::Body(htmlNodePtr node) : ElementNode(node) {

}

std::string Body::getClassName() {
    std::string className("body");
    return className;
};