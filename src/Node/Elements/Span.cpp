#include "Span.h"

Span::Span(htmlNodePtr node) : InlineElementNode(node) {

}

std::string Span::getClassName() {
    std::string className("Span");
    return className;
};
