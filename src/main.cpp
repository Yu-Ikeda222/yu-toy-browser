#include "Parse/parseHTML.h"
#include "Window/Window.h"


int main(int argc, char *argv[]) {

    const char *htmlFileName = "../examples/example.html";
    ElementNode *rootNode = parseHtml(htmlFileName);
    Window *window = new Window(rootNode);

    window->start();
    return 0;
}

