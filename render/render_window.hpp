#ifndef render_window_hpp
#define render_window_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <locale>
#include <codecvt>
#include <math.h>

#include <GL/glew.h>
#include <GL/freeglut.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "shader.hpp"
#include "ElementNode.hpp"
#include "TextSizeFactory.hpp"

#define WINDOW_POSITION_X 100
#define WINDOW_POSITION_Y 100
#define WIDTH 1024
#define HEIGHT 1024

extern GLuint program;
extern GLint attribute_coord;
extern GLint uniform_tex;
extern GLint uniform_color;

struct point {
    GLfloat x;
    GLfloat y;
    GLfloat s;
    GLfloat t;
};

extern GLuint vbo;

extern FT_Library ft;
extern FT_Face face;

extern void render_window_opneGL(ElementNode* root_node);
extern void Init();
extern int init_resources();
extern void Display();
extern void Square2D(int x1,int y1,int x2, int y2,float size);
extern void set_default_char_data();
extern void render();
extern void render_text(const char *text, char* tag_name, float x, float y, float sx, float sy);
extern char* set_window_title(ElementNode* root_node);
extern void free();


#endif /* render_window_hpp */
