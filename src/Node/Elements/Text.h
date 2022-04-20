#ifndef Text_h
#define Text_h

#include <stdio.h>
#include "../ElementNode.h"

class Text : public ElementNode {
public:
    Text(htmlNodePtr node);

    ~Text() {};

    std::string getClassName();
};

#endif /* Text_h */
