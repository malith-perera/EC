#include <stdio.h>
#include "ec_ecs.h"


/*--------*/
/* Entity */
/*--------*/

void
ECS_Init ()
{
    ec_entity_list = (Entity *) malloc (sizeof (Entity)); 
    ec_entity_list->next = NULL;

    ec_entity_list->id = (EntityId *) malloc (sizeof (EntityId));
    ec_entity_list->id->i = 0;
    ec_entity_list->id->n = 0;
    ec_entity_list->id->max = 0;
    ec_entity_list->id->next = NULL;
}


EntityId *
Entity_Get_Id (Entity *entity, int n, int max)
{
    EntityId *entity_id;

    int required =  max - entity->id->max;

    if (required > 0) // required more space than exist
    {
        if (ec_entity_list->id->next != NULL) // more than one entity id exist in ec_entity_list
        {
            /* EntityId *current_id = ec_entity_list->id; */
            /* EntityId *previous_id = ec_entity_list->id; */

            /* EntityId *match_id = NULL; */

            /* while (current_id != NULL) */
            /* { */
            /*     if (current_id->max == required) */
            /*     { */
            /*         previous_id->next = current_id->next; */
            /*         return current_id; */
            /*     } */
            /*     else if (current_id->max >= required) */
            /*     { */
            /*         match_id = current_id; */
            /*     } */

            /*     previous_id = current_id; */
            /*     current_id = current_id->next; */
            /* } */

            /* if (match_id != NULL) */
            /* { */
                
            /* } */
            /* else */
            /* { */
            /* } */
        }
        else // only one entity id exist in ec_entity_list
        {
            entity_id = (EntityId *) malloc (sizeof (EntityId));
            entity_id->i = ec_entity_list->id->i;
            entity_id->n = n;
            entity_id->max = max;
            entity_id->next = NULL;

            ec_entity_list->id->i += max;
        }
    } 
    else if (required < 0) // required less space than exist
    {
    }
    else
    {
    }

    return entity_id;
}


Entity *
Init_Entity (Entity *entity, int n, int max)
{
    EntityId *entity_id;

    if (entity != NULL) // Entity exist already
    {
        entity_id = Entity_Get_Id (entity, n, max);
    }
    else // New entity
    {
        EntityId *entity_id = (EntityId *) malloc (sizeof (EntityId));
        entity_id->i = ec_entity_list->id->i;
        entity_id->n = n;
        entity_id->max = max;
        entity_id->next = NULL;

        entity = (Entity *) malloc (sizeof (Entity)); 
        entity->id = entity_id;
        entity->next = NULL;
    }

    if (ec_entity_list->id->next != NULL)
    {
    }
    else
    {
        ec_entity_list->id->i += max;
        ec_entity_list->id->n += n; // total number of entities in use
    }

    ec_entity_total += max; // total number of entities

    // add entity to ec_entity_list
    entity->next = ec_entity_list->next;
    ec_entity_list->next = entity;
    
    return entity;
}


void
Entity_Reset_Components (Component *component)
{
}


void
Entity_Drop (Entity *entity)
{
    Entity *current_entity = ec_entity_list;

    while (current_entity != NULL)
    {
        if (current_entity == entity)
        {
            if (ec_entity_droped_list == NULL)
            {
                ec_entity_droped_list = current_entity;
            }
            else
            {
               //**here  
            }
        }
        else
        {
        }

        current_entity = current_entity->next;
    }
}


void
EC_Entity_Clean()
{
    /* Entity *current_entity = ec_entity_list; */ 
    /* Entity *temp_entity; */ 

    /* EntityId *current_entity_id; */
    /* EntityId *temp_entity_id; */

    /* while (current_entity != NULL) */
    /* { */
    /*     current_entity_id = current_entity->id; */
        
    /*     while (current_entity_id != NULL) */
    /*     { */
    /*         temp_entity_id = current_entity_id; */
    /*         current_entity_id = current_entity_id->next; */

    /*         free (temp_entity_id); */
    /*     } */

    /*     temp_entity = current_entity; */
    /*     current_entity = current_entity->next; */
    /*     free (temp_entity); */
    /* } */

    /* free (active_entity); */
}


void
EC_Entity_Change_Id (int i, int j)
{
    /* Entity_Change(active_entity, i, j); */
}


/*-----------*/
/* Component */
/*-----------*/


void
EC_Components(void (*Entity_Change_Id_Func)(int, int))
{
    /* if (active_entity == NULL) */
    /*     active_entity = New_Component (ActiveEntity); */

    /* for (int i = 0; i < ec_entity_total; i++) */
    /* { */
    /*     active_entity[i] = false; */
    /* } */

    /* Entity *current_entity = ec_entity_list; */

    /* while (current_entity != NULL) */
    /* { */
    /*     foreach_entity(current_entity, entity_id) */
    /*     { */
    /*         active_entity[entity_id] = true; */
    /*     } */

    /*     current_entity = current_entity->next; */
    /* } */

    /* if (EC_Entity_Change_Id_Func != NULL) */
    /*     EC_Entity_Change_Id_Func = Entity_Change_Id_Func; */
}


void
EC_Free_Components ()
{
    /* free(active_entity); */
}


Entity *
EC_Get_Entity_List ()
{
    return ec_entity_list;
}
