#ifndef Span_hpp
#define Span_hpp

#include <stdio.h>
#include "ElementNode.hpp"

class Span : public ElementNode {
public:
    Span(htmlNodePtr node);
    ~Span(){};
    std::string get_class_name();
};

#endif /* Span_hpp */
