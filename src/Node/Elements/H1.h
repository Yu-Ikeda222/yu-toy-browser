#ifndef H1_h
#define H1_h

#include <stdio.h>
#include "../ElementNode.h"

class H1 : public ElementNode {
public:
    H1(htmlNodePtr node);

    ~H1() {};

    std::string getClassName();
};

#endif /* H1_h */
