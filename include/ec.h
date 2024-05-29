/* ------------------
 * Extended C Library
 * ------------------

 * Extended C(EC) is a library that help you to develop pure C programs more easily.
 * It allows you to create varibles, arrays, lists, queues, stacks and their relevent functions more quickly.
 * It helps you to think programs with objects in mind.
 * It also supports data oriented desing using EC entity component system.
 * Further more EC manages memory and minimize memory errors and leaks if you are interested in.
 
 * Syntax
 * ------
 
 THIS_IS_A_CONSTANT_OR_MACRO                -> constant / macro
 This_Is_A_Function_Or_Function_Like_Macro  -> function / function like macro
 NewType                                    -> new type
 this_is_a_variable                         -> variable
 thisIsAPointer                             -> pointer / array / list / queues / stacks
 
 vi: set expandtab tabstop=4 shiftwidth=4 softtabstop=4

 Also used more spaces than usual to minimize headaches. :)
*/

#ifndef EC_H
#define EC_H

#ifndef EC_MSG_WIDTH
#define EC_MSG_WIDTH 80
#endif

/* below EC_DEBUG and EC_WARN should EC_MEMORY should input at compile time */


#ifndef EC_DEV      // on developement stage
#define EC_DEV 0

#ifndef EC_DEBUG
#define EC_DEBUG 0
#endif

#ifndef EC_WARN
#define EC_WARN 0
#endif

#ifndef EC_MEMORY
#define EC_MEMORY 0
#endif

#else

#undef EC_DEV
#define EC_DEV 1
#define EC_DEBUG 1
#define EC_WARN 1
#define EC_MEMORY 1

#endif // EC_DEV


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "ec_text_color.h"
#include "ec_type.h"
#include "ec_macro.h"
#include "ec_string.h"
#include "ec_file.h"

#include "ec_test.h"
#include "ec_debug.h"
#include "ec_error.h"
#include "ec_warn.h"
#include "ec_memory.h"

#include "ec_var.h"
#include "ec_array.h"
#include "ec_list.h"
#include "ec_queue.h"
#include "ec_stack.h"


#include "ec_loc.h"

#include "ec_ecs.h"

//#include "ec_syntax.h"
//#include "ec_bits.h"
//#include "ec_vector.h"

void
EC_Clean();

#define EC(TYPE) 	\
	EC_VAR(TYPE)	\
	EC_ARRAY(TYPE) 	\
	EC_LIST(TYPE) 	\
	EC_QUEUE(TYPE) 	\
	EC_STACK(TYPE) 	


#endif // EC_H
