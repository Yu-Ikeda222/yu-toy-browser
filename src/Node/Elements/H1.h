#ifndef H1_h
#define H1_h

#include <stdio.h>
#include "../BlockElementNode.h"

class H1 : public BlockElementNode {
public:
    H1(htmlNodePtr node);

    ~H1() {};

    std::string getClassName();
};

#endif /* H1_h */
