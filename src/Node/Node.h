#ifndef YU_TOY_BROWSER_NODE_H
#define YU_TOY_BROWSER_NODE_H

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <libxml/HTMLparser.h>
#include "../Layout/LayoutConstants.h"

//typedef void (*renderfunc)(int x1, int y1, int x2, int y2, float size);

typedef void (*renderTextFunc)(const char *text, const char *tagName, float x, float y, float sx, float sy);


//できるだけすべてprotectedにする。privateとの違いも調べる->protectedは依存の複雑化を招くから使わない
class Node {
public:
    Node(htmlNodePtr node);

    virtual ~Node() {};

    htmlNodePtr getNode();

    std::vector<Node *> getChildren();

    int getChildrenSize();

    std::string getContent();

    Node *getParent();

    Node *getPrev();

    int getId();

    virtual std::string getClassName() = 0;

    virtual int getWidth() = 0;

    virtual int getHeight() = 0;

    virtual int getXPosition() = 0;

    virtual int getYPosition() = 0;

    void setNode(htmlNodePtr node);

    void setId(int id);

    void addChild(Node *node);

    void addAttribute(char *key, char *value);

    void setParent(Node *node);

    //引数に何か渡した方がいい？
    void setPrev();

    //operationの名前変えて、下の使ってないやつ消す
    virtual void operation(renderTextFunc renderTextFunc) = 0;

    virtual void layout(Rect rect) = 0;

private:
    htmlNodePtr _node;
    //今のところは使ってないけど使いそう
    Rect _rect;
    int _id;
    //contentはNodeで持ってていいものなんか
    std::string _content;
    Node *_parent = nullptr;
    Node *_prev = nullptr;
    std::map<std::string, std::string> _attributes;
    std::vector<Node *> _children;
};

#endif /* YU_TOY_BROWSER_NODE_h */
