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

EC_STACK_FUNCTIONS(Student)

//EC_QUEUE_FUNCTIONS(Student)


Student students[7] = {{0, "Malith"}, {1, "Geethike"}, {2, "Perera"}, {3, "Rohasha"}, {4, "Malshi"}, {5, "Prisenthi"}, {6, "Magret"}};


Student *st0;
Student *st1;
Student *st2;
Student *st3;
Student *st4;
Student *st5;
Student *st6;


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
