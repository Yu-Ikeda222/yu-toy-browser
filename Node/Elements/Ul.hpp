#ifndef Ul_hpp
#define Ul_hpp

#include <stdio.h>
#include "ElementNode.hpp"


class Ul : public ElementNode {
public:
    Ul(htmlNodePtr node);
    ~Ul(){};
    std::string get_class_name();
};
#endif /* Ul_hpp */
