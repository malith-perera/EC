#include <stdio.h>
#include <stdlib.h>
#if 0
#include "ecerror.h"

void
ec_error (EcError error, char *file, int line, int column, char *text)
{
  switch (error)
  {
    case FILE_ERROR:
      printf ("FileError:\n%s file not found\n", file);
      printf("\033[1mec:\033[0m\e[1;31m fatal error:\e[0m no input file found\nTranslation terminated.\n");
      break;
    case INDENT_ERROR:
      printf ("IndentError:\n%s\n", file);
      break;
    default:
      break;
  }
  exit (EXIT_FAILURE);
}
#endif

