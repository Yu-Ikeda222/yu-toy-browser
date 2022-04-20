#ifndef YU_TOY_BROWSER_WINDOW_H
#define YU_TOY_BROWSER_WINDOW_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <codecvt>
#include <math.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <ft2build.h>
#include FT_FREETYPE_H
#include "freetype/freetype.h"

#include "../utils/shader/shader.h"
#include "../Node/ElementNode.h"
#include "../Factory/TextSizeFactory/TextSizeFactory.h"
#include "render_functions.h"

#define WIDTH 1024
#define HEIGHT 1024

class Window {
public:
    Window(ElementNode *rootNode);

    ~Window();

    void start();

    void init();

    void windowLoop();

    void createWindow();

    void setWindowTitle();

    void display();

    ElementNode *getRootNode();

    void prepareShader();

    void prepareFont();

    GLuint program;
    GLint attributeCoord;
    GLint uniformTex;
    GLint uniformColor;
    struct Point {
        GLfloat x;
        GLfloat y;
        GLfloat s;
        GLfloat t;
    };

    GLuint vbo;

    FT_Library ft;
    FT_Face face;

private:
    char *_windowTitle;
    GLFWwindow *_window;
    ElementNode *_rootNode;
};


#endif //YU_TOY_BROWSER_WINDOW_H