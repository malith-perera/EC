#include "ec.h"

#ifndef EC_LIST_H
#define EC_LIST_H


/* Anyone can use foreach in ec_type.h interchangebly with this. */
/* #define foreach_list(lst)  \ */
/*     for (lst->var = lst->list; lst->var != NULL; lst->var = lst->var_next) */

//lst->var_next = lst->var->next


//#define foreach_list(lst)                                                                           \
//    for (lst->var = lst->list, lst->var_next = lst->var != NULL ? lst->var->next : NULL;            \
//        lst->var != NULL;                                                                           \
//        lst->var = lst->var_next, lst->var_next = lst->var != NULL ? lst->var->next : NULL)


#define for_list(ec_list, ec_var)                                                                                               \
    StudentList *EC_CONCAT3(current, _, ec_var) = ec_list;                                                                      \
    Student *ec_var;                                                                                                            \
    if (EC_CONCAT3(current, _, ec_var)) {ec_var = EC_CONCAT3(current, _, ec_var)->var;}                                         \
    for (;                                                                                                                      \
         EC_CONCAT3(current, _, ec_var) != NULL;                                                                                \
         EC_CONCAT3(current, _, ec_var) = EC_CONCAT3(current, _, ec_var) != NULL ? EC_CONCAT3(current, _, ec_var)->next: NULL,  \
         ec_var = EC_CONCAT3(current, _, ec_var) != NULL? EC_CONCAT3(current, _, ec_var)->var: NULL)


#define foreach_drop(ec_list, ec_var)                                                                                           \
    StudentList *EC_CONCAT3(current, _, ec_var) = ec_list;                                                                      \
    StudentList *EC_CONCAT3(previous, _, ec_var) = NULL;                                                                        \
    Student *ec_var;                                                                                                            \
    if (EC_CONCAT3(current, _, ec_var)) {ec_var = EC_CONCAT3(current, _, ec_var)->var;}                                         \
    for (;                                                                                                                      \
         EC_CONCAT3(current, _, ec_var) != NULL;                                                                                \
         EC_CONCAT3(previous, _, ec_var) = EC_CONCAT3(current, _, ec_var),                                                      \
         EC_CONCAT3(current, _, ec_var) = EC_CONCAT3(current, _, ec_var) != NULL ? EC_CONCAT3(current, _, ec_var)->next: NULL,  \
         ec_var = EC_CONCAT3(current, _, ec_var) != NULL? EC_CONCAT3(current, _, ec_var)->var: NULL)


#define drop_var(ec_list, ec_var)                                                               \
    if (EC_CONCAT3(previous, _, ec_var) != NULL)                                                \
    {                                                                                           \
        EC_CONCAT3(previous, _, ec_var)->next = EC_CONCAT3(current, _, ec_var)->next;           \
        EC_CONCAT3(current, _, ec_var) = EC_CONCAT3(previous, _, ec_var);                       \
    }                                                                                           \
    else                                                                                        \
    {                                                                                           \
        ec_list = (EC_CONCAT3(current, _, ec_var))->next;                                       \
    }


//foreach(list, student)
//{
//    printf ("%d %d\n", i, student->age);
//
//    //if (student->age == 6 && student->grade == 1)
//    //    drop_var (list, student); 
//}


/* Function name macros */
#define EC_LIST_VAR_FREE_FUNCTION_NAME(TYPE)        EC_CONCAT(TYPE, _List_Var_Free_Func) // *** when change errors
#define EC_LIST_FREE_FUNCTION_NAME(TYPE)            EC_CONCAT(TYPE, _List_Free)
#define EC_LIST_FUNCTION_NAME(TYPE)                 EC_CONCAT(TYPE, _List)
#define EC_LIST_VAR_FUNCTION_NAME(TYPE)             EC_CONCAT(TYPE, _List_Var)
#define EC_LIST_COPY_FUNCTION_NAME(TYPE)            EC_CONCAT(TYPE, _List_Copy)

#define EC_LIST_APPEND_FUNCTION_NAME(TYPE)          EC_CONCAT(Append_, TYPE)
#define EC_LIST_INSERT_FUNCTION_NAME(TYPE)          EC_CONCAT(TYPE, _Insert)
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


#define EC_LIST(TYPE)                                   /* VAR should define and pass by user as a macro */\
typedef struct EC_LIST_STRUCT(TYPE) {                   \
    TYPE *list;                                         /* first var in the list */\
    TYPE *last;                                         /* last var in the list */\
    TYPE *var;                                          /* current (holding) var in the list */\
    struct EC_LIST_STRUCT(TYPE) *current;                      /* hold var temporaly in for_list repeatition */\
    struct EC_LIST_STRUCT(TYPE) *previous;              \
    struct EC_LIST_STRUCT(TYPE) *next;                  \
    EC_MEMORY_REF                                       \
} EC_LIST_STRUCT(TYPE);                                 \
                                                        \
EC_LIST_STRUCT(TYPE) *EC_UNLIST_NAME(TYPE);


/* Function prototype macros */
#define EC_LIST_VAR_EXIST_PROTOTYPE(TYPE)               \
bool                                                    \
EC_LIST_VAR_EXIST_FUNCTION_NAME(TYPE)                   \
(                                                       \
    EC_LIST_STRUCT(TYPE)        *lst,                   \
    TYPE                        *var                    \
);


#define EC_LIST_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)       \
void                                                    \
EC_LIST_VAR_FREE_FUNCTION_NAME(TYPE)                    \
(                                                       \
    EC_LIST_STRUCT(TYPE)        *lst,                   \
    TYPE                        *var                    \
);


#define EC_LIST_FREE_FUNCTION_PRTOTYPE(TYPE)            \
void                                                    \
EC_LIST_FREE_FUNCTION_NAME(TYPE)                        \
(                                                       \
    void *lst                                           \
);


#define EC_LIST_NEW_FUNCTION_PRTOTYPE(TYPE)             \
EC_LIST_STRUCT(TYPE) *                                  \
EC_LIST_FUNCTION_NAME(TYPE)                             \
();                  


#define EC_LIST_FUNCTION_PROTOTYPES(TYPE)               \
    EC_LIST_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)           \
    EC_LIST_FREE_FUNCTION_PRTOTYPE(TYPE)                \
    EC_LIST_NEW_FUNCTION_PRTOTYPE(TYPE)


#define EC_LIST_NEW_FUNCTION(TYPE)                                      \
EC_LIST_STRUCT(TYPE) *                                                  \
EC_LIST_FUNCTION_NAME(TYPE)                                             \
()                                                                      \
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


#define EC_LIST_FUNCTIONS(TYPE)             \
    EC_LIST_VAR_FREE_FUNCTION(TYPE)         \
    EC_LIST_NEW_FUNCTION(TYPE)


#endif // EC_LIST_H
     





#if 0






#define EC_LIST_VAR_DELETE_FUNCTION(TYPE)                   \
void                                                        \
EC_LIST_VAR_DELETE_FUNCTION_NAME(TYPE)                      \
(                                                           \
    EC_LIST_STRUCT(TYPE)        *lst,                       \
    TYPE                        *var                        \
)                                                           \
{                                                           \
    if (var != NULL)                                        \
    {                                                       \
        if (var != lst->list)                               /* not the first var */\
        {                                                   \
            if (var != lst->last)                           /* not the first and the last */\
            {                                               \
                var->next->previous = var->previous;        \
                var->previous->next = var->next;            \
            }                                               \
            else                                            /* not the first but the last */\
            {                                               \
                lst->last = var->previous;                  \
                var->previous->next = NULL;                 \
            }                                               \
        }                                                   \
        else                                                /* first var */\
        {                                                   \
            if (var != lst->last)                           /* first but not last */\
            {                                               \
                lst->list = var->next;                      \
                var->next->previous = NULL;                 \
            }                                               \
            else                                            /* first and last */\
            {                                               \
                lst->list = NULL;                           \
                lst->last = NULL;                           \
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
    EC_LIST_STRUCT(TYPE)        *lst,                       \
    TYPE                        *var                        \
)                                                           \
{                                                           \
                                                            \
}


/* List Append Function */
#define EC_LIST_APPEND_FUNCTION(TYPE)       \
void                                        \
EC_LIST_APPEND_FUNCTION_NAME(TYPE)          \
(                                           \
    EC_LIST_STRUCT(TYPE)        *lst,       \
    TYPE                        *var        \
)                                           \
{                                           \
    var->next = NULL;                       \
                                            \
    if (lst->list != NULL)                  /* List not empty */\
    {                                       \
        var->previous = lst->last;          \
        lst->last->next = var;              \
    }                                       \
    else                                    /* empty list */\
    {                                       \
        var->previous = NULL;               \
        lst->list = var;                    \
    }                                       \
                                            \
    lst->n++;                               \
    lst->last = var;                        \
}


/* List Insert Function */
#define EC_LIST_INSERT_FUNCTION(TYPE)           \
void                                            \
EC_LIST_INSERT_FUNCTION_NAME(TYPE)              \
(                                               \
    EC_LIST_STRUCT(TYPE)        *lst,           \
    TYPE                        *var,           \
    TYPE                        *ref,           \
    short                       pos             \
)                                               \
{                                               \
    if (lst->list == NULL && ref == NULL)       /* Empty list */\
    {                                           \
        var->previous = NULL;                   \
        var->next = NULL;                       \
        lst->list = var;                        \
        lst->last = var;                        \
    }                                           \
    else if (ref == lst->list)                  /* ref is the first list var */\
    {                                           \
        if (pos < 0)                            /* Insert befor the first list var */\
        {                                       \
            var->previous = NULL;               \
            var->next = ref;                    \
            ref->previous = var;                \
            lst->list = var;                    \
        }                                       \
        else                                    /* Insert after the first list var */\
        {                                       \
            if (ref == lst->last)               /* ref var is the first and also the last list var */ \
            {                                   \
                var->previous = lst->list;      \
                var->next = NULL;               \
                lst->list->next = var;           \
                lst->last = var;                \
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
    else if (ref == lst->last)                  /* ref var is the last list var */\
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
            lst->last = var;                    \
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
    lst->n++;                                   \
}


    //if (rep->previous != NULL) printf ("rp %d\n", rep->previous->no);\
/* List Replace Function */
#define EC_LIST_REPLACE_FUNCTION(TYPE)          \
void                                            \
EC_LIST_REPLACE_FUNCTION_NAME(TYPE)             \
(                                               \
    EC_LIST_STRUCT(TYPE)        *lst,           \
    TYPE                        *rep,           /* replaced rep */\
    TYPE                        *var            /* replaced by var*/\
)                                               \
{                                               \
    if (EC_WARN)                                \
    {                                           \
        if (lst->list == NULL)                  \
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
            EC_Warn_Print_Msg ("List_Var_Replace", "higher than lst->n"); \
            return;                             \
        }                                       \
                                                \
        if (rep == var)                         \
        {                                       \
            EC_Warn_Print_Msg ("List_Var_Move_Down var pos", "higher than lst->n"); \
            return;                             \
        }                                       \
    }                                           \
                                                \
    if (var->next == rep)                       \
    {                                           \
        if (rep != lst->last)                   \
        {                                       \
            var->next = rep->next;              \
            rep->next->previous = var;          \
        }                                       \
        else                                    \
        {                                       \
            lst->last = var;                    \
            var->next = NULL;                   \
        }                                       \
                                                \
        goto free_rep;                          \
    }                                           \
                                                \
    if (var->previous == rep)                   \
    {                                           \
        if (rep != lst->list)                   \
        {                                       \
            rep->previous->next = var;          \
            var->previous = rep->previous;      \
        }                                       \
        else                                    \
        {                                       \
            lst->list = var;                    \
            var->previous = NULL;               \
        }                                       \
                                                \
        goto free_rep;                          \
    }                                           \
                                                \
    if (var == lst->list)                       \
    {                                           \
        lst->list = var->next;                  \
        lst->list->previous = NULL;             \
    }                                           \
    else if (var == lst->last)                  \
    {                                           \
        lst->last = var->previous;              \
        lst->last->next = NULL;                 \
    }                                           \
    else                                        \
    {                                           \
        var->previous->next = var->next;        \
        var->next->previous = var->previous;    \
    }                                           \
                                                \
    if (rep == lst->list)                       \
    {                                           \
        lst->list = var;                        \
        lst->list->previous = NULL;             \
        lst->list->next = rep->next;            \
        rep->next->previous = var;              \
    }                                           \
    else if (rep == lst->last)                  \
    {                                           \
        lst->last = var;                        \
        lst->last->next = NULL;                 \
        lst->last->previous = rep->previous;    \
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
    EC_LIST_STRUCT(TYPE) *lst                                   \
)                                                               \
{                                                               \
    TYPE *previous;                         \
    TYPE *current;                          \
    TYPE *ref;                              \
                                                                \
    ref = lst->list;                                            \
                                                                \
    while (ref->next != NULL)                                   \
    {                                                           \
        previous = NULL;                                        \
        current = lst->list;                                    \
                                                                \
        if (ref->SORT_WITH > ref->next->SORT_WITH)              \
        {                                                       \
            while (current != ref->next)                        \
            {                                                   \
                if (current->SORT_WITH > ref->next->SORT_WITH)  \
                {                                               \
                    if (previous == NULL)                       /* list first var */\
                    {                                           \
                        lst->list = ref->next;                  \
                        ref->next = ref->next->next;            \
                        lst->lst->next = current;               \
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
    EC_LIST_STRUCT(TYPE)        *lst,               \
    TYPE                        *var                \
)                                                   \
{                                                   \
    if (var == lst->list)                           /* drop the first var in the list */\
    {                                               \
        if (var->next == NULL)                      \
        {                                           \
            lst->list = NULL;                       \
        }                                           \
        else                                        \
        {                                           \
            var->next->previous  = NULL;            \
            lst->list = var->next;                  \
        }                                           \
    }                                               \
    else if (var == lst->last)                      /* drop the last item in the list */\
    {                                               \
        var->previous->next = NULL;                 \
    }                                               \
    else                                            \
    {                                               \
        var->previous->next = var->next;            \
        var->next->previous = var->previous;        \
    }                                               \
    lst->n--;                                       \
}


// Copy array
#define EC_LIST_COPY_FUNCTION(TYPE)                                         \
EC_LIST_STRUCT(TYPE) *                                                      \
EC_LIST_COPY_FUNCTION_NAME(TYPE)                                            \
(                                                                           \
    EC_LIST_STRUCT(TYPE) *lst                                               \
)                                                                           \
{                                                                           \
    EC_LIST_STRUCT(TYPE) *list_copy = EC_LIST_FUNCTION_NAME(TYPE)(lst->n);  \
                                                                            \
    TYPE *var;                                          \
                                                                            \
    for_list(lst)                                                           \
    {                                                                       \
        var = EC_LIST_VAR_FUNCTION_NAME(TYPE)(lst);                         \
        memcpy(var, lst->var, sizeof(TYPE));            \
        EC_LIST_APPEND_FUNCTION_NAME(TYPE)(list_copy, var);                 \
    }                                                                       \
                                                                            \
    return list_copy;                                                       \
}


/* Move up functions */
#define EC_LIST_VAR_MOVE_UP_FUNCTION(TYPE)                      \
void                                                            \
EC_LIST_VAR_MOVE_UP_FUNCTION_NAME(TYPE)                         \
(                                                               \
    EC_LIST_STRUCT(TYPE)        *lst,                           \
    TYPE                        *var,                           \
    int                         steps                           \
)                                                               \
{                                                               \
    int i, pos;                                                 \
    if (var == NULL || steps == 0) return;                      /* unnessary involve should rise a warn */\
                                                                \
    if (lst->list != var)                                       /* var is NULL */\
    {                                                           \
        lst->var = lst->list->next;                             \
        for (i = 1; i < lst->n; i++)                            \
        {                                                       \
            if (lst->var == var) break;                         \
            lst->var = lst->var->next;                          \
        }                                                       \
                                                                \
        pos = i - steps;                                        \
        if (pos < 0)                                            \
        {                                                       \
            pos = 0;                                            \
            if (EC_WARN) EC_Warn_Print_Msg ("List_Var_Move_Up var pos", "lower than 0"); \
        }                                                       \
                                                                \
        lst->var = lst->list;                                   \
        for (i = 0; i < pos; i++)                               \
        {                                                       \
            lst->var = lst->var->next;                          \
        }                                                       \
                                                                \
        var->previous->next = var->next;                        \
        if (lst->last != var)                                   \
            var->next->previous = var->previous;                \
        else                                                    \
            lst->last = lst->last->previous;                    \
                                                                \
        var->previous = lst->var->previous;                     \
        if (pos != 0)                                           \
            lst->var->previous->next = var;                     \
        else                                                    \
            lst->list = var;                                    \
                                                                \
        var->next = lst->var;                                   \
        lst->var->previous = var;                               \
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
    EC_LIST_STRUCT(TYPE)        *lst,                           \
    TYPE                        *var,                           \
    int                         steps                           \
)                                                               \
{                                                               \
    int i, pos;                                                 \
    if (var == NULL || steps == 0) return;                      /* unnecessary involve should rise a warn */\
                                                                \
    if (lst->last != var)                                       /* var is NULL */\
    {                                                           \
        lst->var = lst->list;                                   \
        for (i = 0; i < lst->n - 1; i++)                        \
        {                                                       \
            if (lst->var == var) break;                         \
            lst->var = lst->var->next;                          \
        }                                                       \
                                                                \
        pos = i + steps;                                        \
        if (pos > lst->n)                                       \
        {                                                       \
            pos = lst->n;                                       \
            if (EC_WARN) EC_Warn_Print_Msg ("List_Var_Move_Down var pos", "higher than lst->n"); \
        }                                                       \
                                                                \
        lst->var = lst->list;                                   \
        for (i = 0; i < pos; i++)                               \
        {                                                       \
            lst->var = lst->var->next;                          \
        }                                                       \
                                                                \
        var->next->previous = var->previous;                    \
        if (lst->list != var)                                   \
            var->previous->next = var->next;                    \
        else                                                    \
            lst->list = lst->list->next;                        \
                                                                \
        var->next = lst->var->next;                             \
        if (pos != lst->n - 1)                                  \
            lst->var->next->previous = var;                     \
        else                                                    \
            lst->last = var;                                    \
                                                                \
        var->previous = lst->var;                               \
        lst->var->next = var;                                   \
    }                                                           \
    else                                                        \
    {                                                           \
        if (EC_WARN) EC_Warn_Print_Msg ("List_Var_Move_Down arg *var NULL", "OK"); \
    }                                                           \
}


/*
#define EC_LIST_VAR_UNLIST_FUNCTION(TYPE)                               \
void                                                                    \
EC_LIST_VAR_UNLIST_FUNCTION_NAME(TYPE)                                  \
(                                                                       \
    EC_LIST_STRUCT(TYPE)        *lst,                                   \
    TYPE                        *var                                    \
)                                                                       \
{                                                                       \
    if (EC_UNLIST_NAME(TYPE) == NULL)                                   \
    {                                                                   \
        EC_UNLIST_NAME(TYPE) = EC_LIST_FUNCTION_NAME(TYPE)(0);          \
    }                                                                   \
                                                                        \
    EC_LIST_DROP_FUNCTION_NAME(TYPE) (lst, var);                        \
    EC_LIST_APPEND_FUNCTION_NAME(TYPE) (EC_UNLIST_NAME(TYPE), var);     \
}

*/

#define EC_LIST_FUNCTIONS(TYPE)             \
    EC_LIST_VAR_EXIST_FUNCTION(TYPE)        \
    EC_LIST_VAR_FREE_FUNCTION(TYPE)         \
    EC_LIST_FREE_FUNCTION(TYPE)             \
    EC_LIST_NEW_VAR_FUNCTION(TYPE)          \
    EC_LIST_VAR_DELETE_FUNCTION(TYPE)       \
    EC_LIST_APPEND_FUNCTION(TYPE)           \
    EC_LIST_INSERT_FUNCTION(TYPE)           \
    EC_LIST_REPLACE_FUNCTION(TYPE)          \
    EC_LIST_DROP_FUNCTION(TYPE)             \
    EC_LIST_COPY_FUNCTION(TYPE)             \
                                            \
    EC_LIST_VAR_MOVE_UP_FUNCTION(TYPE)      \
    EC_LIST_VAR_MOVE_DOWN_FUNCTION(TYPE)    \
    EC_LIST_VAR_DROP_FUNCTION(TYPE)     
    /*EC_LIST_VAR_UNLIST_FUNCTION(TYPE)*/

#endif
