#pragma once

#include <GLFW/glfw3.h>
#include <iostream>

class Runtime
{
public:
    Runtime()
    {
        if (glfwInit())
            std::cout << "Runtime: GLFW init success." << std::endl;
        else
            std::cout << "Runtime: GLFW init fail." << std::endl;
    }

    void PrintTime();
};