#include "ElementNodeFactory.h"
//#include "../../Node/include/ElementNode.h"

ElementNodeFactory::ElementNodeFactory() {
};

ElementNodeFactory::~ElementNodeFactory() {};

ElementNode *ElementNodeFactory::createNode(htmlNodePtr node) {
    ElementNode *_node = _factory[(char *) (node->name)](node);
    return _node;
}


