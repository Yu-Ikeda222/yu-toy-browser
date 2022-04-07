#ifndef ElementNodeLayoutFactory_hpp
#define ElementNodeLayoutFactory_hpp

#include <stdio.h>
#include <map>
#include "ILayoutFactory.hpp"

class ElementNodeLayoutFactory : public ILayoutFactory{
public:
    ElementNodeLayoutFactory();
    ~ElementNodeLayoutFactory();
    Rect createElementLayoutNode(std::string node_name);
    static Rect create_html(std::string node_name) {return ElementNodeLayout::html;}
    static Rect create_head(std::string node_name) {return ElementNodeLayout::head;}
    static Rect create_title(std::string node_name) {return ElementNodeLayout::title;}
    static Rect create_body(std::string node_name) {return ElementNodeLayout::body;}
    static Rect create_h1(std::string node_name) {return ElementNodeLayout::h1;}
    static Rect create_h2(std::string node_name) {return ElementNodeLayout::h2;}
    static Rect create_div(std::string node_name) {return ElementNodeLayout::div;}
    static Rect create_a(std::string node_name) {return ElementNodeLayout::a;}
    static Rect create_b(std::string node_name) {return ElementNodeLayout::b;}
    static Rect create_span(std::string node_name) {return ElementNodeLayout::span;}
    static Rect create_p(std::string node_name) {return ElementNodeLayout::p;}
    static Rect create_img(std::string node_name) {return ElementNodeLayout::img;}
    static Rect create_ul(std::string node_name) {return ElementNodeLayout::ul;}
    static Rect create_li(std::string node_name) {return ElementNodeLayout::li;}
    static Rect create_em(std::string node_name) {return ElementNodeLayout::em;}
    static Rect create_text(std::string node_name) {return ElementNodeLayout::text;}
    std::map<std::string, Rect(*)(std::string)> _factory = {
        {"html", create_html },
        {"head", create_head },
        {"title", create_title },
        {"body", create_body },
        {"h1", create_h1 },
        {"h2", create_h2 },
        {"div", create_div},
        {"a", create_a},
        {"b", create_b},
        {"span", create_span},
        {"p", create_p},
        {"img", create_img},
        {"ul", create_ul},
        {"li", create_li},
        {"text", create_text},
    };
};
#endif /* ElementNodeLayoutFactory_hpp */
