#ifndef Li_h
#define Li_h

#include <stdio.h>
#include "../BlockElementNode.h"

class Li : public BlockElementNode {
public:
    Li(htmlNodePtr node);

    ~Li() {};

    std::string getClassName();
};

#endif /* Li_h */
