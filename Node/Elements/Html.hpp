#ifndef Html_hpp
#define Html_hpp

#include <stdio.h>
#include "ElementNode.hpp"

class Html : public ElementNode {
public:
    Html(htmlNodePtr node);
    ~Html(){};
    std::string get_class_name();
};

#endif /* Html_hpp */
