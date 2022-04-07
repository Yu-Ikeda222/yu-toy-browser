#include "Title.hpp"

Title::Title(htmlNodePtr node) : ElementNode(node) {

}

std::string Title::get_class_name(){
    std::string class_name("Title");
    return class_name;
};
