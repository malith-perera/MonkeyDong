#include "mission1.h"


void
Mission1_init()
{
    Player_Init_SpriteSheet("resources/textures/player.png");
    Arrow_Init_Spritesheet("resources/textures/arrow.png");
    MonkeyDong_Init_Spriteshteet("resources/textures/monkeydong.png");
    Stone_Init_Spritesheet("resources/textures/stone.png");

    // player_id, pos_x, pos_y, vel_x, vel_y, scale
    // players.I - first player id
    //Player_Init(players.I, 0, (engine_height - 16), 1, 2, 1);
    Player_Init(0, 0, (engine_height - 16), 1, 2, 1);
    Arrow_Init(0, 16, 16, 0, 0, 1);
    MonkeyDong_Init(0, engine_width - 32, 16, 0, 0, 1);
    Stone_Init(0, 0, (engine_height - 16), 1, -1, 1);

    // Initialize grounds
    Ground_Init();
}


void
Mission1_Free()
{
    // Free entities
    Player_Free();
    Arrow_Free();
    MonkeyDong_Free();
    Stone_Free();
    Ground_Free();

    // New ECS
    Free_Component(place);
    Free_Component(action);
}


int
Mission1()
{
    // New ECS    
    player = New_Entity(1, 2);
    arrow = New_Entity(1, 2);
    monkey = New_Entity(1, 2);
    stone = New_Entity(1, 2);

    // Assign
    Assign_Player();
    Assign_Arrow();
    Assign_Monkey();
    Assign_Stone();

    // Allocate
    Allocate(Place, place);
    Allocate(Action, action);
    Allocate(Rotation, rotation);
    Engine_Allocate();

    // Initialize entities
    Mission1_init();

    bool *quit_mission;

    // Bind keys to game play
    Engine_Event_Key_Bind(&player_move_left, &engine_key_left);
    Engine_Event_Key_Bind(&player_move_right, &engine_key_right);
    Engine_Event_Key_Bind(&player_jump, &engine_key_space);
    Engine_Event_Key_Bind(&arrow_turn_left, &engine_key_down);
    Engine_Event_Key_Bind(&arrow_turn_right, &engine_key_up);

    Engine_Event_Key_Bind(&quit_mission, &engine_key_esc);

    int player_state = 0;
    
    // Reset time
    Engine_Init_Time();

    /* mission loop */
    while(*quit_mission != true)
    {
        Engine_Frame_Rate(60, 1); // 1 - print fps

        Engine_Update_Triger(&triger1);
        Engine_Update_Triger(&triger2);
        Engine_Update_Triger(&triger4);
        Engine_Update_Triger(&triger6);

        Engine_Event_Handler();

        if(engine_event_close_window == true) { // window quit button pressed
            *quit_mission = true;
            engine_quit = true;
        }

        if(engine_key_esc == true) { // quit mission by pressing esc key
            engine_key_esc_pressed = true;
        }

        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        /* Detect entity collissions */
        System_Player_Stone_Collission();

        /* Update entities */
        //Engine_Ground_Repeat_Left_Update(far_ground_id);
        //Engine_Ground_Repeat_Left_Update(back_ground_id);
        //Engine_Ground_Repeat_Left_Update(fore_ground_id);

        Stone_Update();
        Arrow_Update();
        Player_Update();
        MonkeyDong_Update();

        System_Render();

        SDL_RenderPresent(renderer);
    }

    Mission1_Free();

    return 0; //  return 0 for menu or next mission number.
}
