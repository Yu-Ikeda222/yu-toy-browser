#ifndef Li_h
#define Li_h

#include <stdio.h>
#include "../ElementNode.h"

class Li : public ElementNode {
public:
    Li(htmlNodePtr node);

    ~Li() {};

    std::string getClassName();
};

#endif /* Li_h */
