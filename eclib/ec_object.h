#ifndef EC_OBJECT_H
#define EC_OBJECT_H

#include "ec.h"

#define EC_NEW_METHOD(T) EC_CONCAT(New_, T,)
#define EC_OBJECT_FREE_METHOD(T) EC_CONCAT(Free_, T,)

#endif // EC_OBJECT_H


#ifndef EC_OBJECT
#ifdef EC
#define EC_OBJECT EC
#endif // EC
#endif // EC_OBJECT

#ifdef EC_OBJECT

void
EC_OBJECT_FREE_METHOD(EC_OBJECT)
(
 void *obj
)
{
  EC_OBJECT *p = (EC_OBJECT *) obj;
  free (p);
  p = NULL;
}


EC_OBJECT *
EC_NEW_METHOD(EC_OBJECT)
()
{
  EC_OBJECT *obj = (EC_OBJECT *) malloc (sizeof(EC_OBJECT));

  if (obj == NULL)
  {
    printf ("Cannot allocate memory to create object\n");
    return NULL;
  }


#ifdef EC_GARBAGE
  ECWorld *ec_world_new = (ECWorld *) malloc (sizeof(ECWorld));

  if (ec_world_new == NULL)
  {
    printf ("Cannot allocate memory to create ec_world_new\n");
    return NULL;
  }

  ec_world_new->type = EC_OBJECT_TYPE;
  ec_world_new->obj = obj;
  ec_world_new->garbage = NULL;
  ec_world_new->Free_List = EC_OBJECT_FREE_METHOD (EC_OBJECT);
  ec_world_new->next = NULL;

  if (ec_world != NULL)
  {
    ec_world_new->next = ec_world;
    ec_world = ec_world_new;
  }
  else
  {
    ec_world = ec_world_new;
  }

#endif

  return obj;
}


#undef EC_OBJECT
#endif // EC_OBJECT
