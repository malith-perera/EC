#ifndef EC_STACK_H
#define EC_STACK_H

#include "ec.h"


/* Anyone can use foreach in ec_type.h interchangebly with this. */
#define foreach_stack(queue)                                                            \
    for (stack->var = stack->first; stack->var != NULL; stack->var = stack->var->next)


/* Function name macros */
#define EC_STACK_VAR_FREE_FUNCTION_NAME(TYPE)           EC_CONCAT(TYPE, _Stack_Var_Free,)
#define EC_STACK_FREE_FUNCTION_NAME(TYPE)               EC_CONCAT(TYPE, _Stack_Free,)
#define EC_STACK_NEW_FUNCTION_NAME(TYPE)                EC_CONCAT(TYPE, _Stack,)
#define EC_STACK_NEW_VAR_FUNCTION_NAME(TYPE)            EC_CONCAT(TYPE, _Stack_Var,)
#define EC_STACK_COPY_FUNCTION_NAME(TYPE)               EC_CONCAT(TYPE, _Stack_Copy,)

#define EC_STACK_PUSH_FUNCTION_NAME(TYPE)               EC_CONCAT(TYPE, _Push,)
#define EC_STACK_POP_FUNCTION_NAME(TYPE)                EC_CONCAT(TYPE, _Pop,)
#define EC_STACK_SORT_FUNCTION_NAME(TYPE, SW)           EC_CONCAT4(Sort_, TYPE, _Stack_With_, SW)

/* Structure macros */
// defined in ec_memory.h

#define EC_STACK_STRUCT(TYPE)                   EC_CONCAT(TYPE, Stack,)
#define EC_STACK_VAR_STRUCT(TYPE)               EC_CONCAT(TYPE, StackVar,)


#define EC_STACK(TYPE, VAR)                         /* VAR should define and pass by user as a macro */\
typedef struct EC_STACK_VAR_STRUCT(TYPE) {          \
    VAR                                             \
    struct EC_STACK_VAR_STRUCT(TYPE) *next;         \
} EC_STACK_VAR_STRUCT(TYPE);                        \
                                                    \
                                                    \
typedef struct EC_STACK_STRUCT(TYPE) {              \
    EC_STACK_VAR_STRUCT(TYPE) *first;               \
    EC_STACK_VAR_STRUCT(TYPE) *var;                 \
    EC_MEMORY_REF                                   \
} EC_STACK_STRUCT(TYPE);


/* Function prototype macros */

#define EC_STACK_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)  \
void                                                \
EC_STACK_VAR_FREE_FUNCTION_NAME(TYPE)               \
(                                                   \
    EC_STACK_STRUCT(TYPE) *stack                    \
);


#define EC_STACK_FREE_FUNCTION_PROTOTYPE(TYPE)      \
void                                                \
EC_STACK_FREE_FUNCTION_NAME(TYPE)                   \
(                                                   \
    void *var                                       \
);


#define EC_STACK_NEW_FUNCTION_PROTOTYPE(TYPE)       \
EC_STACK_STRUCT(TYPE) *                             \
EC_STACK_NEW_FUNCTION_NAME(TYPE)                    \
();


#define EC_STACK_NEW_VAR_FUNCTION_PROTOTYPE(TYPE)   \
EC_STACK_VAR_STRUCT(TYPE) *                         \
EC_STACK_NEW_VAR_FUNCTION_NAME(TYPE)                \
();


#define EC_STACK_PUSH_FUNCTION_PROTOTYPE(TYPE)      \
void                                                \
EC_STACK_PUSH_FUNCTION_NAME(TYPE)                   \
(                                                   \
    EC_STACK_STRUCT(TYPE) *stack,                   \
    EC_STACK_VAR_STRUCT(TYPE) *var                  \
);


#define EC_STACK_POP_FUNCTION_PROTOTYPE(TYPE)       \
EC_STACK_VAR_STRUCT(TYPE) *                         \
EC_STACK_POP_FUNCTION_NAME(TYPE)                    \
(                                                   \
    EC_STACK_STRUCT(TYPE) *stack                    \
);


#define EC_STACK_COPY_FUNCTION_PROTOTYPE(TYPE)      \
EC_STACK_STRUCT(TYPE) *                             \
EC_STACK_COPY_FUNCTION_NAME(TYPE)                   \
(                                                   \
    EC_STACK_STRUCT(TYPE) *stack                    \
);


#define EC_STACK_FUNCTION_PROTOTYPES(TYPE)          \
    EC_STACK_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)      \
    EC_STACK_FREE_FUNCTION_PROTOTYPE(TYPE)          \
    EC_STACK_NEW_FUNCTION_PROTOTYPE(TYPE)           \
    EC_STACK_NEW_VAR_FUNCTION_PROTOTYPE(TYPE)       \
    EC_STACK_PUSH_FUNCTION_PROTOTYPE(TYPE)          \
    EC_STACK_POP_FUNCTION_PROTOTYPE(TYPE)           \
    EC_STACK_COPY_FUNCTION_PROTOTYPE(TYPE)


/* Function macros */
#define EC_STACK_VAR_FREE_FUNCTION(TYPE)            \
void                                                \
EC_STACK_VAR_FREE_FUNCTION_NAME(TYPE)               \
(                                                   \
    EC_STACK_STRUCT(TYPE) *stack                    \
)                                                   \
{                                                   \
    EC_STACK_VAR_STRUCT(TYPE) *temp;                \
    if (stack->first != NULL)                       \
    {                                               \
        temp = stack->first;                        \
        stack->first = stack->first->next;          \
        free (temp);                                \
    }                                               \
}


#define EC_STACK_FREE_FUNCTION(TYPE)                            \
void                                                            \
EC_STACK_FREE_FUNCTION_NAME(TYPE)                               \
(                                                               \
    void *stack                                                 \
)                                                               \
{                                                               \
    EC_STACK_STRUCT(TYPE) *s = (EC_STACK_STRUCT(TYPE)*) stack;  \
    foreach (s)                                                 \
    {                                                           \
        EC_STACK_VAR_FREE_FUNCTION_NAME(TYPE)(s);               \
    }                                                           \
    free (s);                                                   \
    s = NULL;                                                   \
}


#define EC_STACK_NEW_FUNCTION(TYPE)                                     \
EC_STACK_STRUCT(TYPE) *                                                 \
EC_STACK_NEW_FUNCTION_NAME(TYPE)                                        \
()                                                                      \
{                                                                       \
    EC_VAR_CREATE(EC_STACK_STRUCT(TYPE), stack)                         /*TYPE *var is in this macro in ec_var.h*/\
                                                                        \
    if (EC_MEMORY)                                                      \
    {                                                                   \
        EC_MEMORY_CREATE(TYPE, EC_STACK_TYPE, stack)                    \
        ec_memory_new->Free_Func = EC_STACK_FREE_FUNCTION_NAME(TYPE);   \
        stack->ec_mem = ec_memory_new;                                  \
        stack->ec_mem->lock = EC_LOCK;                                  \
    }                                                                   \
                                                                        \
    stack->first = NULL;                                                \
    stack->var = NULL;                                                  \
                                                                        \
    return stack;                                                         \
}


/* New Stack Variable Method */
#define EC_STACK_NEW_VAR_FUNCTION(TYPE)                                 \
EC_STACK_VAR_STRUCT(TYPE) *                                             \
EC_STACK_NEW_VAR_FUNCTION_NAME(TYPE)                                    \
()                                                                      \
{                                                                       \
    EC_VAR_CREATE(EC_STACK_VAR_STRUCT(TYPE), var)                            /*TYPE *var is in this macro in ec_var.h*/\
                                                                        \
    if (EC_MEMORY)                                                      \
    {                                                                   \
        EC_MEMORY_CREATE(TYPE, EC_STACK_VAR_TYPE, var)                  \
    }                                                                   \
                                                                        \
    return var;                                                         \
}


#define EC_STACK_PUSH_FUNCTION(TYPE)                        \
void                                                        \
EC_STACK_PUSH_FUNCTION_NAME(TYPE)                           \
(                                                           \
    EC_STACK_STRUCT(TYPE) *stack,                           \
    EC_STACK_VAR_STRUCT(TYPE) *var                          \
)                                                           \
{                                                           \
    var->next = stack->first;                               \
    stack->first = var;                                     \
}


#define EC_STACK_POP_FUNCTION(TYPE)                         \
EC_STACK_VAR_STRUCT(TYPE) *                                 \
EC_STACK_POP_FUNCTION_NAME(TYPE)                            \
(                                                           \
    EC_STACK_STRUCT(TYPE) *stack                            \
)                                                           \
{                                                           \
    if (stack->first == NULL)                               \
    {                                                       \
        return NULL;                                        \
    }                                                       \
                                                            \
    EC_STACK_VAR_STRUCT(TYPE) *pop_var = stack->first;      \
    stack->first = stack->first->next;                      \
                                                            \
    return pop_var;                                         \
}


// Copy stack
#define EC_STACK_COPY_FUNCTION(TYPE)                                        \
EC_STACK_STRUCT(TYPE) *                                                     \
EC_STACK_COPY_FUNCTION_NAME(TYPE)                                           \
(                                                                           \
    EC_STACK_STRUCT(TYPE) *stack                                            \
)                                                                           \
{                                                                           \
    EC_STACK_STRUCT(TYPE) *stack_copy = EC_STACK_NEW_FUNCTION_NAME(TYPE)(); \
                                                                            \
    EC_STACK_VAR_STRUCT(TYPE) *var;                                         \
                                                                            \
    foreach(stack)                                                          \
    {                                                                       \
        var = EC_STACK_NEW_VAR_FUNCTION_NAME(TYPE)();                       \
        *var = *stack->var;                                                 \
        EC_STACK_PUSH_FUNCTION_NAME(TYPE)(stack_copy, var);                 \
    }                                                                       \
                                                                            \
    return stack_copy;                                                      \
}


#define EC_STACK_FUNCTIONS(TYPE)            \
    EC_STACK_VAR_FREE_FUNCTION(TYPE)        \
    EC_STACK_FREE_FUNCTION(TYPE)            \
    EC_STACK_NEW_FUNCTION(TYPE)             \
    EC_STACK_NEW_VAR_FUNCTION(TYPE)         \
    EC_STACK_PUSH_FUNCTION(TYPE)            \
    EC_STACK_POP_FUNCTION(TYPE)             \
    EC_STACK_COPY_FUNCTION(TYPE)

#endif // EC_STACK_H



/*-------------------------------------------------------------------------------------*
 *                                  Stack Drop Method                                   *
 *=====================================================================================*/

//void
//EC_STACK_DROP_FUNCTION_NAME(TYPE)
//(
    //EC_STACK_STRUCT(TYPE) *list,
    //EC_STACK_VAR_STRUCT(TYPE) *item
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
    //EC_STACK_STRUCT(TYPE) *list,
    //EC_STACK_VAR_STRUCT(TYPE) *item
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
