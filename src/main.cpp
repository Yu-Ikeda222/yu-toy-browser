#include "Parse/parseHTML.h"
#include "WIndow/Window.h"


int main(int argc, char *argv[]) {

    const char *htmlFileName = "/Users/ikedayu/yu_browser/yu_browser/examples/example.html";
    ElementNode *rootNode = parseHtml(htmlFileName);
//    //[](){}　この中でroot_node->Render();
    Window *window = new Window(rootNode);

    window->start();
    return 0;
}

