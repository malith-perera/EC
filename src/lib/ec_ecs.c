#include "ec_ecs.h"

EC_VAR_C(Entity)
EC_LIST_C(Entity)

EntityList *ec_ecs_entity_list = NULL;

void
Init_ECS()
{
    ec_ecs_entity_list = Entity_List();
}


Entity *
New_Entity(int n, int M)
{
    Entity *entity = Entity_New();
    entity->n = n;
    entity->M = M;

    Entity_Append(ec_ecs_entity_list, entity);

    return entity;
}


void
Free_Entity_List()
{
    EntityListVar *current;
    EntityListVar *temp;
    
    current = ec_ecs_entity_list->first;

    while(current == NULL) {
        temp = current;
        current = current->next;
        free(temp->var);
        free(temp);
    }
}

void
Free_ECS()
{
    Free_Entity_List();
}
