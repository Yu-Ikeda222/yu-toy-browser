#include "Head.h"

Head::Head(htmlNodePtr node) : ElementNode(node) {

}


std::string Head::getClassName() {
    std::string class_name("Head");
    return class_name;
};

//operationのオーバーライド
//void Head::operation(renderfunc func, renderTextfunc render_text_func) {
//    //headのなかは何もしない
//}
