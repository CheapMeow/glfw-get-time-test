## glfw-get-time-test

`glfw-in-dll` folder contains project that uses `glfwGetTime` in dll. 

glfw-in-dll\src\runtime\time_utils.h

```cpp
#pragma once

#include "macro.h"

#include <GLFW/glfw3.h>

class LIBRARY_API Time
{
public:
    static float GetTime() { return glfwGetTime(); }
};
```

`glfw-in-lib` folder contains project that uses `glfwGetTime` in lib.

glfw-in-lib\src\runtime\time_utils.h

```cpp
#pragma once

#include <GLFW/glfw3.h>

class Time
{
public:
    static float GetTime() { return glfwGetTime(); }
};
```

Both projects print `glfwGetTime()` in library.

```cpp
void Runtime::PrintTime() { std::cout << "Runtime: " << Time::GetTime() << "s" << std::endl; }
```

Both projects print `glfwGetTime()` in executable.

```cpp
int main()
{
    if (glfwInit())
        std::cout << "Editor: GLFW init success." << std::endl;
    else
        std::cout << "Editor: GLFW init fail." << std::endl;

    Runtime runtime;

    std::size_t output_count     = 0;
    std::size_t max_output_count = 100;
    while (1)
    {
        randomSleep(50.0, 100.0);
        std::cout << "Editor: " << Time::GetTime() << "s" << std::endl;
        runtime.PrintTime();

        output_count++;
        if (output_count >= max_output_count)
            break;
    }

    return 0;
}
```

`glfw-in-dll` output

```
Editor: Waited for 87.1732 ms.
Editor: 0.723095s
Runtime: 0s
Editor: Waited for 69.2278 ms.
Editor: 0.800194s
Runtime: 0s
Editor: Waited for 99.8627 ms.
Editor: 0.908878s
Runtime: 0s
Editor: Waited for 70.4661 ms.
Editor: 0.985678s
Runtime: 0s
Editor: Waited for 83.087 ms.
Editor: 1.07766s
Runtime: 0s
```

`glfw-in-lib` output

```
Editor: Waited for 74.9078 ms.
Editor: 0.833975s
Runtime: 0.834277s
Editor: Waited for 75.4188 ms.
Editor: 0.910967s
Runtime: 0.911241s
Editor: Waited for 75.6444 ms.
Editor: 0.990564s
Runtime: 0.990761s
Editor: Waited for 82.5768 ms.
Editor: 1.08412s
Runtime: 1.08442s
Editor: Waited for 80.6122 ms.
Editor: 1.17785s
Runtime: 1.17831s
```