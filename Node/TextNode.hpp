#ifndef TextNode_hpp
#define TextNode_hpp

#include <stdio.h>
#include "ElementNode.hpp"

//できるだけすべてprotectedにする。privateとの違いも調べる
class TextNode : public Node {
public:
    TextNode(htmlNodePtr node);
    ~TextNode(){};
    //使ってるか？
    std::string get_text(std::string) {return _text;};
    std::string trim(const std::string& string, const char* trimCharacterList = " \t\v\r\n");
    int get_width();
    int get_height();
    int get_x_position();
    int get_y_position();
    //名前変更
    void operation(Renderfunc func, RenderTextfunc render_text_func);
    void layout(Rect rect);
private:
    std::string _text;
};

#endif /* TextNode_hpp */
