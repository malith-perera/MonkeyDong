#include "component.h"

Engine_Components();

Component_Array(Place, place);
Component_Array(Action, action);
Component_Array(Rotation, rotation);


void
Free_Components()
{
    if(place != NULL) {
        free(place);
        place = NULL;
    }

    if(action != NULL) {
        free(action);
        action = NULL;
    }

    Engine_Component_Free();
}
