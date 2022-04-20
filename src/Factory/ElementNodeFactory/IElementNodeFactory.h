#ifndef IElementNodeFactory_h
#define IElementNodeFactory_h

#include <stdio.h>
#include "../../Node/ElementNode.h"

class IElementNodeFactory {
public:
    virtual ElementNode *createNode(htmlNodePtr node) = 0;
};

#endif /* IFactory_h */
