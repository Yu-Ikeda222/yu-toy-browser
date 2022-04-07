#include "Img.hpp"
Img::Img(htmlNodePtr node) : ElementNode(node) {
    
}

std::string Img::get_class_name(){
    std::string class_name("img");
    return class_name;
};
