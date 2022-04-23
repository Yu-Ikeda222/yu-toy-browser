#ifndef B_h
#define B_h

#include <stdio.h>
#include "../InlineElementNode.h"

class B : public InlineElementNode {
public:
    B(htmlNodePtr node);

    ~B() {};

    std::string getClassName();
};

#endif /* B_h */
