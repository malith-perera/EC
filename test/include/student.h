#ifndef STUDENT_H
#define STUDENT_H

#include "ec.h"

#define ec_var      \
    int     no;     \
    char*   name;

EC_TYPE(Student, ec_var)

EC_VAR_FUNCTION_PROTOTYPES(Student)


#endif // STUDENT_H

