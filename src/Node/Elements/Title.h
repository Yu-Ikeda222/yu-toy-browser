#ifndef Title_h
#define Title_h

#include <stdio.h>
#include "../InlineElementNode.h"

class Title : public InlineElementNode {
public:
    Title(htmlNodePtr node);

    ~Title() {};

    std::string getClassName();
};

#endif /* Title_h */
