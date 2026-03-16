#pragma once



#include "core/abys_types.h"




typedef struct abys_Window abys_Window;
typedef struct abys_Text abys_Text;





abys_Text* abys_CreateText(abys_Window* window, const char* fontPath, float fontSize);

void abys_UpdateText(abys_Text* text, const char* str, abys_Color color, float x, float y);


void abys_DestroyText(abys_Text* text);