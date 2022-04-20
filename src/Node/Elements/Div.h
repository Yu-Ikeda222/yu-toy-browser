#ifndef Div_h
#define Div_h

#include <stdio.h>
#include "../ElementNode.h"

class Div : public ElementNode {
public:
    Div(htmlNodePtr node);

    ~Div() {};

    std::string getClassName();
};

#endif /* Div_h */
