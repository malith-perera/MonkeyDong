#include "system.h"

void
System_Player_Nebula_Collission()
{
    for (int player_id = players.I; player_id < players.n; player_id++) {
        for (int nebula_id = nebulae.I; nebula_id < nebulae.n; nebula_id++) {
            if (Engine_AABB_Collition (sprite[player_id].dst, sprite[nebula_id].dst, 12, 12)) {
                printf ("collided\n");
            }
        }
    }
}


void
System_Toggle_Player_And_Arrow()
{
    for (int player_id = players.I; player_id < players.n; player_id++) {
        
    }
}
