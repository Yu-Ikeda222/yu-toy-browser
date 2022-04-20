#ifndef Html_h
#define Html_h

#include <stdio.h>
#include "../ElementNode.h"

class Html : public ElementNode {
public:
    Html(htmlNodePtr node);

    ~Html() {};

    std::string getClassName();
};

#endif /* Html_h */
