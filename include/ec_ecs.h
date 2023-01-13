#ifndef EC_ECS_H
#define EC_ECS_H


#include "ec.h"


typedef struct Entity {
    int i;
    int n;
    struct Entity *next;
} Entity;


typedef struct EntityWorld {
    int i;
    int n;
    int max;
    int active;
    Entity *entity;
    struct EntityWorld *next;
} EntityWorld;


EntityWorld *ec_world;

int ec_entity_i;
int ec_entity_max;


#define New_Component(TYPE) (TYPE *) malloc (sizeof (TYPE) * ec_entity_max)


Entity *
New_Entity (int n, int max);


void
EC_Entity_Reset ();


int
Get_Entity_i ();


#endif // EC_ECS_H
