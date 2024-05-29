#ifndef __EC_EC_TEST_H__
#define __EC_EC_TEST_H__

#include "ec_main_test.h"

typedef struct Book {
    char name[30];
    int no;
    EC_MEMORY_REF
} Book;


void
Run_EC_Test();


#endif //__EC_EC_TEST_H__
