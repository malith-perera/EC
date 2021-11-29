#include "ec_memory.h"


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


void
EC_Memory_Append (ECMemory* ec_memory_new)
{
    if (ec_memory != NULL)
    {
        ec_memory_new->next = ec_memory;
        ec_memory = ec_memory_new;
    }
    else
    {
        ec_memory = ec_memory_new;
    }
}


/* Delete memory if lock == false in ec_memory variable */

void
EC_Memory_Free_Unlock ()
{
    ECMemory *current;
    ECMemory *temp;

    current = ec_memory;

    while (current != NULL)
    {
        if (current->lock == false)
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

    ec_memory = NULL;
}
