#include "Li.hpp"
Li::Li(htmlNodePtr node) : ElementNode(node) {

}

std::string Li::get_class_name(){
    std::string class_name("Li");
    return class_name;
};
