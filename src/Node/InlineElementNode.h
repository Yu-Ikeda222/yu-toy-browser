#ifndef YU_TOY_BROWSER_INLINEELEMENTNODE_H
#define YU_TOY_BROWSER_INLINEELEMENTNODE_H

#include "ElementNode.h"

class InlineElementNode : public ElementNode {
public:
    InlineElementNode(htmlNodePtr node);

    virtual ~InlineElementNode();

    int getXPosition();

    int getYPosition();
};


#endif //YU_TOY_BROWSER_INLINEELEMENTNODE_H
