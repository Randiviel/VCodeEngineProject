#pragma once

struct GLFWwindow;

namespace StratEngine {

    class WinWindow{
    public:
        WinWindow();
        ~WinWindow();
        void Run();
        private:

        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
        GLFWwindow* m_Window;
    };
}