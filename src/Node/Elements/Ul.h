#ifndef Ul_h
#define Ul_h

#include <stdio.h>
#include "../ElementNode.h"


class Ul : public ElementNode {
public:
    Ul(htmlNodePtr node);

    ~Ul() {};

    std::string getClassName();
};

#endif /* Ul_h */
