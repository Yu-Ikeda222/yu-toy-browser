#ifndef P_hpp
#define P_hpp

#include <stdio.h>
#include "ElementNode.hpp"

class P : public ElementNode {
public:
    P(htmlNodePtr node);
    ~P(){};
    std::string get_class_name();
};

#endif /* P_hpp */
