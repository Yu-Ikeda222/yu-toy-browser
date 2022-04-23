#ifndef Head_h
#define Head_h

#include <stdio.h>
#include "../InlineElementNode.h"

class Head : public InlineElementNode {
public:
    Head(htmlNodePtr node);

    ~Head() {};

    std::string getClassName();
};

#endif /* Head_h */
