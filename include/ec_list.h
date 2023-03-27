#include "ec.h"

//#define for_list(lst, ec_lst_var, ec_var)                                                                                           \
//    for (ec_lst_var = lst->current = lst->list, ec_var = lst->current != NULL ? lst->current->var: NULL;                            \
//         lst->current != NULL;                                                                                                      \
//         lst->current = lst->current != NULL ? lst->current->next: NULL, ec_var = lst->current != NULL ? lst->current->var: NULL)


#define for_list(lst)                                                                                           \
    for (lst->list_var = lst->list, lst->var = lst->list_var != NULL ? lst->list_var->var: NULL;                            \
         lst->list_var != NULL;                                                                                                      \
         lst->list_var = lst->list_var != NULL ? lst->list_var->next: NULL, lst->var = lst->list_var != NULL ? lst->list_var->var: NULL)


#ifndef EC_LIST_H
#define EC_LIST_H

/* Function name macros */
#define EC_LIST_VAR_FREE_FUNCTION_NAME(TYPE)        EC_CONCAT(TYPE, _List_Var_Free_Func) // *** when change errors
#define EC_LIST_FREE_FUNCTION_NAME(TYPE)            EC_CONCAT(TYPE, _List_Free)
#define EC_LIST_FUNCTION_NAME(TYPE)                 EC_CONCAT(TYPE, _List)
#define EC_LIST_VAR_FUNCTION_NAME(TYPE)             EC_CONCAT(TYPE, _List_Var)
#define EC_LIST_COPY_FUNCTION_NAME(TYPE)            EC_CONCAT(TYPE, _List_Copy)

#define EC_LIST_APPEND_FUNCTION_NAME(TYPE)          EC_CONCAT(TYPE, _Append)
#define EC_LIST_INSERT_BEFORE_FUNCTION_NAME(TYPE)   EC_CONCAT(TYPE, _Insert_Before)
#define EC_LIST_INSERT_AFTER_FUNCTION_NAME(TYPE)    EC_CONCAT(TYPE, _Insert)
#define EC_LIST_REPLACE_FUNCTION_NAME(TYPE)         EC_CONCAT(TYPE, _Replace)
#define EC_LIST_DROP_FUNCTION_NAME(TYPE)            EC_CONCAT(Drop_, TYPE)
#define EC_LIST_SORT_FUNCTION_NAME(TYPE, SW)        EC_CONCAT4(Sort_, TYPE, _List_With_, SW)

#define EC_LIST_VAR_MOVE_UP_FUNCTION_NAME(TYPE)     EC_CONCAT(TYPE, _List_Var_Move_Up)
#define EC_LIST_VAR_MOVE_DOWN_FUNCTION_NAME(TYPE)   EC_CONCAT(TYPE, _List_Var_Move_Down)
#define EC_LIST_VAR_DELETE_FUNCTION_NAME(TYPE)      EC_CONCAT(TYPE, _List_Var_Delete)
#define EC_LIST_VAR_DROP_FUNCTION_NAME(TYPE)        EC_CONCAT(TYPE, _List_Var_Drop)

#define EC_LIST_VAR_EXCHANGE_FUNCTION_NAME(TYPE)    EC_CONCAT(TYPE, _List_Var_Exchange)
#define EC_LIST_VAR_REPLACE_FUNCTION_NAME(TYPE)     EC_CONCAT(TYPE, _List_Var_Replace)
#define EC_LIST_VAR_CHANGE_LIST_FUNCTION_NAME(TYPE) EC_CONCAT(TYPE, _List_Var_Change_List)

//#define EC_LIST_VAR_UNLIST_FUNCTION_NAME(TYPE)      EC_CONCAT(TYPE, _Unlist)
//#define EC_UNLIST_NAME(TYPE)                        EC_CONCAT(TYPE, _unlisted_list)


/* Structure macros */
// EC_MEMORY_REF defined in ec_memory.h
#define EC_LIST_STRUCT(TYPE)                        EC_CONCAT(TYPE, List)
#define EC_LIST_VAR_STRUCT(TYPE)                    EC_CONCAT(TYPE, ListVar)


#define EC_LIST(TYPE)                                   /* VAR should define and pass by user as a macro */\
typedef struct EC_LIST_VAR_STRUCT(TYPE) {               \
    TYPE                            *var;               \
    struct EC_LIST_VAR_STRUCT(TYPE) *next;              \
    struct EC_LIST_VAR_STRUCT(TYPE) *previous;          \
} EC_LIST_VAR_STRUCT(TYPE);                             \
                                                        \
                                                        \
typedef struct EC_LIST_STRUCT(TYPE) {                   \
    EC_LIST_VAR_STRUCT(TYPE) *list;                     /* first var in the list */\
    EC_LIST_VAR_STRUCT(TYPE) *last;                     /* last var in the list */\
    TYPE                     *var;                      /* current (holding) var in the list */\
    EC_LIST_VAR_STRUCT(TYPE) *list_var;                 /* hold var temporaly in for_list repeatition */\
    EC_MEMORY_REF                                       \
} EC_LIST_STRUCT(TYPE);


/*---------------------------*/
/* Function prototype macros */
/*---------------------------*/

#define EC_LIST_FREE_FUNCTION_PROTOTYPE(TYPE)           \
void                                                    \
EC_LIST_FREE_FUNCTION_NAME(TYPE)                        \
(                                                       \
    void *lst                                           \
);


#define EC_LIST_NEW_FUNCTION_PROTOTYPE(TYPE)            \
EC_LIST_STRUCT(TYPE) *                                  \
EC_LIST_FUNCTION_NAME(TYPE)                             \
(void);


#define EC_LIST_APPEND_FUNCTION_PROTOTYPE(TYPE)         \
void                                                    \
EC_LIST_APPEND_FUNCTION_NAME(TYPE)                      \
(                                                       \
    EC_LIST_STRUCT(TYPE)        *list,                  \
    TYPE                        *var                    \
);


/* List Insert Before Function */
#define EC_LIST_INSERT_BEFORE_FUNCTION_PROTOTYPE(TYPE)  \
void                                                    \
EC_LIST_INSERT_BEFORE_FUNCTION_NAME(TYPE)               \
(                                                       \
    EC_LIST_STRUCT(TYPE)        *list,                  \
    EC_LIST_VAR_STRUCT(TYPE)    *ref,                   \
    EC_LIST_VAR_STRUCT(TYPE)    *var                    \
);


/* List Insert After Function */
#define EC_LIST_INSERT_AFTER_FUNCTION_PRTOTYPE(TYPE)    \
void                                                    \
EC_LIST_INSERT_AFTER_FUNCTION_NAME(TYPE)                \
(                                                       \
    EC_LIST_STRUCT(TYPE)        *list,                  \
    EC_LIST_VAR_STRUCT(TYPE)    *ref,                   \
    EC_LIST_VAR_STRUCT(TYPE)    *var                    \
);


#define EC_LIST_FUNCTION_PROTOTYPES(TYPE)               \
    EC_LIST_FREE_FUNCTION_PROTOTYPE(TYPE)               \
    EC_LIST_NEW_FUNCTION_PROTOTYPE(TYPE)                \
    EC_LIST_APPEND_FUNCTION_PROTOTYPE(TYPE)             \
    EC_LIST_INSERT_BEFORE_FUNCTION_PROTOTYPE(TYPE)      \
    EC_LIST_INSERT_AFTER_FUNCTION_PRTOTYPE(TYPE)


/*---------------------------*/
/* Macro Generated Functions */
/*---------------------------*/


#define EC_LIST_FREE_FUNCTION(TYPE)                                 \
void                                                                \
EC_LIST_FREE_FUNCTION_NAME(TYPE)                                    \
(                                                                   \
    void *lst                                                       \
)                                                                   \
{                                                                   \
    EC_LIST_STRUCT(TYPE) *l = (EC_LIST_STRUCT(TYPE) *) lst;         \
}


#define EC_LIST_NEW_FUNCTION(TYPE)                                      \
EC_LIST_STRUCT(TYPE) *                                                  \
EC_LIST_FUNCTION_NAME(TYPE)                                             \
(void)                                                                  \
{                                                                       \
    EC_VAR_CREATE(EC_LIST_STRUCT(TYPE), lst)                            /* This macro in ec_var.h*/\
                                                                        \
    EC_MEMORY_CREATE(ec_memory_new, EC_TYPE_LIST, lst)                  \
                                                                        \
    ec_memory_new->Free_Func = EC_LIST_FREE_FUNCTION_NAME(TYPE);        \
                                                                        \
    lst->list = NULL;                                                   \
    lst->last = NULL;                                                   \
    lst->var = NULL;                                                    \
                                                                        \
    return lst;                                                         \
}


/* List Append Function */
#define EC_LIST_APPEND_FUNCTION(TYPE)                                                                   \
void                                                                                                    \
EC_LIST_APPEND_FUNCTION_NAME(TYPE)                                                                      \
(                                                                                                       \
    EC_LIST_STRUCT(TYPE)        *lst,                                                                   \
    TYPE                        *var                                                                    \
)                                                                                                       \
{                                                                                                       \
    EC_LIST_VAR_STRUCT(TYPE) *list_var = (EC_LIST_VAR_STRUCT(TYPE) *) malloc (sizeof (EC_LIST_VAR_STRUCT(TYPE)));   \
    list_var->var = var;                                                                                \
                                                                                                        \
    list_var->next = NULL;                                                                              \
                                                                                                        \
    if (lst->list != NULL)                                                                              /* List not empty */\
    {                                                                                                   \
        list_var->previous = lst->last;                                                                 \
        lst->last->next = list_var;                                                                     \
    }                                                                                                   \
    else                                                                                                /* empty list */\
    {                                                                                                   \
        list_var->previous = NULL;                                                                      \
        lst->list = list_var;                                                                           \
    }                                                                                                   \
                                                                                                        \
    lst->last = list_var;                                                                               \
}


/* List Insert Before Function */
#define EC_LIST_INSERT_BEFORE_FUNCTION(TYPE)            \
void                                                    \
EC_LIST_INSERT_BEFORE_FUNCTION_NAME(TYPE)               \
(                                                       \
    EC_LIST_STRUCT(TYPE)        *lst,                   \
    EC_LIST_VAR_STRUCT(TYPE)    *ref,                   \
    EC_LIST_VAR_STRUCT(TYPE)    *var                    \
)                                                       \
{                                                       \
    if (lst->list == NULL && ref == NULL)               /* Empty list */\
    {                                                   \
        var->previous = NULL;                           \
        var->next = NULL;                               \
        lst->list = var;                                \
        lst->last = var;                                \
    }                                                   \
    else if (ref == lst->list)                          /* ref is the first list var */\
    {                                                   \
        var->previous = NULL;                           \
        var->next = ref;                                \
        ref->previous = var;                            \
        lst->list = var;                                \
    }                                                   \
    else if (ref == lst->last)                          /* ref var is the last list var */\
    {                                                   \
        var->previous = ref->previous;                  \
        var->next = ref;                                \
        ref->previous->next = var;                      \
        ref->previous = var;                            \
    }                                                   \
    else                                                \
    {                                                   \
        var->previous = ref->previous;                  \
        var->next = ref;                                \
        ref->previous->next = var;                      \
        ref->previous = var;                            \
    }                                                   \
}


/* List Insert After Function */
#define EC_LIST_INSERT_AFTER_FUNCTION(TYPE)             \
void                                                    \
EC_LIST_INSERT_AFTER_FUNCTION_NAME(TYPE)                \
(                                                       \
    EC_LIST_STRUCT(TYPE)        *lst,                   \
    EC_LIST_VAR_STRUCT(TYPE)    *ref,                   \
    EC_LIST_VAR_STRUCT(TYPE)    *var                    \
)                                                       \
{                                                       \
    if (lst->list == NULL && ref == NULL)               /* Empty list */\
    {                                                   \
        var->previous = NULL;                           \
        var->next = NULL;                               \
        lst->list = var;                                \
        lst->last = var;                                \
    }                                                   \
    else if (ref == lst->list)                          /* ref is the first list var */\
    {                                                   \
        if (ref == lst->last)                           /* ref var is the first and also the last list var */ \
        {                                               \
            var->previous = lst->list;                  \
            var->next = NULL;                           \
            lst->list->next = var;                      \
            lst->last = var;                            \
        }                                               \
        else                                            /* ref var is the first list var but not the last */ \
        {                                               \
            var->previous = ref;                        \
            var->next = ref->next;                      \
            ref->next->previous = var;                  \
            ref->next = var;                            \
        }                                               \
    }                                                   \
    else if (ref == lst->last)                          /* ref var is the last list var */\
    {                                                   \
        var->previous = ref;                            \
        var->next = NULL;                               \
        ref->next = var;                                \
        lst->last = var;                                \
    }                                                   \
    else                                                \
    {                                                   \
        var->previous = ref;                            \
        var->next = ref->next;                          \
        ref->next->previous = var;                      \
        ref->next = var;                                \
    }                                                   \
}


#define EC_LIST_FUNCTIONS(TYPE)             \
    EC_LIST_FREE_FUNCTION(TYPE)             \
    EC_LIST_NEW_FUNCTION(TYPE)              \
    EC_LIST_APPEND_FUNCTION(TYPE)           \
    EC_LIST_INSERT_BEFORE_FUNCTION(TYPE)    \
    EC_LIST_INSERT_AFTER_FUNCTION(TYPE)


#endif
