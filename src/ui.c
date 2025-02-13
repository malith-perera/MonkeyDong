#include "ui.h"


bool engine_quit;

int
Start_Ui()
{
    static Ui option = GAME_UI;

    bool quit_menu = false;
    engine_quit = false;
    int btn_pos_y = engine_height/2;

    // Initialize background
    SDL_FRect src, dst;
    SDL_FRect play_btn_src, play_btn_dst;
    SDL_FRect settings_btn_src, settings_btn_dst;
    SDL_FRect quit_btn_src, quit_btn_dst;

    Engine_Rect_Images_Src(&src, 0, 0, engine_width, engine_height);
    Engine_Rect_Images_Dst(&dst, 0, 0, engine_window_width, engine_window_height);

    SDL_Texture *main_menu_texture = Engine_Create_Texture("resources/textures/menu.png", renderer);

    Engine_Rect_Images_Src(&play_btn_src, 0, 0, 43, 15);
    Engine_Rect_Images_Dst(&play_btn_dst, engine_width*7/10, btn_pos_y, 43, 15);

    SDL_Texture *play_btn_texture = Engine_Create_Texture("resources/textures/play_btn.png", renderer);
    SDL_Texture *play_btn_texture2 = Engine_Create_Texture("resources/textures/play_btn2.png", renderer);

    Engine_Rect_Images_Src(&settings_btn_src, 0, 0, 88, 15);
    Engine_Rect_Images_Dst(&settings_btn_dst, engine_width*7/10, btn_pos_y + 25, 88, 15);

    SDL_Texture *settings_btn_texture = Engine_Create_Texture("resources/textures/settings_btn.png", renderer);
    SDL_Texture *settings_btn_texture2 = Engine_Create_Texture("resources/textures/settings_btn2.png", renderer);

    Engine_Rect_Images_Src(&quit_btn_src, 0, 0, 39, 12);
    Engine_Rect_Images_Dst(&quit_btn_dst, engine_width*7/10, btn_pos_y + 25 * 2, 39, 12);

    SDL_Texture *quit_btn_texture = Engine_Create_Texture("resources/textures/quit_btn.png", renderer);
    SDL_Texture *quit_btn_texture2 = Engine_Create_Texture("resources/textures/quit_btn2.png", renderer);

    float m_x, m_y; // mouse x, y positions

    while(quit_menu != true) {
        Engine_Event_Handler();
        
        // mouse x, y positions
        SDL_GetMouseState(&m_x, &m_y);

        // Engine_Event_Handler set engine_quit
        if(engine_quit == true) {
            quit_menu = true;
        }

        // Up arrow press to go through menu
        if(engine_key_up == 1 && option < -1) {
            if(engine_key_up_pressed != true) {
                option += 1;
                engine_key_up_pressed = true;
            }
        }

        // Down arrow press to go through menu
        if(engine_key_down == 1 && option > -3) {
            if(engine_key_down_pressed != true) {
                option -= 1;
                engine_key_down_pressed = true;
            }
        }


        // Esc key press
        if(engine_key_esc == true && engine_key_esc_pressed != true) {
            engine_quit = true;
            option = START_UI;
        }

        // window quit button press
        if(engine_event_close_window == true) {
            quit_menu = true;
            engine_quit = true;
            option = QUIT_UI;
        }

        if(engine_key_enter == 1) {
            quit_menu = true;
        }

        // mouse press
        if(engine_mouse_btn) {
            if(Engine_Pointer_Rect_Collition(play_btn_dst, m_x, m_y)) {
                option = GAME_UI;
                quit_menu = true;
            }

            if(Engine_Pointer_Rect_Collition(settings_btn_dst, m_x, m_y)) {
                option = SETTINGS_UI;
                quit_menu = true;
            }

            if(Engine_Pointer_Rect_Collition(quit_btn_dst, m_x, m_y)) {
                option = QUIT_UI;
                quit_menu = true;
            }
        }

        // Rendering
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        SDL_RenderTexture(
            renderer,
            main_menu_texture,
            NULL,
            NULL
        );

        if(option == QUIT_UI) {
            SDL_RenderTexture(
                renderer,
                quit_btn_texture2,
                &quit_btn_src,
                &quit_btn_dst
            );
        }
        else {
            SDL_RenderTexture(
                renderer,
                quit_btn_texture,
                &quit_btn_src,
                &quit_btn_dst
            );
        }

        if(option == SETTINGS_UI) {
            SDL_RenderTexture(
                renderer,
                settings_btn_texture2,
                &settings_btn_src,
                &settings_btn_dst
            );
        }
        else {
            SDL_RenderTexture(
                renderer,
                settings_btn_texture,
                &settings_btn_src,
                &settings_btn_dst
            );
        }

        if(option == GAME_UI) {
            SDL_RenderTexture(
                renderer,
                play_btn_texture2,
                &play_btn_src,
                &play_btn_dst
            );
        }
        else {
            SDL_RenderTexture(
                renderer,
                play_btn_texture,
                &play_btn_src,
                &play_btn_dst
            );
        }
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(main_menu_texture);
    SDL_DestroyTexture(play_btn_texture);
    SDL_DestroyTexture(settings_btn_texture);
    SDL_DestroyTexture(quit_btn_texture);

    return option;
}


void
Menu_Play()
{
}


int
Settings_Ui()
{
    printf("Settings\n");
    return START_UI;
}
