#include "TextNode.hpp"
#include <GL/freeglut.h>

TextNode::TextNode(htmlNodePtr node) : Node(node) {
    _text = trim((char*)(node->content));
}

int TextNode::get_width() {
//    printf("window %d\n",glutGet(GLUT_WINDOW_WIDTH));
    unsigned long text_length = 0;
    Node* parent = get_parent();
    if(strcmp((char*)(parent->get_node()->name), "h1") == 0){
        text_length = _text.size();
//        printf("%d\n", (int)(text_length * 32));
        return (int)(text_length * 32);
    } else if (strcmp((char*)(parent->get_node()->name), "h2") == 0){
        text_length = _text.size();
//        printf("%d\n", (int)(text_length * 24));
        return (int)(text_length * 24);
    } else {
        text_length = _text.size();
//        printf("%d\n", (int)(text_length * 16));
        
        //やりたいこととしてはwindowサイズを変えた時に改行されるように、画面外に出ることがないように
        if((int)(text_length * 16) > glutGet(GLUT_WINDOW_WIDTH)) {
            int max_text_length = 0;
            int over_char_size = 0;
            for(int i = 0; i < text_length; ++i) {
                max_text_length = (int)(text_length - i);
                if((int)(max_text_length * 16) > glutGet(GLUT_WINDOW_WIDTH)) {
                    continue;
                } else {
                    over_char_size = i;
//                    printf("over %d\n", (int)(over_char_size));
                    return (int)(max_text_length * 16);
                }
            }
        }
        return (int)(text_length * 16);
    }
}

int TextNode::get_height() {
    Node* parent = get_parent();
    if (strcmp((char*)(parent->get_node()->name), "title") == 0){
        return 0;
    } else if (strcmp((char*)(parent->get_node()->name), "h1") == 0) {
        return 32;
    } else if (strcmp((char*)(parent->get_node()->name), "h2") == 0) {
        return 24;
    } else if (strcmp((char*)(parent->get_node()->name), "text") == 0) {
        //計算コスト
        if(get_width() > 0) {
            return 16;
        } else {
            return 0;
        }

    }
    else {
        return 16;
    }
}

int TextNode::get_x_position() {
    return 0;
}

int TextNode::get_y_position() {
    Node* parent = get_parent();
    int y_position = parent->get_height() + parent->get_y_position();
    return y_position;
}


//今のところRenderfuncが意味を成してない
void TextNode::operation(Renderfunc func, RenderTextfunc render_text_func) {
    Node* parent = get_parent();
    
    float sx = 2.0 / glutGet(GLUT_WINDOW_WIDTH);
    float sy = 2.0 / glutGet(GLUT_WINDOW_HEIGHT);
    
//    場所の計算の仕方の明確なルールがよくわかっていない
    render_text_func(_text.c_str(),(const char*)(parent->get_node()->name), -1 + (8 + get_x_position()) * sx, 1 - (get_y_position()) * sy, sx, sy);
}

void TextNode::layout(Rect rect) {
    
}

std::string TextNode::trim(const std::string& string, const char* trimCharacterList)

{
    std::string result;
    std::string reduced_string;
    std::string::size_type left = string.find_first_not_of(trimCharacterList);
    if (left != std::string::npos)
    {
        std::string::size_type right = string.find_last_not_of(trimCharacterList);
        reduced_string = string.substr(left, right - left + 1);
    }
    
    for (int i = 0; i < reduced_string.size(); ++i) {
        if ((!isspace(reduced_string[i]) || (isspace(reduced_string[i]) && !isspace(reduced_string[i+1]))) && reduced_string[i] != '\n') {
            result.push_back(reduced_string[i]);
        }
    }
    return result;
}
