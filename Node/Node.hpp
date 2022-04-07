#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <libxml/HTMLparser.h>
#include "LayoutConstants.hpp"

typedef void (*Renderfunc)(int x1,int y1,int x2, int y2,float size);

typedef void (*RenderTextfunc)(const char *text, const char* tag_name, float x, float y, float sx, float sy);

//できるだけすべてprotectedにする。privateとの違いも調べる->protectedは依存の複雑化を招くから使わない
class Node{
public:
    Node(htmlNodePtr node);
    virtual ~Node(){};
    htmlNodePtr get_node();
    std::vector<Node*> get_children();
    int get_children_size();
    std::string get_content();
    Node* get_parent();
    Node* get_prev();
    int get_id();
    virtual int get_width()=0;
    virtual int get_height()=0;
    virtual int get_x_position()=0;
    virtual int get_y_position()=0;
    void set_node(htmlNodePtr node);
    void set_id(int id);
    void add_child(Node* node);
    void add_attribute(char* key, char* value);
    void set_parent(Node* node);
    //引数に何か渡した方がいい？
    void set_prev();
    //operationの名前変えて、下の使ってないやつ消す
    virtual void operation(Renderfunc func, RenderTextfunc render_text_func)=0;
    virtual void layout(Rect rect)=0;
private:
    htmlNodePtr _node;
    //今のところは使ってないけど使いそう
    Rect _rect;
    int _id;
    //contentはNodeで持ってていいものなんか
    std::string _content;
    Node* _parent = nullptr;
    Node* _prev = nullptr;
    std::map<std::string, std::string> _attributes;
    std::vector<Node*> _children ={};
};

#endif /* Node_hpp */
