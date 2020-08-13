#ifndef class_H
#define class_H

#include "ec.h"

#ifdef EC_GARBAGE
#define expand(S)                             \
typedef struct S                              \
{                                             \
  class(S);                                   \
  bool lock;                                  \
} S;                                          \
                                              \
                                              \
typedef struct EC_CONCAT (S, Array,)          \
{                                             \
  S *array;                                   \
  int count;                                  \
  bool lock;                                  \
} EC_CONCAT (S, Array,);                      \
                                              \
                                              \
typedef struct EC_CONCAT (S, ListObj,)        \
{                                             \
  class(S);                                   \
  struct EC_CONCAT (S, ListObj,) *next;       \
  struct EC_CONCAT (S, ListObj,) *previous;   \
  bool lock;                                  \
} EC_CONCAT (S, ListObj,);                    \
                                              \
                                              \
typedef struct EC_CONCAT (S, List,)           \
{                                             \
  EC_CONCAT (S, ListObj,) *first;             \
  EC_CONCAT (S, ListObj,) *last;              \
  bool lock;                                  \
} EC_CONCAT (S, List,);                       \
                                              \
typedef S EC_CONCAT (S, ArrayObj,)
#endif  // ifdef EC_GARBAGE


#ifndef EC_GARBAGE
#define expand(S)                             \
typedef struct S                              \
{                                             \
  class(S);                                   \
} S;                                          \
                                              \
                                              \
typedef struct EC_CONCAT (S, Array,)          \
{                                             \
  S *array;                                   \
  int count;                                  \
} EC_CONCAT (S, Array,);                      \
                                              \
                                              \
typedef struct EC_CONCAT (S, ListObj,)        \
{                                             \
  class(S);                                   \
  struct EC_CONCAT (S, ListObj,) *next;       \
  struct EC_CONCAT (S, ListObj,) *previous;   \
} EC_CONCAT (S, ListObj,);                    \
                                              \
                                              \
typedef struct EC_CONCAT (S, List,)           \
{                                             \
  EC_CONCAT (S, ListObj,) *first;             \
  EC_CONCAT (S, ListObj,) *last;              \
} EC_CONCAT (S, List,);                       \
                                              \
typedef S EC_CONCAT (S, ArrayObj,)
#endif // ifndef EC_GARBAGE

#endif // class_H
