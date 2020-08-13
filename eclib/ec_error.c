#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include "ec_error.h"


void
EC_Print_Error
(
  char *test,
  char *result
)
{
  printf ("%-40s %s\n", test, result);
}

#if 0

void
ec_file_open_error ()
{
  FILE *fptr;

  fptr = fopen("nofile", "r");

  printf("Value of errno: %d\n", errno);
  printf("Error opening the file: %s\n", strerror(errno));
  perror("Error printed by perror");
}

#endif
