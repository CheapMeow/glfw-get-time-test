#include "runtime/runtime.h"
#include "runtime/time_utils.h"

#include <chrono>
#include <iostream>
#include <random>
#include <thread>

#include <GLFW/glfw3.h>

void randomSleep(float min_ms, float max_ms)
{
    std::random_device                    rd;
    std::mt19937                          gen(rd());
    std::uniform_real_distribution<float> dis(min_ms, max_ms);
    float                                 dt = dis(gen);

    auto durationInSeconds = static_cast<int64_t>(dt);
    auto duration          = std::chrono::milliseconds(durationInSeconds);
    std::this_thread::sleep_for(duration);

    std::cout << "Editor: Waited for " << dt << " ms." << std::endl;
}

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