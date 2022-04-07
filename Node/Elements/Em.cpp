#include "Em.hpp"
Em::Em(htmlNodePtr node) : ElementNode(node) {

}

std::string Em::get_class_name(){
    std::string class_name("em");
    return class_name;
};
