#include "ec.h" 

#ifndef EC_ECS_H
#define EC_ECS_H

/*-------------*/
/* Extened ECS */
/*-------------*/

/*--------*/
/* Entity */
/*--------*/

struct Entity {
    int n; /*number of active entities*/
    int m; /*number of maximum entities*/
};

typedef struct Entity Entity;

EC_VAR_H(Entity);
EC_LIST_H(Entity)


Entity *
New_Entity(Entity *entity);


EntityList *
New_Entity_List(EntityList *entity_list, int n, int M);


/*-----------*/
/* Component */
/*-----------*/

#define New_Component_H(component, array)\
    extern int ecN##array;\
    extern int ecM##array;\
    extern component *array;\
    EC_VAR_H(component)\
    EC_LIST_H(component)\
    extern component##List *array##List;


#define New_Component(component, array)\
    int ecN##array;\
    int ecM##array;\
    component *array;\
    EC_VAR_C(component)\
    EC_LIST_C(component);\
    component##List *array##List;

/*------------------*/
/* Entity Component */
/*------------------*/

#define EntityComponent_H(entity, component)\
    struct entity##component##struc {\
        int I;\
        component *a;\
    };\
    typedef struct entity##component##struc entity##component##struc;\
    EC_VAR_H(entity##component##struc)\
    EC_LIST_H(entity##component##struc)\
    extern entity##component##struc##List *entity##component##List;\
    extern entity##component##struc entity##component

#define EntityComponent(entity, component)\
    entity##component##struc##List *entity##component##List;\
    entity##component##struc entity##component


#define Free_Component(array)\
    ({\
        if(array != NULL) {\
            free(array);\
            array = NULL;\
        }\
    })


// End Extended ECS

#define Assign(entity, array, entityComponent)\
    entityComponent.I = ecN##array;\
    entityComponent.a = array;\
    ecN##array += entity->n;\
    ecM##array += entity->m


#define Allocate(component, array)\
    array = (component*) malloc(sizeof(component) * ecM##array);


#endif // EC_ECS_H
