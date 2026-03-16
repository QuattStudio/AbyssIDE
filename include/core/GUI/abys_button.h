#pragma once


#include "core/abys_types.h"
#include "core/abys_utils.h"




typedef struct abys_Window abys_Window;
typedef struct abys_Button abys_Button;



typedef void (*abys_ButtonCallback)(void* pointer);



abys_Button* abys_CreateButton(
    abys_Window* window,
    abys_Rect* rect, 
    abys_Color backColor,
    abys_Color backHoverColor
);



void abys_DestroyButton(abys_Button* button);


void abys_UpdateButton(abys_Button* button, abys_ButtonCallback callback);
void abys_PassPointerToButton(abys_Button* button, void* pointer);