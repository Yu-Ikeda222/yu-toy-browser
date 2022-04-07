#include "H1.hpp"

H1::H1(htmlNodePtr node) : ElementNode(node) {

}

std::string H1::get_class_name(){
    std::string class_name("H1");
    return class_name;
};
