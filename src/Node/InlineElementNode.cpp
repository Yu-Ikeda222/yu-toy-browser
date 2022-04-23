#include "InlineElementNode.h"

InlineElementNode::InlineElementNode(htmlNodePtr node) : ElementNode(node) {
    setDisplayType("inline");
}

InlineElementNode::~InlineElementNode() {

}

int InlineElementNode::getXPosition() {
    if (Node *prev = getPrev()) {
        if (prev->getDisplayType() == "block") {
            return 0;
        }
//        printf("%d %d\n", prev->getWidth(), prev->getXPosition());
        return prev->getWidth() + prev->getXPosition();
    } else {
        return 0;
    }

}

int InlineElementNode::getYPosition() {
    Node *parent = getParent();
    Node *prev = getPrev();
    if (prev != nullptr) {
        if (prev->getDisplayType() == "block") {
            return prev->getHeight() + prev->getYPosition();
        }
        return prev->getYPosition();
    } else if (parent != nullptr) {
        return parent->getYPosition();
    }


    return 0;
}
