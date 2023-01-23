#ifndef EC_ECS_H
#define EC_ECS_H

#include "ec.h"


typedef struct EntityId {
    int i;                      /* Entity begining id */
    int n;                      /* Number of entities in use */
    struct EntityId *next;      /* Next EntityId */
} EntityId;


typedef struct Entity{
    EntityId *id;               /* List of entity id */
    int max;                    /* Maximum number of entities */
    bool active;                /* Whether entity active */
    struct Entity *next;        /* Next entity */
} Entity;


Entity *ec_entity_list;


#define for_entity_ids(entity_ids, entity_id)                       \
    for (int entity_id = entity_ids->i;                             \
        entity_id < entity_ids->i + entity_ids->n; entity_id++)


#define for_entity(entity, entity_ids)                              \
    for (EntityId *entity_ids = entity->id;                         \
            entity_ids != NULL; entity_ids = entity_ids->next)


#define foreach_entity(entity, entity_id)                                   \
    int entity_id = entity->id->i;                                          \
    for (EntityId *entity_ids = entity->id;                                 \
        entity_ids != NULL;                                                 \
        entity_ids = (entity_id++ < (entity_ids->i + entity_ids->n)) ?      \
        entity_ids : (entity_ids->next != NULL ? entity_ids->next : NULL))


#define Realloc(TYPE, ptr, size)                                    \
    TYPE * EC_CONCAT2(TYPE, _old_ptr);                              \
    TYPE * EC_CONCAT2(TYPE, _new_ptr);                              \
    memcpy (EC_CONCAT2(TYPE, _old_ptr), ptr, size);                 \
    EC_CONCAT2(TYPE, _new_ptr) = realloc(ptr, sizeof(TYPE) * size); \
                                                                    \
    if (EC_CONCAT2(TYPE, _new_ptr) == NULL)                         \
        ptr = EC_CONCAT2(TYPE, _old_ptr);                           \
    else                                                            \
        ptr = EC_CONCAT2(TYPE, _new_ptr);


#define New_Component(TYPE) (TYPE *) malloc (sizeof (TYPE) * ec_entity_list->max)
#define Entity_Change(component, i, j) component[i] = component[j]


void
ECS_Init ();


Entity *
Init_Entity (Entity *entity, int n, int max);


void
EC_Entity_Clean();


Entity *
EC_Get_Entity_List ();


typedef bool ActiveEntity;


void (*EC_Entity_Change_Id_Func)(int, int);


void
EC_Components(void (*Entity_Change_Id_Func)(int, int));


void
EC_Entity_Change_Id (int i, int j);


/*-----------*/
/* Component */
/*-----------*/

ActiveEntity *active_entity; 


#endif // EC_ECS_H