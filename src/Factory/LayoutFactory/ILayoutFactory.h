#ifndef ILayoutFactory_h
#define ILayoutFactory_h

#include <stdio.h>
#include <string>
#include "../../Layout/StyledNode.h"

class ILayoutFactory{
public:
    virtual Rect createElementLayoutNode(std::string node_name)=0;
};
#endif /* ILayoutFactory_h */
