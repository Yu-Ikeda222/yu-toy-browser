#ifndef ElementNodeFactory_hpp
#define ElementNodeFactory_hpp

#include <stdio.h>
#include <vector>
#include <map>
#include "Node.hpp"
#include "IElementNodeFactory.hpp"
#include "Html.hpp"
#include "Body.hpp"
#include "Head.hpp"
#include "Title.hpp"
#include "H1.hpp"
#include "H2.hpp"
#include "Div.hpp"
#include "A.hpp"
#include "B.hpp"
#include "Span.hpp"
#include "P.hpp"
#include "Img.hpp"
#include "Ul.hpp"
#include "Li.hpp"
#include "Em.hpp"
#include "Text.hpp"

class ElementNodeFactory : public IElementNodeFactory{
public:
    ElementNodeFactory();
    ~ElementNodeFactory();
    ElementNode* createNode(htmlNodePtr node);
    std::map<std::string, std::function<ElementNode*(htmlNodePtr node)>> _factory = {
        {"html", [](htmlNodePtr node){ return new Html(node);} },
        {"head", [](htmlNodePtr node){ return new Head(node);} },
        {"title", [](htmlNodePtr node){ return new Title(node);} },
        {"body", [](htmlNodePtr node){ return new Body(node);} },
        {"h1", [](htmlNodePtr node){ return new H1(node);} },
        {"h2", [](htmlNodePtr node){ return new H2(node);} },
        {"div", [](htmlNodePtr node){ return new Div(node);}},
        {"a", [](htmlNodePtr node){ return new A(node);}},
        {"b", [](htmlNodePtr node){ return new B(node);}},
        {"span", [](htmlNodePtr node){ return new Span(node);}},
        {"p", [](htmlNodePtr node){ return new P(node);}},
        {"img", [](htmlNodePtr node){ return new Img(node);}},
        {"ul", [](htmlNodePtr node){ return new Ul(node);}},
        {"li", [](htmlNodePtr node){ return new Li(node);}},
        {"em", [](htmlNodePtr node){ return new Em(node);}},
        {"text", [](htmlNodePtr node){ return new Text(node);}},
    };
};
#endif /* ElementNodeFactory_hpp */
