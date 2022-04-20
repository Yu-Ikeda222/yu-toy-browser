#ifndef B_h
#define B_h

#include <stdio.h>
#include "../ElementNode.h"

class B : public ElementNode {
public:
    B(htmlNodePtr node);

    ~B() {};

    std::string getClassName();
};

#endif /* B_h */
