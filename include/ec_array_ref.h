#ifndef EC_ARRAY_REF_H
#define EC_ARRAY_REF_H

#include "ec.h"


#define foreach_array_ref(array)                                                                        \
    array->i = 0;                                                                                       \
    for (array->var = array->index; array->i < array->length; array->var = array->index + ++array->i)

/*
#define EC_ARRAY_FIND_FUNCTION_NAME(T, F) EC_CONCAT3(Find_, T, F)
#define EC_ARRAY_RESIZE_FUNCTION_NAME(TYPE) EC_CONCAT(Resize_, T)
*/

/* Function name macros */
#define EC_ARRAY_REF_FREE_FUNCTION_NAME(TYPE)                       EC_CONCAT(TYPE, _Free_Ref) // memory Free
#define EC_ARRAY_REF_NEW_FUNCTION_NAME(TYPE)                        EC_CONCAT(TYPE, _Array_Ref)
#define EC_ARRAY_REF_COPY_FUNCTION_NAME(TYPE)                       EC_CONCAT(TYPE, _Array_Ref_Copy)
#define EC_ARRAY_REF_SORT_FUNCTION_NAME(TYPE, SORT_WITH)            EC_CONCAT3(TYPE, _Array_Ref_Sort_, SORT_WITH)
#define EC_ARRAY_REF_REVERSE_FUNCTION_NAME(TYPE)                    EC_CONCAT(TYPE, _Array_Ref_Reverse)
#define EC_ARRAY_REF_SEARCH_FUNCTION_NAME(TYPE, SORT_WITH)          EC_CONCAT3(TYPE, _Sorted_Search_Ref_, SORT_WITH)
#define EC_ARRAY_REF_SEARCH_MAX_FUNCTION_NAME(TYPE, SORT_WITH)      EC_CONCAT3(TYPE, _Max_Ref_, SORT_WITH)
#define EC_ARRAY_REF_SEARCH_MIN_FUNCTION_NAME(TYPE, SORT_WITH)      EC_CONCAT3(TYPE, _Min_Ref_, SORT_WITH)


/* Structure macros */
// defined in ec_memory.h
#define EC_ARRAY_REF_STRUCT(TYPE)           EC_CONCAT(TYPE, ArrayRef)
#define EC_ARRAY_VAR_REF_STRUCT(TYPE)       EC_CONCAT(TYPE, ArrayVarRef)


#define EC_ARRAY_REF(TYPE)                              \
typedef struct EC_ARRAY_REF_STRUCT(TYPE) {              \
    TYPE*          index;                               \
    int            length;                              \
    int            i;                                   \
    TYPE*          var;                                 \
    EC_MEMORY_REF                                       \
} EC_ARRAY_REF_STRUCT(TYPE);


/* Function prototype macros */

#define EC_ARRAY_REF_FREE_FUNCTION_PROTOTYPE(TYPE)      \
void                                                    \
EC_ARRAY_REF_FREE_FUNCTION_NAME(TYPE)                   \
(                                                       \
    void* var                                           \
);


#define EC_ARRAY_REF_NEW_FUNCTION_PROTOTYPE(TYPE)       \
EC_ARRAY_REF_STRUCT(TYPE)*                              \
EC_ARRAY_REF_NEW_FUNCTION_NAME(TYPE)                    \
(                                                       \
    int length                                          \
);


#define EC_ARRAY_REF_REVERSE_FUNCTION_PROTOTYPE(TYPE)   \
void                                                    \
EC_ARRAY_REF_REVERSE_FUNCTION_NAME(TYPE)                \
(                                                       \
    EC_ARRAY_REF_STRUCT(TYPE)* array                    \
);


#define EC_ARRAY_REF_COPY_FUNCTION_PROTOTYPE(TYPE)      \
EC_ARRAY_REF_STRUCT(TYPE)*                              \
EC_ARRAY_REF_COPY_FUNCTION_NAME(TYPE)                   \
(                                                       \
    EC_ARRAY_REF_STRUCT(TYPE)* array                    \
);


#define EC_ARRAY_REF_FUNCTION_PROTOTYPES(TYPE)          \
    EC_ARRAY_REF_FREE_FUNCTION_PROTOTYPE(TYPE)          \
    EC_ARRAY_REF_NEW_FUNCTION_PROTOTYPE(TYPE)           \
    EC_ARRAY_REF_REVERSE_FUNCTION_PROTOTYPE(TYPE)       \
    EC_ARRAY_REF_COPY_FUNCTION_PROTOTYPE(TYPE)


#define EC_ARRAY_REF_SORT_FUNCTION_PROTOTYPE(TYPE, SORT_WITH)   \
void                                                            \
EC_ARRAY_REF_SORT_FUNCTION_NAME(TYPE, SORT_WITH)                \
(                                                               \
    EC_ARRAY_REF_STRUCT(TYPE)* array                            \
);


#define EC_ARRAY_REF_SEARCH_FUNCTION_PROTOTYPE(TYPE, SEARCH_WITH)   \
int                                                                 \
EC_ARRAY_REF_SEARCH_FUNCTION_NAME(TYPE, SEARCH_WITH)                \
(                                                                   \
    EC_ARRAY_REF_STRUCT(TYPE)*  array,                              \
    int                     search_value                            \
);


#define EC_ARRAY_REF_SEARCH_MAX_FUNCTION_PROTOTYPE(TYPE, SEARCH_WITH)       \
TYPE*                                                                       \
EC_ARRAY_REF_SEARCH_MAX_FUNCTION_NAME(TYPE, SEARCH_WITH)                    \
(                                                                           \
    EC_ARRAY_REF_STRUCT(TYPE)* array                                        \
);


#define EC_ARRAY_REF_SEARCH_MIN_FUNCTION_PROTOTYPE(TYPE, SEARCH_WITH)       \
TYPE*                                                                       \
EC_ARRAY_REF_SEARCH_MIN_FUNCTION_NAME(TYPE, SEARCH_WITH)                    \
(                                                                           \
    EC_ARRAY_REF_STRUCT(TYPE)* array                                        \
);


//[> reverse int array <]
//void
//Int_Array_Reverse
//(
    //int* array,
    //int  array_length
//);


//int*
//Int_Array_Search
//(
    //int* array,
    //int  array_length,
    //int  search_value, // search search_value
    //int  search_times  // how much times search
//);


//int
//Int_Sorted_Array_Search
//(
    //int* array,
    //int  array_length,
    //int  search_value
//);


//[> find maximum number in an integer array <]
//int
//Int_Array_Max
//(
    //int* array,
    //int  array_length
//);


//[> find minimum number in an integer array <]
//int
//Int_Array_Min
//(
    //int* array,
    //int  array_length
//);


/* Function macros */

#define EC_ARRAY_REF_FREE_FUNCTION(TYPE)                                    \
void                                                                        \
EC_ARRAY_REF_FREE_FUNCTION_NAME(TYPE)                                       \
(                                                                           \
    void* var                                                               \
)                                                                           \
{                                                                           \
    EC_ARRAY_REF_STRUCT(TYPE)* p = (EC_ARRAY_REF_STRUCT(TYPE)*) var;        \
    free (p->index);                                                        \
    free (p);                                                               \
}


#define EC_ARRAY_REF_NEW_FUNCTION(TYPE)                                     \
EC_ARRAY_REF_STRUCT(TYPE)*                                                  \
EC_ARRAY_REF_NEW_FUNCTION_NAME(TYPE)                                        \
(                                                                           \
    int length                                                              \
)                                                                           \
{                                                                           \
    EC_ARRAY_REF_STRUCT(TYPE)* var = (EC_ARRAY_REF_STRUCT(TYPE)*)           \
        malloc (sizeof (EC_ARRAY_REF_STRUCT(TYPE)));                        \
                                                                            \
    if (var == NULL)                                                        \
    {                                                                       \
        EC_Error_Mem_Alloc (__FILE__, __LINE__);                            \
        return NULL;                                                        \
    }                                                                       \
                                                                            \
    TYPE* array = (TYPE*) malloc (sizeof (TYPE) * length);                  \
                                                                            \
    if (array == NULL)                                                      \
    {                                                                       \
        EC_Error_Mem_Alloc (__FILE__, __LINE__);                            \
        return NULL;                                                        \
    }                                                                       \
                                                                            \
    var->length = length;                                                   \
    var->index = array;                                                     \
                                                                            \
    if (EC_MEMORY)                                                          \
    {                                                                       \
        ECMemory* ec_memory_new = (ECMemory*) malloc (sizeof(ECMemory));    \
                                                                            \
        ec_memory_new->type = EC_ARRAY_TYPE;                                \
        ec_memory_new->var = var;                                           \
        ec_memory_new->lock = EC_LOCK;                                      \
        ec_memory_new->Free_Func = EC_ARRAY_REF_FREE_FUNCTION_NAME (TYPE);  \
        ec_memory_new->next = NULL;                                         \
                                                                            \
        EC_Memory_Append (ec_memory_new);                                   \
                                                                            \
        var->ec_memory_ref = ec_memory_new;                                 \
        var->lock = EC_LOCK;                                                \
    }                                                                       \
                                                                            \
    return var;                                                             \
}


/* EC_Array_Sort */

#define EC_ARRAY_REF_SORT_FUNCTION(TYPE, SORT_WITH)                 \
void                                                                \
EC_ARRAY_REF_SORT_FUNCTION_NAME(TYPE, SORT_WITH)                    \
(                                                                   \
    EC_ARRAY_REF_STRUCT(TYPE)* array                                \
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
        for (j = i + 1; j < array->length - 2; j++)                 \
        {                                                           \
            if (array->index[j].SORT_WITH < min_ref->SORT_WITH)     \
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


#define EC_ARRAY_REF_REVERSE_FUNCTION(TYPE)                         \
void                                                                \
EC_ARRAY_REF_REVERSE_FUNCTION_NAME(TYPE)                            \
(                                                                   \
    EC_ARRAY_REF_STRUCT(TYPE)* array                                \
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


/* Array Search */

#define EC_ARRAY_REF_SEARCH_FUNCTION(TYPE, SEARCH_WITH)             \
int                                                                 \
EC_ARRAY_REF_SEARCH_FUNCTION_NAME(TYPE, SEARCH_WITH)                \
(                                                                   \
    EC_ARRAY_REF_STRUCT(TYPE)*  array,                              \
    int                     search_value                            \
)                                                                   \
{                                                                   \
    int lei, uei, mi;                                               /* lei = lower end index, uei = upper end index, mi = mid index */\
                                                                    \
    lei = 0;                                                        \
    uei = array->length - 1;                                        \
    mi = (lei + uei) / 2;                                           \
                                                                    \
    if (search_value < array->index[lei].SEARCH_WITH)               \
    {                                                               \
        printf ("Search value is lower than minimum value\n");      \
        return -1;                                                  \
    }                                                               \
    else if (search_value > array->index[uei].SEARCH_WITH)          \
    {                                                               \
        printf ("Search value is grater than maximum value\n");     \
        return -1;                                                  \
    }                                                               \
                                                                    \
    while (1)                                                       \
    {                                                               \
        printf ("lei %d uei %d mi %d\n", lei, uei, mi);             \
                                                                    \
        if (search_value == array->index[mi].SEARCH_WITH)           \
        {                                                           \
            printf ("mi %d\n", mi);                                 \
            return mi;                                              \
        }                                                           \
        else if (search_value == array->index[lei].SEARCH_WITH)     \
        {                                                           \
            printf ("lei %d\n", lei);                               \
            return lei;                                             \
        }                                                           \
        else if (search_value == array->index[uei].SEARCH_WITH)     \
        {                                                           \
            printf ("uei %d\n", uei);                               \
            return uei;                                             \
        }                                                           \
        else if (search_value > array->index[mi].SEARCH_WITH)       \
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
            if (search_value == array->index[lei].SEARCH_WITH)      \
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

/* Search maximum var according to var attribute SEARCH_WITH */

#define EC_ARRAY_REF_SEARCH_MAX_FUNCTION(TYPE, SEARCH_WITH)         \
TYPE*                                                               \
EC_ARRAY_REF_SEARCH_MAX_FUNCTION_NAME(TYPE, SEARCH_WITH)            \
(                                                                   \
    EC_ARRAY_REF_STRUCT(TYPE)* array                                \
)                                                                   \
{                                                                   \
    TYPE* max = &array->index[0];                                   \
                                                                    \
    for (int i = 1; i < array->length; i++)                         \
    {                                                               \
        if (array->index[i].SEARCH_WITH > max->SEARCH_WITH)         \
        {                                                           \
            max = &array->index[i];                                 \
        }                                                           \
    }                                                               \
                                                                    \
    return max;                                                     \
}


/* Search minimum var according to var attribute SEARCH_WITH */

#define EC_ARRAY_REF_SEARCH_MIN_FUNCTION(TYPE, SEARCH_WITH)         \
TYPE*                                                               \
EC_ARRAY_REF_SEARCH_MIN_FUNCTION_NAME(TYPE, SEARCH_WITH)            \
(                                                                   \
    EC_ARRAY_REF_STRUCT(TYPE)* array                                \
)                                                                   \
{                                                                   \
    TYPE* min = &array->index[0];                                   \
                                                                    \
    for (int i = 1; i < array->length; i++)                         \
    {                                                               \
        if (array->index[i].SEARCH_WITH < min->SEARCH_WITH)         \
        {                                                           \
            min = &array->index[i];                                 \
        }                                                           \
    }                                                               \
                                                                    \
    return min;                                                     \
}

// Copy
#define EC_ARRAY_REF_COPY_FUNCTION(TYPE)                                                            \
EC_ARRAY_REF_STRUCT(TYPE)*                                                                          \
EC_ARRAY_REF_COPY_FUNCTION_NAME(TYPE)                                                               \
(                                                                                                   \
    EC_ARRAY_REF_STRUCT(TYPE)* array                                                                \
)                                                                                                   \
{                                                                                                   \
    EC_ARRAY_REF_STRUCT(TYPE)* array_copy = EC_ARRAY_REF_NEW_FUNCTION_NAME(TYPE) (array->length);   \
                                                                                                    \
    memcpy (array_copy->index, array->index, sizeof(TYPE) * array->length);                         \
                                                                                                    \
    array_copy->length = array->length;                                                             \
                                                                                                    \
    return array_copy;                                                                              \
}


#define EC_ARRAY_REF_FUNCTIONS(TYPE)    \
    EC_ARRAY_REF_FREE_FUNCTION(TYPE)    \
    EC_ARRAY_REF_NEW_FUNCTION(TYPE)     \
    EC_ARRAY_REF_COPY_FUNCTION(TYPE)

#endif // EC_ARRAY_REF_H


/*
EC_ARRAY_REF_RESIZE**
EC_ARRAY_REF_RESIZE_FUNCTION_NAME(EC_ARRAY_REF_RESIZE)
(
    EC_ARRAY_REF_RESIZE** var,
    int* current_size,
    int new_size
)
{
    EC_ARRAY_REF_RESIZE* arr = (EC_ARRAY_REF_RESIZE* ) realloc (*var, sizeof (EC_ARRAY_REF_RESIZE)*  new_size);

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
