#include "student.h"

EC_VAR_FUNCTIONS(Student)

EC_ARRAY_FUNCTIONS(Student)

EC_ARRAY_SORT_FUNCTION(Student, no)
EC_ARRAY_INT_FUNCTION(Student, no)
EC_ARRAY_STR_FUNCTION(Student, name)
EC_ARRAY_MAX_FUNCTION(Student, no)
EC_ARRAY_MIN_FUNCTION(Student, no)

EC_LIST_FUNCTIONS(Student)
//EC_LIST_SORT_FUNCTION(Student, no)
//
//EC_QUEUE_FUNCTIONS(Student)
//
//EC_STACK_FUNCTIONS(Student)


bool
Student_Compare (Student *a, Student *b)
{
    if (a->no != b->no)
    {
        return false;
    }

    if (strcmp(a->name, b->name) != 0)
    {
        return false;
    }

    return true;
}
