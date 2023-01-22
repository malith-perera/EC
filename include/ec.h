/* ------------------
 * Extended C Library
 * ------------------
 
 * Extended C (EC) is a library that help you to develop pure C programs more easily.
 * Help you to think with objects in mind.
 * Allow you to create varibles, arrays, lists, queues, stacks and their relevent functions easily.
 * Manages memory and minimize memory errors and leaks if you are interested in.
 * Also support data oriented desing using inbuilt entity component system.

 * Syntax
 * ------
 
 LIB_OBJECT_NOUN    -> constant / macro
 Lib_Object_Verb()  -> function / function like macro
 LibType            -> new type
 lib_noun           -> variable
 libNoun            -> pointer / array / list / queues / stacks

 vi: set expandtab tabstop=4 shiftwidth=4

 Also used more spaces than usual to minimize headaches. :)
*/


#ifndef EC_H
#define EC_H

#ifndef DEBUG
#define DEBUG 1
#endif

#ifndef EC_WARN
#define EC_WARN 1
#endif

#ifndef EC_MEMORY
#define EC_MEMORY 1
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "ec_text_color.h"
#include "ec_type.h"
#include "ec_string.h"

#include "ec_test.h"
#include "ec_error.h"
#include "ec_warn.h"
#include "ec_memory.h"

#include "ec_var.h"
#include "ec_array.h"
#include "ec_list.h"
#include "ec_queue.h"
#include "ec_stack.h"
#include "ec_ecs.h"

#include "ec_var_ref.h"
#include "ec_array_ref.h"
#include "ec_list_ref.h"
#include "ec_queue_ref.h"
#include "ec_stack_ref.h"

//#include "ec_syntax.h"
//#include "ec_bits.h"
//#include "ec_vector.h"

void
EC_Clean();

#endif // EC_H
