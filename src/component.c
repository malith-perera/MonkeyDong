#include "component.h"

Place* place;
Action* action;
int* player_arrow_id;

void
Create_Components()
{
    place = (Place*) malloc(sizeof(Place) * nEntity);
    action = (Action*) malloc(sizeof(Action) * nEntity);
    player_arrow_id = (int*) malloc(sizeof(int) * 2);
}

void
Assign_Components() 
{
    // Assign components
    for(int i = 0; i < players.M; i++) {
        player_arrow_id[i] = arrow.I + i; // created in component.c
    }
}

void
Free_Components()
{
    free(place);
    free(action);
    free(player_arrow_id);
}
