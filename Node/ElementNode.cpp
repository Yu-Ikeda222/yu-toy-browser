#include "ElementNode.hpp"

ElementNode::ElementNode(htmlNodePtr node) : Node(node){
    set_node(node);
    _tag = (char*)get_node()->name;
    if(node->content){
        get_content() = (char*)get_node()->content;
    }
}



std::string ElementNode::get_class_name() {
    return "Element";
}


int ElementNode::get_width() {
    int width=0;
    int max_child_width=0;
    std::vector<Node*> children = get_children();
    for (int i= 0; i< get_children_size(); ++i) {
        int child_width = children[i]->get_width();
        if(max_child_width < child_width){
            max_child_width = child_width;
            width += max_child_width;
        }
    }
    return width;
}

int ElementNode::get_height() {
    int height=0;
    std::vector<Node*> children = get_children();
    for (int i= 0; i< get_children_size(); ++i) {
        height += children[i]->get_height();
    }
    return height;
}

int ElementNode::get_x_position() {
    return 0;
}

int ElementNode::get_y_position() {
    Node* parent = get_parent();
    Node* prev = get_prev();
    if(parent != nullptr && prev == nullptr){
        return parent->get_y_position();
    }
    else if(prev != nullptr) {
        return prev->get_height()+prev->get_y_position();
    } else {
        return 0;
    }
}


//そもそもoperationとかいうのが違う
void ElementNode::operation(Renderfunc func, RenderTextfunc render_text_func) {
    std::vector<Node*> children = get_children();
        for(int i=0; i < get_children_size(); ++i) {
//            set_prev()ここでいいのか
            children[i]->set_prev();
            
//            int width = _children[i]->get_width();
//            int height = _children[i]->get_height();
//            int x_position = _children[i]->get_x_position();
//            int y_position = _children[i]->get_y_position();
//            printf("%s width %d height %d x_position %d y_position %d id %d\n",_children[i]->_node->name, width, height, x_position, y_position, _children[i]->_id);
//            printf("%s %d %d (%d %d)%d %d \n", _tag.c_str(),x_position, y_position, width, height, width + x_position, height + y_position);
            
            //ここが機能していないから治す、これが終わったら横幅変えた時に対応するようにする。その後スクロールできる様にする。その後全力リファクタリング
//                func( x_position, y_position, width + x_position, height + y_position, 1);
            
            children[i]->operation(func, render_text_func);
        }
}

void ElementNode::layout(Rect rect){
    
}
