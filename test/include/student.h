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

EC_ARRAY_SORT_FUNCTION_PROTOTYPE(Student, no)

EC_ARRAY_REVERSE_FUNCTION_PROTOTYPE(Student)


#endif // STUDENT_H
