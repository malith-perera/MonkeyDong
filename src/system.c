#include "system.h"

void
System_Player_Stone_Collission()
{
    int stoneSpriteId, playerSpriteId;
    static bool collied = false;
    static int test = 0;

    for (int player_id = 0; player_id < player->n; player_id++) {
        playerSpriteId = playerSprite.I + player_id; 

        for (int stone_id = 0; stone_id < stone->n; stone_id++) {
            stoneSpriteId = stoneSprite.I + stone_id;

            if (Engine_AABB_Collition (sprite[playerSpriteId].dst, sprite[stoneSpriteId].dst, 12, 12) == true && collied == false) {
                printf ("score %d\n", test++);
                collied = true;
            }
            else if(Engine_AABB_Collition (sprite[playerSpriteId].dst, sprite[stoneSpriteId].dst, 12, 12) == false && collied == true) {
                collied = false;
            }
        }
    }
}


void
System_Toggle_Player_And_Arrow()
{
    for (int player_id = 0; player_id < player->n; player_id++) {
        
    }
}


void
System_Render()
{

    // Render players
    for(int player_id = 0; player_id < player->n; player_id++) {
        Engine_Render(&sprite[playerSprite.I + player_id], renderer);
    }

    // Render arrows
    for(int i = 0; i < arrow->n; i++) {
        if (arrow_rotation) {}
    }

    // Render
    for(int i = 0; i < monkey->n; i++) {
    }

    for(int i = 0; i < stone->n; i++) {
    }

}
