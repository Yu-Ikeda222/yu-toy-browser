#ifndef Span_h
#define Span_h

#include <stdio.h>
#include "../ElementNode.h"

class Span : public ElementNode {
public:
    Span(htmlNodePtr node);

    ~Span() {};

    std::string getClassName();
};

#endif /* Span_h */
