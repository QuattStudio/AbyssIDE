#pragma once



#include "abys_inc.h"
#include "core/abys_types.h"
#include "core/abys_utils.h"





typedef struct {
    int flag;
    int glfw_flag;
    int state;
} FlagMap;




FlagMap map[] = {
    {ABYS_WINDOW_MAXIMIZED, GLFW_MAXIMIZED, ABYS_TRUE},
    {ABYS_WINDOW_RESIZABLE, GLFW_RESIZABLE, ABYS_TRUE},
    {ABYS_WINDOW_DECORATED, GLFW_DECORATED, ABYS_TRUE},
    {ABYS_WINDOW_UNDECORATED, GLFW_DECORATED, ABYS_FALSE},
    {ABYS_WINDOW_FLOATING, GLFW_FLOATING, ABYS_TRUE},
};







static inline void abys__InitWindowFlags(abys_Uint32 flags)
{
    for (int i = 0; i < sizeof(map)/sizeof(map[0]); i++)
    {
        if (flags & map[i].flag)
            glfwWindowHint(map[i].glfw_flag, map[i].state);
    }
}