#ifndef YU_TOY_BROWSER_ELEMENTNODE_H
#define YU_TOY_BROWSER_ELEMENTNODE_H

#include <stdio.h>
#include <string.h>
#include "Node.h"
#include "../Layout/StyledNode.h"
#include "../Layout/LayoutConstants.h"
#include "../Factory/LayoutFactory/ElementNodeLayoutFactory.h"


//できるだけすべてprotectedにする。privateとの違いも調べる
class ElementNode : public Node {
public:

    ElementNode(htmlNodePtr node);

    virtual ~ElementNode() {};

    virtual std::string getClassName();

    int getWidth();

    int getHeight();

    int getXPosition();

    int getYPosition();

    char *getDisplayType();

    //operationは以下略
    void operation(renderTextFunc renderTextFunc);

    void layout(Rect rect);

    void setTag(char *tag);

    void setDisplayType(char *displayType);

private:
    std::string _tag;
    char *_displayType;

};

#endif /* YU_TOY_BROWSER_ELEMENTNODE_H */
