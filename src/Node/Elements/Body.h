#ifndef Body_h
#define Body_h

#include <stdio.h>
#include "../BlockElementNode.h"

class Body : public BlockElementNode {
public:
    Body(htmlNodePtr node);

    ~Body() {};

    std::string getClassName();
};

#endif /* Body_h */
