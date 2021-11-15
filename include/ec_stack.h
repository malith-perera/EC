#ifndef EC_STACK_H
#define EC_STACK_H

#include "ec.h"

#define foreach_list(list_type, list)                                       \
  for (list_type* item = list->first;  item != NULL; item = item->next)


/* Function name macros */

#define EC_STACK_FREE_FUNCTION_NAME(TYPE)               EC_CONCAT(Free_, TYPE,) // memory Free
#define EC_STACK_FREE_VAR_FUNCTION_NAME(TYPE)           EC_CONCAT(Free_Stack_, TYPE,)
#define EC_STACK_NEW_FUNCTION_NAME(TYPE)                EC_CONCAT(TYPE, _Stack,)
#define EC_STACK_NEW_VAR_FUNCTION_NAME(TYPE)            EC_CONCAT(TYPE, _Stack_Var,)
#define EC_STACK_APPEND_FUNCTION_NAME(TYPE)             EC_CONCAT(Append_, TYPE,)
#define EC_STACK_INSERT_FUNCTION_NAME(TYPE)             EC_CONCAT(Insert_, TYPE,)
#define EC_STACK_FOREACH(TYPE)                          EC_CONCAT(Foreach_, TYPE,)
#define EC_STACK_REPLACE_FUNCTION_NAME(TYPE)            EC_CONCAT(Replace_, TYPE,)
#define EC_STACK_DROP_FUNCTION_NAME(TYPE)               EC_CONCAT(Drop_, TYPE,)
#define EC_STACK_FREE_VAR_FUNCTION_NAME(TYPE)           EC_CONCAT(Free_, TYPE,_Stack_Var)
#define EC_STACK_FREE_STACK_FUNCTION_NAME(TYPE)         EC_CONCAT(Free_, TYPE, _Stack)
#define EC_STACK_SORT_FUNCTION_NAME(TYPE, SW)           EC_CONCAT4(Sort_, TYPE, _Stack_With_, SW)

#define EC_STACK_PUSH_FUNCTION_NAME(TYPE)               EC_CONCAT(TYPE, _Push,)
#define EC_STACK_POP_FUNCTION_NAME(TYPE)                EC_CONCAT(TYPE, _Pop,)


/* Structure macros */
// defined in ec_memory.h

#define EC_STACK_STRUCT(TYPE)                  EC_CONCAT(TYPE, Stack,)
#define EC_STACK_VAR_STRUCT(TYPE)              EC_CONCAT(TYPE, StackVar,)


#define EC_Stack(TYPE, VAR)                         \
typedef struct EC_STACK_VAR_STRUCT(TYPE){           \
    VAR                                             \
    struct EC_STACK_VAR_STRUCT(TYPE)* next;         \
    EC_MEMORY_LOCK                                  \
} EC_STACK_VAR_STRUCT(TYPE);                        \
                                                    \
                                                    \
typedef struct EC_STACK_STRUCT(TYPE){               \
    int max;                                        \
    int n;                                          \
    EC_STACK_VAR_STRUCT(TYPE)* top;                 \
    EC_MEMORY_LOCK                                  \
} EC_STACK_STRUCT(TYPE);


/* Function prototype macros */

#define EC_STACK_FREE_FUNCTION_PROTOTYPE(TYPE)             \
void                                                       \
EC_STACK_FREE_FUNCTION_NAME(EC_STACK_STRUCT(TYPE))         \
(                                                          \
    void* var                                              \
);

#define EC_STACK_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)         \
void                                                       \
EC_STACK_FREE_VAR_FUNCTION_NAME(TYPE)                      \
(                                                          \
    void* var                                              \
);

#define EC_STACK_NEW_FUNCTION_PROTOTYPE(TYPE)              \
EC_STACK_STRUCT(TYPE)*                                     \
EC_STACK_NEW_FUNCTION_NAME(TYPE)                           \
(                                                          \
    int max                                                \
);


/* Function macros */

#define EC_STACK_FREE_FUNCTION(TYPE)                                \
void                                                                \
EC_STACK_FREE_FUNCTION_NAME(EC_STACK_STRUCT(TYPE))                  \
(                                                                   \
    void* var                                                       \
)                                                                   \
{                                                                   \
    EC_STACK_STRUCT(TYPE)* p = (EC_STACK_STRUCT(TYPE)*) var;        \
    free (p);                                                       \
}


#define EC_STACK_VAR_FREE_FUNCTION(TYPE)                            \
void                                                                \
EC_STACK_FREE_VAR_FUNCTION_NAME(TYPE)                               \
(                                                                   \
    void* var                                                       \
)                                                                   \
{                                                                   \
    EC_STACK* p = (EC_STACK*) var;                                  \
    free (p);                                                       \
}

#define EC_STACK_NEW_FUNCTION(TYPE)                                                                         \
EC_STACK_STRUCT(TYPE)*                                                                                      \
EC_STACK_NEW_FUNCTION_NAME(TYPE)                                                                            \
(                                                                                                           \
    int max                                                                                                 \
)                                                                                                           \
{                                                                                                           \
    EC_STACK_STRUCT(TYPE)* var = (EC_STACK_STRUCT(TYPE)*) malloc (sizeof (EC_STACK_STRUCT(TYPE)));          \
                                                                                                            \
    if (var == NULL)                                                                                        \
    {                                                                                                       \
        printf ("Cannot allocate memory to create list\n");                                                 \
        return NULL;                                                                                        \
    }                                                                                                       \
                                                                                                            \
    var->max = max;                                                                                         \
    var->top = 0;                                                                                           \
    var->var = NULL;                                                                                        \
                                                                                                            \
    if (EC_MEMORY)                                                                                          \
    {                                                                                                       \
        ECMemory* ec_memory_new = (ECMemory*) malloc (sizeof(ECMemory));                                    \
                                                                                                            \
        ec_memory_new->type = EC_STACK_TYPE;                                                                \
        ec_memory_new->var = var;                                                                           \
        ec_memory_new->memory = NULL;                                                                       \
        ec_memory_new->Free_Func = EC_STACK_FREE_FUNCTION_NAME (EC_STACK_STRUCT(TYPE));                     \
        ec_memory_new->next = NULL;                                                                         \
                                                                                                            \
        if (ec_memory != NULL)                                                                              \
        {                                                                                                   \
            ec_memory_new->next = ec_memory;                                                                \
            ec_memory = ec_memory_new;                                                                      \
        }                                                                                                   \
        else                                                                                                \
        {                                                                                                   \
            ec_memory = ec_memory_new;                                                                      \
        }                                                                                                   \
    }                                                                                                       \
                                                                                                            \
    return var;                                                                                             \
}


/* New Stack Variable Method */

EC_STACK_VAR_STRUCT (TYPE)*
EC_STACK_NEW_VAR_FUNCTION_NAME(TYPE)
()
{
    EC_STACK_VAR_STRUCT(TYPE)* var = (EC_STACK_VAR_STRUCT(TYPE)*) malloc (sizeof (EC_STACK_VAR_STRUCT(TYPE)));

    if (EC_MEMORY)
    {
        ECMemory* ec_memory_new = (ECMemory*) malloc (sizeof (ECMemory));

        ec_memory_new->type = EC_STACK_VAR_TYPE;
        ec_memory_new->var = var;
        ec_memory_new->memory = NULL;
        ec_memory_new->Free_Func = EC_STACK_FREE_VAR_FUNCTION_NAME (TYPE);
        ec_memory_new->next = NULL;

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

  return var;
}


#define EC_STACK_PUSH_FUNCTION(TYPE)                        \
void                                                        \
EC_STACK_PUSH_FUNCTION_NAME(TYPE)                           \
(                                                           \
    EC_STACK_STRUCT(TYPE)* stack,                           \
    EC_STACK_VAR_STRUCT(TYPE)* var                          \
)                                                           \
{                                                           \
    /* check if the stack is already full. */               \
    /* Then inserting an element would */                   \
    /* lead to stack overflow */                            \
                                                            \
    if (stack->top == stack->max -1)                        \
    {                                                       \
        printf("Overflow\nProgram Terminated\n");           \
        /*exit(EXIT_FAILURE);*/                             \
    }                                                       \
                                                            \
    var->next = stack->top;                                 \
    stack->top = var;                                       \
}


#define EC_STACK_POP_FUNCTION(TYPE)                         \
EC_STACK_VAR_STRUCT(TYPE)*                                  \
EC_STACK_POP_FUNCTION_NAME(TYPE)                            \
(                                                           \
    EC_STACK_STRUCT(TYPE)* stack                            \
)                                                           \
{                                                           \
    EC_STACK_VAR_STRUCT(TYPE)* pop_var = stack->top;        \
    stack->top = stack->top->next;                          \
                                                            \
    return pop_var;                                         \
}


#endif // EC_STACK_H



/*-------------------------------------------------------------------------------------*
 *                                  Stack Drop Method                                   *
 *=====================================================================================*/

//void
//EC_STACK_DROP_FUNCTION_NAME(TYPE)
//(
    //EC_STACK_STRUCT(TYPE)* list,
    //EC_STACK_VAR_STRUCT(TYPE)* item
//)
//{
    //if (item == list->first)  // drop the first item in the list
    //{
        //if (item->next == NULL)
        //{
            //list->first = NULL;
        //}
        //else
        //{
            //item->next->previous  = NULL;
            //list->first = item->next;
        //}
    //}
    //else if (item == list->last) // drop the last item in the list
    //{
        //item->previous->next = NULL;
    //}
    //else
    //{
        //item->previous->next = item->next;
        //item->next->previous = item->previous;
    //}
//}


/*-------------------------------------------------------------------------------------*
 *                                  Stack Free Variable Method                            *
 *=====================================================================================*/

//void
//EC_STACK_FREE_VAR_FUNCTION_NAME(TYPE)
//(
    //EC_STACK_STRUCT(TYPE)* list,
    //EC_STACK_VAR_STRUCT(TYPE)* item
//)
//{
    //EC_STACK_DROP_FUNCTION_NAME(TYPE) (list, item);
    //free (item);
//}


/*-------------------------------------------------------------------------------------*
 *                                  Stack Free Stack Method                              *
 *=====================================================================================*/

/*void*/
//EC_STACK_FREE_STACK_FUNCTION_NAME(TYPE)
//(
  //void *list_ptr
//)
//{
  //EC_STACK_STRUCT(TYPE) **list;

  //*list = (EC_STACK_STRUCT(TYPE) *) list_ptr;

  //EC_STACK *current, *temp;

  //current = *(*list)->first;

  //while (current != NULL)
  //{
    //temp = current;
    //current = current->next;
    //free (temp);
    //temp = NULL;
  //}
//}


