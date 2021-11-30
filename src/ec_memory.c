#include "ec_memory.h"

/* User to free ec_memory one at a time with EC_Memory_Free_Unlock_One function
 * to track current position */

ECMemory* free_one = NULL;


/* Clean all ec_memory at the end of the program */
void
EC_Clean ()
{
    ECMemory *current;
    ECMemory *temp;

    current = ec_memory;

    while (current != NULL)
    {
        if (current->var != NULL)
        {
            current->Free_Func (current->var);
        }

        temp = current;
        current = current->next;
        free (temp);
        temp = NULL;
    }

    ec_memory = NULL;
}


/* Append new_ec_memory to ec_memory */
void
EC_Memory_Append (ECMemory* ec_memory_new)
{
    if (ec_memory != NULL)
    {
        ec_memory_new->next = ec_memory;
        ec_memory->previous = ec_memory_new;
        ec_memory = ec_memory_new;
    }
    else
    {
        ec_memory = ec_memory_new;
        ec_memory->previous = NULL;
    }
}


/* Delete memory if lock == EC_UNLOCK in ec_memory lock variable */
void
EC_Memory_Free_Unlock ()
{
    ECMemory *current;
    ECMemory *temp;

    current = ec_memory;

    while (current != NULL)
    {
        if (current->lock == EC_UNLOCK)
        {
            if (current->var != NULL)
            {
                if (current->type == EC_VAR_TYPE)
                {
                    current->Free_Var_Func (current->var);
                }
                else if (current->type == EC_ARRAY_TYPE)
                {

                }
                else if (current->type == EC_LIST_TYPE)
                {

                }
                else if (current->type == EC_QUEUE_TYPE)
                {

                }
                else if (current->type == EC_STACK_TYPE)
                {

                }
                else
                {

                }

                /*current->Free_Var_Func();*/
                current->Free_Func (current->var);
            }

            temp = current;
            current = current->next;
            current->previous->next = current->next;
            free (temp);
            temp = NULL;
        }
    }
}


/* Free ec_memory if lock == EC_UNLOCK but only one at a time */
void
EC_Memory_Free_Unlock_One ()
{
    ECMemory *current;
    ECMemory *temp;

    if (free_one != NULL)
    {
        current = free_one;         // ECMemory* free_one; global variable defined above
    }
    else
    {
        current = ec_memory;
    }

    while (current != NULL)
    {
        if (current->lock == EC_UNLOCK)
        {
            if (current->var != NULL)
            {
                current->Free_Func (current->var);
            }

            temp = current;
            current = current->next;
            free (temp);
            temp = NULL;

            free_one = current;
            break;
        }
    }
}


void
EC_Memory_Free_EC_Memory (ECMemory* free_ec_memory)
{
    ECMemory *current;
    ECMemory *temp;

    current = ec_memory;

    while (current != NULL)
    {
        if (current->lock == EC_UNLOCK)
        {
            if (current->var != NULL)
            {
                current->Free_Func (current->var);
            }

            temp = current;
            current = current->next;
            free (temp);
            temp = NULL;
        }
    }
}
