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

        if (current->memory != NULL)
        {
            current->Free_Func (current->memory);
        }

        temp = current;
        current = current->next;
        free (temp);
        temp = NULL;
    }

    ec_memory = NULL;
}
