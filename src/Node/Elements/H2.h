#ifndef H2_h
#define H2_h

#include <stdio.h>
#include "../ElementNode.h"

class H2 : public ElementNode {
public:
    H2(htmlNodePtr node);

    ~H2() {};

    std::string getClassName();
};

#endif /* H2_h */
