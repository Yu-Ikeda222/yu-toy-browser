#include "shader.h"

/**
 * Store all the file's contents in memory, useful to pass shaders
 * source code to OpenGL
 */
char *fileRead(const char *filename) {
    FILE *in = fopen(filename, "rb");
    if (in == NULL) return NULL;

    int res_size = BUFSIZ;
    char *res = (char *) malloc(res_size);
    int nb_read_total = 0;

    while (!feof(in) && !ferror(in)) {
        if (nb_read_total + BUFSIZ > res_size) {
            if (res_size > 10 * 1024 * 1024) break;
            res_size = res_size * 2;
            res = (char *) realloc(res, res_size);
        }
        char *p_res = res + nb_read_total;
        nb_read_total += fread(p_res, 1, BUFSIZ, in);
    }

    fclose(in);
    res = (char *) realloc(res, nb_read_total + 1);
    res[nb_read_total] = '\0';
    return res;
}

/**
 * Display compilation errors from the OpenGL shader compiler
 */
void printLog(GLuint object) {
    GLint log_length = 0;
    if (glIsShader(object))
        glGetShaderiv(object, GL_INFO_LOG_LENGTH, &log_length);
    else if (glIsProgram(object))
        glGetProgramiv(object, GL_INFO_LOG_LENGTH, &log_length);
    else {
        fprintf(stderr, "printlog: Not a shader or a program\n");
        return;
    }

    char *log = (char *) malloc(log_length);

    if (glIsShader(object))
        glGetShaderInfoLog(object, log_length, NULL, log);
    else if (glIsProgram(object))
        glGetProgramInfoLog(object, log_length, NULL, log);

    fprintf(stderr, "%s", log);
    free(log);
}

/**
 * Compile the shader from file 'filename', with error handling
 */
GLuint createShader(const char *filename, GLenum type) {
    const GLchar *source = fileRead(filename);
    if (source == NULL) {
        fprintf(stderr, "Error opening %s: ", filename);
        perror("");
        return 0;
    }
    GLuint res = glCreateShader(type);
    const GLchar *sources[] = {
            // Define GLSL version
#ifdef GL_ES_VERSION_2_0
            "#version 100\n"  // OpenGL ES 2.0
#else
            "#version 120\n"  // OpenGL 2.1
#endif
            ,
            // GLES2 precision specifiers
#ifdef GL_ES_VERSION_2_0
            // Define default float precision for fragment shaders:
            (type == GL_FRAGMENT_SHADER) ?
            "#ifdef GL_FRAGMENT_PRECISION_HIGH\n"
            "precision highp float;           \n"
            "#else                            \n"
            "precision mediump float;         \n"
            "#endif                           \n"
            : ""
            // Note: OpenGL ES automatically defines this:
            // #define GL_ES
#else
            // Ignore GLES 2 precision specifiers:
            "#define lowp   \n"
            "#define mediump\n"
            "#define highp  \n"
#endif
            ,
            source};
    glShaderSource(res, 3, sources, NULL);
    free((void *) source);

    glCompileShader(res);
    GLint compile_ok = GL_FALSE;
    glGetShaderiv(res, GL_COMPILE_STATUS, &compile_ok);
    if (compile_ok == GL_FALSE) {
        fprintf(stderr, "%s:", filename);
        printLog(res);
        glDeleteShader(res);
        return 0;
    }

    return res;
}

GLuint createProgram(const char *vertexfile, const char *fragmentfile) {
    GLuint program = glCreateProgram();
    GLuint shader;

    if (vertexfile) {
        shader = createShader(vertexfile, GL_VERTEX_SHADER);
        if (!shader)
            return 0;
        glAttachShader(program, shader);
    }

    if (fragmentfile) {
        shader = createShader(fragmentfile, GL_FRAGMENT_SHADER);
        if (!shader)
            return 0;
        glAttachShader(program, shader);
    }

    glLinkProgram(program);
    GLint link_ok = GL_FALSE;
    glGetProgramiv(program, GL_LINK_STATUS, &link_ok);
    if (!link_ok) {
        fprintf(stderr, "glLinkProgram:");
        printLog(program);
        glDeleteProgram(program);
        return 0;
    }

    return program;
}

GLint getAttrib(GLuint program, const char *name) {
    GLint attribute = glGetAttribLocation(program, name);
    if (attribute == -1)
        fprintf(stderr, "Could not bind attribute %s\n", name);
    return attribute;
}

GLint getUniform(GLuint program, const char *name) {
    GLint uniform = glGetUniformLocation(program, name);
    if (uniform == -1)
        fprintf(stderr, "Could not bind uniform %s\n", name);
    return uniform;
}
