#include "Node.hpp"

Node::Node(htmlNodePtr node): _id(-1){
    set_node(node);
}

htmlNodePtr Node::get_node() {
    return _node;
}

std::vector<Node*> Node::get_children() {
    return _children;
}

int Node::get_children_size() {
    return (int)(_children.size());
}

std::string Node::get_content() {
    return _content;
}

Node* Node::get_parent() {
    return _parent;
}

Node* Node::get_prev() {
    return _prev;
}

int Node::get_id() {
    return _id;
}

void Node::set_node(htmlNodePtr node) {
    _node = node;
}

void Node::set_id(int id) {
    _id = id;
}

void Node::add_child(Node* node) {
    _children.emplace_back(node);
}
void Node::add_attribute(char* key, char* value) {
    _attributes[key] = value;
}

void Node::set_parent(Node* node) {
    _parent = node;
}
void Node::set_prev(){
    Node* parent = get_parent();
    if(parent != nullptr) {
        for(int i = 0; i < parent->get_children_size(); ++i){
            std::vector<Node*> parents_children = parent->get_children();
            if(i > 0 && get_id() == parents_children[i]->get_id()){
                _prev = parents_children[i-1];
            }
        }
    }
};
