#ifndef Em_h
#define Em_h

#include <stdio.h>
#include "../ElementNode.h"

class Em : public ElementNode {
public:
    Em(htmlNodePtr node);

    ~Em() {};

    std::string getClassName();
};

#endif /* Em_h */
