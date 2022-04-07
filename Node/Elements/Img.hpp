#ifndef Img_hpp
#define Img_hpp

#include <stdio.h>
#include "ElementNode.hpp"

class Img : public ElementNode {
public:
    Img(htmlNodePtr node);
    ~Img(){};
    std::string get_class_name();
};
#endif /* Img_hpp */
