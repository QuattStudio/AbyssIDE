#include "core/GUI/abys_button.h"

#include "core/internals/abys_i.h"

#include "core/abys_algo.h"
#include "abys_inc.h"

#include "core/window/abys_event.h"
#include "core/canvas/abys_canvas.h"


#include <stdio.h>
#include <stdlib.h>


typedef struct abys_Button {
    abys_Rect* rect;

    abys_Window* window;
    abys_Color originalBackColor;
    abys_Color backColor;
    // abys_Color foreColor;

    abys_Color backColorOnHovered;
    // abys_Color foreColorOnHovered;

    abys_Bool isHovered;

    void* userPointer;
} abys_Button;





/* internal functions */



ABYS_INLINE void abys__UIDrawButton(abys_Button* button)
{
    // considering that button and window that is passed is already exists

    
    abys_DrawRectangle(button->window, button->rect, button->backColor);    

}





/* exposed functions */

abys_Button* abys_CreateButton(
    abys_Window* window,
    abys_Rect* rect, 
    abys_Color backColor,
    abys_Color backHoverColor
) 
{
    if (!rect) return NULL;

    abys_Button* button = (abys_Button*)malloc(sizeof(abys_Button));
    if (!button)
    {
        ABYS_LOG_WARN("Memory allocation Failed while creating button!");
        return NULL;
    }

    button->rect = rect;
    button->originalBackColor = backColor;
    button->backColor = backColor;
    button->backColorOnHovered = backHoverColor;
    button->isHovered = 0;
    button->window = window;
    button->userPointer = NULL;

    return button;
}



void abys_DestroyButton(abys_Button* button)
{
    if (!button) return;

    free(button);
}



void abys_PassPointerToButton(abys_Button* button, void* pointer)
{
    if (!button) return;

    button->userPointer = pointer;
}






void abys_UpdateButton(abys_Button* button, abys_ButtonCallback callback)
{
    if (!button) return;

    ABYS__CHECK_WINDOW(button->window, ABYS__EXCEPT_WINDOW_NOT_FOUND, ABYS__RET_NOTHING);


    double MouseX, MouseY;
    glfwGetCursorPos(button->window->handle, &MouseX, &MouseY);


    if (abys_PointRectCollision(button->rect, &ABYS_POINT(MouseX, MouseY)))
    {
        button->backColor = button->backColorOnHovered;

        
        int pressed = abys_IsMouseButtonDown(button->window, ABYS_MOUSE_BUTTON_LEFT);
        if (pressed) {
            if (button->userPointer)
                callback(button->userPointer);
            else
                callback(NULL);
        }

    }
    else {
        button->backColor = button->originalBackColor;
    }

    abys__UIDrawButton(button);

}








