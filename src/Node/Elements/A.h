#ifndef A_h
#define A_h

#include <stdio.h>
#include "../ElementNode.h"

class A : public ElementNode {
public:
    A(htmlNodePtr node);

    ~A() {};

    std::string getClassName();
};

#endif /* A_h */
