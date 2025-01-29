#include "main.h"

Engine_Renderer *renderer;

/* Triger sprite images
 * Use globaly in entire game */
SpriteTriger triger6; /* 6 images per second */
SpriteTriger triger8; /* 8 images per second */

int gravity = 1;

int main()
{
    // title, development_width, development_height, window_width, window_height, engine_scale, full screen = 1, fps
    //Engine_Start("Lift Me Up", 1920, 1080, 640, 360, 0, 60); // window
    Engine_Start("Monkey Dong", 320, 180, 640, 360, 0, 60); // full screen

    renderer = engine_renderer; /* set engine_renderer as renderer */

    engine_quit = false; /* Should initalize to false at begining */

    /* Set triger sprites per second */
    Engine_Init_Triger(&triger6, 6);
    Engine_Init_Triger(&triger8, 8);

    int option; // from menu and missions

    //initAudio();

    // main loop
    while(!engine_quit) {
        Engine_Event_Handler();
        option = Menu_Main();

        switch(option) {
            case -1:
                engine_quit = true;
                break;
            case 0:
                Menu_Settings();
                break;
            case 1:
                option = Mission1();
                break;
            /*case 1:*/
                /*option = Mission2();*/
                /*break;*/
            default:
                break;
        }
    }

    //endAudio();

    // Free components
    Free_Components();

    // End game and clean the memory
    Engine_Stop();

    return 0;
}
