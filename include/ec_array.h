/*------------------------------------------------------------------------------------*
 *                                  EC_ARRAY                                          *
 *====================================================================================*/


/*-------------------------------*
 *        EC_ARRAY_H             *
 *===============================*/

int ec_i;

#ifndef EC_ARRAY_H
#define EC_ARRAY_H

#include "ec.h"

#define foreach_array(arr_type, arr)                                                 \
  ec_i = 0;                                                                          \
  for (arr_type* item = arr->array;  ec_i < arr->count; item = arr->array + ++ec_i)

/*

#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))

#define EC_ARRAY_FIND_METHOD(T, F) EC_CONCAT(Find_, T, F)
#define EC_ARRAY_RESIZE_METHOD(T) EC_CONCAT(Resize_, T,)

*/

#define EC_ARRAY_METHOD(T)                      EC_CONCAT(T, _Array,)
#define EC_ARRAY_STRUCT(T)                      EC_CONCAT(T, Array,)
#define EC_ARRAY_FREE_METHOD(T)                 EC_CONCAT(Free_, T,) // garbage Free
#define EC_ARRAY_SORT_METHOD(T)                 EC_CONCAT(Sort_, T, _Array)
#define REVERSE_ARRAY(T)                        EC_CONCAT(Reverse_, T, _Array)
#define EC_ARRAY_BINARY_SEARCH_METHOD(T, SW)    EC_CONCAT4(Search_Sorted_, T, _With_, SW)
#define SEARCH_MAX_ARRAY_METHOD(T, SW)          EC_CONCAT4(Max_, T, _With_, SW)
#define SEARCH_MIN_ARRAY_METHOD(T, SW)          EC_CONCAT4(Min_, T, _With_, SW)

#endif // EC_ARRAY_H


#include "ec.h"

/*------------------------------------------------------------------------------------*
 *                                New Array Method                                    *
 *                                Free Array Method                                   *
 *====================================================================================*/


#ifdef EC_ARRAY

#ifdef  EC_MEMORY
#define EC_Array(T)                                     \
typedef struct EC_CONCAT(T, Array,){                    \
    ec_var(T)                                           \
    T*      array;                                      \
    int     count;                                      \
    bool    lock;                                       \
} EC_CONCAT(T, Array,);                                 \
                                                        \
typedef T EC_CONCAT(T, ArrayObj,)
#endif  // ifdef EC_MEMORY


#ifndef EC_MEMORY
#define EC_Array(T)                                     \
typedef struct EC_CONCAT(T, Array,){                    \
    ec_var(T)                                           \
    T*      array;                                      \
    int     count;                                      \
} EC_CONCAT(T, Array,);                                 \
                                                        \
typedef T EC_CONCAT(T, ArrayObj,)
#endif // ifndef EC_MEMORY


void
EC_ARRAY_FREE_METHOD(EC_ARRAY_STRUCT(EC_ARRAY))
(
    void* obj
)
{
    EC_ARRAY_STRUCT(EC_ARRAY)* p = (EC_ARRAY_STRUCT(EC_ARRAY)*) obj;
    free (p->array);
    free (p);
}


EC_ARRAY_STRUCT(EC_ARRAY)*
EC_ARRAY_METHOD(EC_ARRAY)
(
    int count
)
{
    EC_ARRAY_STRUCT(EC_ARRAY)* obj = (EC_ARRAY_STRUCT(EC_ARRAY)*) malloc (sizeof (EC_ARRAY_STRUCT(EC_ARRAY)));

    if (obj == NULL)
    {
        printf ("Cannot allocate memory to create array\n");
        return NULL;
    }

    EC_ARRAY* arrayobj = (EC_ARRAY*) malloc (count*  sizeof (EC_ARRAY));

    if (obj == NULL)
    {
        printf ("Cannot allocate memory to create array\n");
        return NULL;
    }

    obj->count = count;
    obj->array = arrayobj;

#ifdef EC_MEMORY
    ECMemory* ec_memory_new = (ECMemory*) malloc (sizeof(ECMemory));

    ec_memory_new->type = EC_ARRAY_TYPE;
    ec_memory_new->obj = obj;
    ec_memory_new->garbage = NULL;
    ec_memory_new->Free_Func = EC_ARRAY_FREE_METHOD (EC_ARRAY_STRUCT(EC_ARRAY));
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

#endif

    return obj;
}


/*----------------------------------------------------------------------------------*
 *                                 Array Sort                                       *
 *==================================================================================*/

#ifdef  EC
#define EC_ARRAY EC
#endif

#ifdef  EC_ARRAY

#define EC_SORT EC_ARRAY
#ifdef  EC_SORT_WITH

void
EC_ARRAY_SORT_METHOD(EC_ARRAY)
(
  EC_ARRAY_STRUCT(EC_ARRAY)* array
)
{
  EC_ARRAY* min_ref;
  EC_ARRAY temp;

  int j = 0;
  int i = 0;

  for (i; i < array->count - 1; i++)
  {
    min_ref = &array->array[i];

    for (j = i + 1; j < array->count; j++)
    {
      if (array->array[j].EC_SORT_WITH < min_ref->EC_SORT_WITH)
      {
        min_ref = &array->array[j];
      }
    }

    temp = array->array[i];
    array->array[i] = *min_ref;
    *min_ref = temp;
  }
}


void
REVERSE_ARRAY(EC_ARRAY)
(
  EC_ARRAY_STRUCT(EC_ARRAY)* array
)
{
  EC_ARRAY temp;

  for (int i = 0; i < (array->count) / 2; i++)
  {
    temp = array->array[i];
    array->array[i] = array->array[array->count - (1 + i)];
    array->array[array->count - 1 - i] = temp;
  }
}

#undef EC_SORT_WITH
#endif // EC_SORT_WITH


/* reverse int array */

void
Reverse_Int_Array
(
  int* array,
  int  array_count
)
{
  int temp;

  for (int i = 0; i < array_count / 2; i++)
  {
    temp = array[i];
    array[i] = array[array_count - 1 - i];
    array[array_count - 1 - i] = temp;
  }
}

#undef EC_SORT
#endif  // EC_SORT


/*-------------------------------------------------------------------------------*
 *                              Array Search                                     *
 *===============================================================================*/

#define EC_SEARCH EC_ARRAY
#ifdef  EC_SEARCH_WITH


/* Search integer array */
// return array index if found else NULL if not found

/* Search int array
 * count = 0 -> find all.
 * count = 1,2,3,.. from begin to end.
 * count = -1, -2, -3, from end to begin */


// ********* reverse search is a good idea
int*
Search_Int_Array
(
    int* array,
    int  array_count,
    int  search_value, // search search_value
    int  search_times  // how much times search
)
{
    int indexarray[search_times]; // ***** use list here

    int counter = 0;

    for (int i = 0; i < array_count; i++)
    {
        if (array[i] == search_value)
        {
            indexarray[counter] = i;
            counter++;

            if (search_times == counter)
            {
                //return indexarray;
            }
        }
    }

    return NULL;  // if not search value found
}


/* Binary search sorted integer array */
// return array index if found else return -1 if no found

int
Search_Sorted_Int_Array
(
    int* array,
    int  array_count,
    int  search_value
)
{
    int lei, uei, mi;  // lei = lower end index, uei = upper end index, mi = mid index

    lei = 0;
    uei = array_count - 1;
    mi = (lei + uei) / 2;

    if (search_value < array[lei] )
    {
        printf ("Search value is lower than minimum value\n");
        return -1;
    }
    else if (search_value > array[uei])
    {
        printf ("Search value is grater than maximum value\n");
        return -1;
    }

    while (1)
    {
        printf ("lei %d uei %d mi %d\n", lei, uei, mi);

        if (search_value == array[mi])
        {
            printf ("mi %d\n", mi);
            return mi;
        }
        else if (search_value == array[lei])
        {
            printf ("lei %d\n", lei);
            return lei;
        }
        else if (search_value == array[uei])
        {
            printf ("uei %d\n", uei);
            return uei;
        }
        else if (search_value > array[mi])
        {
            printf ("search_value > mi\n");
            lei = mi + 1;
            uei = uei - 1;
            mi = (lei + uei) / 2;
        }
        else
        {
            printf ("search_value < mi\n");
            uei = mi - 1;
            lei = lei + 1;
            mi = (lei + uei) / 2;
        }

        if (lei == uei)
        {
            if (search_value == array[lei])
            {
                printf ("lei = uei %d\n", lei);
                return lei;
            }
            else
            {
                printf ("No search result found lei %d uei %d\n", lei, uei);
                return -1;
            }
        }
    }
}


int
EC_ARRAY_BINARY_SEARCH_METHOD(EC_SEARCH, EC_SEARCH_WITH)
(
    EC_ARRAY_STRUCT(EC_ARRAY)* array,
    int                        search_value
)
{
    int lei, uei, mi;  // lei = lower end index, uei = upper end index, mi = mid index

    lei = 0;
    uei = array->count - 1;
    mi = (lei + uei) / 2;

    if (search_value < array->array[lei].EC_SEARCH_WITH)
    {
        printf ("Search value is lower than minimum value\n");
        return -1;
    }
    else if (search_value > array->array[uei].EC_SEARCH_WITH)
    {
        printf ("Search value is grater than maximum value\n");
        return -1;
    }

    while (1)
    {
        printf ("lei %d uei %d mi %d\n", lei, uei, mi);

        if (search_value == array->array[mi].EC_SEARCH_WITH)
        {
            printf ("mi %d\n", mi);
            return mi;
        }
        else if (search_value == array->array[lei].EC_SEARCH_WITH)
        {
            printf ("lei %d\n", lei);
            return lei;
        }
        else if (search_value == array->array[uei].EC_SEARCH_WITH)
        {
            printf ("uei %d\n", uei);
            return uei;
        }
        else if (search_value > array->array[mi].EC_SEARCH_WITH)
        {
            printf ("v > mi\n");
            lei = mi + 1;
            uei = uei - 1;
            mi = (lei + uei) / 2;
        }
        else
        {
            printf ("v < mi\n");
            uei = mi - 1;
            lei = lei + 1;
            mi = (lei + uei) / 2;
        }

        if (lei == uei)
        {
            if (search_value == array->array[lei].EC_SEARCH_WITH)
            {
                printf ("lei = uei %d\n", lei);
                return lei;
            }
            else
            {
                printf ("No search result found lei %d uei %d\n", lei, uei);
                return -1;
            }
        }
    }
}


/* Search maximum object according to object attribute SEARCH_WITH */


EC_ARRAY*
SEARCH_MAX_ARRAY_METHOD(EC_SEARCH, EC_SEARCH_WITH)
(
    EC_ARRAY_STRUCT(EC_ARRAY)* array
)
{
    EC_ARRAY* max = &array->array[0];

    for (int i = 1; i < array->count; i++)
    {
        if (array->array[i].EC_SEARCH_WITH > max->EC_SEARCH_WITH)
        {
            max = &array->array[i];
        }
    }

    return max;
}


/* Search minimum object according to object attribute SEARCH_WITH */


EC_ARRAY*
SEARCH_MIN_ARRAY_METHOD(EC_SEARCH, EC_SEARCH_WITH)
(
    EC_ARRAY_STRUCT(EC_ARRAY)* array
)
{
    EC_ARRAY* min = &array->array[0];

    for (int i = 1; i < array->count; i++)
    {
        if (array->array[i].EC_SEARCH_WITH < min->EC_SEARCH_WITH)
        {
            min = &array->array[i];
        }
    }

    return min;
}


#undef EC_SEARCH
#undef EC_SEARCH_WITH
#endif  // EC_SEARCH_WITH


/* find maximum number in an integer array */
int
Max_Int_Array
(
    int* array,
    int  array_count
)
{
    int max = array[0];

    for (int i = 1; i < array_count; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    return max;
}


/* find minimum number in an integer array */
int
Min_Int_Array
(
    int* array,
    int  array_count
)
{
    int min = array[0];

    for (int i = 1; i < array_count; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }

    return min;
}


#undef EC_ARRAY
#endif // EC_ARRAY


/*

EC_ARRAY_RESIZE**
EC_ARRAY_RESIZE_METHOD(EC_ARRAY_RESIZE)
(
    EC_ARRAY_RESIZE** obj,
    int* current_size,
    int new_size
)
{
    EC_ARRAY_RESIZE* arr = (EC_ARRAY_RESIZE* ) realloc (*obj, sizeof (EC_ARRAY_RESIZE)*  new_size);

    *current_size = new_size;

    if (arr != NULL)
    {
        *obj = arr;
        return obj;
    }

    printf ("Cannot resize array\n");
    return NULL;
}

*/

