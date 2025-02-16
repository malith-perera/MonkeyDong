#include "component.h"

New_Component(Place, place);
New_Component(Action, action);
New_Component(Rotation, rotation);

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
