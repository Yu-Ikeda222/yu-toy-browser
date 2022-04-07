#include "Body.hpp"

Body::Body(htmlNodePtr node) : ElementNode(node) {

}

std::string Body::get_class_name(){
    std::string class_name("body");
    return class_name;
};
