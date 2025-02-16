#include "stone.h"

Entity *stone;
EntityComponent(stone, Place);
EntityComponent(stone, Action);
EntityComponent(stone, Sprite);
EntityComponent(stone, Position);
EntityComponent(stone, Velocity);

EntityList *stone_list;

SpriteImages *stone_sprites;

void
Stone_Init_Spritesheet(char *image)
{
    SpriteSheet *spritesheet = Engine_Create_Spritesheet(image, renderer);

    /* image , renderer, src_x, src_y, src_w, src_h, scale, nRows, nColumns, nSprite images in the sprite sheet, sprites per second */
    stone_sprites  = Engine_New_Sprite(
            spritesheet,   // sprite image                    
            0, 0,          // src_x, src_y                             
            4, 4,          // src_w, src_h                         
            1,             // scale                                    
            1, 8,          // nRows, nColumns                      
            8, 4);         // nSprites, sprites per second     
}

void
Stone_Init (
    int entity_id,
    int pos_x, int pos_y,
    int vel_x, int vel_y,
    float scale
)
{
    Engine_Init(stone, entity_id);

    /* int entity_id, SpriteImage* sprite images, float scale */
    Engine_Assign_Sprite(&sprite[stoneSpriteId], stone_sprites);

    /* entity_id, pos_x, pos_y, vel_x, vel_y, initial_scale */
    Engine_New_Entity_Init(stone, entity_id, pos_x, pos_y, vel_x, vel_y, scale);
}


void
Stone_Free ()
{    
    free (stone_sprites);
}

void
Stone_Update ()
{
    int stoneRotationId, stoneLastRotationId, stoneSpriteId, stonePositionId; 

    for(int stone_id = 0; stone_id < stone->n; stone_id++) {
        stoneSpriteId = stoneSprite.I + stone_id;
        stonePositionId = stonePosition.I + stone_id;

        Engine_Triger_Sprite(&sprite[stoneSpriteId], &triger4);

        sprite[stoneSpriteId].dst.x = position[stonePositionId].x;
        sprite[stoneSpriteId].dst.y = position[stonePositionId].y;

        Engine_Render(&sprite[stoneSpriteId], renderer);

        Stone_Move(stone_id);
    }
}

void
Stone_Render ()
{

}

void
Stone_Move (int stone_id)
{
    const int stonePositionId = stonePosition.I + stone_id;
    const int stoneVelocityId = stoneVelocity.I + stone_id;

    if (player_move_right) {
        position[stonePositionId].x += velocity[stoneVelocityId].x;
        position[stonePositionId].y += velocity[stoneVelocityId].y;
    }
    else {
        position[stonePositionId].x += velocity[stoneVelocityId].x;
        position[stonePositionId].y += velocity[stoneVelocityId].y;
    }


    if (position[stonePositionId].x <= 0 || position[stonePositionId].x >= engine_width * engine_scale)
    {
        velocity[stoneVelocityId].x = -1 * velocity[stoneVelocityId].x; 
    }

    if (position[stonePositionId].y <= 0 || position[stonePositionId].y >= engine_height * engine_scale)
    {
        velocity[stoneVelocityId].y = -1 * velocity[stoneVelocityId].y; 
    }
}
