#include <stdio.h>
#include <stdlib.h>
#include "ecs.h"


Entity
New_Entity(int n, int M)
{
    Entity entity;
    entity.n = n;
    entity.M = M;

    return entity;
}
