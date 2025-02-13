#include "main.h"

Engine_Renderer *renderer;
Engine_Renderer *engine_renderer;

int gravity = 1;

int main()
{
    // title, development_width, development_height, window_width, window_height, engine_scale, full screen = 1, fps
    //Engine_Start("Lift Me Up", 1920, 1080, 640, 360, 0, 60); // window
    Engine_Start("Monkey Dong", 320, 180, 640, 360, 0, 60); // full screen

    renderer = engine_renderer; /* set engine_renderer as renderer */

    engine_quit = false; /* Should initalize to false at begining */

    /* triger sprite images per second */
    Engine_Init_Triger(&triger1, 1, 1);
    Engine_Init_Triger(&triger2, 2, 1);
    Engine_Init_Triger(&triger4, 4, 1);
    Engine_Init_Triger(&triger6, 6, 1);
    Engine_Init_Triger(&triger8, 8, 1);

    Ui option = START_UI; // switch default for Menu_Main 

    Init_ECS();

    //initAudio();
    
    // main loop
    while(!engine_quit) {
        Engine_Event_Handler();

        switch(option) {
            case GAME_UI:
                option = 1;
                break;
            case START_UI:
                option = Start_Ui();
                break;
            case QUIT_UI:
                engine_quit = true;
                break;
            case SETTINGS_UI:
                option = Settings_Ui();
                break;
            case 1:
                option = Mission1();
                break;
            case 2:
                engine_quit = true;
                //option = Mission2();
                break;
            default:
                break;
        }
    }

    //endAudio();

    // Free components
    Free_Components();

    Clean();

    Free_ECS();

    // End game and clean the memory
    Engine_Stop();

    return 0;
}
