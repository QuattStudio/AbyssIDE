#include <stdio.h>
#include <stdlib.h>




#include "core/window/abys_window.h"
#include "core/abys_utils.h"
#include "core/window/abys_event.h"


#include "core/internals/abys_i.h"
#include "core/internals/abys__window.h"



#define NANOVG_GL3_IMPLEMENTATION
#include "nanovg_gl.h"



/* Internals */








/* functions */

int abys_Start(abys_Uint32 flags)
{
    abys_Bool result = glfwInit();

    if (result != ABYS_TRUE)
    {
        ABYS_LOG_ERROR("GLFW-Init Failed!");
        return ABYS_FALSE;
    }

    // reset error system
    abys_ResetError();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    ABYS_LOG_INFO("GL version used: GL %s core profile", ABYS_GL_VERSION_STRING);


    ABYS_LOG_INFO("Abys-Started!");
}






abys_Window* abys_OpenWindow(int width, int height, const char* title, abys_Uint32 flags)
{
    abys__InitWindowFlags(flags);
    GLFWwindow* window_handle = glfwCreateWindow(width, height, title, NULL, NULL);

    if (!window_handle)
    {
        abys_SetError("GLFW-Window Creation Failed!");
        goto ABYS_WINDOW_CREATION_FAILED;
    }
    

    glfwMakeContextCurrent(window_handle);


    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        abys_SetError("Failed to initialize GLAD");
        goto ABYS_WINDOW_CREATION_FAILED;        
    }



    NVGcontext* nvg_ctx = nvgCreateGL3(NVG_ANTIALIAS);
    
    if (!nvg_ctx)
    {
        abys_SetError("Failed to create nvg context!");
        goto ABYS_WINDOW_CREATION_FAILED;
    }


    abys_Window* window = (abys_Window*)malloc(sizeof(abys_Window));

    if (!window)
    {
        abys_SetError("Memory allocation failed!");
        goto ABYS_WINDOW_CREATION_FAILED;
    }


    window->handle = window_handle;
    window->canvas = nvg_ctx;

    window->color.r = 0.0f;
    window->color.g = 0.0f;
    window->color.b = 0.0f;

    window->eventSystem = abys__InitEventSystem();

    glfwSetWindowUserPointer(window_handle, window);
    abys__SetWindowEventCallBacks(window_handle);


    ABYS_LOG_INFO("Window Creation Completed!");
    return window;

    
ABYS_WINDOW_CREATION_FAILED:
    ABYS_LOG_ERROR("Window Creation Failed! Reason: %s", abys_GetError());
    return NULL;
}



void abys_CloseWindow(abys_Window* window)
{
    ABYS__CHECK_WINDOW(window, "No Window found to close!", ABYS__RET_NOTHING);
 

    glfwDestroyWindow(window->handle);
    nvgDeleteGL3(window->canvas);

    free(window->eventSystem);
    free(window);

    abys_ResetError();

    glfwTerminate();

    ABYS_LOG_INFO("Window Successfully closed!");
}



int abys_RunWindow(abys_Window* window)
{
    ABYS__CHECK_WINDOW(window, "No Window found to close!", ABYS_FALSE);


    glfwPollEvents();

    abys_UpdateInput(window);


    return (ABYS_NOT glfwWindowShouldClose(window->handle));
}


int abys_StopWindow(abys_Window* window)
{
    ABYS__CHECK_WINDOW(window, "No Window found to close!", ABYS_FALSE);


    glfwSetWindowShouldClose(window->handle, ABYS_TRUE);
}






GLFWwindow* abys__GetWindowHandle(abys_Window* window)
{
    ABYS__CHECK_WINDOW(window, "No Window found to close!", NULL);


    return window->handle;
}
