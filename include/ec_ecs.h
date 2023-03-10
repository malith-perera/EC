#include "ec.h"

#ifndef EC_ECS_H
#define EC_ECS_H

//#define EC_LIST_VAR_FREE_FUNCTION_NAME(TYPE)        EC_CONCAT(TYPE, _List_Var_Free_Func,)

/*--------*/
/* Entity */
/*--------*/

typedef enum {
    ENTITY_NEW,
    ENTITY_INCRESE,
    ENTITY_DECRESE,
    ENTITY_DROP,
    ENTITY_DELETE,
    N_ENTITY_REQUEST_MODE
} EntityRequestMode;


typedef struct Component {
    int i;
    void *component;
    struct Component *next;
} Component;


typedef struct Entity {
    int n;                      // number of entities in play
    int m;                      // maximum number of entities
    Component *component;
    struct Entity *next;
} Entity;


typedef struct Entity EntityType;


static Entity *entity_list;
static Entity *entity_list_last;
static Entity *request_list;


static Entity *entity_request_array[N_ENTITY_REQUEST_MODE];


static int entity_i;


Entity *
Entity_Request2 (Entity *type, int n, int m);

#define Entity_Request(TYPE, n, m)  \
    Entity_Request2 (&TYPE, n, m)


void
Entity_Reset(Entity *entity, int n, int m);


void
Entity_Request_Complete();


void
ECS_Free ();


Entity *
Get_Request_List();

/*-----------*/
/* Component */
/*-----------*/

void
Component_Reset ();


#define EC_Component(TYPE, VAR)                                 \
    typedef struct TYPE {                                       \
        VAR                                                     \
    } TYPE;                                                     \
                                                                \
    typedef struct EC_CONCAT2(TYPE, List) {                     \
        TYPE *array;                                            \
        struct EC_CONCAT2(TYPE, List) *next;                    \
    } EC_CONCAT2(TYPE, List);                                   \
                                                                \
    extern EC_CONCAT2(TYPE, List) *EC_CONCAT2(TYPE, _list);     \
                                                                \
    void                                                        \
    EC_CONCAT2(TYPE, _List_Append)();


#define Component_List_Append(TYPE, var)                                                                                \
    int EC_CONCAT2(n_, var);                                                                                            \
                                                                                                                        \
    EC_CONCAT2(TYPE, List) *EC_CONCAT2(var, _list);                                                                     \
                                                                                                                        \
    void                                                                                                                \
    EC_CONCAT2(TYPE, _List_Append)()                                                                                    \
    {                                                                                                                   \
        EC_CONCAT2(TYPE, List) *new_list_var = (EC_CONCAT2(TYPE, List) *) malloc (sizeof (EC_CONCAT2(TYPE, List)));     \
        new_list_var->array = NULL;                                                                                     \
        if (EC_CONCAT2(var, _list) != NULL)                                                                             \
        {                                                                                                               \
            EC_CONCAT2(TYPE, List) *temp = EC_CONCAT2(var, _list);                                                      \
            EC_CONCAT2(var, _list) = new_list_var;                                                                     \
            EC_CONCAT2(var, _list)->next = temp;                                                                        \
        }                                                                                                               \
        else                                                                                                            \
        {                                                                                                               \
            EC_CONCAT2(var, _list) =  new_list_var;                                                                     \
            new_list_var->next = NULL;                                                                                  \
        }                                                                                                               \
    }


#define Component_Functions(TYPE, var)                          \
    EC_CONCAT2(TYPE, List) *EC_CONCAT2(TYPE, _list) = NULL;     \
                                                                \
    Component_List_Append(TYPE, var)


#define Add_Component(entity, ComponentType, component)         \
    static ComponentType *EC_CONCAT(entity, _, component)
    

#define get_val(entity_component) (*(entity_component++))


#define foreach_entity(entity, ...)                     \
	//init all components here 							\
	for (Entity player_entity = entity; 	    		\
	       player_entity != NULL; 						\
	       if (player_entity->i < player_entity->n)		\
	      { 										    \
		player_entity->i++;  component_up();		    \
	      } 										    \
	       else { 									    \
		player_entity = player_entity->next;  			\
		if (player_entity != NULL) 						\
		{ 									            \
		      player_next(); 							\
		}									            \
	})


//#define foreach_entity_inner(n, ...) EC_CONCAT2(ARG_SET, n)(__VA_ARGS__)
//
//#define foreach_entity(entity, ...)                             \
//    foreach_entity_inner(EC_COUNT_ARGS(__VA_ARGS__), __VA_ARGS__);

// below functions only use for testing purpose
Entity **
Get_Request_Array ();

#endif // EC_ECS_H



