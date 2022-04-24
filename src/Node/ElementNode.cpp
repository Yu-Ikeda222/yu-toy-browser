#include "ElementNode.h"

ElementNode::ElementNode(htmlNodePtr node) : Node(node) {
    setNode(node);
    _tag = (char *) (getNode()->name);
    if (node->content) {
        getContent() = (char *) getNode()->content;
    }
}

std::string ElementNode::getClassName() {
    return "Element";
}


int ElementNode::getWidth() {
    int width = 0;
    int maxChildWidth = 0;
    std::vector<Node *> children = getChildren();
    for (int i = 0; i < getChildrenSize(); ++i) {
        int childWidth = children[i]->getWidth();
        if (maxChildWidth < childWidth) {
            maxChildWidth = childWidth;
            width += maxChildWidth;
        }
    }
    return width;
}

//少し気持ち悪い
int ElementNode::getHeight() {
    int height = 0;
    std::vector<Node *> children = getChildren();
    for (int i = 0; i < getChildrenSize(); ++i) {
        if (children[i]->getDisplayType() != "inline") {
            height += children[i]->getHeight();
        } else {
            height = children[0]->getHeight();
        }
    }
    return height;
}

//int ElementNode::getXPosition() {
//    return 0;
//}
//
//int ElementNode::getYPosition() {
//    Node *parent = getParent();
//    Node *prev = getPrev();
//    if (parent != nullptr && prev == nullptr) {
//        return parent->getYPosition();
//    } else if (prev != nullptr) {
//        return prev->getHeight() + prev->getYPosition();
//    } else {
//        return 0;
//    }
//}

//そもそもoperationとかいうのが違う
void ElementNode::operation(renderTextFunc renderTextFunc) {
    std::vector<Node *> children = getChildren();
    for (int i = 0; i < getChildrenSize(); ++i) {
//            setPrev()ここでいいのか
        children[i]->setPrev();

        int width = children[i]->getWidth();
//            int height = _children[i]->getHeight();
//            int x_position = _children[i]->getXPosition();
//            int y_position = _children[i]->getYPosition();
//            printf("%s width %d height %d x_position %d y_position %d id %d\n",_children[i]->_node->name, width, height, x_position, y_position, _children[i]->_id);
//            printf("%s %d %d (%d %d)%d %d \n", _tag.c_str(),x_position, y_position, width, height, width + x_position, height + y_position);

        //ここが機能していないから治す、これが終わったら横幅変えた時に対応するようにする。その後スクロールできる様にする。その後全力リファクタリング
//                func( x_position, y_position, width + x_position, height + y_position, 1);

        children[i]->operation(renderTextFunc);
    }
}

void ElementNode::setTag(char *tag) {
    _tag = tag;
}

void ElementNode::layout(Rect rect) {

}
