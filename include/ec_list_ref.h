#ifndef EC_LIST_REF_H
#define EC_LIST_REF_H

#include "ec.h"

#define foreach_list_ref(list)                                                          \
  for (list->var = list->first; list->var != NULL; list->var = list->var->next)


/* Function name macros */
#define EC_LIST_REF_FREE_FUNCTION_NAME(TYPE)            EC_CONCAT2(TYPE, _List_Free) // memory Free
#define EC_LIST_REF_VAR_FREE_FUNCTION_NAME(TYPE)        EC_CONCAT2(TYPE, _List_Var_Free)
#define EC_LIST_REF_NEW_LIST_FUNCTION_NAME(TYPE)        EC_CONCAT2(TYPE, _List)
#define EC_LIST_REF_NEW_VAR_FUNCTION_NAME(TYPE)         EC_CONCAT2(TYPE, _List_Var)
#define EC_LIST_REF_COPY_FUNCTION_NAME(TYPE)            EC_CONCAT2(TYPE, _List_Copy)

#define EC_LIST_REF_APPEND_FUNCTION_NAME(TYPE)          EC_CONCAT2(Append_, TYPE)
#define EC_LIST_REF_INSERT_FUNCTION_NAME(TYPE)          EC_CONCAT2(Insert_, TYPE)
#define EC_LIST_REF_FOREACH(TYPE)                       EC_CONCAT2(Foreach_, TYPE)
#define EC_LIST_REF_REPLACE_FUNCTION_NAME(TYPE)         EC_CONCAT2(Replace_, TYPE)
#define EC_LIST_REF_DROP_FUNCTION_NAME(TYPE)            EC_CONCAT2(Drop_, TYPE)
#define EC_LIST_REF_FREE_VAR_FUNCTION_NAME(TYPE)        EC_CONCAT3(Free_, TYPE, _List_Var)
#define EC_LIST_REF_FREE_LIST_FUNCTION_NAME(TYPE)       EC_CONCAT3(Free_, TYPE, _List)
#define EC_LIST_REF_SORT_FUNCTION_NAME(TYPE, SW)        EC_CONCAT4(Sort_, TYPE, _List_With_, SW)


/* Structure macros */
// EC_MEMORY_REF defined in ec_memory.h
#define EC_LIST_REF_STRUCT(TYPE)                        EC_CONCAT2(TYPE, ListRef)
#define EC_LIST_REF_VAR_STRUCT(TYPE)                    EC_CONCAT2(TYPE, ListVar)
#define EC_LIST_REF_VAR_REF_STRUCT(TYPE)                EC_CONCAT2(TYPE, ListVarRef)


#define EC_LIST_REF(TYPE, VAR)                              \
typedef struct EC_LIST_REF_VAR_STRUCT(TYPE) {               \
    VAR                                                     \
    struct EC_LIST_REF_VAR_STRUCT(TYPE)* next;              \
    struct EC_LIST_REF_VAR_STRUCT(TYPE)* previous;          \
} EC_LIST_REF_VAR_STRUCT(TYPE);                             \
                                                            \
                                                            \
typedef struct EC_LIST_REF_STRUCT(TYPE) {                   \
    EC_LIST_REF_VAR_STRUCT(TYPE)* first;                    \
    EC_LIST_REF_VAR_STRUCT(TYPE)* last;                     \
    EC_LIST_REF_VAR_STRUCT(TYPE)* var;                      \
    EC_MEMORY_REF                                           \
} EC_LIST_REF_STRUCT(TYPE);                                 \
                                                            \
                                                            \
typedef struct EC_LIST_REF_VAR_REF_STRUCT(TYPE) {           \
    struct EC_LIST_REF_VAR_STRUCT(TYPE)* ref;               \
    struct EC_LIST_REF_VAR_REF_STRUCT(TYPE)* next;          \
    struct EC_LIST_REF_VAR_REF_STRUCT(TYPE)* previous;      \
} EC_LIST_REF_VAR_REF_STRUCT(TYPE);                         \
                                                            \
                                                            \
typedef struct EC_LIST_REF_REF_STRUCT(TYPE) {               \
    EC_LIST_REF_VAR_REF_STRUCT(TYPE)* first;                \
    EC_LIST_REF_VAR_REF_STRUCT(TYPE)* last;                 \
    EC_LIST_REF_VAR_REF_STRUCT(TYPE)* var;                  \
    EC_MEMORY_REF                                           \
} EC_LIST_REF_REF_STRUCT(TYPE);

/* Function prototype macros */

#define EC_LIST_REF_FREE_FUNCTION_PROTOTYPE(TYPE)           \
void                                                        \
EC_LIST_REF_FREE_FUNCTION_NAME(TYPE)                        \
(                                                           \
    void* var                                               \
);


#define EC_LIST_REF_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)       \
void                                                        \
EC_LIST_REF_VAR_FREE_FUNCTION_NAME(TYPE)                    \
(                                                           \
    void* var                                               \
);


#define EC_LIST_REF_NEW_FUNCTION_PROTOTYPE(TYPE)            \
EC_LIST_REF_STRUCT(TYPE)*                                   \
EC_LIST_REF_NEW_LIST_FUNCTION_NAME(TYPE)                    \
();


#define EC_LIST_REF_NEW_VAR_FUNCTION_PROTOTYPE(TYPE)        \
EC_LIST_REF_VAR_STRUCT (TYPE)*                              \
EC_LIST_REF_NEW_VAR_FUNCTION_NAME(TYPE)                     \
();


#define EC_LIST_REF_APPEND_FUNCTION_PROTOTYPE(TYPE)         \
void                                                        \
EC_LIST_REF_APPEND_FUNCTION_NAME(TYPE)                      \
(                                                           \
    EC_LIST_REF_STRUCT(TYPE)* list,                         \
    EC_LIST_REF_VAR_STRUCT(TYPE)* var                       \
);


#define EC_LIST_REF_INSERT_FUNCTION_PROTOTYPE(TYPE)         \
void                                                        \
EC_LIST_REF_INSERT_FUNCTION_NAME(TYPE)                      \
(                                                           \
    EC_LIST_REF_STRUCT(TYPE)* list,                         \
    EC_LIST_REF_VAR_STRUCT(TYPE)* var,                      \
    EC_LIST_REF_VAR_STRUCT(TYPE)* ref,                      \
    short pos                                               \
);


#define EC_LIST_REF_REPLACE_FUNCTION_PROTOTYPE(TYPE)        \
void                                                        \
EC_LIST_REF_REPLACE_FUNCTION_NAME(TYPE)                     \
(                                                           \
    EC_LIST_REF_STRUCT(TYPE)* list,                         \
    EC_LIST_REF_VAR_STRUCT(TYPE)* var,                      \
    EC_LIST_REF_VAR_STRUCT(TYPE)* ref                       \
);


#define EC_LIST_REF_SORT_FUNCTION_PROTOTYPE(TYPE, SORT_WITH)\
void                                                        \
EC_LIST_REF_SORT_FUNCTION_NAME (TYPE, SORT_WITH)            \
(                                                           \
    EC_LIST_REF_STRUCT(TYPE)* list                          \
);


#define EC_LIST_REF_DROP_FUNCTION_PROTOTYPE(TYPE)           \
void                                                        \
EC_LIST_REF_DROP_FUNCTION_NAME(TYPE)                        \
(                                                           \
    EC_LIST_REF_STRUCT(TYPE)* list,                         \
    EC_LIST_REF_VAR_STRUCT(TYPE)* var                       \
);


#define EC_LIST_REF_FREE_VAR_FUNCTION_PROTOTYPE(TYPE)       \
void                                                        \
EC_LIST_REF_FREE_VAR_FUNCTION_NAME(TYPE)                    \
(                                                           \
    EC_LIST_REF_STRUCT(TYPE)* list,                         \
    EC_LIST_REF_VAR_STRUCT(TYPE)* var                       \
);


#define EC_LIST_REF_COPY_FUNCTION_PROTOTYPE(TYPE)           \
EC_LIST_REF_STRUCT(TYPE)*                                   \
EC_LIST_REF_COPY_FUNCTION_NAME(TYPE)                        \
(                                                           \
    EC_LIST_REF_STRUCT(TYPE)* list                          \
);


#define EC_LIST_REF_FUNCTION_PROTOTYPES(TYPE)               \
    EC_LIST_REF_FREE_FUNCTION_PROTOTYPE(TYPE)               \
    EC_LIST_REF_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)           \
    EC_LIST_REF_NEW_FUNCTION_PROTOTYPE(TYPE)                \
    EC_LIST_REF_NEW_VAR_FUNCTION_PROTOTYPE(TYPE)            \
    EC_LIST_REF_APPEND_FUNCTION_PROTOTYPE(TYPE)             \
    EC_LIST_REF_INSERT_FUNCTION_PROTOTYPE(TYPE)             \
    EC_LIST_REF_REPLACE_FUNCTION_PROTOTYPE(TYPE)            \
    EC_LIST_REF_DROP_FUNCTION_PROTOTYPE(TYPE)               \
    EC_LIST_REF_FREE_VAR_FUNCTION_PROTOTYPE(TYPE)           \
    EC_LIST_REF_COPY_FUNCTION_PROTOTYPE(TYPE)


/* Function macros */

#define EC_LIST_REF_FREE_FUNCTION(TYPE)                             \
void                                                                \
EC_LIST_REF_FREE_FUNCTION_NAME(TYPE)                                \
(                                                                   \
    void* var                                                       \
)                                                                   \
{                                                                   \
    EC_LIST_REF_STRUCT(TYPE)* p = (EC_LIST_REF_STRUCT(TYPE)*) var;  \
    free (p);                                                       \
}


#define EC_LIST_REF_VAR_FREE_FUNCTION(TYPE)                         \
void                                                                \
EC_LIST_REF_VAR_FREE_FUNCTION_NAME(TYPE)                            \
(                                                                   \
    void* var                                                       \
)                                                                   \
{                                                                   \
    TYPE* v = (TYPE*) var;                                          \
    free (v);                                                       \
    v = NULL;                                                       \
}


#define EC_LIST_REF_NEW_FUNCTION(TYPE)                                                                          \
EC_LIST_REF_STRUCT(TYPE)*                                                                                       \
EC_LIST_REF_NEW_LIST_FUNCTION_NAME(TYPE)                                                                        \
()                                                                                                              \
{                                                                                                               \
    EC_LIST_REF_STRUCT(TYPE)* var = (EC_LIST_REF_STRUCT(TYPE)*) malloc (sizeof (EC_LIST_REF_STRUCT(TYPE)));     \
                                                                                                                \
    if (var == NULL)                                                                                            \
    {                                                                                                           \
        EC_Error_Mem_Alloc (__FILE__, __LINE__);                                                                \
        return NULL;                                                                                            \
    }                                                                                                           \
                                                                                                                \
    var->first = NULL;                                                                                          \
    var->last = NULL;                                                                                           \
                                                                                                                \
    if (EC_MEMORY)                                                                                              \
    {                                                                                                           \
        ECMemory* ec_memory_new = (ECMemory*) malloc (sizeof(ECMemory));                                        \
                                                                                                                \
        if (ec_memory_new == NULL)                                                                              \
        {                                                                                                       \
            EC_Error_Mem_Alloc (__FILE__, __LINE__);                                                            \
            return NULL;                                                                                        \
        }                                                                                                       \
                                                                                                                \
        ec_memory_new->type = EC_LIST_REF_TYPE;                                                                 /* Defined in ec.h */ \
        ec_memory_new->var = var;                                                                               \
        ec_memory_new->lock = EC_LOCK;                                                                          \
        ec_memory_new->Free_Func = EC_LIST_REF_FREE_FUNCTION_NAME (TYPE);                                       \
        ec_memory_new->Free_Var_Func = EC_LIST_REF_VAR_FREE_FUNCTION_NAME (TYPE);                               \
        ec_memory_new->next = NULL;                                                                             \
                                                                                                                \
        EC_Memory_Append (ec_memory_new);                                                                       \
                                                                                                                \
        var->ec_memory_ref = ec_memory_new;                                                                     \
        var->lock = EC_LOCK;                                                                                    \
    }                                                                                                           \
                                                                                                                \
    return var;                                                                                                 \
}


/* New List Variable Function */

#define EC_LIST_REF_NEW_VAR_FUNCTION(TYPE)                                                                                  \
EC_LIST_REF_VAR_STRUCT (TYPE)*                                                                                              \
EC_LIST_REF_NEW_VAR_FUNCTION_NAME(TYPE)                                                                                     \
()                                                                                                                          \
{                                                                                                                           \
    EC_LIST_REF_VAR_STRUCT(TYPE)* var = (EC_LIST_REF_VAR_STRUCT(TYPE)*) malloc (sizeof (EC_LIST_REF_VAR_STRUCT(TYPE)));     \
                                                                                                                            \
    if (var == NULL)                                                                                                        \
    {                                                                                                                       \
        EC_Error_Mem_Alloc (__FILE__, __LINE__);                                                                            \
        return NULL;                                                                                                        \
    }                                                                                                                       \
                                                                                                                            \
    if (EC_MEMORY)                                                                                                          \
    {                                                                                                                       \
        ECMemory* ec_memory_new = (ECMemory*) malloc (sizeof (ECMemory));                                                   \
                                                                                                                            \
        if (ec_memory_new == NULL)                                                                                          \
        {                                                                                                                   \
            EC_Error_Mem_Alloc (__FILE__, __LINE__);                                                                        \
            return NULL;                                                                                                    \
        }                                                                                                                   \
                                                                                                                            \
        ec_memory_new->type = EC_LIST_REF_VAR_TYPE;                                                                         /* Defined in ec.h */ \
        ec_memory_new->var = var;                                                                                           \
        ec_memory_new->lock = EC_NONE_LOCK;                                                                                 \
        ec_memory_new->Free_Func = EC_LIST_REF_VAR_FREE_FUNCTION_NAME (TYPE);                                               \
        ec_memory_new->next = NULL;                                                                                         \
                                                                                                                            \
        EC_Memory_Append (ec_memory_new);                                                                                   \
    }                                                                                                                       \
                                                                                                                            \
    return var;                                                                                                             \
}


#define EC_LIST_REF_REF_FREE_FUNCTION(TYPE)                                 \
void                                                                        \
EC_LIST_REF_REF_FREE_FUNCTION_NAME(TYPE)                                    \
(                                                                           \
    void* var                                                               \
)                                                                           \
{                                                                           \
    EC_LIST_REF_REF_STRUCT(TYPE)* p = (EC_LIST_REF_REF_STRUCT(TYPE)*) var;  \
    free (p);                                                               \
}


#define EC_LIST_REF_REF_VAR_FREE_FUNCTION(TYPE)                 \
void                                                            \
EC_LIST_REF_REF_VAR_FREE_FUNCTION_NAME(TYPE)                    \
(                                                               \
    void* var                                                   \
)                                                               \
{                                                               \
    TYPE* v = (TYPE*) var;                                      \
    free (v);                                                   \
    v = NULL;                                                   \
}


#define EC_LIST_REF_REF_NEW_FUNCTION(TYPE)                                                          \
EC_LIST_REF_REF_STRUCT(TYPE)*                                                                       \
EC_LIST_REF_REF_NEW_LIST_REF_FUNCTION_NAME(TYPE)                                                    \
()                                                                                                  \
{                                                                                                   \
    EC_LIST_REF_REF_STRUCT(TYPE)* var = (EC_LIST_REF_REF_STRUCT(TYPE)*) malloc (sizeof (EC_LIST_REF_REF_STRUCT(TYPE)));     \
                                                                                                    \
    if (var == NULL)                                                                                \
    {                                                                                               \
        EC_Error_Mem_Alloc (__FILE__, __LINE__);                                                    \
        return NULL;                                                                                \
    }                                                                                               \
                                                                                                    \
    var->first = NULL;                                                                              \
    var->last = NULL;                                                                               \
                                                                                                    \
    if (EC_MEMORY)                                                                                  \
    {                                                                                               \
        ECMemory* ec_memory_new = (ECMemory*) malloc (sizeof(ECMemory));                            \
                                                                                                    \
        if (ec_memory_new == NULL)                                                                  \
        {                                                                                           \
            EC_Error_Mem_Alloc (__FILE__, __LINE__);                                                \
            return NULL;                                                                            \
        }                                                                                           \
                                                                                                    \
        ec_memory_new->type = EC_LIST_REF_REF_TYPE;                                                 /* Defined in ec.h */ \
        ec_memory_new->var = var;                                                                   \
        ec_memory_new->lock = EC_LOCK;                                                              \
        ec_memory_new->Free_Func = EC_LIST_REF_REF_FREE_FUNCTION_NAME (TYPE);                       \
        ec_memory_new->Free_Var_Func = EC_LIST_REF_REF_VAR_FREE_FUNCTION_NAME (TYPE);               \
        ec_memory_new->next = NULL;                                                                 \
                                                                                                    \
        EC_Memory_Append (ec_memory_new);                                                           \
                                                                                                    \
        var->ec_memory_ref = ec_memory_new;                                                         \
        var->lock = EC_LOCK;                                                                        \
    }                                                                                               \
                                                                                                    \
    return var;                                                                                     \
}


/* New List Ref Variable Function */

#define EC_LIST_REF_REF_NEW_VAR_FUNCTION(TYPE)                                      \
EC_LIST_REF_REF_VAR_STRUCT (TYPE)*                                                  \
EC_LIST_REF_REF_NEW_VAR_FUNCTION_NAME(TYPE)                                         \
()                                                                                  \
{                                                                                   \
    EC_LIST_REF_REF_VAR_STRUCT(TYPE)* var = (EC_LIST_REF_REF_VAR_STRUCT(TYPE)*)     \
        malloc (sizeof (EC_LIST_REF_REF_VAR_STRUCT(TYPE)));                         \
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
        ec_memory_new->type = EC_LIST_REF_REF_VAR_TYPE;                             /* Defined in ec.h */ \
        ec_memory_new->var = var;                                                   \
        ec_memory_new->lock = EC_NONE_LOCK;                                         \
        ec_memory_new->Free_Func = EC_LIST_REF_REF_VAR_FREE_FUNCTION_NAME (TYPE);   \
        ec_memory_new->next = NULL;                                                 \
                                                                                    \
        EC_Memory_Append (ec_memory_new);                                           \
    }                                                                               \
                                                                                    \
    return var;                                                                     \
}


/* List Append Function */

#define EC_LIST_REF_APPEND_FUNCTION(TYPE)       \
void                                            \
EC_LIST_REF_APPEND_FUNCTION_NAME(TYPE)          \
(                                               \
    EC_LIST_REF_STRUCT(TYPE)* list,             \
    EC_LIST_REF_VAR_STRUCT(TYPE)* var           \
)                                               \
{                                               \
    var->next = NULL;                           \
                                                \
    if (list->first != NULL)                    /* List var exit */ \
    {                                           \
        list->last->next = var;                 \
        var->previous = list->last;             \
    }                                           \
    else                                        /* empty list */ \
    {                                           \
        var->previous = NULL;                   \
        list->first = var;                      \
    }                                           \
                                                \
    list->last = var;                           \
}


/* List Insert Function */
#define EC_LIST_REF_INSERT_FUNCTION(TYPE)       \
void                                            \
EC_LIST_REF_INSERT_FUNCTION_NAME(TYPE)          \
(                                               \
    EC_LIST_REF_STRUCT(TYPE)*       list,       \
    EC_LIST_REF_VAR_STRUCT(TYPE)*   var,        \
    EC_LIST_REF_VAR_STRUCT(TYPE)*   ref,        \
    short pos                                   \
)                                               \
{                                               \
    if (list->first == NULL && ref == NULL)     /* Empty list */ \
    {                                           \
        var->previous = NULL;                   \
        var->next = NULL;                       \
        list->first = var;                      \
        list->last = var;                       \
    }                                           \
    else if (ref == list->first)                /* ref is the first list var */ \
    {                                           \
        if (pos < 0)                            /* Insert befor the first list var */ \
        {                                       \
            var->previous = NULL;               \
            var->next = ref;                    \
            ref->previous = var;                \
            list->first = var;                  \
        }                                       \
        else                                    /* Insert after the first list var */ \
        {                                       \
            if (ref == list->last)              /* ref var is the first and also the last list var */ \
            {                                   \
                var->previous = list->first;    \
                var->next = NULL;               \
                list->first->next = var;        \
                list->last = var;               \
            }                                   \
            else                                /* ref var is the first list var but not the last */ \
            {                                   \
                var->previous = ref;            \
                var->next = ref->next;          \
                ref->next->previous = var;      \
                ref->next = var;                \
            }                                   \
        }                                       \
    }                                           \
    else if (ref == list->last)                 /* ref var is the last list var */ \
    {                                           \
        if (pos < 0)                            /* Insert before the last var */ \
        {                                       \
            var->previous = ref->previous;      \
            var->next = ref;                    \
            ref->previous->next = var;          \
            ref->previous = var;                \
        }                                       \
        else                                    /* insert after the last list var as last var */ \
        {                                       \
            var->previous = ref;                \
            var->next = NULL;                   \
            ref->next = var;                    \
            list->last = var;                   \
        }                                       \
    }                                           \
    else                                        \
    {                                           \
        if (pos < 0)                            /* Insert before the ref var */ \
        {                                       \
            var->previous = ref->previous;      \
            var->next = ref;                    \
            ref->previous->next = var;          \
            ref->previous = var;                \
        }                                       \
        else                                    /* insert after the ref var*/ \
        {                                       \
            var->previous = ref;                \
            var->next = ref->next;              \
            ref->next->previous = var;          \
            ref->next = var;                    \
        }                                       \
    }                                           \
}


/* List Replace Function */

#define EC_LIST_REF_REPLACE_FUNCTION(TYPE)      \
void                                            \
EC_LIST_REF_REPLACE_FUNCTION_NAME(TYPE)         \
(                                               \
    EC_LIST_REF_STRUCT(TYPE)* list,             \
    EC_LIST_REF_VAR_STRUCT(TYPE)* var,          \
    EC_LIST_REF_VAR_STRUCT(TYPE)* ref           \
)                                               \
{                                               \
    if (var == list->first)                     /* ref var is the first var in the list */ \
    {                                           \
        if (var->next == NULL)                  /* ref var is the only var in the list */ \
        {                                       \
            ref->previous = NULL;               \
            ref->next = NULL;                   \
            list->first = ref;                  \
        }                                       \
        else                                    /* ref var is the first var but not the only var in the list */ \
        {                                       \
            ref->previous = NULL;               \
            ref->next = var->next;              \
            var->next->previous = ref;          \
            list->first = ref;                  \
        }                                       \
    }                                           \
    else if (var == list->last)                 /* ref var is the last var in the list */ \
    {                                           \
        ref->previous = var->previous;          \
        ref->next = NULL;                       \
        var->previous->next = ref;              \
    }                                           \
    else                                        /* ref var is an anyother var than the first and the last */ \
    {                                           \
        ref->previous = var->previous;          \
        ref->next = var->next;                  \
        var->previous->next = ref;              \
        var->next->previous = ref;              \
    }                                           \
}


/* List Sort Function */

#define EC_LIST_REF_SORT_FUNCTION(TYPE, SORT_WITH)                      \
void                                                                    \
EC_LIST_REF_SORT_FUNCTION_NAME (TYPE, SORT_WITH)                        \
(                                                                       \
    EC_LIST_REF_STRUCT(TYPE)* list                                      \
)                                                                       \
{                                                                       \
    EC_LIST_REF_VAR_STRUCT(TYPE)* previous;                             \
    EC_LIST_REF_VAR_STRUCT(TYPE)* current;                              \
    EC_LIST_REF_VAR_STRUCT(TYPE)* ref;                                  \
                                                                        \
    ref = list->first;                                                  \
                                                                        \
    while (ref->next != NULL)                                           \
    {                                                                   \
        previous = NULL;                                                \
        current = list->first;                                          \
                                                                        \
        if (ref->SORT_WITH > ref->next->SORT_WITH)                      \
        {                                                               \
            while (current != ref->next)                                \
            {                                                           \
                if (current->SORT_WITH > ref->next->SORT_WITH)          \
                {                                                       \
                    if (previous == NULL)                               /* list first var */ \
                    {                                                   \
                        list->first = ref->next;                        \
                        ref->next = ref->next->next;                    \
                        list->first->next = current;                    \
                    }                                                   \
                    else                                                \
                    {                                                   \
                        previous->next = ref->next;                     \
                        ref->next = ref->next->next;                    \
                        previous->next->next = current;                 \
                    }                                                   \
                                                                        \
                    break;                                              \
                }                                                       \
                else                                                    \
                {                                                       \
                    previous = current;                                 \
                    current = current->next;                            \
                }                                                       \
            }                                                           \
        }                                                               \
        else                                                            \
        {                                                               \
            ref = ref->next;                                            \
        }                                                               \
    }                                                                   \
}


/* List Drop Function */

#define EC_LIST_REF_DROP_FUNCTION(TYPE)             \
void                                                \
EC_LIST_REF_DROP_FUNCTION_NAME(TYPE)                \
(                                                   \
    EC_LIST_REF_STRUCT(TYPE)* list,                 \
    EC_LIST_REF_VAR_STRUCT(TYPE)* var               \
)                                                   \
{                                                   \
    if (var == list->first)                         /* drop the first var in the list */ \
    {                                               \
        if (var->next == NULL)                      \
        {                                           \
            list->first = NULL;                     \
        }                                           \
        else                                        \
        {                                           \
            var->next->previous  = NULL;            \
            list->first = var->next;                \
        }                                           \
    }                                               \
    else if (var == list->last)                     /* drop the last item in the list */ \
    {                                               \
        var->previous->next = NULL;                 \
    }                                               \
    else                                            \
    {                                               \
        var->previous->next = var->next;            \
        var->next->previous = var->previous;        \
    }                                               \
}


/* List Free Variable Function */

#define EC_LIST_REF_FREE_VAR_FUNCTION(TYPE)             \
void                                                    \
EC_LIST_REF_FREE_VAR_FUNCTION_NAME(TYPE)                \
(                                                       \
    EC_LIST_REF_STRUCT(TYPE)* list,                     \
    EC_LIST_REF_VAR_STRUCT(TYPE)* var                   \
)                                                       \
{                                                       \
    EC_LIST_REF_DROP_FUNCTION_NAME(TYPE) (list, var);   \
    free (var);                                         \
}


// Copy array
#define EC_LIST_REF_COPY_FUNCTION(TYPE)                                                 \
EC_LIST_REF_STRUCT(TYPE)*                                                               \
EC_LIST_REF_COPY_FUNCTION_NAME(TYPE)                                                    \
(                                                                                       \
    EC_LIST_REF_STRUCT(TYPE)* list                                                      \
)                                                                                       \
{                                                                                       \
    EC_LIST_REF_STRUCT(TYPE)* list_copy = EC_LIST_REF_NEW_LIST_FUNCTION_NAME(TYPE)();   \
                                                                                        \
    EC_LIST_REF_VAR_STRUCT(TYPE)* var;                                                  \
                                                                                        \
    foreach_list(list)                                                                  \
    {                                                                                   \
        var = EC_LIST_REF_NEW_VAR_FUNCTION_NAME(TYPE)();                                \
        memcpy(var, list->var, sizeof(EC_LIST_REF_VAR_STRUCT(TYPE)));                   \
        EC_LIST_REF_APPEND_FUNCTION_NAME(TYPE)(list_copy, var);                         \
    }                                                                                   \
                                                                                        \
    return list_copy;                                                                   \
}


#define EC_LIST_REF_FUNCTIONS(TYPE)         \
    EC_LIST_REF_FREE_FUNCTION(TYPE)         \
    EC_LIST_REF_VAR_FREE_FUNCTION(TYPE)     \
    EC_LIST_REF_NEW_FUNCTION(TYPE)          \
    EC_LIST_REF_NEW_VAR_FUNCTION(TYPE)      \
    EC_LIST_REF_APPEND_FUNCTION(TYPE)       \
    EC_LIST_REF_INSERT_FUNCTION(TYPE)       \
    EC_LIST_REF_REPLACE_FUNCTION(TYPE)      \
    EC_LIST_REF_DROP_FUNCTION(TYPE)         \
    EC_LIST_REF_FREE_VAR_FUNCTION(TYPE)     \
    EC_LIST_REF_COPY_FUNCTION(TYPE)


#endif // EC_LIST_REF_H


/*-------------------------------------------------------------------------------------*
 *                                  List Free List Function                            *
 *=====================================================================================*/

/*void*/
//EC_LIST_REF_FREE_LIST_FUNCTION_NAME(TYPE)
//(
  //void *list_ptr
//)
//{
  //EC_LIST_REF_STRUCT(TYPE) **list;

  //*list = (EC_LIST_REF_STRUCT(TYPE) *) list_ptr;

  //TYPE *current, *temp;

  //current = *(*list)->first;

  //while (current != NULL)
  //{
    //temp = current;
    //current = current->next;
    //free (temp);
    //temp = NULL;
  //}
//}
