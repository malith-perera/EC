#ifndef EC_ARRAY_H
#define EC_ARRAY_H

#include "ec.h"


#define foreach_array(array)                                                                            \
    array->i = 0;                                                                                       \
    for (array->var = array->index; array->i < array->length; array->var = array->index + ++array->i)


#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))

/*
#define EC_ARRAY_FIND_FUNCTION_NAME(T, F) EC_CONCAT(Find_, T, F)
#define EC_ARRAY_RESIZE_FUNCTION_NAME(TYPE) EC_CONCAT(Resize_, T,)
*/

/* Function name macros */
#define EC_ARRAY_FREE_FUNCTION_NAME(TYPE)           EC_CONCAT(TYPE, _Array_Free,) // memory Free
#define EC_ARRAY_FREE_ONE_FUNCTION_NAME(TYPE)       EC_CONCAT(TYPE, _Array_Free_One,)
#define EC_ARRAY_UNLOCK_FUNCTION_NAME(TYPE)         EC_CONCAT(TYPE, _Array_Unlock,)
#define EC_ARRAY_NEW_FUNCTION_NAME(TYPE)            EC_CONCAT(TYPE, _Array,)
#define EC_ARRAY_COPY_FUNCTION_NAME(TYPE)           EC_CONCAT(TYPE, _Array_Copy,)
#define EC_ARRAY_REVERSE_FUNCTION_NAME(TYPE)        EC_CONCAT(TYPE, _Array, _Reverse)
#define EC_ARRAY_SORT_FUNCTION_NAME(TYPE, SW)       EC_CONCAT(TYPE, _Array_Sort_With_, SW)
#define EC_ARRAY_INT_FUNCTION_NAME(TYPE, SW)        EC_CONCAT(TYPE, _Array_Int_, SW)
#define EC_ARRAY_STR_FUNCTION_NAME(TYPE, SW)        EC_CONCAT(TYPE, _Array_Str_, SW)
#define EC_ARRAY_MAX_FUNCTION_NAME(TYPE, SW)        EC_CONCAT(TYPE, _Array_Max_, SW)
#define EC_ARRAY_MIN_FUNCTION_NAME(TYPE, SW)        EC_CONCAT(TYPE, _Array_Min_, SW)


/* Structure macros */
// defined in ec_memory.h
#define EC_ARRAY_STRUCT(TYPE)           EC_CONCAT(TYPE, Array,)

#define EC_ARRAY(TYPE)                                  \
typedef struct EC_ARRAY_STRUCT(TYPE) {                  \
    TYPE*           index;                              \
    int             length;                             \
    int             i;                                  \
    TYPE*           var;                                \
    EC_MEMORY_REF                                       \
} EC_ARRAY_STRUCT(TYPE);


/* Function prototype macros */

#define EC_ARRAY_FREE_FUNCTION_PROTOTYPE(TYPE)          \
void                                                    \
EC_ARRAY_FREE_FUNCTION_NAME(TYPE)                       \
(                                                       \
    void* var                                           \
);


#define EC_ARRAY_FREE_ONE_FUNCTION_PROTOTYPE(TYPE)      \
void                                                    \
EC_ARRAY_FREE_ONE_FUNCTION_NAME(TYPE)                   \
(                                                       \
    void* var                                           \
);


#define EC_ARRAY_UNLOCK_FUNCTION_PROTOTYPE(TYPE)        \
void                                                    \
EC_ARRAY_UNLOCK_FUNCTION_NAME(TYPE)                     \
(                                                       \
    void* var                                           \
);


#define EC_ARRAY_NEW_FUNCTION_PROTOTYPE(TYPE)           \
EC_ARRAY_STRUCT(TYPE)*                                  \
EC_ARRAY_NEW_FUNCTION_NAME(TYPE)                        \
(                                                       \
    int length                                          \
);


#define EC_ARRAY_COPY_FUNCTION_PROTOTYPE(TYPE)          \
EC_ARRAY_STRUCT(TYPE)*                                  \
EC_ARRAY_COPY_FUNCTION_NAME(TYPE)                       \
(                                                       \
    EC_ARRAY_STRUCT(TYPE)* array                        \
);


#define EC_ARRAY_REVERSE_FUNCTION_PROTOTYPE(TYPE)       \
void                                                    \
EC_ARRAY_REVERSE_FUNCTION_NAME(TYPE)                    \
(                                                       \
    EC_ARRAY_STRUCT(TYPE)* array                        \
);


#define EC_ARRAY_FUNCTION_PROTOTYPES(TYPE)              \
    EC_ARRAY_FREE_FUNCTION_PROTOTYPE(TYPE)              \
    EC_ARRAY_FREE_ONE_FUNCTION_PROTOTYPE(TYPE)          \
    EC_ARRAY_UNLOCK_FUNCTION_PROTOTYPE(TYPE)            \
    EC_ARRAY_NEW_FUNCTION_PROTOTYPE(TYPE)               \
    EC_ARRAY_COPY_FUNCTION_PROTOTYPE(TYPE)              \
    EC_ARRAY_REVERSE_FUNCTION_PROTOTYPE(TYPE)


#define EC_ARRAY_SORT_FUNCTION_PROTOTYPE(TYPE, SW)      \
void                                                    \
EC_ARRAY_SORT_FUNCTION_NAME(TYPE, SW)                   \
(                                                       \
    EC_ARRAY_STRUCT(TYPE)* array                        \
);


#define EC_ARRAY_INT_FUNCTION_PROTOTYPE(TYPE, SW)       \
int                                                     \
EC_ARRAY_INT_FUNCTION_NAME(TYPE, SW)                    \
(                                                       \
    EC_ARRAY_STRUCT(TYPE)*  array,                      \
    int                     search_value                \
);


#define EC_ARRAY_STR_FUNCTION_PROTOTYPE(TYPE, SW)       \
int                                                     \
EC_ARRAY_STR_FUNCTION_NAME(TYPE, SW)                    \
(                                                       \
    EC_ARRAY_STRUCT(TYPE)*  array,                      \
    char*                   search_value                \
);


#define EC_ARRAY_MAX_FUNCTION_PROTOTYPE(TYPE, SW)       \
TYPE*                                                   \
EC_ARRAY_MAX_FUNCTION_NAME(TYPE, SW)                    \
(                                                       \
    EC_ARRAY_STRUCT(TYPE)* array                        \
);


#define EC_ARRAY_MIN_FUNCTION_PROTOTYPE(TYPE, SW)       \
TYPE*                                                   \
EC_ARRAY_MIN_FUNCTION_NAME(TYPE, SW)                    \
(                                                       \
    EC_ARRAY_STRUCT(TYPE)* array                        \
);


#define EC_ARRAY_SW_FUNCTION_PROTOTYPES(TYPE, SW)       /* SW for Search With or Sort With */ \
    EC_ARRAY_SORT_FUNCTION_PROTOTYPE(TYPE, SW)          \
    EC_ARRAY_INT_FUNCTION_PROTOTYPE(TYPE, SW)           \
    EC_ARRAY_STR_FUNCTION_PROTOTYPE(TYPE, SW)           \
    EC_ARRAY_MAX_FUNCTION_PROTOTYPE(TYPE, SW)           \
    EC_ARRAY_MIN_FUNCTION_PROTOTYPE(TYPE, SW)


/* reverse int array */
void
Int_Array_Reverse
(
    int* array,
    int  array_length
);


int*
Int_Array_Search
(
    int* array,
    int  array_length,
    int  search_value, // search search_value
    int  search_times  // how much times search
);


int
Int_Sorted_Array_Search
(
    int* array,
    int  array_length,
    int  search_value
);


/* find maximum number in an integer array */
int
Int_Array_Max
(
    int* array,
    int  array_length
);


/* find minimum number in an integer array */
int
Int_Array_Min
(
    int* array,
    int  array_length
);


/* Function macros */

#define EC_ARRAY_FREE_FUNCTION(TYPE)                                \
void                                                                \
EC_ARRAY_FREE_FUNCTION_NAME(TYPE)                                   \
(                                                                   \
    void* var                                                       \
)                                                                   \
{                                                                   \
    EC_ARRAY_STRUCT(TYPE)* v = (EC_ARRAY_STRUCT(TYPE)*) var;        \
    free (v->index);                                                \
    v->index = NULL;                                                \
    EC_Memory_Var_Free (v->ec_memory_ref);                          \
    v->ec_memory_ref = NULL;                                        \
    free (v);                                                       \
    v = NULL;                                                       \
}


#define EC_ARRAY_FREE_ONE_FUNCTION(TYPE)                            \
void                                                                \
EC_ARRAY_FREE_ONE_FUNCTION_NAME(TYPE)                               \
(                                                                   \
    void* var                                                       \
)                                                                   \
{                                                                   \
    EC_ARRAY_STRUCT(TYPE)* v = (EC_ARRAY_STRUCT(TYPE)*) var;        \
    free (v->index);                                                \
    v->index = NULL;                                                \
    free (v);                                                       \
    v = NULL;                                                       \
}


#define EC_ARRAY_UNLOCK_FUNCTION(TYPE)                              \
void                                                                \
EC_ARRAY_UNLOCK_FUNCTION_NAME(TYPE)                                 \
(                                                                   \
    void* var                                                       \
)                                                                   \
{                                                                   \
    EC_ARRAY_STRUCT(TYPE)* v = (EC_ARRAY_STRUCT(TYPE)*) var;        \
    v->ec_memory_ref->lock = EC_UNLOCK;                             \
}


#define EC_ARRAY_NEW_FUNCTION(TYPE)                                             \
EC_ARRAY_STRUCT(TYPE)*                                                          \
EC_ARRAY_NEW_FUNCTION_NAME(TYPE)                                                \
(                                                                               \
    int length                                                                  \
)                                                                               \
{                                                                               \
    EC_VAR_CREATE(EC_ARRAY_STRUCT(TYPE))                                        /* TYPE* var is in this macro in ec_var.h*/\
                                                                                \
    if (EC_MEMORY)                                                              \
    {                                                                           \
        EC_MEMORY_CREATE(TYPE, EC_ARRAY_TYPE)                                   \
        ec_memory_new->Free_Func = EC_ARRAY_FREE_ONE_FUNCTION_NAME(TYPE);       /**** this works */\
        ec_memory_new->Free_Var_Func = EC_ARRAY_FREE_ONE_FUNCTION_NAME(TYPE);   /**** this does not work */\
        var->ec_memory_ref = ec_memory_new;                                     \
        var->lock = EC_LOCK;                                                    \
    }                                                                           \
                                                                                \
    TYPE* array = (TYPE*) malloc (sizeof (TYPE) * length);                      \
                                                                                \
    if (array == NULL)                                                          \
    {                                                                           \
        EC_Error_Mem_Alloc (__FILE__, __LINE__);                                \
        return NULL;                                                            \
    }                                                                           \
                                                                                \
    var->length = length;                                                       \
    var->index = array;                                                         \
                                                                                \
    return var;                                                                 \
}


/* Array_Copy
 * This function return exact copy of ec array.
 * But there is no inter connection between original and the copy */
#define EC_ARRAY_COPY_FUNCTION(TYPE)                                                        \
EC_ARRAY_STRUCT(TYPE)*                                                                      \
EC_ARRAY_COPY_FUNCTION_NAME(TYPE)                                                           \
(                                                                                           \
    EC_ARRAY_STRUCT(TYPE)* array                                                            \
)                                                                                           \
{                                                                                           \
    EC_ARRAY_STRUCT(TYPE)* array_copy = EC_ARRAY_NEW_FUNCTION_NAME(TYPE) (array->length);   \
                                                                                            \
    memcpy (array_copy->index, array->index, sizeof(TYPE) * array->length);                 \
                                                                                            \
    array_copy->length = array->length;                                                     \
                                                                                            \
    return array_copy;                                                                      \
}


#define EC_ARRAY_REVERSE_FUNCTION(TYPE)                             \
void                                                                \
EC_ARRAY_REVERSE_FUNCTION_NAME(TYPE)                                \
(                                                                   \
    EC_ARRAY_STRUCT(TYPE)* array                                    \
)                                                                   \
{                                                                   \
    TYPE temp;                                                      \
                                                                    \
    for (int i = 0; i < (array->length) / 2; i++)                   \
    {                                                               \
        temp = array->index[i];                                     \
        array->index[i] = array->index[array->length - (1 + i)];    \
        array->index[array->length - 1 - i] = temp;                 \
    }                                                               \
}


#define EC_ARRAY_FUNCTIONS(TYPE)        \
    EC_ARRAY_FREE_FUNCTION(TYPE)        \
    EC_ARRAY_FREE_ONE_FUNCTION(TYPE)    \
    EC_ARRAY_UNLOCK_FUNCTION(TYPE)      \
    EC_ARRAY_NEW_FUNCTION(TYPE)         \
    EC_ARRAY_COPY_FUNCTION(TYPE)        \
    EC_ARRAY_REVERSE_FUNCTION(TYPE)


/* EC_Array_Sort */

#define EC_ARRAY_SORT_FUNCTION(TYPE, SW)                            \
void                                                                \
EC_ARRAY_SORT_FUNCTION_NAME(TYPE, SW)                               \
(                                                                   \
    EC_ARRAY_STRUCT(TYPE)* array                                    \
)                                                                   \
{                                                                   \
    TYPE* min_ref;                                                  \
    TYPE temp;                                                      \
                                                                    \
    int j = 0;                                                      \
    int i = 0;                                                      \
                                                                    \
    for (i; i < array->length - 1; i++)                             \
    {                                                               \
        min_ref = &array->index[i];                                 \
                                                                    \
        for (j = i + 1; j < array->length; j++)                     \
        {                                                           \
            if (array->index[j].SW < min_ref->SW)                   \
            {                                                       \
                min_ref = &array->index[j];                         \
            }                                                       \
        }                                                           \
                                                                    \
        temp = array->index[i];                                     \
        array->index[i] = *min_ref;                                 \
        *min_ref = temp;                                            \
    }                                                               \
}


/* Array Search */

#define EC_ARRAY_INT_FUNCTION(TYPE, SW)                             \
int                                                                 \
EC_ARRAY_INT_FUNCTION_NAME(TYPE, SW)                                \
(                                                                   \
    EC_ARRAY_STRUCT(TYPE)*  array,                                  \
    int                     search_value                            \
)                                                                   \
{                                                                   \
    foreach_array (array)                                           \
    {                                                               \
        if (array->var->SW == search_value)                         \
        {                                                           \
            return array->i;                                        \
        }                                                           \
    }                                                               \
                                                                    \
    return -1;                                                      \
}


#define EC_ARRAY_STR_FUNCTION(TYPE, SW)                             \
int                                                                 \
EC_ARRAY_STR_FUNCTION_NAME(TYPE, SW)                                \
(                                                                   \
    EC_ARRAY_STRUCT(TYPE)*  array,                                  \
    char*                   search_value                            \
)                                                                   \
{                                                                   \
    foreach_array (array)                                           \
    {                                                               \
        if (strcmp(array->var->SW, search_value) == 0)              \
        {                                                           \
            return array->i;                                        \
        }                                                           \
    }                                                               \
                                                                    \
    return -1;                                                      \
}


/* do it with internal refference sort array and keep it in global */
#define EC_ARRAY_SORTED_INT_FUNCTION(TYPE, SW)                      \
int                                                                 \
EC_ARRAY_SORTED_INT_FUNCTION_NAME(TYPE, SW)                         \
(                                                                   \
    EC_ARRAY_STRUCT(TYPE)*  array,                                  \
    int                     search_value                            \
)                                                                   \
{                                                                   \
    int lei, uei, mi;                                               /* lei = lower end index, uei = upper end index, mi = mid index */\
                                                                    \
    lei = 0;                                                        \
    uei = array->length - 1;                                        \
    mi = (lei + uei) / 2;                                           \
                                                                    \
    if (search_value < array->index[lei].SW)                        /* Search value is lower than minimum value */ \
    {                                                               \
        return -1;                                                  \
    }                                                               \
    else if (search_value > array->index[uei].SW)                   /* Search value is grater than maximum value */ \
    {                                                               \
        return -1;                                                  \
    }                                                               \
                                                                    \
    while (1)                                                       \
    {                                                               \
        printf ("lei %d uei %d mi %d\n", lei, uei, mi);             \
                                                                    \
        if (search_value == array->index[mi].SW)                    \
        {                                                           \
            printf ("mi %d\n", mi);                                 \
            return mi;                                              \
        }                                                           \
        else if (search_value == array->index[lei].SW)              \
        {                                                           \
            printf ("lei %d\n", lei);                               \
            return lei;                                             \
        }                                                           \
        else if (search_value == array->index[uei].SW)              \
        {                                                           \
            printf ("uei %d\n", uei);                               \
            return uei;                                             \
        }                                                           \
        else if (search_value > array->index[mi].SW)                \
        {                                                           \
            printf ("v > mi\n");                                    \
            lei = mi + 1;                                           \
            uei = uei - 1;                                          \
            mi = (lei + uei) / 2;                                   \
        }                                                           \
        else                                                        \
        {                                                           \
            printf ("v < mi\n");                                    \
            uei = mi - 1;                                           \
            lei = lei + 1;                                          \
            mi = (lei + uei) / 2;                                   \
        }                                                           \
                                                                    \
        if (lei == uei)                                             \
        {                                                           \
            if (search_value == array->index[lei].SW)               \
            {                                                       \
                printf ("lei = uei %d\n", lei);                     \
                return lei;                                         \
            }                                                       \
            else                                                    \
            {                                                       \
                printf ("No search result found lei %d uei %d\n",   \
                        lei, uei);                                  \
                return -1;                                          \
            }                                                       \
        }                                                           \
    }                                                               \
}


/* Search maximum var according to var attribute SW */

#define EC_ARRAY_MAX_FUNCTION(TYPE, SW)             \
TYPE*                                               \
EC_ARRAY_MAX_FUNCTION_NAME(TYPE, SW)                \
(                                                   \
    EC_ARRAY_STRUCT(TYPE)* array                    \
)                                                   \
{                                                   \
    TYPE* max = &array->index[0];                   \
                                                    \
    for (int i = 1; i < array->length; i++)         \
    {                                               \
        if (array->index[i].SW > max->SW)           \
        {                                           \
            max = &array->index[i];                 \
        }                                           \
    }                                               \
                                                    \
    return max;                                     \
}


/* Search minimum var according to var attribute SW */

#define EC_ARRAY_MIN_FUNCTION(TYPE, SW)             \
TYPE*                                               \
EC_ARRAY_MIN_FUNCTION_NAME(TYPE, SW)                \
(                                                   \
    EC_ARRAY_STRUCT(TYPE)* array                    \
)                                                   \
{                                                   \
    TYPE* min = &array->index[0];                   \
                                                    \
    for (int i = 1; i < array->length; i++)         \
    {                                               \
        if (array->index[i].SW < min->SW)           \
        {                                           \
            min = &array->index[i];                 \
        }                                           \
    }                                               \
                                                    \
    return min;                                     \
}

#define EC_ARRAY_SW_FUNCTIONS(TYPE, SW)             /* SW for Search With or Sort With */ \
    EC_ARRAY_SORT_FUNCTION(TYPE, SW)                \
    EC_ARRAY_INT_FUNCTION(TYPE, SW)                 \
    EC_ARRAY_MAX_FUNCTION(TYPE, SW)                 \
    EC_ARRAY_MIN_FUNCTION(TYPE, SW)



#endif // EC_ARRAY_H


/*
EC_ARRAY_RESIZE**
EC_ARRAY_RESIZE_FUNCTION_NAME(EC_ARRAY_RESIZE)
(
    EC_ARRAY_RESIZE** var,
    int* current_size,
    int new_size
)
{
    EC_ARRAY_RESIZE* arr = (EC_ARRAY_RESIZE* ) realloc (*var, sizeof (EC_ARRAY_RESIZE)*  new_size);

    *current_size = new_size;

    if (arr != NULL)
    {
        *var = arr;
        return var;
    }


    printf ("Cannot resize array\n");
    return NULL;
}

*/
