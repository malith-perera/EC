#ifndef EC_ECS_H
#define EC_ECS_H

#include "ec.h"


/* new ecs */

extern int ec_n_entity; // total number of entities

typedef struct EC_Entity {
	int n;
	int m;
} EC_Entity;

typedef struct EC_EntityComponent {
    int I;  // first entity index
	int i;  // current entity index
    int n;  // number of active entities 
	int m;  // maximum number of entities
    int M;  // maximum number of entities ***delete m is up
	EC_MEMORY_REF
} EC_EntityComponent;


typedef struct EC_EntityComponentList {
	EC_EntityComponent *entity_component;
	struct EC_EntityComponentList *next;
} EC_EntityComponentList;


#define for_entity(entity_type, i) 	\
	for (int i = 0; i < EC_CONCAT3(ec, entity_type, Entity).n; i++)


#define EC_Component(entity_type, n, component_type)	\
		EC_CONCAT(ec, component_type)[EC_CONCAT3(ec, entity_type, component_type)->i + n]


/* Entity */

#define EC_Entity_H(entity_type) 													\
	extern EC_Entity EC_CONCAT3(ec, entity_type, Entity);							\
    extern EC_EntityComponentList *EC_CONCAT3(ec, entity_type, EntityComponentList);\
	void EC_CONCAT(entity_type, _Assign)(int n, int m);  							\
	void EC_CONCAT(entity_type, _Free)();


#define EC_Entity_C(entity_type) 													\
	EC_Entity EC_CONCAT3(ec, entity_type, Entity);									\
	void EC_CONCAT(entity_type, _Assign)(int n, int m) { 							\
		EC_CONCAT3(ec, entity_type, Entity).n = n;									\
		EC_CONCAT3(ec, entity_type, Entity).m = m;									\
	}																				\
																					\
	void EC_CONCAT(entity_type, _Free)() { 											\
		EC_EntityComponentList *temp, *next; 										\
		temp = EC_CONCAT3(ec, entity_type, EntityComponentList); 					\
																					\
		while (temp != NULL) { 														\
			next = temp->next; 														\
			free(temp);																\
			temp = next; 															\
		} 																			\
	}


/* Component */

#define EC_Component_H(component_type)												\
	extern int EC_CONCAT(ecN, component_type);										\
	extern int EC_CONCAT3(ecN, component_type, Request);							\
	extern component_type *EC_CONCAT(ec, component_type);							\
																					\
	void EC_CONCAT(component_type, _Assign) (); 									\
	void EC_CONCAT(component_type, _Free) ();										\


#define EC_Component_C(component_type)												\
	int EC_CONCAT(ecN, component_type);					  							\
	component_type *EC_CONCAT(ec, component_type);									\
																					\
	void EC_CONCAT(component_type, _Assign) () 										\
	{	 																			\
		component_type *component_ptr;												\
		if (EC_CONCAT(ec, component_type) == NULL) {							 	\
			component_ptr = (component_type *) calloc (EC_CONCAT(ecN, component_type), sizeof (component_type)); \
			if (component_ptr == NULL) 												\
			{																		\
				printf ("Error: Cannot allocate component memory\n");				\
				exit(0);															\
			} 																		\
		} 																			\
		else {																		\
			component_ptr = (component_type *) realloc (EC_CONCAT(ec, component_type), EC_CONCAT(ecN, component_type)); \
			if (component_ptr == NULL) 												\
			{																		\
				printf ("Error: Cannot reallocate component memory\n"); 			\
				return;																\
			}																		\
		} 																			\
		EC_CONCAT(ec, component_type) = component_ptr; 								\
	} 																				\
																					\
	void EC_CONCAT(component_type, _Free)()											\
	{ 																				\
		free (EC_CONCAT(ec, component_type)); 										\
		EC_EntityComponentList *temp, *next; 										\
		temp = EC_CONCAT3(ec, component_type, EntityComponentList); 				\
		while (temp != NULL) { 														\
			next = temp->next; 														\
			free(temp->entity_component); 											\
			free(temp); 															\
			temp = next; 															\
		} 																			\
    }


/* Entity Components */

#define EC_Entity_Component_H(entity_type, component_type) 								\
    extern EC_EntityComponentList *EC_CONCAT3(ec, component_type, EntityComponentList); \
	extern EC_EntityComponent *EC_CONCAT3(ec, entity_type, component_type); 			\
	void EC_CONCAT4(entity_type, _, component_type, _Assign)();							\
	component_type *EC_CONCAT3(entity_type, _, component_type)(int n);


#define EC_Entity_Component_C(entity_type, component_type)									\
    EC_EntityComponentList *EC_CONCAT3(ec, entity_type, EntityComponentList);				\
    EC_EntityComponentList *EC_CONCAT3(ec, component_type, EntityComponentList);			\
	EC_EntityComponent *EC_CONCAT3(ec, entity_type, component_type);						\
																							\
	void EC_CONCAT4(entity_type, _, component_type, _Assign)()								\
	{																						\
		EC_EntityComponent *entity_component = (EC_EntityComponent *) malloc (sizeof (EC_EntityComponent)); 					\
		EC_EntityComponentList *entity_component_list = (EC_EntityComponentList *) malloc (sizeof (EC_EntityComponentList)); 	\
		EC_EntityComponentList *entity_component_list2 = (EC_EntityComponentList *) malloc (sizeof (EC_EntityComponentList)); 	\
																							\
		EC_EntityComponentList *temp;														\
																							\
		if (entity_component == NULL || entity_component_list == NULL || entity_component_list2 == NULL) {  \
			printf ("Error: Entity_Component_Assign memory allocation Error\n");			\
			exit (0);																		\
		}																					\
																							\
		entity_component_list->entity_component = entity_component;							\
		entity_component_list2->entity_component = entity_component;						\
																							\
		EC_CONCAT3(ec, entity_type, component_type) = entity_component;						\
																							\
		entity_component->n = EC_CONCAT3(ec, entity_type, Entity).n; 						\
		entity_component->m = EC_CONCAT3(ec, entity_type, Entity).m; 						\
																							\
		/* Find i */																		\
		EC_EntityComponentList *list = EC_CONCAT3(ec, component_type, EntityComponentList);	\
		int i = 0; 																			\
																							\
		while (list != NULL) { 																\
			i += list->entity_component->m;  												\
			list = list->next; 																\
		}																					\
																							\
		entity_component->i = i; 															\
		EC_CONCAT(ecN, component_type) = i + entity_component->m; 							\
																							\
		/* Add to component, EntityComponentList */											\
																							\
		if (EC_CONCAT3(ec, component_type, EntityComponentList) != NULL) {					\
			temp = EC_CONCAT3(ec, component_type, EntityComponentList);						\
			EC_CONCAT3(ec, component_type, EntityComponentList) = entity_component_list;	\
			entity_component_list->next = temp;												\
		}																					\
		else {																				\
			EC_CONCAT3(ec, component_type, EntityComponentList) = entity_component_list;	\
			entity_component_list->next = NULL;												\
		}																					\
																							\
		/* Add to entity, EntityComponentList */											\
																							\
		if (EC_CONCAT3(ec, entity_type, EntityComponentList) != NULL) {						\
			temp = EC_CONCAT3(ec, entity_type, EntityComponentList);						\
			EC_CONCAT3(ec, entity_type, EntityComponentList) = entity_component_list2;		\
			entity_component_list2->next = temp;											\
		}																					\
		else {																				\
			EC_CONCAT3(ec, entity_type, EntityComponentList) = entity_component_list2;		\
			entity_component_list2->next = NULL;											\
		}																					\
	}																						\
																							\
	component_type *EC_CONCAT3(entity_type, _, component_type)(int n) {						\
		return &EC_CONCAT(ec, component_type)[EC_CONCAT3(ec, entity_type, component_type)->i + n]; 	\
	}


/*
	EC_CONCAT(entity_type, component_type) = (ECEntityComponent *) malloc (sizeof (ECEntityComponent));
*/

/* end new ecs */




extern int nEntity;


typedef struct ECEntity {
    int I;  // first entity index
	int i;  // current entity index
    int n;  // number of active entities 
    int M;  // maximum number of entities
} ECEntity;


#define EC_Get_Component(n, entity, component) \
    component[EC_CONCAT3(entity, _, component).I + n - 1]


ECEntity
EC_Entity_New (int n, int M);


void
ECS_Free ();


#endif  // EC_ECS_H


#if 0




/*--------*/
/* Entity */
/*--------*/



#define EC_ENTITY_COMPONENT(entity_type, component_type) 			\
	typedef struct EC_CONCAT(entity_type, component_type) { 		\
		int I;														/* entity begining index */\
		int i;														/* current index */\
		int n;														/* current entity amount */\
		int m;														/* maximum entity amount */\
		component_type *array; 										\
	} EC_CONCAT(entity_type, component_type); 						\
																	\
	typedef struct EC_CONCAT3(entity_type, component_type, List) {  \
		EC_CONCAT(entity_type, component_type) *list;				\
		EC_CONCAT3(entity_type, component_type, List) *next; 		\
	} EC_CONCAT3(entity_type, component_type, List);












//#define EC_LIST_VAR_FREE_FUNCTION_NAME(TYPE)        EC_CONCAT(TYPE, _List_Var_Free_Func)

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
    typedef struct EC_CONCAT(TYPE, List) {                     \
        TYPE *array;                                            \
        struct EC_CONCAT(TYPE, List) *next;                    \
    } EC_CONCAT(TYPE, List);                                   \
                                                                \
    extern EC_CONCAT(TYPE, List) *EC_CONCAT(TYPE, _list);     \
                                                                \
    void                                                        \
    EC_CONCAT(TYPE, _List_Append)();


#define Component_List_Append(TYPE, var)                                                                                \
    int EC_CONCAT(n_, var);                                                                                            \
                                                                                                                        \
    EC_CONCAT(TYPE, List) *EC_CONCAT(var, _list);                                                                     \
                                                                                                                        \
    void                                                                                                                \
    EC_CONCAT(TYPE, _List_Append)()                                                                                    \
    {                                                                                                                   \
        EC_CONCAT(TYPE, List) *new_list_var = (EC_CONCAT(TYPE, List) *) malloc (sizeof (EC_CONCAT(TYPE, List)));     \
        new_list_var->array = NULL;                                                                                     \
        if (EC_CONCAT(var, _list) != NULL)                                                                             \
        {                                                                                                               \
            EC_CONCAT(TYPE, List) *temp = EC_CONCAT(var, _list);                                                      \
            EC_CONCAT(var, _list) = new_list_var;                                                                     \
            EC_CONCAT(var, _list)->next = temp;                                                                        \
        }                                                                                                               \
        else                                                                                                            \
        {                                                                                                               \
            EC_CONCAT(var, _list) =  new_list_var;                                                                     \
            new_list_var->next = NULL;                                                                                  \
        }                                                                                                               \
    }


#define Component_Functions(TYPE, var)                          \
    EC_CONCAT(TYPE, List) *EC_CONCAT(TYPE, _list) = NULL;     \
                                                                \
    Component_List_Append(TYPE, var)


#define Add_Component(entity, ComponentType, component)         \
    static ComponentType *EC_CONCAT3(entity, _, component)
    

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


//#define foreach_entity_inner(n, ...) EC_CONCAT(ARG_SET, n)(__VA_ARGS__)
//
//#define foreach_entity(entity, ...)                             \
//    foreach_entity_inner(EC_COUNT_ARGS(__VA_ARGS__), __VA_ARGS__);

// below functions only use for testing purpose
Entity **
Get_Request_Array ();


#endif
