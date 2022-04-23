#ifndef H2_h
#define H2_h

#include <stdio.h>
#include "../BlockElementNode.h"

class H2 : public BlockElementNode {
public:
    H2(htmlNodePtr node);

    ~H2() {};

    std::string getClassName();
};

#endif /* H2_h */
