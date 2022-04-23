#ifndef Ul_h
#define Ul_h

#include <stdio.h>
#include "../BlockElementNode.h"


class Ul : public BlockElementNode {
public:
    Ul(htmlNodePtr node);

    ~Ul() {};

    std::string getClassName();
};

#endif /* Ul_h */
