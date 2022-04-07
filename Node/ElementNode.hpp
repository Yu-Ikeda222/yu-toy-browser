#ifndef ElementNode_hpp
#define ElementNode_hpp

#include <stdio.h>
#include <string.h>
#include "Node.hpp"
#include "StyledNode.hpp"
#include "LayoutConstants.hpp"
#include "ElementNodeLayoutFactory.hpp"

//できるだけすべてprotectedにする。privateとの違いも調べる
class ElementNode : public Node {
public:
    
    ElementNode(htmlNodePtr node);
    ~ElementNode(){};
    virtual std::string get_class_name();
    int get_width();
    int get_height();
    int get_x_position();
    int get_y_position();
    void set_prev();
    //operationは以下略
    void operation(Renderfunc func, RenderTextfunc render_text_func);
    void layout(Rect rect);
private:
    std::string _tag;

};

#endif /* ElementNode_hpp */
