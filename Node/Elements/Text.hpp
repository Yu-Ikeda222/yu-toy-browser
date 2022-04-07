#ifndef Text_hpp
#define Text_hpp

#include <stdio.h>
#include "ElementNode.hpp"

class Text : public ElementNode {
public:
    Text(htmlNodePtr node);
    ~Text(){};
    std::string get_class_name();
};
#endif /* Text_hpp */
