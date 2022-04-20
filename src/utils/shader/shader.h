#ifndef shader_h
#define shader_h

#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>

char *fileRead(const char *filename);

void printLog(GLuint object);

GLuint createShader(const char *filename, GLenum type);

GLuint createProgram(const char *vertexfile, const char *fragmentfile);

GLint getAttrib(GLuint program, const char *name);

GLint getUniform(GLuint program, const char *name);

#endif /* shader_h */
