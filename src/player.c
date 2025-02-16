#include "player.h"

Add(player, Place);

// New ECS
Entity *player;
EntityComponent playerPlace;
EntityComponent playerAction;
EntityComponent playerSprite;
EntityComponent playerPosition;
EntityComponent playerVelocity;

EntCom player_Place;

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
            0, 0,                 // src_x, src_y                
            16, 16,               // src_w, src_h                
            1,                    // scale                       
            1, 6,                 // nRows, nColumns             
            6, 6);                // nSprites, sprites per second

    player_move_sprites = Engine_New_Sprite(
            spritesheet,                     
            0, 16,                           
            16, 16,                          
            1,                               
            1, 6,                            
            6, 6);                           

    player_jump_sprites = Engine_New_Sprite(
            spritesheet,
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
    Engine_Init(player, entity_id);

    Engine_Assign_Sprite(&sprite[playerSpriteId], player_idle_sprites);
    
    /* entity_id, pos_x, pos_y, vel_x, vel_y, initial_scale */
    Engine_New_Entity_Init(player, entity_id, pos_x, pos_y, vel_x, vel_y, scale);


    action[playerAction + entity_id] = IDLE;
    place[playerPlace + entity_id] = ON_GROUND;
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
    int entity_id = 0;
    int playerActionId = playerAction + entity_id;
    int playerPlaceId = playerPlace + entity_id;
    int playerSpriteId = playerSprite + entity_id;
    int playerPositionId = playerPosition + entity_id;

    /* check key presses */
    if(*player_move_right == 1 && *player_jump == 1) { // jump right
        action[playerActionId] = JUMP_RIGHT;
    } 
    else if(*player_move_right == 1) { // move right
        action[playerActionId] = MOVE_RIGHT;
    }

    if(*player_move_left == 1 && *player_jump == 1) { // jump left
        action[playerActionId] = JUMP_LEFT;
    } 
    else if(*player_move_left == 1) { // move left key pressed 
        action[playerActionId] = MOVE_LEFT;
    }

    if(*player_jump == 1 && *player_move_left != 1 && *player_move_right != 1) { // jump up 
        action[playerActionId] = JUMP;
    }

    if(!(*player_move_right || *player_move_left || *player_jump)) {
        action[playerActionId] = IDLE;
    }

    for(int player_id = 0; player_id < player->n; player_id++)
    {
        playerPlaceId = playerPlace + player_id;
        playerActionId = playerAction + player_id;
        playerPositionId = playerPosition + player_id;

        if(action[playerActionId] == IDLE && (action[playerActionId] == TURN_LEFT || action[playerActionId] == TURN_RIGHT || action[playerActionId] == TURN)) {
            //printf("%d\n", players.M);
        }
        else {
            if(action[playerActionId] == JUMP || place[playerPlaceId] == ON_SKY) {
                Player_Jump(player_id);
            }

            if(action[playerActionId] == JUMP_LEFT || place[playerPlaceId] == ON_SKY) {
                Player_Jump_Left(player_id);
            }

            if(action[playerActionId] == JUMP_RIGHT || place[playerPlaceId] == ON_SKY) {
                Player_Jump_Right(player_id);
            }

            if(action[playerActionId] == MOVE_RIGHT || action[playerActionId] == MOVE_LEFT) {
                Player_Move(player_id);
            }
        
            if(action[playerActionId] == IDLE) {
                Player_Idle(player_id);
            }

            sprite[playerSpriteId].dst.x = position[playerPositionId].x;
            sprite[playerSpriteId].dst.y = position[playerPositionId].y;

            Engine_Triger_Sprite(&sprite[playerSpriteId], &triger4);
        }
    }
}


void
Player_Move(int player_id)
{
    const int playerPlaceId = playerPlace + player_id;
    const int playerActionId = playerAction + player_id;
    const int playerSpriteId = playerSprite + player_id;
    const int playerPositionId = playerPosition + player_id;
    const int playerVelocityId = playerVelocity + player_id;

    if(place[playerPlaceId] == ON_GROUND) {
        Engine_Assign_Sprite(&sprite[playerSpriteId], player_move_sprites);
    }
    else {
        Engine_Assign_Sprite(&sprite[playerSpriteId], player_jump_sprites);
    }

    if (action[playerActionId] == MOVE_RIGHT || action[playerActionId] == JUMP_RIGHT) {
        position[playerPositionId].x += velocity[playerVelocityId].x;
        if(position[playerPositionId].x > (engine_width - 16) * engine_scale) {
            position[playerPositionId].x = (engine_width - 16) * engine_scale; 
        } 
    }
    else if (action[playerActionId] == MOVE_LEFT || action[playerActionId] == JUMP_LEFT) {
        position[playerPositionId].x -= velocity[playerVelocityId].x;
        if (position[playerPositionId].x < 0) {
            position[playerPositionId].x = 0;
        }
    }
}

void
Player_Jump(int player_id)
{
    const int playerPlaceId = playerPlace + player_id;
    const int playerActionId = playerAction + player_id;
    const int playerSpriteId = playerSprite + player_id;
    const int playerPositionId = playerPosition + player_id;

    static int frm = 0;
    int height[5] = {10, 8, 6, 3, 3};

    static bool ready_play_sound = false;

    if(place[playerPlaceId] == ON_GROUND) {
        place[playerPlaceId] = ON_SKY;
        Engine_Assign_Sprite(&sprite[playerSpriteId], player_jump_sprites);
    }

    if(ready_play_sound == true) {
        ready_play_sound = false;
    }

    if(frm >= 60) {
        frm = 0;
    }
    else {
        frm++;
    }

    if(frm % 6 == 0) {
        if(frm < 30) {
            position[playerPositionId].y -= height[frm/6] * engine_scale;
        }
        else{
            position[playerPositionId].y += height[frm/6 - 5] * engine_scale;
        }
    }

    if(position[playerPositionId].y >= (engine_height - 16 ) * engine_scale) {
        place[playerPlaceId] = ON_GROUND;
        action[playerActionId] = IDLE;
        position[playerPositionId].y = (engine_height - 16) * engine_scale;
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
    const int playerSpriteId = playerSprite + player_id;

    Engine_Assign_Sprite(&sprite[playerSpriteId], player_jump_sprites);
}
