#ifndef YU_TOY_BROWSER_STYLEDNODE_H
#define YU_TOY_BROWSER_STYLEDNODE_H

#include <stdio.h>
#include <map>
#include "../Node/Node.h"
#include "LayoutConstants.h"

//右上右下左上左下
// 3-1=幅　4-2=高さ
namespace elementNodeLayout {
//constexpr Rect html{0,0,1024,0};
//constexpr Rect head{0,0,0,0};
//constexpr Rect title{0,0,0,0};
//constexpr Rect body{0,0,0,0};
//constexpr Rect div{0,0,0,0};
//constexpr Rect h1{30,20,100,60};
//constexpr Rect h2{30,20,100,100};
//constexpr Rect a{0,0,0,0};
//constexpr Rect b{0,0,0,0};
//constexpr Rect span{0,0,0,0};
//constexpr Rect img{0,0,0,0};
//constexpr Rect p{0,0,0,0};
//constexpr Rect ul{0,0,0,0};
//constexpr Rect li{0,0,0,0};
//constexpr Rect em {0,0,0,0};
//constexpr Rect text{0,0,0,0};
}

class StyledNode {
public:
    StyledNode(Node *node);

    ~StyledNode() {};
    std::vector<StyledNode *> _children;
    Node *_node;
    Node *_parent;
    Rect _rect;
    int _width = 0;
    int _height = 0;

    void calculateStyle(Rect rect);

private:
    std::map<std::string, std::string> _style_value;
};

#endif /* YU_TOY_BROWSER_STYLEDNODE_H */
