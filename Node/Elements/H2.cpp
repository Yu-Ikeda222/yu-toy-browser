#include "H2.hpp"

H2::H2(htmlNodePtr node) : ElementNode(node) {

}

std::string H2::get_class_name(){
    std::string class_name("H2");
    return class_name;
};
