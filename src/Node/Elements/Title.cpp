#include "Title.h"

Title::Title(htmlNodePtr node) : InlineElementNode(node) {

}

std::string Title::getClassName() {
    std::string className("Title");
    return className;
};
