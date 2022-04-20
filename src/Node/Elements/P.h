#ifndef P_h
#define P_h

#include <stdio.h>
#include "../ElementNode.h"

class P : public ElementNode {
public:
    P(htmlNodePtr node);

    ~P() {};

    std::string getClassName();
};

#endif /* P_h */
