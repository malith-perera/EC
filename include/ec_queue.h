#ifndef EC_QUEUE_H
#define EC_QUEUE_H

#include "ec.h"

//#define foreach_queue(queue_type, queue)                                       \
  //for (queue_type *item = queue->first;  item != NULL; item = item->next)

#define EC_QUEUE_STRUCT(T)              EC_CONCAT(T, Queue,)
#define EC_QUEUE_FREE_METHOD(T)         EC_CONCAT(Free_, T,) // memory Free
#define EC_QUEUE_NEW_QUEUE_METHOD(T)    EC_CONCAT(T, _Queue,)
#define EC_QUEUE_OBJECT(T)              EC_CONCAT(T, QueueObj,)
#define EC_QUEUE_OBJECT_FREE_METHOD(T)  EC_CONCAT(Free_Queue_, T,)
#define EC_QUEUE_NEW_OBJECT_METHOD(T)   EC_CONCAT(T, _Queue_Object,)
#define EC_QUEUE_FOREACH(T)             EC_CONCAT(Foreach_, T,)
#define EC_QUEUE_DROP_METHOD(T)         EC_CONCAT(Drop_, T,)
#define EC_QUEUE_FREE_OBJECT_METHOD(T)  EC_CONCAT(Free_, T,_Queue_Object)
#define EC_QUEUE_FREE_QUEUE_METHOD(T)   EC_CONCAT(Free_, T, _Queue)
#define EC_QUEUE_ENQUEUE_METHOD(T)      EC_CONCAT(T, _Enqueue,)
#define EC_QUEUE_DEQUEUE_METHOD(T)      EC_CONCAT(T, _Dequeue,)
#define EC_QUEUE_FRONT_METHOD(T)        EC_CONCAT(T, _Front,)

#endif // EC_QUEUE_H


#ifndef EC_QUEUE
#ifdef  EC
#define EC_QUEUE EC
#endif
#endif

#ifdef  EC_QUEUE

#ifdef  EC_MEMORY
#define EC_Queue(T)                                     \
typedef struct EC_CONCAT(T, QueueObj,){                 \
    ec_var(T);                                           \
    EC_CONCAT(T, QueueObj,)* next;                      \
    bool lock;                                          \
} EC_CONCAT(T, QueueObj,);                              \
                                                        \
                                                        \
typedef struct EC_CONCAT(T, Queue,){                    \
    EC_CONCAT(T, QueueObj,)* first;                     \
    EC_CONCAT(T, QueueObj,)* last;                      \
} EC_CONCAT(T, Queue,);

#endif  // ifdef EC_MEMORY


#ifndef EC_MEMORY
#define EC_Queue(T)                                       \
typedef struct EC_CONCAT(T, QueueObj,){                 \
    ec_var(T);                                           \
    struct EC_CONCAT(T, QueueObj,)* next;               \
} EC_CONCAT(T, QueueObj,);                              \
                                                        \
                                                        \
typedef struct EC_CONCAT(T, Queue,){                    \
    EC_CONCAT(T, QueueObj,)* first;                     \
    EC_CONCAT(T, QueueObj,)* last;                      \
} EC_CONCAT(T, Queue,);

#endif // ifndef EC_MEMORY

void
EC_QUEUE_FREE_METHOD(EC_QUEUE_STRUCT(EC_QUEUE))
(
    void* obj
)
{
    EC_QUEUE_STRUCT(EC_QUEUE)* p = (EC_QUEUE_STRUCT(EC_QUEUE)*) obj;
    free (p);
}


EC_QUEUE_STRUCT(EC_QUEUE)*
EC_QUEUE_NEW_QUEUE_METHOD(EC_QUEUE)
()
{
    EC_QUEUE_STRUCT(EC_QUEUE)* obj = (EC_QUEUE_STRUCT(EC_QUEUE)*) malloc (sizeof (EC_QUEUE_STRUCT(EC_QUEUE)));

    if (obj == NULL)
    {
        printf ("Cannot allocate memory to create queue\n");
        return NULL;
    }

    obj->first = NULL;
    obj->last = NULL;

#ifdef EC_MEMORY
    ECMemory *ec_memory_new = (ECMemory*) malloc (sizeof(ECMemory));

    ec_memory_new->type = EC_QUEUE_TYPE;
    ec_memory_new->obj = obj;
    ec_memory_new->memory = NULL;
    ec_memory_new->Free_Func = EC_QUEUE_FREE_METHOD (EC_QUEUE_STRUCT(EC_QUEUE));
    ec_memory_new->next = NULL;

    if (ec_memory != NULL)
    {
        ec_memory_new->next = ec_memory;
        ec_memory = ec_memory_new;
    }
    else
    {
        ec_memory = ec_memory_new;
    }

#endif

    return obj;
}


void
EC_QUEUE_OBJECT_FREE_METHOD(EC_QUEUE)
(
    void* obj
)
{
    EC_QUEUE* p = (EC_QUEUE*) obj;
    free (p);
}


/*---------------------------------------------------------------------------*
 *                        New Queue Object Method                            *
 *===========================================================================*/

EC_QUEUE_OBJECT (EC_QUEUE)*
EC_QUEUE_NEW_OBJECT_METHOD(EC_QUEUE)
()
{
    EC_QUEUE_OBJECT(EC_QUEUE)* obj = (EC_QUEUE_OBJECT(EC_QUEUE)*) malloc (sizeof (EC_QUEUE_OBJECT(EC_QUEUE)));

#ifdef EC_MEMORY
    ECMemory* ec_memory_new = (ECMemory*) malloc (sizeof (ECMemory));

    ec_memory_new->type = EC_QUEUE_OBJECT_TYPE;
    ec_memory_new->obj = obj;
    ec_memory_new->memory = NULL;
    ec_memory_new->Free_Func = EC_QUEUE_OBJECT_FREE_METHOD (EC_QUEUE);
    ec_memory_new->next = NULL;

    if (ec_memory != NULL)
    {
        ec_memory_new->next = ec_memory;
        ec_memory = ec_memory_new;
    }
    else
    {
        ec_memory = ec_memory_new;
    }

#endif

  return obj;
}


/*----------------------------------------------------------------------------------------*
 *                                   Queue Methods                                        *
 *========================================================================================*/

void
EC_QUEUE_ENQUEUE_METHOD(EC_QUEUE)
(
    EC_QUEUE_STRUCT(EC_QUEUE)* queue,
    EC_QUEUE_OBJECT(EC_QUEUE)* element
)
{
    element->next = NULL;

    if (queue->first != NULL)
    {
        queue->last->next = element;
        queue->last = element;
    }
    else // no elements in queue
    {
        queue->first = element;
        queue->last = element;
    }
}


EC_QUEUE_OBJECT(EC_QUEUE)*
EC_QUEUE_DEQUEUE_METHOD(EC_QUEUE)
(
    EC_QUEUE_STRUCT(EC_QUEUE)* queue
)
{
    EC_QUEUE_OBJECT(EC_QUEUE)* queued_element = NULL;

    if (queue->first != NULL)
    {
        queued_element = queue->first;
        queue->first = queue->first->next;
        if (queue->first == NULL) queue->last = NULL;

        return queued_element;
        // should do something to free element after use
    }
    else
    {
        return NULL;
    }
}


EC_QUEUE_OBJECT (EC_QUEUE)*
EC_QUEUE_FRONT_METHOD(EC_QUEUE)
(
    EC_QUEUE_STRUCT(EC_QUEUE)* queue
)
{
    return queue->first;
}



/*-------------------------------------------------------------------------------------*
 *                                  Queue Free Object Method                           *
 *=====================================================================================*/

void
EC_QUEUE_FREE_OBJECT_METHOD(EC_QUEUE)
(
    EC_QUEUE_STRUCT(EC_QUEUE)* queue,
    EC_QUEUE_OBJECT(EC_QUEUE)* element
)
{
    //EC_QUEUE_DROP_METHOD(EC_QUEUE) (queue, element);
    free (element);
}


#undef EC_QUEUE
#endif