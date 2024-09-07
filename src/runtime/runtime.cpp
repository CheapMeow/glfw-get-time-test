#include "runtime.h"
#include "time_utils.h"

#include <iostream>

void Runtime::PrintTime() { std::cout << "Runtime: " << Time::GetTime() << "s" << std::endl; }