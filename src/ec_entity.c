#include "ec_entity.h"

#define MAX_ENTITY 5000

Entity new_entity ()
{
    static Entity i = 0;

    if (i >= MAX_ENTITY) i = 0;

    return i++;
}
