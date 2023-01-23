#include <stdio.h>
#include "ec_ecs.h"

static Entity *ec_entity_list;


/*--------*/
/* Entity */
/*--------*/

void
ECS_Init ()
{
    ec_entity_list = (Entity *) malloc (sizeof (Entity)); 
    ec_entity_list->max = 0;
    ec_entity_list->active = true;
    ec_entity_list->next = NULL;

    ec_entity_list->id = (EntityId *) malloc (sizeof (EntityId));
    ec_entity_list->id->i = 0;
    ec_entity_list->id->n = 0;
    ec_entity_list->id->next = NULL;

    ec_entity_total = 0;
}


Entity *
Init_Entity (Entity *entity, int n, int max)
{
    if (entity != NULL) // Existing entity
    {

    }
    else // New entity
    {
        EntityId *entity_id = (EntityId *) malloc (sizeof (EntityId));
        entity_id->i = ec_entity_list->id->i;
        entity_id->n = n;
        entity_id->next = NULL;

        entity = (Entity *) malloc (sizeof (Entity)); 
        entity->id = entity_id;
        entity->max = max;
        entity->active = true;
        entity->next = NULL;
    }

    // add entity to ec_entity_list
    entity->next = ec_entity_list->next;
    ec_entity_list->next = entity;

    if (ec_entity_list->id->next != NULL)
    {
    }
    else
    {
    }
    
    ec_entity_list->id->i += max;
    ec_entity_list->id->n += n; // total number of entities in use
    ec_entity_list->max += max; // total number of entities
    ec_entity_total += max; // Update the total entities

    return entity;
}


void
Entity_Reset_Max (Entity *entity, int max)
{
    Entity *current_entity = ec_entity_list;
    
    int entity_max = 0;

    while (current_entity != NULL)
    {
        foreach_entity(current_entity, entity_id)
        {
            entity_max += current_entity->max;
        }

        if (entity_max <= ec_entity_total)
        {
            entity->max = max;
        }
        else
        {
            printf ("Warning: Allocated entity space exeeded\n");
        }
    }

    entity->max = max;
}


void
Entity_Reset_All ()
{
    Entity *current_entity = ec_entity_list;

    while (current_entity != NULL)
    {
        foreach_entity(current_entity, entity_id)
        {
            current_entity->id->i = 0;
            current_entity->id->n = 0;
        }
        current_entity->max = 0;
        current_entity->active = false;

        current_entity = current_entity->next;
    }
}


void
Entity_Drop (Entity *entity)
{
    foreach_entity(entity, entity_id)
    {
        entity->id->i = 0;
        entity->id->n = 0;
        active_entity[entity_id] = false;
    }

    entity->active = false;
}


void
Entity_Repack ()
{
    /* Mark inactive id */
    Entity *current_entity = ec_entity_list;

    while (current_entity != NULL)
    {
        foreach_entity(current_entity, entity_id)
        {
            if (current_entity->active == false)
            {
                active_entity[entity_id] = false;
            }
        }

        current_entity = current_entity->next;
    }

    current_entity = ec_entity_list;

    while (current_entity != NULL)
    {

        current_entity = current_entity->next;
    }
}


void
EC_Entity_Clean()
{
    Entity *current_entity = ec_entity_list; 
    Entity *temp_entity; 

    EntityId *current_entity_id;
    EntityId *temp_entity_id;

    while (current_entity != NULL)
    {
        current_entity_id = current_entity->id;
        
        while (current_entity_id != NULL)
        {
            temp_entity_id = current_entity_id;
            current_entity_id = current_entity_id->next;

            free (temp_entity_id);
        }

        temp_entity = current_entity;
        current_entity = current_entity->next;
        free (temp_entity);
    }

    free (active_entity);
    active_entity = NULL;
}


void
EC_Entity_Change_Id (int i, int j)
{
    Entity_Change(active_entity, i, j);
}


/*-----------*/
/* Component */
/*-----------*/

void
EC_Components(void (*Entity_Change_Id_Func)(int, int))
{
    if (active_entity == NULL)
        active_entity = New_Component (ActiveEntity);

    for (int i = 0; i < ec_entity_total; i++)
    {
        active_entity[i] = false;
    }

    Entity *current_entity = ec_entity_list;

    while (current_entity != NULL)
    {
        foreach_entity(current_entity, entity_id)
        {
            active_entity[entity_id] = true;
        }

        current_entity = current_entity->next;
    }

    if (EC_Entity_Change_Id_Func != NULL)
        EC_Entity_Change_Id_Func = Entity_Change_Id_Func;
}


void
EC_Free_Components ()
{
    free(active_entity);
}


Entity *
EC_Get_Entity_List ()
{
    return ec_entity_list;
}
