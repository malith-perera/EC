#include <stdlib.h>

#ifndef ECS_H
#define ECS_H

// Entity
typedef struct Entity {
    int n;
    int M;
} Entity;


Entity
New_Entity(int n, int M);

// Component
typedef struct Component {
    int I;
} Component;

#define New_Component(component) \
    int n##component; \
    component *array##component

#define New_Component_H(component) \
    extern int n##component; \
    extern component *array##component

#define Assign(entity, component) \
    entity##_##component.I = n##component; \
    n##component += entity.n

#define Allocate(component) \
    array##component = (component*) malloc(sizeof(component) * n##component)    

// Entity component
#define Register(entity, component) \
    component *entity##component; \
    Component entity##_##component

#define Register_H(entity, component) \
    extern component *entity##component; \
    extern Component entity##_##component

#define Employ(entity, component) \
    entity##component = &array##component[entity##_##component.I] 

#define Free_Component(component)\
    free(array##component)

#endif
