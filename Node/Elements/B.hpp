#ifndef B_hpp
#define B_hpp

#include <stdio.h>
#include "ElementNode.hpp"

class B : public ElementNode {
public:
    B(htmlNodePtr node);
    ~B(){};
    std::string get_class_name();
};
#endif /* B_hpp */
