#ifndef YU_TOY_BROWSER_BLOCKELEMENTNODE_H
#define YU_TOY_BROWSER_BLOCKELEMENTNODE_H

#include "ElementNode.h"

class BlockElementNode : public ElementNode {
public:
    BlockElementNode(htmlNodePtr node);

    virtual ~BlockElementNode();

    int getXPosition();

    int getYPosition();

};


#endif //YU_TOY_BROWSER_BLOCKELEMENTNODE_H
