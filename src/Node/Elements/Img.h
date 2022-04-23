#ifndef YU_TOY_BROWSER_IMG_H
#define YU_TOY_BROWSER_IMG_H

#include <stdio.h>
#include "../InlineElementNode.h"

class Img : public InlineElementNode {
public:
    Img(htmlNodePtr node);

    ~Img() {};

    std::string getClassName();
};

#endif /* YU_TOY_BROWSER_IMG_H */
