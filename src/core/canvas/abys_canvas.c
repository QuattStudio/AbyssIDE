#include "core/canvas/abys_canvas.h"


#include "core/internals/abys_i.h"





/* Internals */



static inline void abys__ClearBackground(float r, float g, float b)
{
    glClearColor(r, g, b, ABYS_MAX_OPACITY_FLOAT);
    glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}




/* functions */



void abys_BeginFrame(abys_Window* window)
{
    ABYS__CHECK_WINDOW(window, "No Window found!", ABYS__RET_NOTHING);

    abys__ClearBackground(window->color.r, window->color.g, window->color.b);
    int WindowWidth, WindowHeight;
    glfwGetFramebufferSize(window->handle, &WindowWidth, &WindowHeight);

    glViewport(0, 0, WindowWidth, WindowHeight);

    nvgBeginFrame(window->canvas, WindowWidth, WindowHeight, 1.0f);

}




void abys_EndFrame(abys_Window* window)
{
    ABYS__CHECK_WINDOW(window, "No Window found!", ABYS__RET_NOTHING);
    
    nvgEndFrame(window->canvas);
    glfwSwapBuffers(window->handle);

    abys_Delay(16);
}





void abys_SetBackgroundColor(abys_Window* window, int r, int g, int b)
{
    ABYS__CHECK_WINDOW(window, "No Window found!", ABYS__RET_NOTHING);

    NVGcolor color = nvgRGB(r, g, b);

    window->color.r = color.r;
    window->color.g = color.g;
    window->color.b = color.b;
}







void abys_DrawRectangle(abys_Window* window, abys_Rect* rect, abys_Color color)
{
    ABYS__CHECK_WINDOW(window, "No Window found!", ABYS__RET_NOTHING);

    nvgBeginPath(window->canvas);
    nvgRect(window->canvas, rect->x, rect->y, rect->width, rect->height);

    nvgFillColor(window->canvas, nvgRGBA(color.r, color.g, color.b, color.a));
    nvgFill(window->canvas);
}