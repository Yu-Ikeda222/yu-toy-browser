#ifndef YU_TOY_BROWSER_RENDERER_H
#define YU_TOY_BROWSER_RENDERER_H

#include "Window.h"

class Renderer {
public:
    void renderText(Window *window, const char *text, const char *tagName, float x, float y, float sx, float sy);

    void renderImage();
};


#endif //YU_TOY_BROWSER_RENDERER_H
