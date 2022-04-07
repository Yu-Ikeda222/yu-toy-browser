#ifndef Title_hpp
#define Title_hpp

#include <stdio.h>
#include "ElementNode.hpp"

class Title : public ElementNode {
public:
    Title(htmlNodePtr node);
    ~Title(){};
    std::string get_class_name();
};

#endif /* Title_hpp */
