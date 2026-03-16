#include "core/window/abys_event.h"

#include "core/internals/abys_i.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define ABYS__MAX_EVENTS     256



typedef struct abys__EventSystem
{
    abys_Event eventQueue[ABYS__MAX_EVENTS];
    int eventCount;

    // ====== INPUT STATES ===== //

    abys_Bool keyDown[ABYS_KEY_LAST + 1];
    abys_Bool keyPressed[ABYS_KEY_LAST + 1];
    abys_Bool keyReleased[ABYS_KEY_LAST + 1];

    abys_Bool mouseDown[ABYS_MOUSE_BUTTON_LAST + 1];
    abys_Bool mousePressed[ABYS_MOUSE_BUTTON_LAST + 1];
    abys_Bool mouseReleased[ABYS_MOUSE_BUTTON_LAST + 1];

    double mouseX;
    double mouseY;
    double mouseWheel;

    // abys_Bool quit;
} abys__EventSystem;







abys__EventSystem* abys__InitEventSystem(void)
{
    
    abys__EventSystem* sys = (abys__EventSystem*)malloc(sizeof(abys__EventSystem));
    if (!sys) {
        ABYS_LOG_ERROR("Event System mem alloc failed!");
    }

    ABYS__INIT_WITH_ZERO(sys->eventQueue);
    ABYS__INIT_WITH_ZERO(sys->keyDown);
    ABYS__INIT_WITH_ZERO(sys->keyPressed);
    ABYS__INIT_WITH_ZERO(sys->keyReleased);

    ABYS__INIT_WITH_ZERO(sys->mouseDown);
    ABYS__INIT_WITH_ZERO(sys->mousePressed);
    ABYS__INIT_WITH_ZERO(sys->mouseReleased);
    
    sys->mouseWheel = 0.0f;
    sys->mouseX = 0.0f;
    sys->mouseY = 0.0f;

    sys->eventCount = 0;




    return sys;
}







void abys_PushEvent(abys_Window* window, abys_Event event)
{
    abys__EventSystem *eventSys = window->eventSystem;

    if (eventSys->eventCount >= ABYS__MAX_EVENTS) return;
    
    eventSys->eventQueue[eventSys->eventCount++] = event;
}






// Call once per frame (after glfwPollEvents())
void abys_UpdateInput(abys_Window* window)
{
    ABYS__CHECK_WINDOW(window, ABYS__EXCEPT_WINDOW_NOT_FOUND, ABYS__RET_NOTHING);


    abys__EventSystem *eventSys = window->eventSystem;

    // Reset "this frame only" flags
    ABYS__INIT_WITH_ZERO(eventSys->keyPressed);
    ABYS__INIT_WITH_ZERO(eventSys->keyReleased);
    ABYS__INIT_WITH_ZERO(eventSys->mousePressed);
    ABYS__INIT_WITH_ZERO(eventSys->mouseReleased);
    eventSys->mouseWheel = 0.0;
}













// NEW: User calls this for every event they poll
void abys_ProcessEvent(abys_Window* window, const abys_Event* event)
{
    ABYS__CHECK_WINDOW(window, ABYS__EXCEPT_WINDOW_NOT_FOUND, ABYS__RET_NOTHING);


    if (!event) return;

    abys__EventSystem* eventSys = window->eventSystem;
    switch (event->type)
    {       
        case ABYS_EVENT_KEY_DOWN:
            if (!eventSys->keyDown[event->key.key]) {
                eventSys->keyPressed[event->key.key] = ABYS_TRUE;
            }
            eventSys->keyDown[event->key.key] = ABYS_TRUE;
            break;

        case ABYS_EVENT_KEY_UP:
            if (eventSys->keyDown[event->key.key]) {
                eventSys->keyReleased[event->key.key] = ABYS_TRUE;
            }
            eventSys->keyDown[event->key.key] = ABYS_FALSE;
            break;

        case ABYS_EVENT_MOUSE_BUTTON_DOWN:
            if (!eventSys->mouseDown[event->mouseButton.button]) {
                eventSys->mousePressed[event->mouseButton.button] = ABYS_TRUE;
            }
            eventSys->mouseDown[event->mouseButton.button] = ABYS_TRUE;
            break;

        case ABYS_EVENT_MOUSE_BUTTON_UP:
            if (eventSys->mouseDown[event->mouseButton.button]) {
                eventSys->mouseReleased[event->mouseButton.button] = ABYS_TRUE;
            }
            eventSys->mouseDown[event->mouseButton.button] = ABYS_FALSE;
            break;

        case ABYS_EVENT_MOUSE_MOVE:
            eventSys->mouseX = event->mouseMove.x;
            eventSys->mouseY = event->mouseMove.y;
            break;

        case ABYS_EVENT_MOUSE_SCROLL:
            eventSys->mouseWheel += event->scroll.offset;
            break;

        default:
            break;
    }
}


























// ====================== PUBLIC GETTERS (unchanged) ======================
abys_Bool abys_IsKeyDown(abys_Window* window, abys_Key key)
{
    ABYS__CHECK_WINDOW(window, ABYS__EXCEPT_WINDOW_NOT_FOUND, 0);

    if (key < 0 || key > ABYS_KEY_LAST) return ABYS_FALSE;
    return window->eventSystem->keyDown[key];
}


abys_Bool abys_IsKeyPressed(abys_Window* window, abys_Key key)
{
    ABYS__CHECK_WINDOW(window, ABYS__EXCEPT_WINDOW_NOT_FOUND, 0);


    if (key < 0 || key > ABYS_KEY_LAST) return ABYS_FALSE;
    return window->eventSystem->keyPressed[key];
}


abys_Bool abys_IsKeyReleased(abys_Window* window, abys_Key key)
{
    ABYS__CHECK_WINDOW(window, ABYS__EXCEPT_WINDOW_NOT_FOUND, 0);

    if (key < 0 || key > ABYS_KEY_LAST) return ABYS_FALSE;
    return window->eventSystem->keyReleased[key];
}



abys_Bool abys_IsMouseButtonDown(abys_Window* window, abys_MouseButton button)
{
    ABYS__CHECK_WINDOW(window, ABYS__EXCEPT_WINDOW_NOT_FOUND, 0);

    if (button < 0 || button > ABYS_MOUSE_BUTTON_LAST) return ABYS_FALSE;
    return window->eventSystem->mouseDown[button];
}

abys_Bool abys_IsMouseButtonPressed(abys_Window* window, abys_MouseButton button)
{
    ABYS__CHECK_WINDOW(window, ABYS__EXCEPT_WINDOW_NOT_FOUND, 0);

    if (button < 0 || button > ABYS_MOUSE_BUTTON_LAST) return ABYS_FALSE;
    return window->eventSystem->mousePressed[button];
}

abys_Bool abys_IsMouseButtonReleased(abys_Window* window, abys_MouseButton button)
{
    ABYS__CHECK_WINDOW(window, ABYS__EXCEPT_WINDOW_NOT_FOUND, 0);

    if (button < 0 || button > ABYS_MOUSE_BUTTON_LAST) return ABYS_FALSE;
    return window->eventSystem->mouseReleased[button];
}

double abys_GetMouseX(abys_Window* window) { 
    ABYS__CHECK_WINDOW(window, ABYS__EXCEPT_WINDOW_NOT_FOUND, 0.0f);
    
    return window->eventSystem->mouseX; 
}

double abys_GetMouseY(abys_Window* window) {
    ABYS__CHECK_WINDOW(window, ABYS__EXCEPT_WINDOW_NOT_FOUND, 0.0f);

    return window->eventSystem->mouseY; 
}

double abys_GetMouseWheel(abys_Window* window) {
    ABYS__CHECK_WINDOW(window, ABYS__EXCEPT_WINDOW_NOT_FOUND, 0.0f);

    return window->eventSystem->mouseWheel; 
}





int abys_PollEvent(abys_Window* window, abys_Event* out)
{
    if (!window || !window->eventSystem) return 0;

    abys__EventSystem* eventSys = window->eventSystem;
    if (eventSys->eventCount == 0) return 0;

    *out = eventSys->eventQueue[0];

    for (int i = 1; i < eventSys->eventCount; i++)
        eventSys->eventQueue[i - 1] = eventSys->eventQueue[i];
    
    abys_ProcessEvent(window, out);

    eventSys->eventCount--;
    return 1;
}








static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    abys_Event event;

    abys_Window* abys__WindowHandle = (abys_Window*)glfwGetWindowUserPointer(window);
    
    if (action == GLFW_PRESS) {
        event.type = ABYS_EVENT_KEY_DOWN;
        event.key.key = key;
        abys_PushEvent(abys__WindowHandle, event);
    }


    else if (action == GLFW_RELEASE) {
        event.type = ABYS_EVENT_KEY_UP;
        event.key.key = key;
        abys_PushEvent(abys__WindowHandle, event);
    }
}



static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    abys_Event event;

    abys_Window* abys__WindowHandle = (abys_Window*)glfwGetWindowUserPointer(window);


    if (action == GLFW_PRESS) {
        event.type = ABYS_EVENT_MOUSE_BUTTON_DOWN;
        event.mouseButton.button = button;
        abys_PushEvent(abys__WindowHandle, event);
    }


    else if (action == GLFW_RELEASE) {
        event.type = ABYS_EVENT_MOUSE_BUTTON_UP;
        event.mouseButton.button = button;
        abys_PushEvent(abys__WindowHandle, event);
    }
}




static void cursor_callback(GLFWwindow* window, double xpos, double ypos)
{
    abys_Event event;

    abys_Window* abys__WindowHandle = (abys_Window*)glfwGetWindowUserPointer(window);

    event.type = ABYS_EVENT_MOUSE_MOVE;
    event.mouseMove.x = xpos;
    event.mouseMove.y = ypos;
    abys_PushEvent(abys__WindowHandle, event);
}



static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    abys_Event event;

    abys_Window* abys__WindowHandle = (abys_Window*)glfwGetWindowUserPointer(window);

    event.type = ABYS_EVENT_MOUSE_SCROLL;
    event.scroll.offset = yoffset;        // positive = scroll up / away from you
    abys_PushEvent(abys__WindowHandle, event);
}





// static void window_resize_callback(GLFWwindow* window, int width, int height)
// {
//     // SA_CHECK_WINDOW_I(SA_WindowInst_I, SA_MSG_WINDOW_NOT_FOUND_I, SA_RET_TYPE_NONE_I);

//     // SA_WindowInst_I->width = width;
//     // SA_WindowInst_I->height = height;
    
    
//     // if using OpenGL, update viewport too
//     glViewport(0, 0, width, height);
// }




void abys__SetWindowEventCallBacks(GLFWwindow* window)
{
    glfwSetKeyCallback(window,          key_callback);
    glfwSetCursorPosCallback(window,    cursor_callback);
    glfwSetMouseButtonCallback(window,  mouse_button_callback);
    glfwSetScrollCallback(window,       scroll_callback);
    // glfwSetWindowSizeCallback(window,   window_resize_callback);
}















