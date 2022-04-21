#ifndef YU_TOY_BROWSER_STYLEDNODE_H
#define YU_TOY_BROWSER_STYLEDNODE_H

#include <stdio.h>
#include <map>
#include "../Node/Node.h"
#include "LayoutConstants.h"

class StyledNode {
    Node *_node;
    Node *_parent;
    Node *_prev;
    Rect _rect;
    std::vector<StyledNode *> _children;
public:
    StyledNode(Node *node);

    ~StyledNode() {};

    Node *getNode() { return _node; };
    int _width = 0;
    int _height = 0;

    void calculateStyle(Rect rect);

private:
    std::map<std::string, std::string> _style_value;
};

#endif /* YU_TOY_BROWSER_STYLEDNODE_H */
