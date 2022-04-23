#ifndef Span_h
#define Span_h

#include <stdio.h>
#include "../InlineElementNode.h"

class Span : public InlineElementNode {
public:
    Span(htmlNodePtr node);

    ~Span() {};

    std::string getClassName();
};

#endif /* Span_h */
