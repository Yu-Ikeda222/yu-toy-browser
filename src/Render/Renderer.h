#ifndef YU_TOY_BROWSER_RENDERER_H
#define YU_TOY_BROWSER_RENDERER_H

#include "../WIndow/Window.h"

class Renderer {
public:
    Renderer();

    ~Renderer();

    void render(Window *window, Node *node);

    void renderText(Window *window, const char *text, const char *tagName, float x, float y, float sx, float sy);

    void renderImage();

    std::string trim(const std::string &string, const char *trimCharacterList = " \t\v\r\n");
};


#endif //YU_TOY_BROWSER_RENDERER_H
