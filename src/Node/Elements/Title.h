#ifndef Title_h
#define Title_h

#include <stdio.h>
#include "../ElementNode.h"

class Title : public ElementNode {
public:
    Title(htmlNodePtr node);

    ~Title() {};

    std::string getClassName();
};

#endif /* Title_h */
