#ifndef H2_hpp
#define H2_hpp

#include <stdio.h>
#include "ElementNode.hpp"

class H2 : public ElementNode {
public:
    H2(htmlNodePtr node);
    ~H2(){};
    std::string get_class_name();
};
#endif /* H2_hpp */
