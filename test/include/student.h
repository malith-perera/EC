#ifndef STUDENT_H
#define STUDENT_H

#define EC_MEMORY 1 // should define before include ec.h
#include "ec.h"

#define STUDENT     \
    int     no;     \
    char*   name;


EC_VAR(Student, STUDENT)
EC_VAR_FUNCTION_PROTOTYPES(Student)

EC_ARRAY(Student)
EC_ARRAY_FUNCTION_PROTOTYPES(Student)

EC_ARRAY_SORT_FUNCTION_PROTOTYPE(Student, no)
EC_ARRAY_SEARCH_FUNCTION_PROTOTYPE(Student, no)
EC_ARRAY_SEARCH_MAX_FUNCTION_PROTOTYPE(Student, no)
EC_ARRAY_SEARCH_MIN_FUNCTION_PROTOTYPE(Student, no)

EC_LIST(Student, STUDENT)
EC_LIST_FUNCTION_PROTOTYPES(Student)
EC_LIST_SORT_FUNCTION_PROTOTYPE(Student, no)

EC_QUEUE(Student, STUDENT)
EC_QUEUE_FUNCTION_PROTOTYPES(Student)

EC_STACK(Student, STUDENT)
EC_STACK_FUNCTION_PROTOTYPES(Student)

EC_VAR_REF(Student)
EC_VAR_REF_FUNCTION_PROTOTYPES(Student)

/* Reference prototypes */
EC_ARRAY_REF(Student)
EC_ARRAY_REF_FUNCTION_PROTOTYPES(Student)

#endif // STUDENT_H
