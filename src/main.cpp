#include <glad/glad.h>
#include <GLFW/glfw3.h>
#pragma comment (lib, "opengl32.lib")

#include <iostream>

int windowSizeWidth = 860;
int windowSizeHeight = 640;

/* Called whenever the window is resized. */
void glfwWindowSizeCallback(GLFWwindow* pWindow, int width, int height)
{
    windowSizeWidth = width;
    windowSizeHeight = height;
    glViewport(0, 0, windowSizeWidth / 2, windowSizeHeight);
}

/* Close the window when press a escape */
void glfwKeyCallback(GLFWwindow* pWindow, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(pWindow, GL_TRUE);
    }
}


int main(void)
{
    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout << "Function glfwInit failed!" << std::endl;
        return -1;
    }

    /* Set base settings*/
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* pWindow = glfwCreateWindow(windowSizeWidth, windowSizeHeight, "Battle City", nullptr, nullptr);
    if (!pWindow)
    {
        std::cout << "Function glfwCreateWindow failed!" << std::endl;
        glfwTerminate();
        return -1;
    }

    /* Set window size callback */
    glfwSetWindowSizeCallback(pWindow, glfwWindowSizeCallback);

    /* TODO: descrip func */
    glfwSetKeyCallback(pWindow, glfwKeyCallback);

    /* Make the window's context current */
    glfwMakeContextCurrent(pWindow);

    /* Initialize GLAD */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pWindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(pWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
