#ifndef EC_H
#define EC_H

#include <stdlib.h>

#include "ec_string.h"
#include "ec_error.h"

typedef enum {
  EC_OBJECT_TYPE,
  EC_ARRAY_TYPE,
  EC_LIST_TYPE,
  EC_LIST_OBJECT_TYPE
} ECType;


typedef struct ECWorld {
  ECType type;
  void *obj;
  void *garbage;
  void (*Free_List) (void *);
  struct ECWorld *next;
} ECWorld;


ECWorld *ec_world;

#include "ec_garbage.h"
#include "ec_class.h"
#include "ec_object.h"
#include "ec_array.h"
#include "ec_list.h"
#include "ec_bool.h"
#include "ec_syntax.h"
#include "ec_bits.h"
#include "ec_vector.h"

#endif // EC_H
