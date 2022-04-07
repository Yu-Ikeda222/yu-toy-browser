#ifndef A_hpp
#define A_hpp

#include <stdio.h>
#include "ElementNode.hpp"

class A : public ElementNode {
public:
    A(htmlNodePtr node);
    ~A(){};
    std::string get_class_name();
};
#endif /* A_hpp */
