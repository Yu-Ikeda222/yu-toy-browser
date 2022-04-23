#ifndef Html_h
#define Html_h

#include <stdio.h>
#include "../BlockElementNode.h"

class Html : public BlockElementNode {
public:
    Html(htmlNodePtr node);

    ~Html() {};

    std::string getClassName();
};

#endif /* Html_h */
