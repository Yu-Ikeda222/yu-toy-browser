#include "Span.h"

Span::Span(htmlNodePtr node) : InlineElementNode(node) {

}

std::string Span::getClassName() {
    std::string className("span");
    return className;
};
