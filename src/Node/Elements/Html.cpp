#include "Html.h"

Html::Html(htmlNodePtr node) : ElementNode(node) {

}

std::string Html::getClassName() {
    std::string className("Html");
    return className;
};
