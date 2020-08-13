/*
Start at 2019.06.26.11.47
version 2018.06.27.09.14
*/

/*
variable : this_is_a_variable
constant : THIS_IS_A_CONSTANT
function : this_is_a_funcion
Structure : ThisIsAStructureType
file : thisisafile
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

#include "ec.h"
#include "ec_file.h"
#include "ec_shell.h"

#define WORD_SIZE 256
#define NUMBER_OF_STD_FUNCS 1

/* debuging */
#ifdef DEBUG
	#define DEBUG 0
#endif


void
ec_file (int argc, char *argv[])
{
  char *ec_file_name;

  //check ec file exist
  if (argc <= 1)
  {

  }
  else
  {
    ec_file_name = argv[1];

    printf ("Source file: %s\ncompiling ...\n", ec_file_name);

    ECFile mainECFile; // create object

    ecfile_ECFile_init (&mainECFile, ec_file_name); // initialize

    ecfile_ECFile_parse (&mainECFile); // call parse

    ECFilePtr startECFile = NULL;

    exit(EXIT_SUCCESS);
  }
}


void
create_new_class ()
{
  printf ("class\n");
}


void
create_new_app ()
{
  printf ("app\n");
}


void
create_new_lib ()
{
  printf ("lib\n");
}


void
create_new_appdir ()
{
  printf ("appdir\n");
}


void
create_new_web ()
{
  printf ("web\n");
}


int
main
(
  int argc,
  char *argv[]
)
{
  if (argc == 1)
  {
    shell ();
  }
  else if (argc >= 2)
  {
    if (!strcmp (argv[1], "class"))
    {
      create_new_class ();
    }
    else if (!strcmp (argv[1], "app"))
    {
      create_new_app ();
    }
    else if (!strcmp (argv[1], "lib"))
    {
      create_new_lib();
    }
    else if (!strcmp (argv[1], "appdir"))
    {
      create_new_appdir ();
    }
    else if (!strcmp (argv[1], "web"))
    {
      create_new_web ();
    }
    else
    {
      printf ("\033[1mec:\033[0m\e[1;31m Unknown command:\e[0m %s\n", argv[1]);
      printf ("commands: appdir, app, lib, class, web\n");
      printf ("Use    : ec command [options]\n");
    }
  }

  return 0;
}
