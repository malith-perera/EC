#include "ec.h"


#ifndef ECS_H
#define ECS_H

#define CONCAT(a, b, c) a ## b ## c

typedef enum {ENTITY_NEW, ENTITY_UNCHANGED, ENTITY_MORE, ENTITY_LESS, ENTITY_DROP, ENTITY_DELETE} EntityRequestType;


typedef struct Ids {
    int i;
    int n;
    int m;
    struct Ids *next;
} Ids;


typedef struct Entity {
    int i;                      // first index or entity request type
    int n;                      // number of entities in play
    int m;                      // maximum number of entities
    struct Entity *next;
} Entity;


static Entity *entity_list;
static Entity *entity_list_last;


typedef struct EntityRequest {
    int                     n;
    int                     m;
    Entity                  *entity;            // use to identify which entity request
    EntityRequestType       type;               // request type 
    struct EntityRequest    *next;
} EntityRequest;


static EntityRequest *entity_request_list;
static EntityRequest *entity_request_list_last;

static int entity_i;


Entity *
Entity_Request (Entity *entity, int n, int m);


void
Entity_Free ();


/*------------*/
/* Components */
/*------------*/

void
Component_Create ();


#define New_Component(TYPE, VAR, var)               \
    typedef struct TYPE {                           \
        VAR                                         \
    } TYPE;                                         \
                                                    \
    static TYPE *var;                               \
                                                    \
    typedef struct CONCAT(TYPE, Component,) {       \
        TYPE *var;                                  \
        struct CONCAT(TYPE, Component,) *next;      \
    } CONCAT(TYPE, Component,);


#define get_val(entity_component) (*(entity_component++))

// below functions only use for testing purpose
EntityRequest *
Get_Request_List ();

#endif
