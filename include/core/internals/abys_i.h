#pragma once



#include "abys_inc.h"
#include "core/abys_types.h"
#include "core/window/abys_event.h"


struct abys_Window {
    GLFWwindow* handle;
    NVGcontext* canvas;
    abys__EventSystem* eventSystem;

    struct {
        float r;
        float g;
        float b;
    } color;
};