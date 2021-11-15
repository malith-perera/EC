/* extended c library
 * -------------------
 * Extended C (ec) is a library help you to develop programs with objects in mind.
 * Also help you a way to develop programs DOP (Data Oriended Programming) like
 * ECS (Entity Component System)
 * Allow you to create lists, queues, stacks and there relevent functions easily
 * Easy to manage memory
 */

#ifndef EC_H
#define EC_H

#include <stdio.h>
#include <stdlib.h>

#include "ec_string.h"
#include "ec_error.h"

typedef enum {
    EC_VAR_TYPE,
    EC_ARRAY_TYPE,
    EC_LIST_TYPE,
    EC_LIST_OBJECT_TYPE,
    EC_QUEUE_TYPE,
    EC_QUEUE_OBJECT_TYPE
} ECType;

//#define EC_MEMORY 0

#include "ec_memory.h"
#include "ec_type.h"
#include "ec_variable.h"
#include "ec_array.h"
#include "ec_list.h"
#include "ec_queue.h"
#include "ec_bool.h"
#include "ec_syntax.h"
#include "ec_bits.h"
#include "ec_vector.h"


#endif // EC_H
