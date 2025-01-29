#include "ec_file.h"
#include "ec_error.h"

#define DEBUG 0

typedef struct ecfile {
	char *name;
	char *type;
	char *lines[];
} ecfile;
