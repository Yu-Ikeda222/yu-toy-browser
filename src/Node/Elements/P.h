#ifndef P_h
#define P_h

#include <stdio.h>
#include "../BlockElementNode.h"

class P : public BlockElementNode {
public:
    P(htmlNodePtr node);

    ~P() {};

    std::string getClassName();
};

#endif /* P_h */
