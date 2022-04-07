#include "A.hpp"

A::A(htmlNodePtr node) : ElementNode(node) {
    
}

std::string A::get_class_name(){
    std::string class_name("A");
    return class_name;
};
