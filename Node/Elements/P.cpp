#include "P.hpp"
P::P(htmlNodePtr node) : ElementNode(node) {

}

std::string P::get_class_name(){
    std::string class_name("p");
    return class_name;
};
