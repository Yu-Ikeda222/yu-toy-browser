#ifndef Head_hpp
#define Head_hpp

#include <stdio.h>
#include "ElementNode.hpp"

class Head : public ElementNode {
public:
    Head(htmlNodePtr node);
    ~Head(){};
    std::string get_class_name();
};

#endif /* Head_hpp */
