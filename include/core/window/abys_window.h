#pragma once




#include "abys_inc.h"
#include "core/abys_types.h"


typedef struct abys_Window abys_Window;





int abys_Start(abys_Uint32 flags);


abys_Window* abys_OpenWindow(int width, int height, const char* title, abys_Uint32 flags);



void abys_CloseWindow(abys_Window* window);



int abys_RunWindow(abys_Window* window);


void abys_BeginFrame(abys_Window* window);

void abys_EndFrame(abys_Window* window);

void abys_ClearBackground(float r, float g, float b);