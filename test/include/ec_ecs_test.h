#ifndef EC_ECS_TEST_H
#define EC_ECS_TEST_H


#include "ec_main_test.h"
#include "ec.h"
#include "student.h"


Entity *players;
Entity *enemies;
Entity *bullets; 


typedef struct Velocity {
    int x;
    int y;
} Velocity;


typedef struct Position {
    int x;
    int y;
} Position;


Velocity *velocity;
Position *position;


void
Run_ECS_Test ();


void
Test_ECS_Create_New_Entites();


void
Test_ECS_Create_Components ();


#endif //EC_ECS_TEST_H
