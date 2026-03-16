

#include <stdlib.h>
#include <string.h>
#include "core/window/abys_window.h"
#include "core/internals/abys_i.h"
#include "abys_inc.h"

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

static Abys_Font fonts[0xff];
static int fontCount = 0;

/* Strip directory and extension from path: "fonts/COOPBL.TTF" -> "COOPBL" */
static void abys__GetBaseFontName(const char* path, char* out, int outSize)
{
    if (!path) { strncpy(out, "default", outSize); return; }

    /* strip directory */
    const char* name = strrchr(path, '/');
    if (!name) name = strrchr(path, '\\');
    name = name ? name + 1 : path;

    strncpy(out, name, outSize - 1);
    out[outSize - 1] = '\0';

    /* strip extension */
    char* dot = strrchr(out, '.');
    if (dot) *dot = '\0';
}

static int abys_GetFont(NVGcontext* vg, const char* path)
{
    /* return cached ID if already loaded */
    for (int i = 0; i < fontCount; i++)
    {
        if (strcmp(fonts[i].path, path) == 0)
            return fonts[i].fontID;
    }

    if (fontCount >= 0xff)
    {
        ABYS_LOG_ERROR("Font cache full!");
        return -1;
    }

    char cleanName[256];
    abys__GetBaseFontName(path, cleanName, sizeof(cleanName));

    int id = nvgCreateFont(vg, cleanName, path);
    if (id == -1)
    {
        ABYS_LOG_ERROR("Failed to load font: %s (name: %s)", path, cleanName);
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

    if (!fontPath)
    {
        ABYS_LOG_ERROR("fontPath is NULL!");
        return NULL;
    }

    abys_Text* abysText = (abys_Text*)malloc(sizeof(abys_Text));
    if (!abysText)
    {
        ABYS_LOG_ERROR("Memory allocation failed!");
        return NULL;
    }

    abysText->fontPath = fontPath;
    abysText->fontSize = fontSize;
    abysText->window   = window;

    /* nvgCreateFont is safe to call here (outside frame) */
    abysText->font = abys_GetFont(window->canvas, fontPath);

    if (abysText->font == -1)
    {
        /* non-fatal: UpdateText will retry lazily */
        ABYS_LOG_WARN("Font not loaded at CreateText time, will retry at UpdateText: %s", fontPath);
    }

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
        ABYS_LOG_WARN("No string provided!");
        return;
    }

    ABYS__CHECK_WINDOW(text->window, ABYS__EXCEPT_WINDOW_NOT_FOUND, ABYS__RET_NOTHING);

    NVGcontext* ctx = text->window->canvas;

    /* lazy retry: if font failed at CreateText time, try again now */
    if (text->font == -1)
    {
        text->font = abys_GetFont(ctx, text->fontPath);
        if (text->font == -1)
        {
            ABYS_LOG_ERROR("Font still unavailable: %s", text->fontPath);
            return;
        }
    }

    nvgFontFaceId(ctx, text->font);
    nvgFontSize(ctx, text->fontSize);

    nvgFillColor(ctx, nvgRGBA(color.r, color.g, color.b, color.a));
    nvgTextAlign(ctx, NVG_ALIGN_LEFT | NVG_ALIGN_TOP);
    nvgText(ctx, x, y, str, NULL);


    // printf("font id: %d | fontSize: %.1f | str: %s\n", text->font, text->fontSize, str);
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