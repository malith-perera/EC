#ifndef STUDENT_H
#define STUDENT_H

#include "ec.h"

#define student     \
    int     no;     \
    char*   name;


#define EC_MEMORY 1
EC_VAR(Student, student)
EC_VAR_FUNCTION_PROTOTYPES(Student)

EC_ARRAY(Student, student)
EC_ARRAY_FUNCTION_PROTOTYPES(Student)
EC_ARRAY_REVERSE_FUNCTION_PROTOTYPE(Student)

EC_ARRAY_SORT_FUNCTION_PROTOTYPE(Student, no)
EC_ARRAY_SEARCH_FUNCTION_PROTOTYPE(Student, no)
EC_ARRAY_SEARCH_MAX_FUNCTION_PROTOTYPE(Student, no)
EC_ARRAY_SEARCH_MIN_FUNCTION_PROTOTYPE(Student, no)

EC_LIST(Student, student)
EC_LIST_FUNCTION_PROTOTYPES(Student)
EC_LIST_SORT_FUNCTION_PROTOTYPE(Student, no)

EC_QUEUE(Student, student)
EC_QUEUE_FUNCTION_PROTOTYPES(Student)

EC_STACK(Student, student)
EC_STACK_FUNCTION_PROTOTYPES(Student)

#endif // STUDENT_H
