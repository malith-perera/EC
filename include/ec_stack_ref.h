#ifndef EC_STACK_REF_H
#define EC_STACK_REF_H

#include "ec.h"

#define foreach_stack_ref(stack)                                                            \
  for (stack->var = stack->top;  stack->var != NULL; stack->var = stack->var->next)


/* Function name macros */

#define EC_STACK_REF_FREE_FUNCTION_NAME(TYPE)               EC_CONCAT(TYPE, _Stack_Free,) // memory Free
#define EC_STACK_REF_FREE_VAR_FUNCTION_NAME(TYPE)           EC_CONCAT(TYPE, _Stack_Var_Free,)
#define EC_STACK_REF_NEW_FUNCTION_NAME(TYPE)                EC_CONCAT(TYPE, _Stack,)
#define EC_STACK_REF_NEW_VAR_FUNCTION_NAME(TYPE)            EC_CONCAT(TYPE, _Stack_Var,)
#define EC_STACK_REF_COPY_FUNCTION_NAME(TYPE)               EC_CONCAT(TYPE, _Stack_Copy,)

#define EC_STACK_REF_FOREACH(TYPE)                          EC_CONCAT(TYPE, _Foreach,)
#define EC_STACK_REF_PUSH_FUNCTION_NAME(TYPE)               EC_CONCAT(TYPE, _Push,)
#define EC_STACK_REF_POP_FUNCTION_NAME(TYPE)                EC_CONCAT(TYPE, _Pop,)
#define EC_STACK_REF_FREE_STACK_FUNCTION_NAME(TYPE)         EC_CONCAT(TYPE, _Free, _Stack)
#define EC_STACK_REF_SORT_FUNCTION_NAME(TYPE, SW)           EC_CONCAT4(Sort_, TYPE, _Stack_With_, SW)

/* Structure macros */
// defined in ec_memory.h

#define EC_STACK_REF_STRUCT(TYPE)                   EC_CONCAT(TYPE, Stack,)
#define EC_STACK_REF_VAR_STRUCT(TYPE)               EC_CONCAT(TYPE, StackVar,)
#define EC_STACK_REF_VAR_REF_STRUCT(TYPE)           EC_CONCAT(TYPE, StackVarRef,)
#define EC_STACK_REF_REF_STRUCT(TYPE)               EC_CONCAT(TYPE, StackRef,)


#define EC_STACK_REF(TYPE, VAR)                         \
typedef struct EC_STACK_REF_VAR_STRUCT(TYPE) {          \
    VAR                                                 \
    struct EC_STACK_REF_VAR_STRUCT(TYPE)* next;         \
} EC_STACK_REF_VAR_STRUCT(TYPE);                        \
                                                        \
                                                        \
typedef struct EC_STACK_REF_STRUCT(TYPE) {              \
    EC_STACK_REF_VAR_STRUCT(TYPE)* top;                 \
    EC_STACK_REF_VAR_STRUCT(TYPE)* var;                 \
    EC_MEMORY_REF                                       \
} EC_STACK_REF_STRUCT(TYPE);                            \
                                                        \
                                                        \
typedef struct EC_STACK_REF_VAR_REF_STRUCT(TYPE) {      \
    struct EC_STACK_REF_VAR_STRUCT(TYPE)* ref;          \
    struct EC_STACK_REF_VAR_REF_STRUCT(TYPE)* next;     \
} EC_STACK_REF_VAR_REF_STRUCT(TYPE);                    \
                                                        \
                                                        \
typedef struct EC_STACK_REF_REF_STRUCT(TYPE) {          \
    EC_STACK_REF_VAR_REF_STRUCT(TYPE)* top;             \
    EC_STACK_REF_VAR_REF_STRUCT(TYPE)* var;             \
    EC_MEMORY_REF                                       \
} EC_STACK_REF_REF_STRUCT(TYPE);



/* Function prototype macros */

#define EC_STACK_REF_FREE_FUNCTION_PROTOTYPE(TYPE)         \
void                                                       \
EC_STACK_REF_FREE_FUNCTION_NAME(TYPE)                      \
(                                                          \
    void* var                                              \
);


#define EC_STACK_REF_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)     \
void                                                       \
EC_STACK_REF_FREE_VAR_FUNCTION_NAME(TYPE)                  \
(                                                          \
    void* var                                              \
);


#define EC_STACK_REF_NEW_FUNCTION_PROTOTYPE(TYPE)          \
EC_STACK_REF_STRUCT(TYPE)*                                 \
EC_STACK_REF_NEW_FUNCTION_NAME(TYPE)                       \
();


#define EC_STACK_REF_NEW_VAR_FUNCTION_PROTOTYPE(TYPE)      \
EC_STACK_REF_VAR_STRUCT(TYPE)*                             \
EC_STACK_REF_NEW_VAR_FUNCTION_NAME(TYPE)                   \
();


#define EC_STACK_REF_PUSH_FUNCTION_PROTOTYPE(TYPE)         \
void                                                       \
EC_STACK_REF_PUSH_FUNCTION_NAME(TYPE)                      \
(                                                          \
    EC_STACK_REF_STRUCT(TYPE)* stack,                      \
    EC_STACK_REF_VAR_STRUCT(TYPE)* var                     \
);


#define EC_STACK_REF_POP_FUNCTION_PROTOTYPE(TYPE)          \
EC_STACK_REF_VAR_STRUCT(TYPE)*                             \
EC_STACK_REF_POP_FUNCTION_NAME(TYPE)                       \
(                                                          \
    EC_STACK_REF_STRUCT(TYPE)* stack                       \
);


#define EC_STACK_REF_COPY_FUNCTION_PROTOTYPE(TYPE)         \
EC_STACK_REF_STRUCT(TYPE)*                                 \
EC_STACK_REF_COPY_FUNCTION_NAME(TYPE)                      \
(                                                          \
    EC_STACK_REF_STRUCT(TYPE)* stack                       \
);


#define EC_STACK_REF_FUNCTION_PROTOTYPES(TYPE)          \
    EC_STACK_REF_FREE_FUNCTION_PROTOTYPE(TYPE)          \
    EC_STACK_REF_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)      \
    EC_STACK_REF_NEW_FUNCTION_PROTOTYPE(TYPE)           \
    EC_STACK_REF_NEW_VAR_FUNCTION_PROTOTYPE(TYPE)       \
    EC_STACK_REF_PUSH_FUNCTION_PROTOTYPE(TYPE)          \
    EC_STACK_REF_POP_FUNCTION_PROTOTYPE(TYPE)           \
    EC_STACK_REF_COPY_FUNCTION_PROTOTYPE(TYPE)


/* Function macros */

#define EC_STACK_REF_FREE_FUNCTION(TYPE)                            \
void                                                                \
EC_STACK_REF_FREE_FUNCTION_NAME(TYPE)                               \
(                                                                   \
    void* var                                                       \
)                                                                   \
{                                                                   \
    EC_STACK_REF_STRUCT(TYPE)* p = (EC_STACK_REF_STRUCT(TYPE)*) var;\
    free (p);                                                       \
}


#define EC_STACK_REF_VAR_FREE_FUNCTION(TYPE)                        \
void                                                                \
EC_STACK_REF_FREE_VAR_FUNCTION_NAME(TYPE)                           \
(                                                                   \
    void* var                                                       \
)                                                                   \
{                                                                   \
    TYPE* p = (TYPE*) var;                                          \
    free (p);                                                       \
}


#define EC_STACK_REF_NEW_FUNCTION(TYPE)                                             \
EC_STACK_REF_STRUCT(TYPE)*                                                          \
EC_STACK_REF_NEW_FUNCTION_NAME(TYPE)                                                \
()                                                                                  \
{                                                                                   \
    EC_STACK_REF_STRUCT(TYPE)* var = (EC_STACK_REF_STRUCT(TYPE)*)                   \
        malloc (sizeof (EC_STACK_REF_STRUCT(TYPE)));                                \
                                                                                    \
    if (var == NULL)                                                                \
    {                                                                               \
        EC_Error_Mem_Alloc (__FILE__, __LINE__);                                    \
        return NULL;                                                                \
    }                                                                               \
                                                                                    \
    var->top = NULL;                                                                \
                                                                                    \
    if (EC_MEMORY)                                                                  \
    {                                                                               \
        ECMemory* ec_memory_new = (ECMemory*) malloc (sizeof(ECMemory));            \
                                                                                    \
        if (ec_memory_new == NULL)                                                  \
        {                                                                           \
            EC_Error_Mem_Alloc (__FILE__, __LINE__);                                \
            return NULL;                                                            \
        }                                                                           \
                                                                                    \
        ec_memory_new->type = EC_STACK_REF_TYPE;                                    \
        ec_memory_new->var = var;                                                   \
        ec_memory_new->lock = EC_LOCK;                                              \
        ec_memory_new->Free_Func = EC_STACK_REF_FREE_FUNCTION_NAME(TYPE);           \
        ec_memory_new->Free_Var_Func = EC_STACK_REF_FREE_VAR_FUNCTION_NAME(TYPE);   \
        ec_memory_new->next = NULL;                                                 \
                                                                                    \
        EC_Memory_Append (ec_memory_new);                                           \
                                                                                    \
        var->ec_memory_ref = ec_memory_new;                                         \
        var->lock = EC_LOCK;                                                        \
    }                                                                               \
                                                                                    \
    return var;                                                                     \
}


/* New Stack Variable Method */
#define EC_STACK_REF_NEW_VAR_FUNCTION(TYPE)                                     \
EC_STACK_REF_VAR_STRUCT (TYPE)*                                                 \
EC_STACK_REF_NEW_VAR_FUNCTION_NAME(TYPE)                                        \
()                                                                              \
{                                                                               \
    EC_STACK_REF_VAR_STRUCT(TYPE)* var = (EC_STACK_REF_VAR_STRUCT(TYPE)*)       \
        malloc (sizeof (EC_STACK_REF_VAR_STRUCT(TYPE)));                        \
                                                                                \
    if (var == NULL)                                                            \
    {                                                                           \
        EC_Error_Mem_Alloc (__FILE__, __LINE__);                                \
        return NULL;                                                            \
    }                                                                           \
                                                                                \
    if (EC_MEMORY)                                                              \
    {                                                                           \
        ECMemory* ec_memory_new = (ECMemory*) malloc (sizeof (ECMemory));       \
                                                                                \
        if (ec_memory_new == NULL)                                              \
        {                                                                       \
            EC_Error_Mem_Alloc (__FILE__, __LINE__);                            \
            return NULL;                                                        \
        }                                                                       \
                                                                                \
        ec_memory_new->type = EC_STACK_REF_VAR_TYPE;                            \
        ec_memory_new->var = var;                                               \
        ec_memory_new->lock = EC_NONE_LOCK;                                     \
        ec_memory_new->Free_Func = EC_STACK_REF_FREE_VAR_FUNCTION_NAME(TYPE);   \
        ec_memory_new->next = NULL;                                             \
                                                                                \
        EC_Memory_Append (ec_memory_new);                                       \
    }                                                                           \
                                                                                \
    return var;                                                                 \
}

/* STACK REF MACRO */

#define EC_STACK_REF_REF_FREE_FUNCTION(TYPE)                                    \
void                                                                            \
EC_STACK_REF_REF_FREE_FUNCTION_NAME(TYPE)                                       \
(                                                                               \
    void* var                                                                   \
)                                                                               \
{                                                                               \
    EC_STACK_REF_REF_STRUCT(TYPE)* p = (EC_STACK_REF_REF_STRUCT(TYPE)*) var;    \
    free (p);                                                                   \
}


#define EC_STACK_REF_REF_VAR_FREE_FUNCTION(TYPE)   \
void                                               \
EC_STACK_REF_REF_FREE_VAR_FUNCTION_NAME(TYPE)      \
(                                                  \
    void* var                                      \
)                                                  \
{                                                  \
    TYPE* p = (TYPE*) var;                         \
    free (p);                                      \
}


#define EC_STACK_REF_REF_NEW_FUNCTION(TYPE)                                             \
EC_STACK_REF_REF_STRUCT(TYPE)*                                                          \
EC_STACK_REF_REF_NEW_FUNCTION_NAME(TYPE)                                                \
()                                                                                      \
{                                                                                       \
    EC_STACK_REF_REF_STRUCT(TYPE)* var = (EC_STACK_REF_REF_STRUCT(TYPE)*)               \
        malloc (sizeof (EC_STACK_REF_REF_STRUCT(TYPE)));                                \
                                                                                        \
    if (var == NULL)                                                                    \
    {                                                                                   \
        EC_Error_Mem_Alloc (__FILE__, __LINE__);                                        \
        return NULL;                                                                    \
    }                                                                                   \
                                                                                        \
    var->top = NULL;                                                                    \
                                                                                        \
    if (EC_MEMORY)                                                                      \
    {                                                                                   \
        ECMemory* ec_memory_new = (ECMemory*) malloc (sizeof(ECMemory));                \
                                                                                        \
        if (ec_memory_new == NULL)                                                      \
        {                                                                               \
            EC_Error_Mem_Alloc (__FILE__, __LINE__);                                    \
            return NULL;                                                                \
        }                                                                               \
                                                                                        \
        ec_memory_new->type = EC_STACK_REF_REF_TYPE;                                    \
        ec_memory_new->var = var;                                                       \
        ec_memory_new->lock = EC_LOCK;                                                  \
        ec_memory_new->Free_Func = EC_STACK_REF_REF_FREE_FUNCTION_NAME(TYPE);           \
        ec_memory_new->Free_Var_Func = EC_STACK_REF_REF_FREE_VAR_FUNCTION_NAME(TYPE);   \
        ec_memory_new->next = NULL;                                                     \
                                                                                        \
        EC_Memory_Append (ec_memory_new);                                               \
                                                                                        \
        var->ec_memory_ref = ec_memory_new;                                             \
        var->lock = EC_LOCK;                                                            \
    }                                                                                   \
                                                                                        \
    return var;                                                                         \
}


/* New Stack Variable Method */
#define EC_STACK_REF_REF_NEW_VAR_FUNCTION(TYPE)                                     \
EC_STACK_REF_REF_VAR_STRUCT (TYPE)*                                                 \
EC_STACK_REF_REF_NEW_VAR_FUNCTION_NAME(TYPE)                                        \
()                                                                                  \
{                                                                                   \
    EC_STACK_REF_REF_VAR_STRUCT(TYPE)* var = (EC_STACK_REF_REF_VAR_STRUCT(TYPE)*)   \
        malloc (sizeof (EC_STACK_REF_REF_VAR_STRUCT(TYPE)));                        \
                                                                                    \
    if (var == NULL)                                                                \
    {                                                                               \
        EC_Error_Mem_Alloc (__FILE__, __LINE__);                                    \
        return NULL;                                                                \
    }                                                                               \
                                                                                    \
    if (EC_MEMORY)                                                                  \
    {                                                                               \
        ECMemory* ec_memory_new = (ECMemory*) malloc (sizeof (ECMemory));           \
                                                                                    \
        if (ec_memory_new == NULL)                                                  \
        {                                                                           \
            EC_Error_Mem_Alloc (__FILE__, __LINE__);                                \
            return NULL;                                                            \
        }                                                                           \
                                                                                    \
        ec_memory_new->type = EC_STACK_REF_REF_VAR_TYPE;                            \
        ec_memory_new->var = var;                                                   \
        ec_memory_new->lock = EC_NONE_LOCK;                                         \
        ec_memory_new->Free_Func = EC_STACK_REF_REF_FREE_VAR_FUNCTION_NAME(TYPE);   \
        ec_memory_new->next = NULL;                                                 \
                                                                                    \
        EC_Memory_Append (ec_memory_new);                                           \
    }                                                                               \
                                                                                    \
    return var;                                                                     \
}


#define EC_STACK_REF_PUSH_FUNCTION(TYPE)                    \
void                                                        \
EC_STACK_REF_PUSH_FUNCTION_NAME(TYPE)                       \
(                                                           \
    EC_STACK_REF_STRUCT(TYPE)* stack,                       \
    EC_STACK_REF_VAR_STRUCT(TYPE)* var                      \
)                                                           \
{                                                           \
    var->next = stack->top;                                 \
    stack->top = var;                                       \
}


#define EC_STACK_REF_POP_FUNCTION(TYPE)                     \
EC_STACK_REF_VAR_STRUCT(TYPE)*                              \
EC_STACK_REF_POP_FUNCTION_NAME(TYPE)                        \
(                                                           \
    EC_STACK_REF_STRUCT(TYPE)* stack                        \
)                                                           \
{                                                           \
    if (stack->top == NULL)                                 \
    {                                                       \
        return NULL;                                        \
    }                                                       \
                                                            \
    EC_STACK_REF_VAR_STRUCT(TYPE)* pop_var = stack->top;    \
    stack->top = stack->top->next;                          \
                                                            \
    return pop_var;                                         \
}


// Copy stack
#define EC_STACK_REF_COPY_FUNCTION(TYPE)                                            \
EC_STACK_REF_STRUCT(TYPE)*                                                          \
EC_STACK_REF_COPY_FUNCTION_NAME(TYPE)                                               \
(                                                                                   \
    EC_STACK_REF_STRUCT(TYPE)* stack                                                \
)                                                                                   \
{                                                                                   \
    EC_STACK_REF_STRUCT(TYPE)* stack_copy = EC_STACK_REF_NEW_FUNCTION_NAME(TYPE)(); \
                                                                                    \
    EC_STACK_REF_VAR_STRUCT(TYPE)* var;                                             \
                                                                                    \
    foreach_stack(stack)                                                            \
    {                                                                               \
        var = EC_STACK_REF_NEW_VAR_FUNCTION_NAME(TYPE)();                           \
        *var = *stack->var;                                                         \
        EC_STACK_REF_PUSH_FUNCTION_NAME(TYPE)(stack_copy, var);                     \
    }                                                                               \
                                                                                    \
    return stack_copy;                                                              \
}


#define EC_STACK_REF_FUNCTIONS(TYPE)            \
    EC_STACK_REF_VAR_FREE_FUNCTION(TYPE)        \
    EC_STACK_REF_FREE_FUNCTION(TYPE)            \
    EC_STACK_REF_NEW_FUNCTION(TYPE)             \
    EC_STACK_REF_NEW_VAR_FUNCTION(TYPE)         \
    EC_STACK_REF_PUSH_FUNCTION(TYPE)            \
    EC_STACK_REF_POP_FUNCTION(TYPE)             \
    EC_STACK_REF_COPY_FUNCTION(TYPE)

#endif // EC_STACK_REF_H



/*-------------------------------------------------------------------------------------*
 *                                  Stack Drop Method                                   *
 *=====================================================================================*/

//void
//EC_STACK_REF_DROP_FUNCTION_NAME(TYPE)
//(
    //EC_STACK_REF_STRUCT(TYPE)* list,
    //EC_STACK_REF_VAR_STRUCT(TYPE)* item
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
//EC_STACK_REF_FREE_VAR_FUNCTION_NAME(TYPE)
//(
    //EC_STACK_REF_STRUCT(TYPE)* list,
    //EC_STACK_REF_VAR_STRUCT(TYPE)* item
//)
//{
    //EC_STACK_REF_DROP_FUNCTION_NAME(TYPE) (list, item);
    //free (item);
//}


/*-------------------------------------------------------------------------------------*
 *                                  Stack Free Stack Method                              *
 *=====================================================================================*/

/*void*/
//EC_STACK_REF_FREE_STACK_FUNCTION_NAME(TYPE)
//(
  //void *list_ptr
//)
//{
  //EC_STACK_REF_STRUCT(TYPE) **list;

  //*list = (EC_STACK_REF_STRUCT(TYPE) *) list_ptr;

  //EC_STACK_REF *current, *temp;

  //current = *(*list)->first;

  //while (current != NULL)
  //{
    //temp = current;
    //current = current->next;
    //free (temp);
    //temp = NULL;
  //}
//}