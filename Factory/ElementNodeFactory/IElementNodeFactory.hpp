#ifndef IElementNodeFactory_hpp
#define IElementNodeFactory_hpp

#include <stdio.h>
#include "ElementNode.hpp"

class IElementNodeFactory{
public:
    virtual ElementNode* createNode(htmlNodePtr node)=0;
};
#endif /* IFactory_hpp */
