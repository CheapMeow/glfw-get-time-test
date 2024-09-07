#pragma once

#include "macro.h"

#include <GLFW/glfw3.h>

class LIBRARY_API Runtime
{
public:
    Runtime() { glfwInit(); }

    void PrintTime();
};