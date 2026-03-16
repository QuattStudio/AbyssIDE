#include "core/GUI/abys_text.h"


#include "abys_inc.h"
#include "core/internals/abys_i.h"

#include "core/abys_utils.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



typedef struct Abys_Font
{
    const char* path;
    int fontID;
} Abys_Font;


typedef struct abys_Text {
    const char* fontPath;
    float fontSize;
    int font;

    abys_Window* window;
} abys_Text;




Abys_Font fonts[0xff];
int fontCount = 0;




static int abys_GetFont(NVGcontext* vg, const char* path)
{
    for(int i = 0; i < fontCount; i++)
    {
        if(strcmp(fonts[i].path, path) == 0)
            return fonts[i].fontID;
    }

    // int id = nvgCreateFont(vg, path, path);
    int id = nvgCreateFont(vg, path, path);

    if(id == -1)
    {
        ABYS_LOG_ERROR("Failed to load font: %s", path);
        return -1;
    }

    fonts[fontCount].path = path;
    fonts[fontCount].fontID = id;
    fontCount++;

    return id;
}




abys_Text* abys_CreateText(abys_Window* window, const char* fontPath, float fontSize)
{
    ABYS__CHECK_WINDOW(window, ABYS__EXCEPT_WINDOW_NOT_FOUND, NULL);


    abys_Text* abysText = (abys_Text*)malloc(sizeof(abys_Text));
    if (!abysText)
    {
        ABYS_LOG_ERROR("Memory allocation failed!");
        return NULL;
    }


    abysText->fontPath = fontPath;
    abysText->fontSize = fontSize;
    abysText->font = abys_GetFont(window->canvas, fontPath);
    
    if(abysText->font == -1)
    {
        ABYS_LOG_ERROR("Font creation failed!");
    }


    abysText->window = window;

    return abysText;
}






void abys_UpdateText(abys_Text* text, const char* str, abys_Color color, float x, float y)
{
    if (!text) 
    {
        ABYS_LOG_WARN("No Text Found!");
        return;
    }


    if (!str) 
    {
        ABYS_LOG_WARN("No Str found!");
        return;
    }


    NVGcontext* ctx = text->window->canvas;

    ABYS__CHECK_WINDOW(text->window, ABYS__EXCEPT_WINDOW_NOT_FOUND, ABYS__RET_NOTHING);


    nvgFontFaceId(ctx, text->font);
    
    nvgFontSize(ctx, text->fontSize);
    nvgFillColor(ctx, *(NVGcolor*)&color);
    nvgTextAlign(ctx, NVG_ALIGN_LEFT | NVG_ALIGN_TOP);
    nvgText(ctx, x, y, str, NULL);
}





void abys_DestroyText(abys_Text* text)
{
    if (!text)
    {
        ABYS_LOG_WARN("No Text found!");
        return;
    }

    free(text);
}