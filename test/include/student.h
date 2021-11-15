#ifndef STUDENT_H
#define STUDENT_H

#include "ec.h"

#define student     \
    int     no;     \
    char*   name;


EC_VAR(Student, student)
EC_VAR_FUNCTION_PROTOTYPES(Student)

#endif // STUDENT_H
