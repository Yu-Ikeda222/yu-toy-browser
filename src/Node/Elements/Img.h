#ifndef Img_h
#define Img_h

#include <stdio.h>
#include "../ElementNode.h"

class Img : public ElementNode {
public:
    Img(htmlNodePtr node);

    ~Img() {};

    std::string getClassName();
};

#endif /* Img_h */
