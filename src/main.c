#include "abys.h"
#include <stdio.h>


#define WINDOW_WIDTH  800
#define WINDOW_HEGITH   600

#define RED     ABYS_RGBA(255, 0, 0, 255)
#define LIME     ABYS_RGBA(0, 255, 0, 255)


void btn1cb(void* pointer)
{
    printf("Button Clicked! 🙂\n");
}


int main(void) {
    abys_Start(0);


    abys_Window* window = abys_OpenWindow(
        WINDOW_WIDTH, WINDOW_HEGITH, 
        "Abyss-IDE", 
        ABYS_WINDOW_UNDECORATED | ABYS_WINDOW_MAXIMIZED
    );

    GLFWwindow* gwnd = abys__GetWindowHandle(window);


    abys_SetBackgroundColor(window, 45, 45, 45);

    abys_Button* btn1 = abys_CreateButton(window, &ABYS_RECT(50, 200, 300, 120), RED, LIME);

    abys_Text* txt1 = abys_CreateText(window, "COOPBL.TTF", 20.0f);


    abys_Event event;


    while (abys_RunWindow(window)) { 

        while(abys_PollEvent(window, &event))
        {
            switch (event.type) {
                case ABYS_KEY_0:
                    printf("0 pressed");
                    break;
            }
        }

        
        if (abys_IsKeyPressed(window, ABYS_KEY_ESCAPE))
            abys_StopWindow(window);


        abys_BeginFrame(window);


            // abys_UpdateButton(btn1, btn1cb);
            abys_UpdateText(txt1, "Abyss-IDE", (abys_Color){255, 45, 67, 255}, 45, 100);

        abys_EndFrame(window);
    }


    abys_DestroyButton(btn1);
    abys_DestroyText(txt1);

    abys_CloseWindow(window);
}