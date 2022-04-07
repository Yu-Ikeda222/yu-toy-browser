#include "Ul.hpp"
Ul::Ul(htmlNodePtr node) : ElementNode(node) {

}

std::string Ul::get_class_name(){
    std::string class_name("Ul");
    return class_name;
};
