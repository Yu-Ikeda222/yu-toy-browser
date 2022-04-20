#ifndef ElementNodeFactory_h
#define ElementNodeFactory_h

#include <stdio.h>
#include <vector>
#include <map>
#include "../../Node/Node.h"
#include "IElementNodeFactory.h"
#include "../../Node/Elements/Html.h"
#include "../../Node/Elements/Body.h"
#include "../../Node/Elements/Head.h"
#include "../../Node/Elements/Title.h"
#include "../../Node/Elements/H1.h"
#include "../../Node/Elements/H2.h"
#include "../../Node/Elements/Div.h"
#include "../../Node/Elements/A.h"
#include "../../Node/Elements/B.h"
#include "../../Node/Elements/Span.h"
#include "../../Node/Elements/P.h"
#include "../../Node/Elements/Img.h"
#include "../../Node/Elements/Ul.h"
#include "../../Node/Elements/Li.h"
#include "../../Node/Elements/Em.h"
#include "../../Node/Elements/Text.h"

typedef ElementNode *(*createElement)(htmlNodePtr node);

class ElementNodeFactory : public IElementNodeFactory {
public:
    ElementNodeFactory();

    ~ElementNodeFactory();

    ElementNode *createNode(htmlNodePtr node);

    static ElementNode *createHtml(htmlNodePtr node) { return new Html(node); };

    static ElementNode *createHead(htmlNodePtr node) { return new Head(node); };

    static ElementNode *createTitle(htmlNodePtr node) { return new Title(node); };

    static ElementNode *createBody(htmlNodePtr node) { return new Body(node); };

    static ElementNode *createH1(htmlNodePtr node) { return new H1(node); };

    static ElementNode *createH2(htmlNodePtr node) { return new H2(node); };

    static ElementNode *createDiv(htmlNodePtr node) { return new Div(node); };

    static ElementNode *createA(htmlNodePtr node) { return new A(node); };

    static ElementNode *createB(htmlNodePtr node) { return new B(node); };

    static ElementNode *createSpan(htmlNodePtr node) { return new Span(node); };

    static ElementNode *createP(htmlNodePtr node) { return new P(node); };

    static ElementNode *createImg(htmlNodePtr node) { return new Img(node); };

    static ElementNode *createUl(htmlNodePtr node) { return new Ul(node); };

    static ElementNode *createLi(htmlNodePtr node) { return new Li(node); };

    static ElementNode *createEm(htmlNodePtr node) { return new Em(node); };

    static ElementNode *createText(htmlNodePtr node) { return new Text(node); };

    std::map<const std::string, createElement> _factory = {
//            std::make_pair("html", createHtml),
//            std::make_pair("head", createHead),
//            std::make_pair("title", createTitle),
//            std::make_pair("body", createBody),
//            std::make_pair("h1", createH1),
//            std::make_pair("h2", createH2),
//            std::make_pair("div", createDiv),
//            std::make_pair("a", createA),
//            std::make_pair("b", createB),
//            std::make_pair("span", createSpan),
//            std::make_pair("p", createP),
//            std::make_pair("img", createImg),
//            std::make_pair("ul", createUl),
//            std::make_pair("li", createLi),
//            std::make_pair("em", createEm),
//            std::make_pair("text", createText),

            {"html",  createHtml},
            {"head",  createHead},
            {"title", createTitle},
            {"body",  createBody},
            {"h1",    createH1},
            {"h2",    createH2},
            {"div",   createDiv},
            {"a",     createA},
            {"b",     createB},
            {"span",  createSpan},
            {"p",     createP},
            {"img",   createImg},
            {"ul",    createUl},
            {"li",    createLi},
            {"em",    createEm},
            {"text",  createText},
    };

//        なぜエラーになるかわからない
//        {"text", [](htmlNodePtr node){ return new Text(node);}},
//    };
};

#endif /* ElementNodeFactory_h */
