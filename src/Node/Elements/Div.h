#ifndef Div_h
#define Div_h

#include <stdio.h>
#include "../BlockElementNode.h"

class Div : public BlockElementNode {
public:
    Div(htmlNodePtr node);

    ~Div() {};

    std::string getClassName();
};

#endif /* Div_h */
