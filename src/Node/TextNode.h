#ifndef YU_TOY_BROWSER_TEXTNODE_H
#define YU_TOY_BROWSER_TEXTNODE_H

#include <stdio.h>
#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include "ElementNode.h"

//できるだけすべてprotectedにする。privateとの違いも調べる
class TextNode : public Node {
public:
    TextNode(htmlNodePtr node);

    ~TextNode() {};

    //使ってるか？
    std::string getText(std::string) { return _text; };

    std::string trim(const std::string &string, const char *trimCharacterList = " \t\v\r\n");

    std::string getClassName() final { return "TextNode"; };

    int getWidth() final;

    int getHeight() final;

    int getXPosition() final;

    int getYPosition() final;

    //名前変更
    void operation(renderTextFunc renderTextFunc) final;

    void layout(Rect rect);

private:
    std::string _text;
};

#endif /* YU_TOY_BROWSER_TEXTNODE_h */
