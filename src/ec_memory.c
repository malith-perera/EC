#include "ec_memory.h"

#define DEBUG_EC_MEMORY 1

/* User to free ec_memory one at a time with EC_Memory_Free_Unlock_One function
 * to track current position */

ECMemory *free_one = NULL;

ECMemory *
EC_Memory_Create(ECType ec_type)                                   
{
    ECMemory *ec_memory_new = (ECMemory*) malloc (sizeof(ECMemory));

    EC_DEBUG_PRINT_ADR("Create: ec memory ", ec_memory_new);

    if (ec_memory_new == NULL)
    {
        EC_Error_Mem_Alloc (__FILE__, __LINE__);
        return NULL;
    }

    ec_memory_new->type = ec_type;
    ec_memory_new->lock = EC_LOCK;
    ec_memory_new->next = NULL;

    EC_Memory_Push (ec_memory_new);
}


/* Free an ec_memory variable */
void
EC_Memory_Var_Free (ECMemory *ec_mem)
{
    if (ec_mem != NULL) /* if ec_mem exist */
    {
        if (ec_mem != ec_memory) /* not the first ec_mem */
        {
            if (ec_mem->next != NULL && ec_mem->previous != NULL)
            {
                ec_mem->previous->next = ec_mem->next;
            }
            else if (ec_mem->previous != NULL)
            {
                ec_mem->previous->next = NULL;
            }
        }
        else /* first ec_mem */
        {
            if (ec_mem->next != NULL) /* not the only ec_mem exist */
            {
                ec_memory = ec_memory->next;
                ec_memory->previous = NULL;
            }
            else /* the only ec_mem exist */
            {
                ec_memory = NULL;
            }
        }

        if (DEBUG) EC_Test_Print_Adr ("ec memory var free", ec_mem);

        free (ec_mem);
    }
    else
    {
        ec_memory = NULL;
    }
}


void
EC_Memory_Free_All
(
    ECMemory *ec_mem
)
{
    if (ec_mem != NULL)
    {
        if (ec_mem->var != NULL)
        {
            ec_mem->Free_Func(ec_mem->var);
        }
    }
}


/* Clean all ec_memory at the end of the program */
void
EC_Memory_Clean ()
{
    ECMemory *current;
    ECMemory *temp;

    current = ec_memory;

    while (current != NULL)
    {
        current->Free_Func(current->var);

        current = current->next;
    }

    ec_memory = NULL;
}


/* Push new_ec_memory to ec_memory */
void
EC_Memory_Push (ECMemory *ec_memory_new)
{
    if (ec_memory != NULL) /* if there ec_memory var exist */
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
                current->Free_Func (current->var);
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
        current = free_one;         // ECMemory *free_one; global variable defined above
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
