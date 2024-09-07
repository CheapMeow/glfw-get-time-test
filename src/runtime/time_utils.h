#pragma once

#include "macro.h"

#include <GLFW/glfw3.h>

class LIBRARY_API Time
{
public:
    static float GetTime() { return glfwGetTime(); }
};