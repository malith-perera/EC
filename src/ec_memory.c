#include "ec_memory.h"

/* User to free ec_memory one at a time with EC_Memory_Free_Unlock_One function
 * to track current position */

ECMemory* free_one = NULL;

/* Free an ec_memory_variable */
void
EC_Memory_Var_Free (ECMemory *ec_memory_var)
{
    if (ec_memory_var != ec_memory)
    {
        if (ec_memory_var->next != NULL)
        {
            ec_memory_var->previous->next = ec_memory_var->next;
        }
        else
        {
            ec_memory_var->previous->next = NULL;
        }

    }
    else
    {
        if (ec_memory_var->next != NULL)
        {
            ec_memory = ec_memory->next;
        }
        else
        {
            ec_memory = NULL;
        }
    }

    free (ec_memory_var);
}


/* Clean all ec_memory at the end of the program */
void
EC_Clean ()
{
    ECMemory *current;
    ECMemory *temp;

    current = ec_memory;

    while (current != NULL)
    {
        temp = current->next;
        if (current->var != NULL)
            current->Free_Var_Func (current->var);
        EC_Memory_Var_Free (current);
        current = NULL;
        current = temp;
    }

    ec_memory = NULL;
}


/* Push new_ec_memory to ec_memory */
void
EC_Memory_Push (ECMemory* ec_memory_new)
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
        ec_memory->next = NULL;
    }
}


/* Free all memory if lock == EC_UNLOCK in ec_memory var */
void
EC_Memory_Free_Unlocked ()
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
                current->Free_Var_Func (current->var);
            }

            temp = current;
            current = current->next;
            free (temp);
            temp = NULL;

            break;

        }

        current = current->next;
    }

    free_one = ec_memory; // reset free_one to ec_memory. free_one use to track the var when free one by one in Free_Unlock_One function.
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
                current->Free_Var_Func (current->var);
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
