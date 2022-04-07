#include "Span.hpp"
Span::Span(htmlNodePtr node) : ElementNode(node) {

}

std::string Span::get_class_name(){
    std::string class_name("span");
    return class_name;
};
