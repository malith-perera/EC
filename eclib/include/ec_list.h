#ifndef EC_LIST_H
#define EC_LIST_H

#include "ec.h"

#define foreach_list(list_type, list)                                       \
  for (list_type *item = list->first;  item != NULL; item = item->next)


#define EC_LIST_STRUCT(T) EC_CONCAT(T, List,)
#define EC_LIST_FREE_METHOD(T) EC_CONCAT(Free_, T,) // garbage Free
#define EC_NEW_LIST_METHOD(T) EC_CONCAT(T, _List,)
#define EC_LIST_OBJECT(T) EC_CONCAT(T, ListObj,)
#define EC_LIST_OBJECT_FREE_METHOD(T) EC_CONCAT(Free_List_, T,)
#define EC_LIST_NEW_OBJECT_METHOD(T) EC_CONCAT(T, _List_Object,)
#define EC_LIST_APPEND_METHOD(T) EC_CONCAT(Append_, T,)
#define EC_LIST_INSERT_METHOD(T) EC_CONCAT(Insert_, T,)
#define EC_LIST_FOREACH(T) EC_CONCAT(Foreach_, T,)
#define EC_LIST_REPLACE_METHOD(T) EC_CONCAT(Replace_, T,)
#define EC_LIST_DROP_METHOD(T) EC_CONCAT(Drop_, T,)
#define EC_LIST_FREE_OBJECT_METHOD(T) EC_CONCAT(Free_, T,_List_Object)
#define EC_LIST_FREE_LIST_METHOD(T) EC_CONCAT(Free_, T, _List)

#define EC_LIST_SORT_METHOD(T, SW) EC_CONCAT4(Sort_, T, _List_With_, SW)

#endif // EC_LIST_H


#ifndef EC_LIST
#ifdef EC
#define EC_LIST EC
#endif
#endif

#ifdef EC_LIST

void
EC_LIST_FREE_METHOD(EC_LIST_STRUCT(EC_LIST))
(
  void *obj
)
{
  EC_LIST_STRUCT(EC_LIST) *p = (EC_LIST_STRUCT(EC_LIST) *) obj;
  free (p);
}


EC_LIST_STRUCT(EC_LIST) *
EC_NEW_LIST_METHOD(EC_LIST)
()
{
  EC_LIST_STRUCT(EC_LIST) *obj = (EC_LIST_STRUCT(EC_LIST) *) malloc (sizeof (EC_LIST_STRUCT(EC_LIST)));

  if (obj == NULL)
  {
    printf ("Cannot allocate memory to create list\n");
    return NULL;
  }

  obj->first = NULL;
  obj->last = NULL;

#ifdef EC_GARBAGE
  ECWorld *ec_world_new = (ECWorld *) malloc (sizeof(ECWorld));

  ec_world_new->type = EC_LIST_TYPE;
  ec_world_new->obj = obj;
  ec_world_new->garbage = NULL;
  ec_world_new->Free_List = EC_LIST_FREE_METHOD (EC_LIST_STRUCT(EC_LIST));
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


void
EC_LIST_OBJECT_FREE_METHOD(EC_LIST)
(
 void *obj
)
{
  EC_LIST *p = (EC_LIST *) obj;
  free (p);
}


/*--------------------------------------------------------------------------*
 *                        New List Object Method                            *
 *==========================================================================*/

EC_LIST_OBJECT (EC_LIST) *
EC_LIST_NEW_OBJECT_METHOD(EC_LIST)
()
{
  EC_LIST_OBJECT(EC_LIST) *obj = (EC_LIST_OBJECT(EC_LIST) *) malloc (sizeof (EC_LIST_OBJECT(EC_LIST)));

#ifdef EC_GARBAGE
  ECWorld *ec_world_new = (ECWorld *) malloc (sizeof (ECWorld));

  ec_world_new->type = EC_LIST_OBJECT_TYPE;
  ec_world_new->obj = obj;
  ec_world_new->garbage = NULL;
  ec_world_new->Free_List = EC_LIST_OBJECT_FREE_METHOD (EC_LIST);
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


/*----------------------------------------------------------------------------------------*
 *                                   List Append Method                                   *
 *========================================================================================*/

void
EC_LIST_APPEND_METHOD(EC_LIST)
(
  EC_LIST_STRUCT(EC_LIST) *list,
  EC_LIST_OBJECT(EC_LIST) *item
)
{
  item->next = NULL;

  if (list->first != NULL) // items in the list
  {
    list->last->next = item;
    item->previous = list->last;
  }
  else // no items in the  list
  {
    item->previous = NULL;
    list->first = item;
  }

  list->last = item;
}


/*-------------------------------------------------------------------------------------*
 *                                   List Insert Method                                *
 *=====================================================================================*/

void
EC_LIST_INSERT_METHOD(EC_LIST)
(
  EC_LIST_STRUCT(EC_LIST) *list,
  EC_LIST_OBJECT(EC_LIST) *item,
  EC_LIST_OBJECT(EC_LIST) *ref,
  short pos
)
{
  if (list->first == NULL && ref == NULL) // no items in the list reference item is NULL
  {
    item->previous = NULL;
    item->next = NULL;
    list->first = item;
    list->last = item;
  }
  else if (ref == list->first) // reference item is the first item
  {
    if (pos < 0)  // insert befor the first item
    {
      item->previous = NULL;
      item->next = ref;
      ref->previous = item;
      list->first = item;
    }
    else  // insert after the first item
    {
      if (ref == list->last) // reference item is the first and also the last
      {
        item->previous = list->first;
        item->next = NULL;
        list->first->next = item;
        list->last = item;
      }
      else // reference item is the first item but not the last
      {
        item->previous = ref;
        item->next = ref->next;
        ref->next->previous = item;
        ref->next = item;
      }
    }
  }
  else if (ref == list->last) // reference item is the last item
  {
    if (pos < 0)  // insert before the last item
    {
      item->previous = ref->previous;
      item->next = ref;
      ref->previous->next = item;
      ref->previous = item;
    }
    else  // insert after the last item as last item
    {
      item->previous = ref;
      item->next = NULL;
      ref->next = item;
      list->last = item;
    }
  }
  else
  {
    if (pos < 0)  // insert before the reference item
    {
      item->previous = ref->previous;
      item->next = ref;
      ref->previous->next = item;
      ref->previous = item;
    }
    else  // insert after the reference item
    {
      item->previous = ref;
      item->next = ref->next;
      ref->next->previous = item;
      ref->next = item;
    }
  }
}


/*-------------------------------------------------------------------------------------*
 *                                  List Replace Method                                *
 *=====================================================================================*/

void
EC_LIST_REPLACE_METHOD(EC_LIST)
(
  EC_LIST_STRUCT(EC_LIST) *list,
  EC_LIST_OBJECT(EC_LIST) *item,
  EC_LIST_OBJECT(EC_LIST) *ref
)
{
  if (item == list->first)  // reference item is the first item in the list
  {
    if (item->next == NULL)  // reference item is the only item in the list
    {
      ref->previous = NULL;
      ref->next = NULL;
      list->first = ref;
    }
    else  // reference item is the first item but not the only item in the list
    {
      ref->previous = NULL;
      ref->next = item->next;
      item->next->previous = ref;
      list->first = ref;
    }
  }
  else if (item == list->last)  // reference item is the last item in the list
  {
    ref->previous = item->previous;
    ref->next = NULL;
    item->previous->next = ref;
  }
  else // reference item is an anyother item than the first and the last
  {
    ref->previous = item->previous;
    ref->next = item->next;
    item->previous->next = ref;
    item->next->previous = ref;
  }
}


/*-------------------------------------------------------------------------------------*
 *                                  List Sort Method                                   *
 *=====================================================================================*/

#ifdef EC_SORT
#ifdef EC_SORT_WITH

void
EC_LIST_SORT_METHOD (EC_SORT, EC_SORT_WITH)
(
  EC_LIST_STRUCT(EC_SORT) *list
)
{
  EC_LIST_OBJECT(EC_SORT) *previous;
  EC_LIST_OBJECT(EC_SORT) *current;
  EC_LIST_OBJECT(EC_SORT) *ref;

  ref = list->first;

  while (ref->next != NULL)
  {
    previous = NULL;
    current = list->first;

    if (ref->EC_SORT_WITH > ref->next->EC_SORT_WITH)
    {
      while (current != ref->next)
      {
        if (current->EC_SORT_WITH > ref->next->EC_SORT_WITH)
        {
          if (previous == NULL) // list item
          {
            list->first = ref->next;
            ref->next = ref->next->next;
            list->first->next = current;
          }
          else
          {
            previous->next = ref->next;
            ref->next = ref->next->next;
            previous->next->next = current;
          }

          break;
        }
        else
        {
          previous = current;
          current = current->next;
        }
      }
    }
    else
    {
      ref = ref->next;
    }
  }
}

#undef EC_SORT_WITH
#undef EC_SORT
#endif // EC_SORT _WITH
#endif // EC_SORT


/*-------------------------------------------------------------------------------------*
 *                                  List Drop Method                                   *
 *=====================================================================================*/

void
EC_LIST_DROP_METHOD(EC_LIST)
(
  EC_LIST_STRUCT(EC_LIST) *list,
  EC_LIST_OBJECT(EC_LIST) *item
)
{
  if (item == list->first)  // drop the first item in the list
  {
    if (item->next == NULL)
    {
      list->first = NULL;
    }
    else
    {
      item->next->previous  = NULL;
      list->first = item->next;
    }
  }
  else if (item == list->last) // drop the last item in the list
  {
    item->previous->next = NULL;
  }
  else
  {
    item->previous->next = item->next;
    item->next->previous = item->previous;
  }
}


/*-------------------------------------------------------------------------------------*
 *                                  List Free Object Method                            *
 *=====================================================================================*/

void
EC_LIST_FREE_OBJECT_METHOD(EC_LIST)
(
  EC_LIST_STRUCT(EC_LIST) *list,
  EC_LIST_OBJECT(EC_LIST) *item
)
{
  EC_LIST_DROP_METHOD(EC_LIST) (list, item);
  free (item);
}


/*-------------------------------------------------------------------------------------*
 *                                  List Free List Method                              *
 *=====================================================================================*/

/*void*/
//EC_LIST_FREE_LIST_METHOD(EC_LIST)
//(
  //void *list_ptr
//)
//{
  //EC_LIST_STRUCT(EC_LIST) **list;

  //*list = (EC_LIST_STRUCT(EC_LIST) *) list_ptr;

  //EC_LIST *current, *temp;

  //current = *(*list)->first;

  //while (current != NULL)
  //{
    //temp = current;
    //current = current->next;
    //free (temp);
    //temp = NULL;
  //}
//}

#undef EC_LIST
#endif
