#include "ground.h"


int far_ground_id, back_ground_id, fore_ground_id;

SpriteImages ground_sprite_sprites[3];

SpriteImages *far_ground_sprites;
SpriteImages *back_ground_sprites;
SpriteImages *fore_ground_sprites;


void
Ground_Init()
{
    SpriteSheet *far = Engine_Create_Texture("resources/textures/far-buildings.png", renderer);
    SpriteSheet *back = Engine_Create_Texture("resources/textures/back-buildings.png", renderer);
    SpriteSheet *fore = Engine_Create_Texture("resources/textures/fore-ground.png", renderer);

    far_ground_sprites = Engine_New_Sprite(
            far, // sprite image
            0, 0,                                   // src_x, src_y
            160, 90,                                // src_w, src_h
            2,                                      // scale according to development size
            1, 1,                                   // nRows, nColumns
            1, 1);                                  // nSprites, sprites per second

    back_ground_sprites = Engine_New_Sprite(
            back,
            0, 0,
            320, 180,
            1,
            1, 1,
            1, 1);

    fore_ground_sprites = Engine_New_Sprite(
            fore,
            0, 0,
            320, 180,
            1,
            1, 1,
            1, 1);

    far_ground_id = 0;
    back_ground_id = 1;
    fore_ground_id = 2;

    //Engine_Assign_Sprite(&groundSprite[far_ground_id], far_ground_sprites);
    //Engine_Assign_Sprite(&groundSprite[back_ground_id], back_ground_sprites);
    //Engine_Assign_Sprite(&groundSprite[fore_ground_id], fore_ground_sprites);

    /* entity_id, pos_x, pos_y, vel_x, vel_y, initial_scale */
    //Engine_New_Entity_Init(ground, far_ground_id, 0, 0, 0, 0, 1);
    //Engine_New_Entity_Init(ground, back_ground_id, 0, 0, 0, 0, 1);
    //Engine_New_Entity_Init(ground, fore_ground_id, 0, 0, 0, 0, 1);
}


void
Ground_Update()
{
    for(int ground_id = 0; ground_id < ground.n; ground_id++) {
        Engine_Ground_Update(ground_id);
    }
}


void
Ground_Free()
{
    free(far_ground_sprites);
    free(back_ground_sprites);
    free(fore_ground_sprites);
}
