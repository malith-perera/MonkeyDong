#include "player.h"

ECEntity players; // player entity ids

SpriteImages *player_move_sprites;
SpriteImages *player_jump_sprites;
SpriteImages *player_idle_sprites;

bool *player_move_right; // key binding
bool *player_move_left; // key binding
bool *player_jump; // key binding

void
Player_Init_SpriteSheet(char *image)
{
    SpriteSheet *spritesheet = Engine_Create_Spritesheet(image, renderer);

    /* image , renderer, src_x, src_y, src_w, src_h, scale, nRows, nColumns, nSprite images in the sprite sheet, sprites per second */
    player_idle_sprites = Engine_New_Sprite(
            spritesheet,          // sprite sheet                
            renderer,             // renderer                    
            0, 0,                 // src_x, src_y                
            16, 16,               // src_w, src_h                
            1,                    // scale                       
            1, 6,                 // nRows, nColumns             
            6, 6);                // nSprites, sprites per second

    player_move_sprites = Engine_New_Sprite(
            spritesheet,                     
            renderer,                        
            0, 16,                           
            16, 16,                          
            1,                               
            1, 6,                            
            6, 6);                           

    player_jump_sprites = Engine_New_Sprite(
            spritesheet,
            renderer,
            0, 32,
            16, 16,
            1,
            1, 6,
            6, 6);
}

void
Player_Init(
    int entity_id,
    int pos_x, int pos_y,
    int vel_x, int vel_y,
    float scale
)
{
    /* int entity_id, SpriteImage* sprite images */
    Engine_Assign_Sprite(entity_id, player_idle_sprites);

    /* entity_id, pos_x, pos_y, vel_x, vel_y, initial_scale */
    Engine_Entity_Init(entity_id, pos_x, pos_y, vel_x, vel_y, 1);

    place[entity_id] = ON_GROUND;
    action[entity_id] = IDLE;
}


void
Player_Free()
{
    free(player_move_sprites);
    free(player_jump_sprites);
    free(player_idle_sprites);
}


void
Player_Update()
{
    /* check key presses */
    if(*player_move_right == 1 && *player_jump == 1) { // jump right
        action[players.I] = JUMP_RIGHT;
    } 
    else if(*player_move_right == 1) { // move right
        action[players.I] = MOVE_RIGHT;
    }

    if(*player_move_left == 1 && *player_jump == 1) { // jump left
        action[players.I] = JUMP_LEFT;
    } 
    else if(*player_move_left == 1) { // move left key pressed 
        action[players.I] = MOVE_LEFT;
    }

    if(*player_jump == 1 && *player_move_left != 1 && *player_move_right != 1) { // jump up 
        action[players.I] = JUMP;
    }

    if(!(*player_move_right || *player_move_left || *player_jump))
    {
        action[players.I] = IDLE;
    }

    int i = 0; 
    for(int player_id = players.I; player_id < players.n; player_id++) {
        if(action[player_id] == IDLE && (action[player_arrow_id[i]] == TURN_LEFT || action[player_arrow_id[i]] == TURN_RIGHT || action[player_arrow_id[i]] == TURN)) {
            printf("%d\n", players.M);
        }
        else {
            if(action[player_id] == JUMP || place[player_id] == ON_SKY) {
                Player_Jump(player_id);
            }

            if(action[player_id] == JUMP_LEFT || place[player_id] == ON_SKY) {
                Player_Jump_Left(player_id);
            }

            if(action[player_id] == JUMP_RIGHT || place[player_id] == ON_SKY) {
                Player_Jump_Right(player_id);
            }

            if(action[player_id] == MOVE_RIGHT || action[player_id] == MOVE_LEFT) {
                Player_Move(player_id);
            }
        
            if(action[player_id] == IDLE) {
                Player_Idle(player_id);
            }

            Engine_Render(player_id, renderer);
            i++;
        }
    }
}


void
Player_Move(int player_id)
{
    if(place[player_id] == ON_GROUND)
        Engine_Assign_Sprite(player_id, player_move_sprites);
    else
        Engine_Assign_Sprite(player_id, player_jump_sprites);

    Engine_Sprite_Triger(&triger6, &sprite[player_id]);

    /*Engine_Update_Sprite(&sprite[player_id]);*/

    for(int ground_id = grounds.I; ground_id < grounds.n; ground_id++) {
        Engine_Ground_Move_Left(ground_id);
    }

    if (action[players.I] == MOVE_RIGHT || action[players.I] == JUMP_RIGHT) {
        *position[player_id].x += velocity[player_id].x;
        if (*position[player_id].x > (engine_width - 16) * engine_scale) {
            *position[player_id].x = (engine_width - 16) * engine_scale; 
        }
    }
    else if (action[players.I] == MOVE_LEFT || action[players.I] == JUMP_LEFT) {
        *position[player_id].x -= velocity[player_id].x;
        if (*position[player_id].x < 0) {
            *position[player_id].x = 0; 
        }
    }
}


void
Player_Jump(int player_id)
{
    static int frm = 0;
    int height[5] = {10, 8, 6, 3, 3};

    static bool ready_play_sound = false;

    if(place[player_id] == ON_GROUND) {
        place[player_id] = ON_SKY;
        Engine_Assign_Sprite(player_id, player_jump_sprites);
    }

    if(ready_play_sound == true) {
        //playSound("resources/audio/jump.wav", SDL_MIX_MAXVOLUME);
        ready_play_sound = false;
    }

    /* 
    *position[player_id].y += velocity[player_id].y;
    velocity[player_id].y += gravity * engine_scale * .8; // I put .8 here 
    if(*position[player_id].y >= (engine_height - 16 ) * engine_scale) {
        place[player_id] = ON_GROUND;
        *position[player_id].y = (engine_height - 16) * engine_scale;
        velocity[player_id].y = -8 * engine_scale;
        ready_play_sound = true;
    }
 */

    if(frm >= 60) {
        frm = 0;
    }
    else {
        frm++;
    }

    if(frm % 6 == 0) {
        if(frm < 30) {
            *position[player_id].y -= height[frm/6] * engine_scale;
        }
        else{
            *position[player_id].y += height[frm/6 - 5] * engine_scale;
        }
    }

    if(*position[player_id].y >= (engine_height - 16 ) * engine_scale) {
        place[player_id] = ON_GROUND;
        action[player_id] = IDLE;
        *position[player_id].y = (engine_height - 16) * engine_scale;
    }
}

void
Player_Jump_Left(int player_id)
{
    Player_Move(player_id);
    Player_Jump(player_id);
}


void
Player_Jump_Right(int player_id)
{
    Player_Move(player_id);
    Player_Jump(player_id);
}


void
Player_Stop(int player_id)
{
    Engine_Sprite_Stop_triger(&sprite[player_id]);
}


void
Player_Idle(int player_id)
{
    Engine_Assign_Sprite(player_id, player_idle_sprites);

    Engine_Update_Sprite(&sprite[player_id]);
}
