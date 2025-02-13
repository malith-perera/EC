#include "ec.h" 

#ifndef EC_ECS_H
#define EC_ECS_H

/*-------------*/
/* Extened ECS */
/*-------------*/

struct Entity {
    int n; /*number of active entities*/
    int M; /*number of maximum entities*/
};

typedef struct Entity Entity;

EC_VAR_H(Entity)
EC_LIST_H(Entity)

#define Create_New_Entity(entity, n, M)\
    entity = New_Entity(n, M);\


#define Component_List_Struct(component)\
    struct component##List {\
        int n; /*total elements in comoponent array*/\
        component *array;\
    };\
    typedef struct component##List component##List;\
    EC_LIST_C(component##List)


#define Component_List_Struct_H(component)\
    typedef struct component##List component##List;\
    EC_LIST_H(component##List)


#define Entity_Component_List_Struct(entity, component)\
    EC_LIST_C(entity##component##List)

#define Entity_Component_List_Struct_H(entity, component)\
    struct entity##component##List {\
        int I;/*entity set first inedex */\
        component *array;\
    };\
    typedef struct entity##component##List entity##component##List;\
    EC_LIST_H(entity##component##List)


// End Extended ECS



void
Init_ECS();


Entity *
New_Entity(int n, int M);


void
Free_ECS();

/*-----------*/
/* Component */
/*-----------*/
struct Component {
    int I;
    int n;
    int M;
};

typedef struct Component Component; 

typedef int EntityComponent;


#define Component_Array(component, array)\
    int ecN##array;\
    int ecM##array;\
    Component ec##array;\
    component *array


#define Component_Array_H(component, array)\
    extern int ecN##array;\
    extern int ecM##array;\
    extern Component ec##array;\
    extern component *array


#define Array(entity_var, array, entity_id)\
    array[entity_var + entity_id]


#define Assign(entity, array, array_index)\
    array_index = ecN##array;\
    ecN##array += entity->n;\
    ecM##array += entity->M


#define Reallocate(component, n)\
    if(n > ec_M##component){\
        printf("EC Warning: Requested allocation exceeds assigned maximum amount of %s\n", #component);\
        printf("Recheck assinged New_Entity functions for %s\n", #component);\
    }\
    if(n == ec_M##component) {\
        printf("EC Warning: Requested allocation same as assigned amount of %s\n", #component);\
    }\
    ec_##component##Ptr = realloc(ec_##component, sizeof(component) * n);\
    if(ec_##component##Ptr != NULL){\
        ec_##component = ec_##component##Ptr;\
    }\
    else{\
        printf("Unable to reallocate memory for %s\n", #component);\
    }


#define Allocate(component, array)\
    array = (component*) malloc(sizeof(component) * ecM##array);

    //Reallocate(component, ec_n##component)


#define Free_Component(array)\
    do {\
        if(array != NULL) {\
            free(array);\
            array = NULL;\
        }\
    } while(0);


#define Clear(array)\
    ecN##array = 0;\
    ecM##array = 0

/*------------------*/
/* Entity component */
/*------------------*/

#define Register(entity, component)\
    component *entity##component; /* points to component array member */\
    Component ec_##entity##component /* first entity index of component array */


#define Register_H(entity, component)\
    extern component *entity##component;\
    extern Component ec_##entity##component


#define Employ(entity, component)\


#endif // EC_ECS_H
