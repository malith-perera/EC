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
    int M; /*number of maximum entities*/
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

struct EntCom {
    int I;
    void *array;
};

typedef struct EntCom EntCom;

EC_VAR_H(EntCom);
EC_LIST_H(EntCom)

#define Add_H(entity, component)\
    extern EntCom entity##_##component;\
    extern EntComList *entity##component##List

#define Add(entity, component)\
    EntCom entity##_##component;\
    EntComList *entity##component##List


#define Free_Component(array)\
    ({\
        if(array != NULL) {\
            free(array);\
            array = NULL;\
        }\
    })


/* still not in use */
/* may be use to tuckle removed entities and there components */
struct ComponentArray{
    Entity *entity;
    EntCom *entityComponent;
    void *array;
};

typedef struct ComponentArray ComponentArray;

// End Extended ECS


typedef int EntityComponent;


#define Assign(entity, array, array_index)\
    array_index = ecN##array;\
    ecN##array += entity->n;\
    ecM##array += entity->M


#define Allocate(component, array)\
    array = (component*) malloc(sizeof(component) * ecM##array);


#endif // EC_ECS_H
