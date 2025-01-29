#include "arrow.h"

ECEntity arrow;

bool *arrow_turn_left; // key binding
bool *arrow_turn_right; // key binding

SpriteImages *arrow_sprite0;
SpriteImages *arrow_sprite15;
SpriteImages *arrow_sprite30;
SpriteImages *arrow_sprite45;
SpriteImages *arrow_sprite60;
SpriteImages *arrow_sprite75;
SpriteImages *arrow_sprite90;

int rotation = 0;

void
Arrow_Rotate(int arrow_id);

void
Arrow_Init_Spritesheet(char *image) {
    SpriteSheet *spritesheet = Engine_Create_Spritesheet(image, renderer);

    /* image , renderer, src_x, src_y, src_w, src_h, scale, nRows, nColumns, nSprite images in the sprite sheet, sprites per second */
    arrow_sprite0 = Engine_New_Sprite(
            spritesheet,                    // sprite image                    
            renderer,                       // renderer                           
            0, 0,                           // src_x, src_y                             
            32, 32,                         // src_w, src_h                         
            .5,                             // scale                                    
            1, 2,                           // nRows, nColumns                      
            2, 2);                          // nSprites, sprites per second     

    arrow_sprite15 = Engine_New_Sprite(
            spritesheet,
            renderer,
            0, 32,
            32, 32,
            .5,
            1, 2,
            2, 2);

    arrow_sprite30 = Engine_New_Sprite(
            spritesheet,
            renderer,
            0, 64,
            32, 32,
            .5,
            1, 2,
            2, 2);

    arrow_sprite45 = Engine_New_Sprite(
            spritesheet,
            renderer,
            0, 96,
            32, 32,
            .5,
            1, 2,
            2, 2);

    arrow_sprite60 = Engine_New_Sprite(
            spritesheet,
            renderer,
            0, 128,
            32, 32,
            .5,
            1, 2,
            2, 2);

    arrow_sprite75 = Engine_New_Sprite(
            spritesheet,
            renderer,
            0, 160,
            32, 32,
            .5,
            1, 2,
            2, 2);

    arrow_sprite90 = Engine_New_Sprite(
            spritesheet,
            renderer,
            0, 192,
            32, 32,
            .5,
            1, 2,
            2, 2);
}

void
Arrow_Init(
    int entity_id,
    int pos_x, int pos_y,
    int vel_x, int vel_y,
    float scale
)
{

    /* int entity_id, SpriteImage* sprite images, float scale */
    Engine_Assign_Sprite(entity_id, arrow_sprite0);

    /* entity_id, pos_x, pos_y, vel_x, vel_y, initial_scale */
    Engine_Entity_Init(entity_id, pos_x, pos_y, vel_x, vel_y, 1);
}


void
Arrow_Free()
{
    free(arrow_sprite0);
    free(arrow_sprite15);
    free(arrow_sprite30);
    free(arrow_sprite45);
    free(arrow_sprite60);
    free(arrow_sprite75);
    free(arrow_sprite90);
}


void
Arrow_Update()
{
    for(int arrow_id = arrow.I; arrow_id < arrow.n; arrow_id++)
    {
        //Engine_Sprite_Simple_Triger(&triger8, &sprite[arrow_id]);
        /*Engine_Sprite_Triger(triger8, &sprite[arrow_id]);*/

        Arrow_Rotate(arrow_id);

        Engine_Update_Sprite(&sprite[arrow_id]);

        if(rotation < 0) {
            SDL_RenderTextureRotated(renderer, sprite[arrow_id].sprite_images->texture,
                &sprite[arrow_id].src, &sprite[arrow_id].dst,
                0, NULL,
                SDL_FLIP_HORIZONTAL);
        }
        else { 
            Engine_Render(arrow_id, renderer);
        }
    }
}


void
Arrow_Rotate(int arrow_id)
{
    static bool key_up_released = true;
    static bool key_down_released = true;
    SpriteImages **arrow_sprite = &arrow_sprite0;
    int angle = 0;
    static int last_rotation = 0;
    static int frame_count = 0; // count frames to detect key is pressing continuously
    int fc = 16; // start count after fc

    // check key presses

    if(*arrow_turn_left == true) {
        key_up_released = false;
        action[arrow_id] = TURN;
    }
    else if(*arrow_turn_right == true){
        key_down_released = false;
        action[arrow_id] = TURN;
    }
    else {
        action[arrow_id] = TURN;
    }

    if(*arrow_turn_left == true) {
        frame_count++;
        if(frame_count % fc == 0) {
            rotation -= 60;
            if(rotation < -90)
                rotation = -90;
        }
    }

    if(*arrow_turn_left == false && key_up_released == false) {
        if(frame_count < fc) {
            rotation -= 15;
            if(rotation < -90)
                rotation = -90;
            key_up_released = true;
        }
        frame_count = 0;
    }

    if(*arrow_turn_right == true) {
        frame_count++;
        if(frame_count % fc == 0) {
            rotation += 60;
            if(rotation > 90)
                rotation = 90;
        }
    }

    if(*arrow_turn_right == false && key_down_released == false) {
        if(frame_count < fc) {
            rotation += 15;
            if(rotation > 90)
                rotation = 90;
            key_down_released = true;
        }

        frame_count = 0;
    }

    angle = rotation;

    if(rotation < 0) {
        angle = rotation * -1;
    }

    switch(angle) {
        case 0:
            arrow_sprite = &arrow_sprite0;
            break;
        case 15:
            arrow_sprite = &arrow_sprite15;
            break;
        case 30:
            arrow_sprite = &arrow_sprite30;
            break;
        case 45:
            arrow_sprite = &arrow_sprite45;
            break;
        case 60:
            arrow_sprite = &arrow_sprite60;
            break;
        case 75:
            arrow_sprite = &arrow_sprite75;
            break;
        case 90:
            arrow_sprite = &arrow_sprite90;
            break;
        default:
            arrow_sprite = &arrow_sprite0;
            break;
    }

    if(rotation != last_rotation) {
        last_rotation = rotation;
        Engine_Assign_Sprite(arrow_id, *arrow_sprite);
    }
}
