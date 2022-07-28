#ifndef EC_LIST_H
#define EC_LIST_H

#include "ec.h"

/* Anyone can use foreach in ec_type.h interchangebly with this. */
//#define foreach_list(list)  \
    //for (list->var = list->first; list->var != NULL; list->var = list->var_temp)

//list->var_temp = list->var->next
//
#define for_list(list)                                                                              \
    for (list->var = list->first, list->var_temp = list->var != NULL ? list->var->next : NULL;      \
        list->var != NULL;                                                                          \
        list->var = list->var_temp, list->var_temp = list->var != NULL ? list->var->next : NULL)


/* Function name macros */
#define EC_LIST_VAR_FREE_FUNCTION_NAME(TYPE)        EC_CONCAT(TYPE, _List_Var_Free,)
#define EC_LIST_FREE_FUNCTION_NAME(TYPE)            EC_CONCAT(TYPE, _List_Free,)
#define EC_LIST_FUNCTION_NAME(TYPE)                 EC_CONCAT(TYPE, _List,)
#define EC_LIST_VAR_FUNCTION_NAME(TYPE)             EC_CONCAT(TYPE, _List_Var,)
#define EC_LIST_COPY_FUNCTION_NAME(TYPE)            EC_CONCAT(TYPE, _List_Copy,)

#define EC_LIST_APPEND_FUNCTION_NAME(TYPE)          EC_CONCAT(Append_, TYPE,)
#define EC_LIST_INSERT_FUNCTION_NAME(TYPE)          EC_CONCAT(TYPE, _Insert,)
#define EC_LIST_REPLACE_FUNCTION_NAME(TYPE)         EC_CONCAT(TYPE, _Replace,)
#define EC_LIST_DROP_FUNCTION_NAME(TYPE)            EC_CONCAT(Drop_, TYPE,)
#define EC_LIST_SORT_FUNCTION_NAME(TYPE, SW)        EC_CONCAT4(Sort_, TYPE, _List_With_, SW)

#define EC_LIST_VAR_MOVE_UP_FUNCTION_NAME(TYPE)     EC_CONCAT(TYPE, _List_Var_Move_Up,)
#define EC_LIST_VAR_MOVE_DOWN_FUNCTION_NAME(TYPE)   EC_CONCAT(TYPE, _List_Var_Move_Down,)
#define EC_LIST_VAR_DELETE_FUNCTION_NAME(TYPE)      EC_CONCAT(TYPE, _List_Var_Delete,)
#define EC_LIST_VAR_DROP_FUNCTION_NAME(TYPE)        EC_CONCAT(TYPE, _List_Var_Drop,)

#define EC_LIST_VAR_EXCHANGE_FUNCTION_NAME(TYPE)    EC_CONCAT(TYPE, _List_Var_Exchange,)
#define EC_LIST_VAR_REPLACE_FUNCTION_NAME(TYPE)     EC_CONCAT(TYPE, _List_Var_Replace,)
#define EC_LIST_VAR_CHANGE_LIST_FUNCTION_NAME(TYPE) EC_CONCAT(TYPE, _List_Var_Change_List,)

/* Structure macros */
// EC_MEMORY_REF defined in ec_memory.h
#define EC_LIST_STRUCT(TYPE)                        EC_CONCAT(TYPE, List,)
#define EC_LIST_VAR_STRUCT(TYPE)                    EC_CONCAT(TYPE, ListVar,)


#define EC_LIST(TYPE, VAR)                              /* VAR should define and pass by user as a macro */\
typedef struct EC_LIST_VAR_STRUCT(TYPE) {               \
    VAR                                                 \
    struct EC_LIST_VAR_STRUCT(TYPE) *next;              \
    struct EC_LIST_VAR_STRUCT(TYPE) *previous;          \
} EC_LIST_VAR_STRUCT(TYPE);                             \
                                                        \
                                                        \
typedef struct EC_LIST_STRUCT(TYPE) {                   \
    EC_LIST_VAR_STRUCT(TYPE) *first;                    /* first var in the list */\
    EC_LIST_VAR_STRUCT(TYPE) *last;                     /* last var in the list */\
    EC_LIST_VAR_STRUCT(TYPE) *var;                      /* current (holding) var in the list */\
    EC_LIST_VAR_STRUCT(TYPE) *var_temp;                 /* hold var temporaly in for_list repeatition */\
    int n;                                              /* number of vars in the list */\
    EC_MEMORY_REF                                       \
} EC_LIST_STRUCT(TYPE);


/* Function prototype macros */
#define EC_LIST_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)       \
void                                                    \
EC_LIST_VAR_FREE_FUNCTION_NAME(TYPE)                    \
(                                                       \
    void *list,                                         \
    void *var                                           \
);


#define EC_LIST_FREE_FUNCTION_PRTOTYPE(TYPE)            \
void                                                    \
EC_LIST_FREE_FUNCTION_NAME(TYPE)                        \
(                                                       \
    void *list                                          \
);


#define EC_LIST_NEW_FUNCTION_PROTOTYPE(TYPE)            \
EC_LIST_STRUCT(TYPE) *                                  \
EC_LIST_FUNCTION_NAME(TYPE)                             \
(                                                       \
    int n                                               \
);


#define EC_LIST_NEW_VAR_FUNCTION_PROTOTYPE(TYPE)        \
EC_LIST_VAR_STRUCT (TYPE) *                             \
EC_LIST_VAR_FUNCTION_NAME(TYPE)                         \
(                                                       \
    EC_LIST_STRUCT(TYPE) *list                          \
);


#define EC_LIST_APPEND_FUNCTION_PROTOTYPE(TYPE)         \
void                                                    \
EC_LIST_APPEND_FUNCTION_NAME(TYPE)                      \
(                                                       \
    EC_LIST_STRUCT(TYPE)        *list,                  \
    EC_LIST_VAR_STRUCT(TYPE)    *var                    \
);


#define EC_LIST_INSERT_FUNCTION_PROTOTYPE(TYPE)         \
void                                                    \
EC_LIST_INSERT_FUNCTION_NAME(TYPE)                      \
(                                                       \
    EC_LIST_STRUCT(TYPE)        *list,                  \
    EC_LIST_VAR_STRUCT(TYPE)    *var,                   \
    EC_LIST_VAR_STRUCT(TYPE)    *ref,                   \
    short pos                                           \
);


#define EC_LIST_REPLACE_FUNCTION_PROTOTYPE(TYPE)        \
void                                                    \
EC_LIST_REPLACE_FUNCTION_NAME(TYPE)                     \
(                                                       \
    EC_LIST_STRUCT(TYPE)        *list,                  \
    EC_LIST_VAR_STRUCT(TYPE)    *var,                   \
    EC_LIST_VAR_STRUCT(TYPE)    *ref                    \
);


#define EC_LIST_SORT_FUNCTION_PROTOTYPE(TYPE, SORT_WITH)    \
void                                                        \
EC_LIST_SORT_FUNCTION_NAME (TYPE, SORT_WITH)                \
(                                                           \
    EC_LIST_STRUCT(TYPE)    *list                           \
);


#define EC_LIST_DROP_FUNCTION_PROTOTYPE(TYPE)               \
void                                                        \
EC_LIST_DROP_FUNCTION_NAME(TYPE)                            \
(                                                           \
    EC_LIST_STRUCT(TYPE)        *list,                      \
    EC_LIST_VAR_STRUCT(TYPE)    *var                        \
);


#define EC_LIST_COPY_FUNCTION_PROTOTYPE(TYPE)               \
EC_LIST_STRUCT(TYPE) *                                      \
EC_LIST_COPY_FUNCTION_NAME(TYPE)                            \
(                                                           \
    EC_LIST_STRUCT(TYPE)    *list                           \
);


/* new prototypes */
#define EC_LIST_VAR_MOVE_UP_FUNCTION_PROTOTYPE(TYPE)        \
void                                                        \
EC_LIST_VAR_MOVE_UP_FUNCTION_NAME(TYPE)                     \
(                                                           \
    EC_LIST_STRUCT(TYPE)        *list,                      \
    EC_LIST_VAR_STRUCT(TYPE)    *var,                       \
    int                         steps                       \
);


#define EC_LIST_VAR_MOVE_DOWN_FUNCTION_PROTOTYPE(TYPE)      \
void                                                        \
EC_LIST_VAR_MOVE_DOWN_FUNCTION_NAME(TYPE)                   \
(                                                           \
    EC_LIST_STRUCT(TYPE)        *list,                      \
    EC_LIST_VAR_STRUCT(TYPE)    *var,                       \
    int                         steps                       \
);


#define EC_LIST_VAR_DELETE_FUNCTION_PROTOTYPE(TYPE)         \
void                                                        \
EC_LIST_VAR_DELETE_FUNCTION_NAME(TYPE)                      \
(                                                           \
    EC_LIST_STRUCT(TYPE)        *list,                      \
    EC_LIST_VAR_STRUCT(TYPE)    *var                        \
);


#define EC_LIST_VAR_DROP_FUNCTION_PROTOTYPE(TYPE)           \
void                                                        \
EC_LIST_VAR_DROP_FUNCTION_NAME(TYPE)                        \
(                                                           \
    EC_LIST_STRUCT(TYPE)        *list,                      \
    EC_LIST_VAR_STRUCT(TYPE)    *var                        \
);

/* Change order carefuly if you need. EC_LIST_VAR_FREE_FUNCTION use this */
#define EC_LIST_FUNCTION_PROTOTYPES(TYPE)                   \
    EC_LIST_APPEND_FUNCTION_PROTOTYPE(TYPE)                 \
    EC_LIST_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)               \
    EC_LIST_FREE_FUNCTION_PRTOTYPE(TYPE)                    \
    EC_LIST_NEW_FUNCTION_PROTOTYPE(TYPE)                    \
    EC_LIST_NEW_VAR_FUNCTION_PROTOTYPE(TYPE)                \
    EC_LIST_VAR_DELETE_FUNCTION_PROTOTYPE(TYPE)             \
    EC_LIST_VAR_DROP_FUNCTION_PROTOTYPE(TYPE)               \
    EC_LIST_INSERT_FUNCTION_PROTOTYPE(TYPE)                 \
    EC_LIST_REPLACE_FUNCTION_PROTOTYPE(TYPE)                \
    EC_LIST_DROP_FUNCTION_PROTOTYPE(TYPE)                   \
    EC_LIST_COPY_FUNCTION_PROTOTYPE(TYPE)                   \
    EC_LIST_VAR_MOVE_UP_FUNCTION_PROTOTYPE(TYPE)            \
    EC_LIST_VAR_MOVE_DOWN_FUNCTION_PROTOTYPE(TYPE)


/* Function macros */

/* Delete a list variable */
#define EC_LIST_VAR_FREE_FUNCTION(TYPE)                             \
void                                                                \
EC_LIST_VAR_FREE_FUNCTION_NAME(TYPE)                                \
(                                                                   \
    void *list,                                                     \
    void *var                                                       \
)                                                                   \
{                                                                   \
    EC_LIST_STRUCT(TYPE) *l = (EC_LIST_STRUCT(TYPE) *) list;        \
    EC_LIST_VAR_STRUCT(TYPE) *v = (EC_LIST_VAR_STRUCT(TYPE) *) var; \
                                                                    \
    if (v != NULL)                                                  \
    {                                                               \
        if (v->next != NULL)                                        /* not final var */\
        {                                                           \
            if (v->previous != NULL)                                /* not final and first var */\
            {                                                       \
                v->previous->next = v->next;                        \
            }                                                       \
            else                                                    /* not final but first var */\
            {                                                       \
                v->next->previous = NULL;                           \
                l->first = v->next;                                 \
            }                                                       \
        }                                                           \
        else                                                        /* final var */\
        {                                                           \
            if (v->previous != NULL)                                /* final but not first */\
            {                                                       \
                l->last = v->previous;                              \
                l->last->next = NULL;                               \
            }                                                       \
            else                                                    /* first and final var */\
            {                                                       \
                l->first = NULL;                                    \
                l->last = NULL;                                     \
            }                                                       \
        }                                                           \
        if (DEBUG) EC_Print_Error ("ec var free", v);               \
        free (v);                                                   \
    }                                                               \
}


/* new for delete list all */
#define EC_LIST_FREE_FUNCTION(TYPE)                                 \
void                                                                \
EC_LIST_FREE_FUNCTION_NAME(TYPE)                                    \
(                                                                   \
    void *list                                                      \
)                                                                   \
{                                                                   \
    EC_LIST_STRUCT(TYPE) *l = (EC_LIST_STRUCT(TYPE) *) list;        \
                                                                    \
    EC_Memory_Var_Free (l->ec_mem);                                 \
                                                                    \
    for_list (l)                                                    \
    {                                                               \
        EC_LIST_VAR_FREE_FUNCTION_NAME(TYPE)(l, l->var);            \
    }                                                               \
                                                                    \
    free (l);                                                       \
    l = NULL;                                                       \
}


/* New List Variable Function */
#define EC_LIST_NEW_VAR_FUNCTION(TYPE)                              \
EC_LIST_VAR_STRUCT (TYPE) *                                         \
EC_LIST_VAR_FUNCTION_NAME(TYPE)                                     \
(                                                                   \
    EC_LIST_STRUCT(TYPE) *list                                      \
)                                                                   \
{                                                                   \
    EC_VAR_CREATE(EC_LIST_VAR_STRUCT(TYPE), var)                    \
                                                                    \
    EC_LIST_APPEND_FUNCTION_NAME(TYPE) (list, var);                 /* TYPE *var is in this macro in ec_var.h */\
                                                                    \
    return var;                                                     \
}


#define EC_LIST_NEW_FUNCTION(TYPE)                                  \
EC_LIST_STRUCT(TYPE) *                                              \
EC_LIST_FUNCTION_NAME(TYPE)                                         \
(                                                                   \
    int ec_n                                                        \
)                                                                   \
{                                                                   \
    EC_VAR_CREATE(EC_LIST_STRUCT(TYPE), list)                       /* TYPE *var is in this macro in ec_var.h*/\
                                                                    \
    if (EC_MEMORY)                                                  \
    {                                                               \
        EC_MEMORY_CREATE(TYPE, EC_LIST_TYPE, list)                  /* ec_memory_new defined here in ec_memory.h*/\
        ec_memory_new->Free_Func = EC_LIST_FREE_FUNCTION_NAME(TYPE);\
        list->ec_mem = ec_memory_new;                               \
    }                                                               \
                                                                    \
    list->first = NULL;                                             \
    list->last = NULL;                                              \
    list->var = NULL;                                               \
    list->var_temp = NULL;                                          \
    list->n = 0;                                                    \
                                                                    \
    if (ec_n != 0)                                                  \
    {                                                               \
        for (int i = 0; i < ec_n; i++)                              \
        {                                                           \
            EC_LIST_VAR_FUNCTION_NAME(TYPE)(list);                  \
        }                                                           \
    }                                                               \
    else                                                            \
    {                                                               \
    }                                                               \
                                                                    \
    return list;                                                    \
}


#define EC_LIST_VAR_DELETE_FUNCTION(TYPE)                   \
void                                                        \
EC_LIST_VAR_DELETE_FUNCTION_NAME(TYPE)                      \
(                                                           \
    EC_LIST_STRUCT(TYPE)        *list,                      \
    EC_LIST_VAR_STRUCT(TYPE)    *var                        \
)                                                           \
{                                                           \
    if (var != NULL)                                        \
    {                                                       \
        if (var != list->first)                             /* not the first var */\
        {                                                   \
            if (var != list->last)                          /* not the first and the last */\
            {                                               \
                var->next->previous = var->previous;        \
                var->previous->next = var->next;            \
            }                                               \
            else                                            /* not the first but the last */\
            {                                               \
                list->last = var->previous;                 \
                var->previous->next = NULL;                 \
            }                                               \
        }                                                   \
        else                                                /* first var */\
        {                                                   \
            if (var != list->last)                          /* first but not last */\
            {                                               \
                list->first = var->next;                    \
                var->next->previous = NULL;                 \
            }                                               \
            else                                            /* first and last */\
            {                                               \
                list->first = NULL;                         \
                list->last = NULL;                          \
            }                                               \
        }                                                   \
                                                            \
        free (var);                                         \
    }                                                       \
}


#define EC_LIST_VAR_DROP_FUNCTION(TYPE)                     \
void                                                        \
EC_LIST_VAR_DROP_FUNCTION_NAME(TYPE)                        \
(                                                           \
    EC_LIST_STRUCT(TYPE)        *list,                      \
    EC_LIST_VAR_STRUCT(TYPE)    *var                        \
)                                                           \
{                                                           \
                                                            \
}


/* List Append Function */

#define EC_LIST_APPEND_FUNCTION(TYPE)       \
void                                        \
EC_LIST_APPEND_FUNCTION_NAME(TYPE)          \
(                                           \
    EC_LIST_STRUCT(TYPE)        *list,      \
    EC_LIST_VAR_STRUCT(TYPE)    *var        \
)                                           \
{                                           \
    var->next = NULL;                       \
                                            \
    if (list->first != NULL)                /* List not empty */\
    {                                       \
        var->previous = list->last;         \
        list->last->next = var;             \
    }                                       \
    else                                    /* empty list */\
    {                                       \
        var->previous = NULL;               \
        list->first = var;                  \
    }                                       \
                                            \
    list->n++;                              \
    list->last = var;                       \
}


/* List Insert Function */
#define EC_LIST_INSERT_FUNCTION(TYPE)           \
void                                            \
EC_LIST_INSERT_FUNCTION_NAME(TYPE)              \
(                                               \
    EC_LIST_STRUCT(TYPE)        *list,          \
    EC_LIST_VAR_STRUCT(TYPE)    *var,           \
    EC_LIST_VAR_STRUCT(TYPE)    *ref,           \
    short pos                                   \
)                                               \
{                                               \
    if (list->first == NULL && ref == NULL)     /* Empty list */\
    {                                           \
        var->previous = NULL;                   \
        var->next = NULL;                       \
        list->first = var;                      \
        list->last = var;                       \
    }                                           \
    else if (ref == list->first)                /* ref is the first list var */\
    {                                           \
        if (pos < 0)                            /* Insert befor the first list var */\
        {                                       \
            var->previous = NULL;               \
            var->next = ref;                    \
            ref->previous = var;                \
            list->first = var;                  \
        }                                       \
        else                                    /* Insert after the first list var */\
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
    else if (ref == list->last)                 /* ref var is the last list var */\
    {                                           \
        if (pos < 0)                            /* Insert before the last var */\
        {                                       \
            var->previous = ref->previous;      \
            var->next = ref;                    \
            ref->previous->next = var;          \
            ref->previous = var;                \
        }                                       \
        else                                    /* insert after the last list var as last var */\
        {                                       \
            var->previous = ref;                \
            var->next = NULL;                   \
            ref->next = var;                    \
            list->last = var;                   \
        }                                       \
    }                                           \
    else                                        \
    {                                           \
        if (pos < 0)                            /* Insert before the ref var */\
        {                                       \
            var->previous = ref->previous;      \
            var->next = ref;                    \
            ref->previous->next = var;          \
            ref->previous = var;                \
        }                                       \
        else                                    /* insert after the ref var*/\
        {                                       \
            var->previous = ref;                \
            var->next = ref->next;              \
            ref->next->previous = var;          \
            ref->next = var;                    \
        }                                       \
    }                                           \
    list->n++;                                  \
}


    //if (rep->previous != NULL) printf ("rp %d\n", rep->previous->no);\
/* List Replace Function */
#define EC_LIST_REPLACE_FUNCTION(TYPE)          \
void                                            \
EC_LIST_REPLACE_FUNCTION_NAME(TYPE)             \
(                                               \
    EC_LIST_STRUCT(TYPE)        *list,          \
    EC_LIST_VAR_STRUCT(TYPE)    *rep,           /* replaced var */\
    EC_LIST_VAR_STRUCT(TYPE)    *var            /* replaced by var*/\
)                                               \
{                                               \
    if (EC_WARN)                                \
    {                                           \
        if (list->first == NULL)                \
        {                                       \
            EC_Warn_Print_Msg ("List_Var_Replace", "list is empty"); \
            return;                             \
        }                                       \
                                                \
        if (rep == var)                         \
        {                                       \
            EC_Warn_Print_Msg ("List_Var_Replace", "var and rep is same"); \
            return;                             \
        }                                       \
                                                \
        if (var == NULL || rep == NULL)         \
        {                                       \
            EC_Warn_Print_Msg ("List_Var_Replace", "higher than list->n"); \
            return;                             \
        }                                       \
                                                \
        if (rep == var)                         \
        {                                       \
            EC_Warn_Print_Msg ("List_Var_Move_Down var pos", "higher than list->n"); \
            return;                             \
        }                                       \
    }                                           \
                                                \
    if (var->next == rep)                       \
    {                                           \
        if (rep != list->last)                  \
        {                                       \
            var->next = rep->next;              \
            rep->next->previous = var;          \
        }                                       \
        else                                    \
        {                                       \
            list->last = var;                   \
            var->next = NULL;                   \
        }                                       \
                                                \
        goto free_rep;                          \
    }                                           \
                                                \
    if (var->previous == rep)                   \
    {                                           \
        if (rep != list->first)                 \
        {                                       \
            rep->previous->next = var;          \
            var->previous = rep->previous;      \
        }                                       \
        else                                    \
        {                                       \
            list->first = var;                  \
            var->previous = NULL;               \
        }                                       \
                                                \
        goto free_rep;                          \
    }                                           \
                                                \
    if (var == list->first)                     \
    {                                           \
        list->first = var->next;                \
        list->first->previous = NULL;           \
    }                                           \
    else if (var == list->last)                 \
    {                                           \
        list->last = var->previous;             \
        list->last->next = NULL;                \
    }                                           \
    else                                        \
    {                                           \
        var->previous->next = var->next;        \
        var->next->previous = var->previous;    \
    }                                           \
                                                \
    if (rep == list->first)                     \
    {                                           \
        list->first = var;                      \
        list->first->previous = NULL;           \
        list->first->next = rep->next;          \
        rep->next->previous = var;              \
    }                                           \
    else if (rep == list->last)                 \
    {                                           \
        list->last = var;                       \
        list->last->next = NULL;                \
        list->last->previous = rep->previous;   \
        rep->previous->next = var;              \
    }                                           \
    else                                        \
    {                                           \
        rep->next->previous = var;              \
        var->next = rep->next;                  \
        rep->previous->next = var;              \
        var->previous = rep->previous;          \
    }                                           \
                                                \
    free_rep:                                   \
    free (rep);                                 \
}


/* List Sort Function */

#define EC_LIST_SORT_FUNCTION(TYPE, SORT_WITH)                  \
void                                                            \
EC_LIST_SORT_FUNCTION_NAME (TYPE, SORT_WITH)                    \
(                                                               \
    EC_LIST_STRUCT(TYPE) *list                                  \
)                                                               \
{                                                               \
    EC_LIST_VAR_STRUCT(TYPE) *previous;                         \
    EC_LIST_VAR_STRUCT(TYPE) *current;                          \
    EC_LIST_VAR_STRUCT(TYPE) *ref;                              \
                                                                \
    ref = list->first;                                          \
                                                                \
    while (ref->next != NULL)                                   \
    {                                                           \
        previous = NULL;                                        \
        current = list->first;                                  \
                                                                \
        if (ref->SORT_WITH > ref->next->SORT_WITH)              \
        {                                                       \
            while (current != ref->next)                        \
            {                                                   \
                if (current->SORT_WITH > ref->next->SORT_WITH)  \
                {                                               \
                    if (previous == NULL)                       /* list first var */\
                    {                                           \
                        list->first = ref->next;                \
                        ref->next = ref->next->next;            \
                        list->first->next = current;            \
                    }                                           \
                    else                                        \
                    {                                           \
                        previous->next = ref->next;             \
                        ref->next = ref->next->next;            \
                        previous->next->next = current;         \
                    }                                           \
                                                                \
                    break;                                      \
                }                                               \
                else                                            \
                {                                               \
                    previous = current;                         \
                    current = current->next;                    \
                }                                               \
            }                                                   \
        }                                                       \
        else                                                    \
        {                                                       \
            ref = ref->next;                                    \
        }                                                       \
    }                                                           \
}


/* List Drop Function */

#define EC_LIST_DROP_FUNCTION(TYPE)                 \
void                                                \
EC_LIST_DROP_FUNCTION_NAME(TYPE)                    \
(                                                   \
    EC_LIST_STRUCT(TYPE)        *list,              \
    EC_LIST_VAR_STRUCT(TYPE)    *var                \
)                                                   \
{                                                   \
    if (var == list->first)                         /* drop the first var in the list */\
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
    else if (var == list->last)                     /* drop the last item in the list */\
    {                                               \
        var->previous->next = NULL;                 \
    }                                               \
    else                                            \
    {                                               \
        var->previous->next = var->next;            \
        var->next->previous = var->previous;        \
    }                                               \
    list->n--;                                      \
}


// Copy array
#define EC_LIST_COPY_FUNCTION(TYPE)                                         \
EC_LIST_STRUCT(TYPE) *                                                      \
EC_LIST_COPY_FUNCTION_NAME(TYPE)                                            \
(                                                                           \
    EC_LIST_STRUCT(TYPE) *list                                              \
)                                                                           \
{                                                                           \
    EC_LIST_STRUCT(TYPE) *list_copy = EC_LIST_FUNCTION_NAME(TYPE)(list->n); \
                                                                            \
    EC_LIST_VAR_STRUCT(TYPE) *var;                                          \
                                                                            \
    foreach(list)                                                           \
    {                                                                       \
        var = EC_LIST_VAR_FUNCTION_NAME(TYPE)(list);                        \
        memcpy(var, list->var, sizeof(EC_LIST_VAR_STRUCT(TYPE)));           \
        EC_LIST_APPEND_FUNCTION_NAME(TYPE)(list_copy, var);                 \
    }                                                                       \
                                                                            \
    return list_copy;                                                       \
}


/* new functions */
#define EC_LIST_VAR_MOVE_UP_FUNCTION(TYPE)                      \
void                                                            \
EC_LIST_VAR_MOVE_UP_FUNCTION_NAME(TYPE)                         \
(                                                               \
    EC_LIST_STRUCT(TYPE)        *list,                          \
    EC_LIST_VAR_STRUCT(TYPE)    *var,                           \
    int                         steps                           \
)                                                               \
{                                                               \
    int i, pos;                                                 \
    if (var == NULL || steps == 0) return;                      /* unnessary involve should rise a warn */\
                                                                \
    if (list->first != var)                                     /* var is NULL */\
    {                                                           \
        list->var = list->first->next;                          \
        for (i = 1; i < list->n; i++)                           \
        {                                                       \
            if (list->var == var) break;                        \
            list->var = list->var->next;                        \
        }                                                       \
                                                                \
        pos = i - steps;                                        \
        if (pos < 0)                                            \
        {                                                       \
            pos = 0;                                            \
            if (EC_WARN) EC_Warn_Print_Msg ("List_Var_Move_Up var pos", "lower than 0"); \
        }                                                       \
                                                                \
        list->var = list->first;                                \
        for (i = 0; i < pos; i++)                               \
        {                                                       \
            list->var = list->var->next;                        \
        }                                                       \
                                                                \
        var->previous->next = var->next;                        \
        if (list->last != var)                                  \
            var->next->previous = var->previous;                \
        else                                                    \
            list->last = list->last->previous;                  \
                                                                \
        var->previous = list->var->previous;                    \
        if (pos != 0)                                           \
            list->var->previous->next = var;                    \
        else                                                    \
            list->first = var;                                  \
                                                                \
        var->next = list->var;                                  \
        list->var->previous = var;                              \
    }                                                           \
    else                                                        \
    {                                                           \
        if (EC_WARN) EC_Warn_Print_Msg ("List_Var_Move_Up arg *var NULL", "OK"); \
    }                                                           \
}


#define EC_LIST_VAR_MOVE_DOWN_FUNCTION(TYPE)                    \
void                                                            \
EC_LIST_VAR_MOVE_DOWN_FUNCTION_NAME(TYPE)                       \
(                                                               \
    EC_LIST_STRUCT(TYPE)        *list,                          \
    EC_LIST_VAR_STRUCT(TYPE)    *var,                           \
    int                         steps                           \
)                                                               \
{                                                               \
    int i, pos;                                                 \
    if (var == NULL || steps == 0) return;                      /* unnessary involve should rise a warn */\
                                                                \
    if (list->last != var)                                      /* var is NULL */\
    {                                                           \
        list->var = list->first;                                \
        for (i = 0; i < list->n - 1; i++)                       \
        {                                                       \
            if (list->var == var) break;                        \
            list->var = list->var->next;                        \
        }                                                       \
                                                                \
        pos = i + steps;                                        \
        if (pos > list->n)                                      \
        {                                                       \
            pos = list->n;                                      \
            if (EC_WARN) EC_Warn_Print_Msg ("List_Var_Move_Down var pos", "higher than list->n"); \
        }                                                       \
                                                                \
        list->var = list->first;                                \
        for (i = 0; i < pos; i++)                               \
        {                                                       \
            list->var = list->var->next;                        \
        }                                                       \
                                                                \
        var->next->previous = var->previous;                    \
        if (list->first != var)                                 \
            var->previous->next = var->next;                    \
        else                                                    \
            list->first = list->first->next;                    \
                                                                \
        var->next = list->var->next;                            \
        if (pos != list->n - 1)                                 \
            list->var->next->previous = var;                    \
        else                                                    \
            list->last = var;                                   \
                                                                \
        var->previous = list->var;                              \
        list->var->next = var;                                  \
    }                                                           \
    else                                                        \
    {                                                           \
        if (EC_WARN) EC_Warn_Print_Msg ("List_Var_Move_Down arg *var NULL", "OK"); \
    }                                                           \
}


#define EC_LIST_FUNCTIONS(TYPE)         \
    EC_LIST_VAR_FREE_FUNCTION(TYPE)     \
    EC_LIST_FREE_FUNCTION(TYPE)         \
    EC_LIST_NEW_FUNCTION(TYPE)          \
    EC_LIST_NEW_VAR_FUNCTION(TYPE)      \
    EC_LIST_VAR_DELETE_FUNCTION(TYPE)   \
    EC_LIST_APPEND_FUNCTION(TYPE)       \
    EC_LIST_INSERT_FUNCTION(TYPE)       \
    EC_LIST_REPLACE_FUNCTION(TYPE)      \
    EC_LIST_DROP_FUNCTION(TYPE)         \
    EC_LIST_COPY_FUNCTION(TYPE)         \
                                        \
    EC_LIST_VAR_MOVE_UP_FUNCTION(TYPE)  \
    EC_LIST_VAR_MOVE_DOWN_FUNCTION(TYPE)\
    EC_LIST_VAR_DROP_FUNCTION(TYPE)

#endif // EC_LIST_H
