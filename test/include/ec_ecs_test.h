#include "ec_main_test.h"


#ifndef EC_ECS_TEST_H
#define EC_ECS_TEST_H


#define VELOCITY    \
    int x;          \
    int y;

EC_Component(Velocity, VELOCITY)


#define POSITION    \
    int x;          \
    int y;

EC_Component(Position, POSITION)


void
Run_ECS_Test ();


#endif // EC_ECS_TEST_H
       
