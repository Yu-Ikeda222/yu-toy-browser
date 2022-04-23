#ifndef Em_h
#define Em_h

#include <stdio.h>
#include "../InlineElementNode.h"

class Em : public InlineElementNode {
public:
    Em(htmlNodePtr node);

    ~Em() {};

    std::string getClassName();
};

#endif /* Em_h */
