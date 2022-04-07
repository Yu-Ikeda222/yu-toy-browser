#include "parse/parseHTML.hpp"
#include "render/render_window.hpp"

void init(int argc, char *argv[]);
int main(int argc, char *argv[]){
    const char* file_name = "/Users/ikedayu/yu_browser/yu_browser/examples/example.html";
    
    //こういうのってクラス？Trimはutils的なのに入れるのがいいかな。namespace?
    ElementNode* root_node = parseHTML(file_name);
    
    // root_node->render();
    //これはクラスかな、いつか抽象化してMetalとか使いたいけど、一旦はwindowクラスとかでいいのかな
//    [](){}　この中でroot_node->
    init(argc, argv);
    render_window_opneGL(root_node);
    return 0;
}

void init(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(WINDOW_POSITION_X, WINDOW_POSITION_Y);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitDisplayMode(GLUT_RGBA);
}
