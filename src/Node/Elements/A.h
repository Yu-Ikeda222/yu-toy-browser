#ifndef A_h
#define A_h

#include <stdio.h>
#include "../InlineElementNode.h"

class A : public InlineElementNode {
public:
    A(htmlNodePtr node);

    ~A() {};

    std::string getClassName();
};

#endif /* A_h */
