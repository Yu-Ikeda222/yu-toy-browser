#include "Title.h"

Title::Title(htmlNodePtr node) : ElementNode(node) {

}

std::string Title::getClassName() {
    std::string className("Title");
    return className;
};
