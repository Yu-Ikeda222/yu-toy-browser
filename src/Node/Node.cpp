#include "Node.h"

Node::Node(htmlNodePtr node) : _id(-1) {
    setNode(node);
}

htmlNodePtr Node::getNode() {
    return _node;
}

std::vector<Node *> Node::getChildren() {
    return _children;
}

int Node::getChildrenSize() {
    return (int) (_children.size());
}

std::string Node::getContent() {
    return _content;
}

Node *Node::getParent() {
    return _parent;
}

Node *Node::getPrev() {
    return _prev;
}

int Node::getId() {
    return _id;
}

void Node::setNode(htmlNodePtr node) {
    _node = node;
}

void Node::setId(int id) {
    _id = id;
}

void Node::addChild(Node *node) {
    _children.emplace_back(node);
}

void Node::addAttribute(char *key, char *value) {
    _attributes[key] = value;
}

void Node::setParent(Node *node) {
    _parent = node;
}

void Node::setPrev() {
    Node *parent = getParent();
    if (parent != nullptr) {
        for (int i = 0; i < parent->getChildrenSize(); ++i) {
            std::vector<Node *> parentsChildren = parent->getChildren();
            if (i > 0 && getId() == parentsChildren[i]->getId()) {
                _prev = parentsChildren[i - 1];
            }
        }
    }
}

std::string Node::getDisplayType() {
    return _displayType;
}

void Node::setDisplayType(std::string displayType) {
    _displayType = displayType;
}
