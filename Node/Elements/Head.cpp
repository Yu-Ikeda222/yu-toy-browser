#include "Head.hpp"

Head::Head(htmlNodePtr node) : ElementNode(node) {

}


std::string Head::get_class_name(){
    std::string class_name("Head");
    return class_name;
};

//operationのオーバーライド
//void Head::operation(Renderfunc func, RenderTextfunc render_text_func) {
//    //headのなかは何もしない
//}
