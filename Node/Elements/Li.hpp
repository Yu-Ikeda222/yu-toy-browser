#ifndef Li_hpp
#define Li_hpp

#include <stdio.h>
#include "ElementNode.hpp"

class Li : public ElementNode {
public:
    Li(htmlNodePtr node);
    ~Li(){};
    std::string get_class_name();
};
#endif /* Li_hpp */
