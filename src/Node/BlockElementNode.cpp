#include "BlockElementNode.h"

BlockElementNode::BlockElementNode(htmlNodePtr node) : ElementNode(node) {
    setDisplayType("block");
}

BlockElementNode::~BlockElementNode() {

}

int BlockElementNode::getXPosition() {
    return 0;
}

int BlockElementNode::getYPosition() {
    Node *parent = getParent();
    Node *prev = getPrev();
    if (parent != nullptr && prev == nullptr) {
        return parent->getYPosition();
    } else if (prev != nullptr) {
        return prev->getHeight() + prev->getYPosition();
    } else {
        return 0;
    }
}

