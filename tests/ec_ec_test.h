#include "ec_main_test.h"

#ifndef EC_EC_TEST_H
#define EC_EC_TEST_H

typedef struct Book {
    char name[30];
    int no;
    EC_MEMORY_REF
} Book;

void
Run_EC_Test();


#endif //EC_EC_TEST_H
