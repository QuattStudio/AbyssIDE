#include "abys_inc.h"



#define WINDOW_WIDTH  800
#define WINDOW_HEGITH   600



int main(void) {
    abys_Start(0);

    glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);


    abys_Window* window = abys_OpenWindow(WINDOW_WIDTH, WINDOW_HEGITH, "Abyss-IDE", 0);


    NVGcontext* vg = nvgCreateGL3(NVG_ANTIALIAS);

    while (abys_RunWindow(window)) {

        abys_ClearBackground(0.35, 0.35, 0.35);

        abys_BeginFrame(window);


        abys_EndFrame(window);
    }

    abys_CloseWindow(window);
}