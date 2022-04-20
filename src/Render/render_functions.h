#ifndef YU_TOY_BROWSER_RENDER_FUNCTIONS_H
#define YU_TOY_BROWSER_RENDER_FUNCTIONS_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <locale>
#include <codecvt>
#include <math.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <ft2build.h>
#include FT_FREETYPE_H
#include "freetype/freetype.h"

#include "../utils/shader/shader.h"
#include "../Node/ElementNode.h"
#include "../Factory/TextSizeFactory/TextSizeFactory.h"

#define WINDOW_POSITION_X 100
#define WINDOW_POSITION_Y 100
#define WIDTH 1024
#define HEIGHT 1024

extern GLuint program;
extern GLint attributeCoord;
extern GLint uniformTex;
extern GLint uniformColor;

struct Point {
    GLfloat x;
    GLfloat y;
    GLfloat s;
    GLfloat t;
};

extern GLuint vbo;

extern FT_Library ft;
extern FT_Face face;

extern void windowLoop(ElementNode *rootNode);

extern int initResources();

extern void display(ElementNode *rootNode);

extern void square2D(int x1, int y1, int x2, int y2, float size);

extern void setDefaultCharData();

extern void render(ElementNode *rootNode);

extern void renderText(const char *text, const char *tagName, float x, float y, float sx, float sy);

extern char *setWindowTitle(ElementNode *rootNode);


#endif /* YU_TOY_BROWSER_RENDER_FUNCTIONS_h */
