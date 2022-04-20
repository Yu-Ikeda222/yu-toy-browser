#include "Span.h"

Span::Span(htmlNodePtr node) : ElementNode(node) {
    setDisplayType("inline");
}

std::string Span::getClassName() {
    std::string className("span");
    return className;
};
