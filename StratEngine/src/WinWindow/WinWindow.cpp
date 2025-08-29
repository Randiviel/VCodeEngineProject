#include "WinWindow.h"
#include "glad/glad.h"
#include "glfw3.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>


namespace StratEngine {

    WinWindow::WinWindow() {
        if (!glfwInit()){
            exit(EXIT_FAILURE);
        }
        
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

        m_Window = glfwCreateWindow(800, 600, "StratEngine Window", nullptr, nullptr);
        glfwSetKeyCallback(m_Window, key_callback);
        glfwMakeContextCurrent(m_Window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
        }

    }

    WinWindow::~WinWindow() {
        glfwDestroyWindow(m_Window);
    }

    void WinWindow::Run()
    {
        while (!glfwWindowShouldClose(m_Window)){
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap front and back buffers
        glfwSwapBuffers(m_Window);
        glfwPollEvents();
    }
    }

    void WinWindow::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
    {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }

    }
}