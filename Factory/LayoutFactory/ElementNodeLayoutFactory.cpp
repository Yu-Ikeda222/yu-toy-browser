#include "ElementNodeLayoutFactory.hpp"

ElementNodeLayoutFactory::ElementNodeLayoutFactory(){
};

ElementNodeLayoutFactory::~ElementNodeLayoutFactory(){};

Rect ElementNodeLayoutFactory::createElementLayoutNode(std::string node_name){
//    printf("ElementLayoutNodeFactory %s\n",node_name.c_str());
    Rect layout = _factory[node_name](node_name);
    return layout;
}
