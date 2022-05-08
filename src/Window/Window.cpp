#include "Window.h"

Window::Window(ElementNode *rootNode) {
    _rootNode = rootNode;
    setWindowTitle();
}

Window::~Window() {

}

void Window::start() {
    init();
    windowLoop();
}

void Window::init() {
    createWindow();
    // 作成したウィンドウを OpenGL の処理
    glfwMakeContextCurrent(_window);
    prepareFont();
    GLenum glewStatus = glewInit();
    if (GLEW_OK != glewStatus) {
        fprintf(stderr, "Error: %s\n", glewGetErrorString(glewStatus));
        return;
    }
    prepareShader();
}

void Window::windowLoop() {
    while (glfwWindowShouldClose(_window) == GL_FALSE) {
        glClear(GL_COLOR_BUFFER_BIT);
        //
        // ここで描画処理を行う
        display();
        //
        // カラーバッファを入れ替える
        glfwSwapBuffers(_window);
        // イベントを取り出す
        glfwWaitEvents();
    }
}

void Window::createWindow() {
    if (glfwInit() == GL_FALSE) {
        std::cerr << "Can't initialize GLFW" << std::endl;
        return;
    }
    _window = glfwCreateWindow(WIDTH, HEIGHT, _windowTitle, NULL, NULL);
    if (_window == NULL) {
        std::cerr << "Can't create GLFW window." << std::endl;
        glfwTerminate();
        return;
    }
}

void Window::display() {
    glUseProgram(_program);
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
//     Enable blending, necessary for our alpha texture
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//    ここもconstants的な感じで別にファイルに切り出したほうがいいのかな
    GLfloat black[4] = {0, 0, 0, 1};
    GLfloat red[4] = {1, 0, 0, 1};
    GLfloat transparentGreen[4] = {0, 1, 0, 0.5};
    glUniform4fv(_uniformColor, 1, black);
    Renderer *renderer = createRenderer();
    renderer->render(this, _rootNode);
    glFlush();
}

void Window::setWindowTitle() {
    ElementNode *node = _rootNode;
    std::vector<Node *> children = node->getChildren();
    for (int i = 0; i < node->getChildrenSize(); ++i) {
        if (strcmp((char *) (children[i]->getNode()->name), "head") == 0) {
            std::vector<Node *> grandChildren = children[i]->getChildren();
            for (int j = 0; j < children[i]->getChildrenSize(); ++j) {
                if (strcmp((char *) (grandChildren[j]->getNode()->name), "title") == 0) {
                    _windowTitle = (char *) (grandChildren[j]->getChildren()[0]->getNode()->content);
                    break;
                }
            }
        }
    }
}


ElementNode *Window::getRootNode() {
    return _rootNode;
}

void Window::prepareShader() {
    _program = createProgram("../src/utils/shader/text.v.glsl",
                             "../src/utils/shader/text.f.glsl");
    if (_program == 0)
        return;
    _attributeCoord = getAttrib(_program, "coord");
    _uniformTex = getUniform(_program, "tex");
    _uniformColor = getUniform(_program, "color");
    if (_attributeCoord == -1 || _uniformTex == -1 || _uniformColor == -1)
        return;
    // Create the vertex buffer object
    glGenBuffers(1, &_vbo);
}

//ここ外に出した方がいい
void Window::prepareFont() {
    if (FT_Init_FreeType(&_ft)) {
        fprintf(stderr, "Could not init freetype library\n");
        return;
    }
    if (FT_New_Face(_ft, "../fonts/851MkPOP_100.ttf", 0, &_face)) {
        return;
    }
}

Renderer *Window::createRenderer() {
    return new Renderer();
}
