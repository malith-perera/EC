#include "ec_garbage.h"

void
EC_Clean ()
{
  ECWorld *current;
  ECWorld *temp;

  current = ec_world;

  while (current != NULL)
  {
    if (current->obj != NULL)
    {
      current->Free_List (current->obj);
    }

    if (current->garbage != NULL)
    {
      current->Free_List (current->garbage);
    }

    temp = current;
    current = current->next;
    free (temp);
    temp = NULL;
  }

  ec_world = NULL;
}
