#pragma once



#include "core/abys_types.h"
#include "core/abys_utils.h"
#include "abys_inc.h"


typedef struct abys_Window abys_Window;



void abys_BeginFrame(abys_Window* window);

void abys_EndFrame(abys_Window* window);

void abys_SetBackgroundColor(abys_Window* window, int r, int g, int b);



void abys_DrawRectangle(abys_Window* window, abys_Rect* rect, abys_Color color);