#ifndef H1_hpp
#define H1_hpp

#include <stdio.h>
#include "ElementNode.hpp"

class H1 : public ElementNode {
public:
    H1(htmlNodePtr node);
    ~H1(){};
    std::string get_class_name();
};
#endif /* H1_hpp */
