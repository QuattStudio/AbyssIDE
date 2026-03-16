#pragma once



#include "abys_inc.h"

#include "core/abys_types.h"
#include "core/abys_utils.h"





typedef struct abys_Window abys_Window;
typedef struct abys__EventSystem abys__EventSystem;





// int abys_IsKeyPressed(abys_Window* window, int key);

















// #define ABYS_KEY_A GLFW_KEY_A
// #define ABYS_KEY_B GLFW_KEY_B
// #define ABYS_KEY_C GLFW_KEY_C
// #define ABYS_KEY_D GLFW_KEY_D
// #define ABYS_KEY_E GLFW_KEY_E
// #define ABYS_KEY_F GLFW_KEY_F
// #define ABYS_KEY_G GLFW_KEY_G
// #define ABYS_KEY_H GLFW_KEY_H
// #define ABYS_KEY_I GLFW_KEY_I
// #define ABYS_KEY_J GLFW_KEY_J
// #define ABYS_KEY_K GLFW_KEY_K
// #define ABYS_KEY_L GLFW_KEY_L
// #define ABYS_KEY_M GLFW_KEY_M
// #define ABYS_KEY_N GLFW_KEY_N
// #define ABYS_KEY_O GLFW_KEY_O
// #define ABYS_KEY_P GLFW_KEY_P
// #define ABYS_KEY_Q GLFW_KEY_Q
// #define ABYS_KEY_R GLFW_KEY_R
// #define ABYS_KEY_S GLFW_KEY_S
// #define ABYS_KEY_T GLFW_KEY_T
// #define ABYS_KEY_U GLFW_KEY_U
// #define ABYS_KEY_V GLFW_KEY_V
// #define ABYS_KEY_W GLFW_KEY_W
// #define ABYS_KEY_X GLFW_KEY_X
// #define ABYS_KEY_Y GLFW_KEY_Y
// #define ABYS_KEY_Z GLFW_KEY_Z








// #define ABYS_KEY_0 GLFW_KEY_0
// #define ABYS_KEY_1 GLFW_KEY_1
// #define ABYS_KEY_2 GLFW_KEY_2
// #define ABYS_KEY_3 GLFW_KEY_3
// #define ABYS_KEY_4 GLFW_KEY_4
// #define ABYS_KEY_5 GLFW_KEY_5
// #define ABYS_KEY_6 GLFW_KEY_6
// #define ABYS_KEY_7 GLFW_KEY_7
// #define ABYS_KEY_8 GLFW_KEY_8
// #define ABYS_KEY_9 GLFW_KEY_9









// #define ABYS_KEY_F1  GLFW_KEY_F1
// #define ABYS_KEY_F2  GLFW_KEY_F2
// #define ABYS_KEY_F3  GLFW_KEY_F3
// #define ABYS_KEY_F4  GLFW_KEY_F4
// #define ABYS_KEY_F5  GLFW_KEY_F5
// #define ABYS_KEY_F6  GLFW_KEY_F6
// #define ABYS_KEY_F7  GLFW_KEY_F7
// #define ABYS_KEY_F8  GLFW_KEY_F8
// #define ABYS_KEY_F9  GLFW_KEY_F9
// #define ABYS_KEY_F10 GLFW_KEY_F10
// #define ABYS_KEY_F11 GLFW_KEY_F11
// #define ABYS_KEY_F12 GLFW_KEY_F12





// #define ABYS_KEY_ESCAPE      GLFW_KEY_ESCAPE
// #define ABYS_KEY_ENTER       GLFW_KEY_ENTER
// #define ABYS_KEY_TAB         GLFW_KEY_TAB
// #define ABYS_KEY_BACKSPACE   GLFW_KEY_BACKSPACE
// #define ABYS_KEY_INSERT      GLFW_KEY_INSERT
// #define ABYS_KEY_DELETE      GLFW_KEY_DELETE
// #define ABYS_KEY_RIGHT       GLFW_KEY_RIGHT
// #define ABYS_KEY_LEFT        GLFW_KEY_LEFT
// #define ABYS_KEY_DOWN        GLFW_KEY_DOWN
// #define ABYS_KEY_UP          GLFW_KEY_UP
// #define ABYS_KEY_PAGE_UP     GLFW_KEY_PAGE_UP
// #define ABYS_KEY_PAGE_DOWN   GLFW_KEY_PAGE_DOWN
// #define ABYS_KEY_HOME        GLFW_KEY_HOME
// #define ABYS_KEY_END         GLFW_KEY_END








// #define ABYS_KEY_LEFT_SHIFT    GLFW_KEY_LEFT_SHIFT
// #define ABYS_KEY_LEFT_CONTROL  GLFW_KEY_LEFT_CONTROL
// #define ABYS_KEY_LEFT_ALT      GLFW_KEY_LEFT_ALT
// #define ABYS_KEY_RIGHT_SHIFT   GLFW_KEY_RIGHT_SHIFT
// #define ABYS_KEY_RIGHT_CONTROL GLFW_KEY_RIGHT_CONTROL
// #define ABYS_KEY_RIGHT_ALT     GLFW_KEY_RIGHT_ALT
// #define ABYS_KEY_SPACE         GLFW_KEY_SPACE























typedef enum
{
    ABYS_EVENT_NONE = 0,
    ABYS_EVENT_KEY_DOWN,
    ABYS_EVENT_KEY_UP,
    ABYS_EVENT_MOUSE_MOVE,
    ABYS_EVENT_MOUSE_BUTTON_DOWN,
    ABYS_EVENT_MOUSE_BUTTON_UP,
    ABYS_EVENT_MOUSE_SCROLL,
    ABYS_EVENT_WINDOW_RESIZE,
    ABYS_EVENT_WINDOW_CLOSE
} abys_EventType;



typedef enum abys_Key
{
    ABYS_KEY_UNKNOWN         = -1,

    ABYS_KEY_SPACE           = 32,
    ABYS_KEY_APOSTROPHE      = 39,   /* ' */
    ABYS_KEY_COMMA           = 44,   /* , */
    ABYS_KEY_MINUS           = 45,   /* - */
    ABYS_KEY_PERIOD          = 46,   /* . */
    ABYS_KEY_SLASH           = 47,   /* / */

    ABYS_KEY_0               = 48,
    ABYS_KEY_1               = 49,
    ABYS_KEY_2               = 50,
    ABYS_KEY_3               = 51,
    ABYS_KEY_4               = 52,
    ABYS_KEY_5               = 53,
    ABYS_KEY_6               = 54,
    ABYS_KEY_7               = 55,
    ABYS_KEY_8               = 56,
    ABYS_KEY_9               = 57,

    ABYS_KEY_SEMICOLON       = 59,   /* ; */
    ABYS_KEY_EQUAL           = 61,   /* = */

    ABYS_KEY_A               = 65,
    ABYS_KEY_B               = 66,
    ABYS_KEY_C               = 67,
    ABYS_KEY_D               = 68,
    ABYS_KEY_E               = 69,
    ABYS_KEY_F               = 70,
    ABYS_KEY_G               = 71,
    ABYS_KEY_H               = 72,
    ABYS_KEY_I               = 73,
    ABYS_KEY_J               = 74,
    ABYS_KEY_K               = 75,
    ABYS_KEY_L               = 76,
    ABYS_KEY_M               = 77,
    ABYS_KEY_N               = 78,
    ABYS_KEY_O               = 79,
    ABYS_KEY_P               = 80,
    ABYS_KEY_Q               = 81,
    ABYS_KEY_R               = 82,
    ABYS_KEY_S               = 83,
    ABYS_KEY_T               = 84,
    ABYS_KEY_U               = 85,
    ABYS_KEY_V               = 86,
    ABYS_KEY_W               = 87,
    ABYS_KEY_X               = 88,
    ABYS_KEY_Y               = 89,
    ABYS_KEY_Z               = 90,

    ABYS_KEY_LEFT_BRACKET    = 91,   /* [ */
    ABYS_KEY_BACKSLASH       = 92,   /* \ */
    ABYS_KEY_RIGHT_BRACKET   = 93,   /* ] */
    ABYS_KEY_GRAVE_ACCENT    = 96,   /* ` */

    ABYS_KEY_WORLD_1         = 161,  /* non-US #1 */
    ABYS_KEY_WORLD_2         = 162,  /* non-US #2 */

    ABYS_KEY_ESCAPE          = 256,
    ABYS_KEY_ENTER           = 257,
    ABYS_KEY_TAB             = 258,
    ABYS_KEY_BACKSPACE       = 259,
    ABYS_KEY_INSERT          = 260,
    ABYS_KEY_DELETE          = 261,
    ABYS_KEY_RIGHT           = 262,
    ABYS_KEY_LEFT            = 263,
    ABYS_KEY_DOWN            = 264,
    ABYS_KEY_UP              = 265,

    ABYS_KEY_PAGE_UP         = 266,
    ABYS_KEY_PAGE_DOWN       = 267,
    ABYS_KEY_HOME            = 268,
    ABYS_KEY_END             = 269,

    ABYS_KEY_CAPS_LOCK       = 280,
    ABYS_KEY_SCROLL_LOCK     = 281,
    ABYS_KEY_NUM_LOCK        = 282,
    ABYS_KEY_PRINT_SCREEN    = 283,
    ABYS_KEY_PAUSE           = 284,

    ABYS_KEY_F1              = 290,
    ABYS_KEY_F2              = 291,
    ABYS_KEY_F3              = 292,
    ABYS_KEY_F4              = 293,
    ABYS_KEY_F5              = 294,
    ABYS_KEY_F6              = 295,
    ABYS_KEY_F7              = 296,
    ABYS_KEY_F8              = 297,
    ABYS_KEY_F9              = 298,
    ABYS_KEY_F10             = 299,
    ABYS_KEY_F11             = 300,
    ABYS_KEY_F12             = 301,
    ABYS_KEY_F13             = 302,
    ABYS_KEY_F14             = 303,
    ABYS_KEY_F15             = 304,
    ABYS_KEY_F16             = 305,
    ABYS_KEY_F17             = 306,
    ABYS_KEY_F18             = 307,
    ABYS_KEY_F19             = 308,
    ABYS_KEY_F20             = 309,
    ABYS_KEY_F21             = 310,
    ABYS_KEY_F22             = 311,
    ABYS_KEY_F23             = 312,
    ABYS_KEY_F24             = 313,
    ABYS_KEY_F25             = 314,

    /* Keypad */
    ABYS_KEY_KP_0            = 320,
    ABYS_KEY_KP_1            = 321,
    ABYS_KEY_KP_2            = 322,
    ABYS_KEY_KP_3            = 323,
    ABYS_KEY_KP_4            = 324,
    ABYS_KEY_KP_5            = 325,
    ABYS_KEY_KP_6            = 326,
    ABYS_KEY_KP_7            = 327,
    ABYS_KEY_KP_8            = 328,
    ABYS_KEY_KP_9            = 329,
    ABYS_KEY_KP_DECIMAL      = 330,
    ABYS_KEY_KP_DIVIDE       = 331,
    ABYS_KEY_KP_MULTIPLY     = 332,
    ABYS_KEY_KP_SUBTRACT     = 333,
    ABYS_KEY_KP_ADD          = 334,
    ABYS_KEY_KP_ENTER        = 335,
    ABYS_KEY_KP_EQUAL        = 336,

    /* Modifiers */
    ABYS_KEY_LEFT_SHIFT      = 340,
    ABYS_KEY_LEFT_CONTROL    = 341,
    ABYS_KEY_LEFT_ALT        = 342,
    ABYS_KEY_LEFT_SUPER      = 343,
    ABYS_KEY_RIGHT_SHIFT     = 344,
    ABYS_KEY_RIGHT_CONTROL   = 345,
    ABYS_KEY_RIGHT_ALT       = 346,
    ABYS_KEY_RIGHT_SUPER     = 347,
    ABYS_KEY_MENU            = 348,

    ABYS_KEY_LAST            = 348
} abys_Key;








typedef enum abys_MouseButton
{
    ABYS_MOUSE_BUTTON_UNKNOWN = -1,

    ABYS_MOUSE_BUTTON_1       = 0,
    ABYS_MOUSE_BUTTON_2       = 1,
    ABYS_MOUSE_BUTTON_3       = 2,
    ABYS_MOUSE_BUTTON_4       = 3,
    ABYS_MOUSE_BUTTON_5       = 4,
    ABYS_MOUSE_BUTTON_6       = 5,
    ABYS_MOUSE_BUTTON_7       = 6,
    ABYS_MOUSE_BUTTON_8       = 7,

    ABYS_MOUSE_BUTTON_LAST    = 7,

    // Common aliases (most games only use these 3)
    ABYS_MOUSE_BUTTON_LEFT    = 0,
    ABYS_MOUSE_BUTTON_RIGHT   = 1,
    ABYS_MOUSE_BUTTON_MIDDLE  = 2,

    // You can also use SA_MOUSE_BUTTON_4 … SA_MOUSE_BUTTON_8 for extra buttons
} abys_MouseButton;





typedef enum abys_MouseWheel
{
    ABYS_MOUSE_WHEEL_NONE = 0,
    ABYS_MOUSE_WHEEL_UP   = 1,
    ABYS_MOUSE_WHEEL_DOWN = -1
} abys_MouseWheel;




typedef struct abys_Event
{
    abys_EventType type;

    union
    {
        struct { abys_Key key; } key;
        struct { double x, y; } mouseMove;
        struct { abys_MouseButton button; } mouseButton;
        struct { double offset; } scroll;
        struct { int width, height; } resize;
    };

} abys_Event;



abys__EventSystem* abys__InitEventSystem(void);

void abys_PushEvent(abys_Window* window, abys_Event event);




int abys_PollEvent(abys_Window* window, abys_Event* out);



void abys__SetWindowEventCallBacks(GLFWwindow* window);









// ================================================================
// Continuous Input (Raylib / SDL / Godot style)
// Call SA_UpdateInput() once per frame!
// ================================================================




void abys_ProcessEvent(abys_Window* window, const abys_Event* event);
void abys_UpdateInput(abys_Window* window);


abys_Bool abys_IsKeyDown(abys_Window* window, abys_Key key);
abys_Bool abys_IsKeyPressed(abys_Window* window, abys_Key key);     // true only this frame
abys_Bool abys_IsKeyReleased(abys_Window* window, abys_Key key);

abys_Bool abys_IsMouseButtonDown(abys_Window* window, abys_MouseButton button);
abys_Bool abys_IsMouseButtonPressed(abys_Window* window, abys_MouseButton button);
abys_Bool abys_IsMouseButtonReleased(abys_Window* window, abys_MouseButton button);

double abys_GetMouseX(abys_Window* window);
double abys_GetMouseY(abys_Window* window);
double abys_GetMouseWheel(abys_Window* window);        // last scroll delta this frame













// void SA_HandleEvents(abys_EventCallback callback);