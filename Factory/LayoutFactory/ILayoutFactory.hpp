#ifndef ILayoutFactory_hpp
#define ILayoutFactory_hpp

#include <stdio.h>
#include <string>
#include "StyledNode.hpp"

class ILayoutFactory{
public:
    virtual Rect createElementLayoutNode(std::string node_name)=0;
};
#endif /* ILayoutFactory_hpp */
