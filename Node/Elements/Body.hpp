#ifndef Body_hpp
#define Body_hpp

#include <stdio.h>
#include "ElementNode.hpp"

class Body : public ElementNode {
public:
    Body(htmlNodePtr node);
    ~Body(){};
    std::string get_class_name();
};
#endif /* Body_hpp */
