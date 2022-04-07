#include "Html.hpp"

Html::Html(htmlNodePtr node) :ElementNode(node) {

}

std::string Html::get_class_name(){
    std::string class_name("Html");
    return class_name;
};
