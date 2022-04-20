#ifndef Head_h
#define Head_h

#include <stdio.h>
#include "../ElementNode.h"

class Head : public ElementNode {
public:
    Head(htmlNodePtr node);

    ~Head() {};

    std::string getClassName();
};

#endif /* Head_h */
