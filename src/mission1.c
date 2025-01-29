#include "mission1.h"

void
Create_Entities()
{
    // Create entities
    // required entities at this level, maximum entities in all levels
    players = EC_Entity_New(1, 2); // player entity
    arrow = EC_Entity_New(1, 2); // arrow entity

    nebulae = EC_Entity_New(1, 2); // nebulae entity
    monkeyDong = EC_Entity_New(1, 2); // monkeyDong entity
    brick = EC_Entity_New(1, 2); // monkeyDong entity

    // Create ground entities
    grounds = EC_Entity_New(3, 6); // ground entity
}


void
Mission1_init()
{
    Player_Init_SpriteSheet("resources/textures/player.png");
    Arrow_Init_Spritesheet("resources/textures/arrow.png");
    MonkeyDong_Init_Spriteshteet("resources/textures/monkeydong.png");
    Nebula_Init_Spritesheet("resources/textures/nebula.png");
    Brick_Init_Spritesheet("resources/textures/brick.png");

    // player_id, pos_x, pos_y, vel_x, vel_y, scale
    // players.I - first player id
    Player_Init(players.I, 0, (engine_height - 16), 1, 2, 1);
    Arrow_Init(arrow.I, 16, 16, 0, 0, 1);
    MonkeyDong_Init(monkeyDong.I, engine_width - 32, 16, 0, 0, 1);
    Nebula_Init(nebulae.I, engine_width/3, engine_height/4, 0, 0, 1);
    Brick_Init(brick.I, 0, (engine_height - 16), 1, -1, 1);


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
    Nebula_Free();
    Brick_Free();
    Ground_Free();
}


int
Mission1()
{
    // Create entities
    Create_Entities();

    // Create components
    Engine_Component_Create();
    Create_Components();

    // Assign components
    Assign_Components();

    // Initialize entities
    Mission1_init();

    // Sprite common trigering
    // triger6 and triger8 are global variables defined in main.h
    Engine_Init_Triger(&triger6, 6);
    Engine_Init_Triger(&triger8, 8);

    Engine_Init_Time();

    bool *quit_mission;

    // Bind keys to game play
    Engine_Event_Key_Bind(&player_move_left, &engine_key_left);
    Engine_Event_Key_Bind(&player_move_right, &engine_key_right);
    Engine_Event_Key_Bind(&player_jump, &engine_key_space);
    Engine_Event_Key_Bind(&arrow_turn_left, &engine_key_down);
    Engine_Event_Key_Bind(&arrow_turn_right, &engine_key_up);

    Engine_Event_Key_Bind(&quit_mission, &engine_key_esc);

    int player_state = 0;

    /* mission loop */
    while(*quit_mission != true)
    {
        Engine_Frame_Rate(60, 0);

        Engine_Sprite_Triger_Update(&triger6); // ** reconsider these two lines
        Engine_Sprite_Triger_Update(&triger8);

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
        //System_Player_Nebula_Collission();

        /* Update entities */
        //Engine_Ground_Repeat_Left_Update(far_ground_id);
        //Engine_Ground_Repeat_Left_Update(back_ground_id);
        //Engine_Ground_Repeat_Left_Update(fore_ground_id);

        Nebula_Update();
        Brick_Update();
        Arrow_Update();
        Player_Update();
        MonkeyDong_Update();

        SDL_RenderPresent(renderer);
    }

    Mission1_Free();
}
