#ifndef EC_ECS_TEST2_H
#define EC_ECS_TEST2_H


#include "ec_main_test.h"
#include "ec.h"


static Entity *player;
static Entity *enemy;
static Entity *bullet; 
static Entity *empty;
static Entity *box;


#define VELOCITY        \
    int x;              \
    int y;

New_Component(Velocity, VELOCITY, velocity)


void
Run_ECS_Test ();


#endif
