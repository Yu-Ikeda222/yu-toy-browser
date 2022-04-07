#ifndef shader_hpp
#define shader_hpp

#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
char* file_read(const char* filename);
void print_log(GLuint object);
GLuint create_shader(const char* filename, GLenum type);
GLuint create_program(const char* vertexfile, const char *fragmentfile);
GLint get_attrib(GLuint program, const char *name);
GLint get_uniform(GLuint program, const char *name);

#endif /* shader_hpp */
