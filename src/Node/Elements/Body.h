#ifndef Body_h
#define Body_h

#include <stdio.h>
#include "../ElementNode.h"

class Body : public ElementNode {
public:
    Body(htmlNodePtr node);

    ~Body() {};

    std::string getClassName();
};

#endif /* Body_h */
