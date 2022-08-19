/* Extended C Library
 * ------------------
 * Extended C (ec) is a library help you to develop pure C programs with objects in mind.
 * Allow you to create varibles, arrays, lists, queues, stacks and their relevent functions easily
 * And automate memory without memory leaks if you are interested in.
 */

/* vi: set ts=4 sw=4 expandtab: */

#ifndef EC_H
#define EC_H

#define DEBUG 1
#define EC_WARN 1

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

#include "ec_var_ref.h"
#include "ec_array_ref.h"
#include "ec_list_ref.h"
#include "ec_queue_ref.h"
#include "ec_stack_ref.h"

//#include "ec_syntax.h"
//#include "ec_bits.h"
//#include "ec_vector.h"

#endif // EC_H
