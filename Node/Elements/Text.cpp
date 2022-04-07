#include "Text.hpp"
Text::Text(htmlNodePtr node) : ElementNode(node) {

}

std::string Text::get_class_name(){
    std::string class_name("Text");
    return class_name;
};

