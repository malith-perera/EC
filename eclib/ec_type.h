/*
#define typename(x) _Generic((x),                                                 \
        _Bool: "_Bool",                  unsigned char: "unsigned char",          \
         char: "char",                     signed char: "signed char",            \
    short int: "short int",         unsigned short int: "unsigned short int",     \
          int: "int",                     unsigned int: "unsigned int",           \
     long int: "long int",           unsigned long int: "unsigned long int",      \
long long int: "long long int", unsigned long long int: "unsigned long long int", \
        float: "float",                         double: "double",                 \
  long double: "long double",                   char *: "pointer to char",        \
       void *: "pointer to void",                int *: "pointer to int",         \
      default: "other")
*/

enum t_typename {
    TYPENAME_BOOL,
    TYPENAME_UNSIGNED_CHAR,
    TYPENAME_CHAR,
    TYPENAME_SIGNED_CHAR,
    TYPENAME_SHORT_INT,
    TYPENAME_UNSIGNED_SHORT_INT,
    TYPENAME_INT,
    TYPENAME_POINTER_TO_INT,
    TYPENAME_FLOAT,
    TYPENAME_POINTER_TO_FLOAT,
    TYPENAME_OTHER
};

typedef enum t_typename ectype;

#define typename(x) _Generic((x),                                                       \
        _Bool: TYPENAME_BOOL,           unsigned char: TYPENAME_UNSIGNED_CHAR,          \
         char: TYPENAME_CHAR,             signed char: TYPENAME_SIGNED_CHAR,            \
    short int: TYPENAME_SHORT_INT, unsigned short int: TYPENAME_UNSIGNED_SHORT_INT,     \
          int: TYPENAME_INT,                     \
        int *: TYPENAME_POINTER_TO_INT,          \
        float: TYPENAME_FLOAT, \
      float *: TYPENAME_POINTER_TO_FLOAT, \
      default: TYPENAME_OTHER)
