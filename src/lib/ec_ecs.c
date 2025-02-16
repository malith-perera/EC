#include "ec_ecs.h"

EC_VAR_C(Entity);
EC_LIST_C(Entity)

EC_VAR_C(EntCom);
EC_LIST_C(EntCom)

EntityList *ec_ecs_entity_list = NULL;


Entity *
New_Entity(Entity *entity)
{
    entity = Entity_New(); // This function is created by EC
    entity->n = 1;
    entity->M = 1;

    //Entity_Append(ec_ecs_entity_list, entity);

    return entity;
}


EntityList *
New_Entity_List(EntityList *entity_list, int n, int M)
{
    Entity *entity = Entity_New(); // This function is created by EC
    entity->n = n;
    entity->M = M;

    //Entity_Append(entity_list, entity);

    return entity_list;
}
