#ifndef Em_hpp
#define Em_hpp

#include <stdio.h>
#include "ElementNode.hpp"

class Em : public ElementNode {
public:
    Em(htmlNodePtr node);
    ~Em(){};
    std::string get_class_name();
};
#endif /* Em_hpp */
