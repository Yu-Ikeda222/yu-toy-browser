#include "B.hpp"
B::B(htmlNodePtr node) : ElementNode(node) {

}

std::string B::get_class_name(){
    std::string class_name("B");
    return class_name;
};
