#ifndef Text_h
#define Text_h

#include <stdio.h>
#include "../InlineElementNode.h"

class Text : public InlineElementNode {
public:
    Text(htmlNodePtr node);

    ~Text() {};

    std::string getClassName();
};

#endif /* Text_h */
