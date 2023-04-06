#include "ec_main_test.h"

#ifndef STUDENT_H
#define STUDENT_H

#define STUDENT     \
    int     no;     \
    char*   name;

EC_VAR(Student, STUDENT)
EC_VAR_FUNCTION_PROTOTYPES(Student)

EC_ARRAY(Student)
EC_ARRAY_FUNCTION_PROTOTYPES(Student)
EC_ARRAY_REVERSE_FUNCTION_PROTOTYPE(Student)

EC_ARRAY_SORT_FUNCTION_PROTOTYPE(Student, no)
EC_ARRAY_INT_FUNCTION_PROTOTYPE(Student, no)
EC_ARRAY_STR_FUNCTION_PROTOTYPE(Student, name)
EC_ARRAY_MAX_FUNCTION_PROTOTYPE(Student, no)
EC_ARRAY_MIN_FUNCTION_PROTOTYPE(Student, no)

EC_LIST(Student)
EC_LIST_FUNCTION_PROTOTYPES(Student)

//EC_LIST_SORT_FUNCTION_PROTOTYPE(Student, no)

EC_STACK(Student, STUDENT)
EC_STACK_FUNCTION_PROTOTYPES(Student)

//EC_QUEUE(Student, STUDENT)
//EC_QUEUE_FUNCTION_PROTOTYPES(Student)

extern Student students[7];

extern Student *st0;
extern Student *st1;
extern Student *st2;
extern Student *st3;
extern Student *st4;
extern Student *st5;
extern Student *st6;

bool
Student_Compare (Student *a, Student *b);


#endif // STUDENT_H
