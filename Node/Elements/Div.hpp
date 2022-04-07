#ifndef Div_hpp
#define Div_hpp

#include <stdio.h>
#include "ElementNode.hpp"

class Div : public ElementNode {
public:
    Div(htmlNodePtr node);
    ~Div(){};
    std::string get_class_name();
};
#endif /* Div_hpp */
