#include "Div.hpp"


Div::Div(htmlNodePtr node) : ElementNode(node) {

}

std::string Div::get_class_name() {
    std::string class_name("Div");
    return class_name;
};
