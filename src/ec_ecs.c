#include "ec_ecs.h"


static int entity_i;


int
Entity_Get ()
{
    return entity_i;
}


Entity *
Entity_Request (Entity *entity, int n, int m)
{
    EntityRequest *entity_request = (EntityRequest *) malloc (sizeof (EntityRequest));

    entity_request->next = NULL;
    
    if (entity == NULL)
    {
        entity = (Entity *) malloc (sizeof (Entity));
        entity->n = n;
        entity->m = m;
        entity->next = NULL;

        entity_request->entity = entity;
        entity_request->type = ENTITY_NEW;
    }
    else
    {
        entity_request->n = n;
        entity_request->m = m;
        entity_request->entity = entity;

        if (m == 0)
        {
            entity_request->type = ENTITY_DROP; // drop but do not delete
        }
        if (m < 0)
        {
            entity_request->type = ENTITY_DELETE; // delete entity
        }
        else
        {
            Entity *current_entity = entity;
            int max = 0;

            while (current_entity != NULL)
            {
                max += current_entity->m;
                current_entity = current_entity->next;
            }

            if (entity->m == max)
            {
                entity_request->type = ENTITY_UNCHANGED; // same amount of entities requested
            }
            else if (entity->m > max)
            {
                entity_request->type = ENTITY_LESS; // less than existing entities
            }
            else
            {
                entity_request->type = ENTITY_MORE; // more than existing entities
            }
        }
    }

    // add new request to entity_request_list
    if (entity_request_list != NULL)
    {
        entity_request_list_last->next = entity_request;
        entity_request_list_last = entity_request;
    }
    else
    {
        entity_request_list = entity_request;
        entity_request_list_last = entity_request;
    }

    return entity;
}


void
Entity_List_Free ()
{
    Entity *temp_entity, *current_entity;

    current_entity = entity_list;

    while (current_entity != NULL)
    {
        temp_entity = current_entity;
        if (temp_entity)
        {
            free (temp_entity);
            temp_entity = NULL;
        }
        current_entity = current_entity->next;
        free (temp_entity);
    }
}


void
Entity_Request_List_Free ()
{
    EntityRequest *temp_request, *current_request;

    current_request = entity_request_list;

    while (current_request != NULL)
    {
        temp_request = current_request;
        if (temp_request->entity)
        {
            free (temp_request->entity);
            temp_request->entity = NULL;
        }
        current_request = current_request->next;
        free (temp_request);
        temp_request = NULL;
    }
}


void
Entity_Free ()
{
    Entity_List_Free ();
    Entity_Request_List_Free ();
}


void
Component_Create ()
{
}


// below functions only use for testing purpose
EntityRequest *
Get_Request_List ()
{
    return entity_request_list;
}

