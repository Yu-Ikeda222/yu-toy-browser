#include "Html.h"

Html::Html(htmlNodePtr node) : BlockElementNode(node) {

}

std::string Html::getClassName() {
    std::string className("Html");
    return className;
};
