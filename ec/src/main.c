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
#include <dirent.h>
#include <unistd.h>

#include "ec.h"
#include "ec_file.h"
#include "ec_shell.h"

#define WORD_SIZE 256
#define NUMBER_OF_STD_FUNCS 1

/* debuging */
#ifdef DEBUG
	#define DEBUG 0
#endif

char cmd[1024];
char cmakefile[4096];


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
Create_CMakeList_file
(
  char *app
)
{
  char *minimum_required = "cmake_minimum_required (VERSION 3.10.2)\n";
  char *project_line_begin = "project (";
  char *project_line_end = ")\n";
  char *lower_body = "\n\
set (CMAKE_BUILD_TYPE DEBUG)  #Release type\n\
\n\
# selecting the build mode in their IDE\n\
if (${CMAKE_CXX_COMPILER_ID} STREQUAL \"GNU\" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL \"Clang\")\n\
  set (CMAKE_CXX_FLAGS \"${CMAKE_CXX_FLAGS}  `--libs --cflags` -ggdb3 -O0 --std=c11 -Wall image -lm\")\n\
  set (CMAKE_CXX_FLAGS_DEBUG \"${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g\")\n\
  set (CMAKE_CXX_FLAGS_RELEASE \"${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2\")\n\
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL \"MSVC\")\n\
  if (CMAKE_CXX_FLAGS MATCHES \"/W[0-4]\")\n\
    string(REGEX REPLACE \"/W[0-4]\" \"/W4\" CMAKE_CXX_FLAGS \"${CMAKE_CXX_FLAGS}\")\n\
  else ()\n\
    set (CMAKE_CXX_FLAGS \"${CMAKE_CXX_FLAGS} /W4\")\n\
  endif ()\n\
endif ()\n\
\n\
get_filename_component (PARENT_DIR  ${PROJECT_SOURCE_DIR} DIRECTORY)\n\
get_filename_component (UPPER_PARENT_DIR ${PARENT_DIR} DIRECTORY)\n\
\n\
# Set an output directory for binary app-icon\n\
set (BIN_DIR ${PARENT_DIR}/bin)\n\
set (PROJECT_INCLUDE_DIRS ${PARENT_DIR}/include)\n\
\n\
set (PROJECT_LINK_LIBS libec.so)\n\
set (PROJECT_LINK_DIRS ${PROJECT_SOURCE_DIR}/lib ${UPPER_PARENT_DIR}/EC/lib)\n\
link_directories (${PROJECT_LINK_DIRS})\n\
\n\
include_directories (${PROJECT_INCLUDE_DIRS} ${UPPER_PARENT_DIR}/EC/include)\n\
\n\
#file (GLOB...) allows wildcard additions\n\
file (GLOB SOURCES \"${PARENT_DIR}/src/*.c\")\n\
\n\
#Generate executable from the sources\n\
add_executable (${PROJECT_NAME} ${SOURCES})\n\
target_link_libraries (${PROJECT_NAME} LINK_PUBLIC ${PROJECT_LINK_LIBS} m)\n\
install (TARGETS ${PROJECT_NAME} DESTINATION ${BIN_DIR})\n";

  snprintf (cmakefile, sizeof (cmakefile), "%s%s%s%s%s", minimum_required, project_line_begin, app, project_line_end, lower_body);
}


int
create_new_app (char *app)
{
  char cur_dir[1024];
  DIR *dr;
  struct dirent *de;
  bool app_dir_exist = false;
  FILE *file,*new_file;
  char cmakefilepath[256];

  chdir ("..");
  system ("echo $PWD");
  printf("%s\n", getcwd(cur_dir, 1024));

  dr = opendir(cur_dir);

  if (dr == NULL) // opendir returns NULL if couldn't open directory
  {
    printf("Could not open current directory" );
    return 0;
  }

  while ((de = readdir(dr)) != NULL)
  {
    if (!strcmp (de->d_name, ".") || !strcmp (de->d_name, ".."))
      continue;

    /*printf("%s\n", de->d_name);*/

    if (!strcmp (de->d_name, app)) // strcmp return 0 when equel
    {
      printf ("%s directory already exist\n", app);
      app_dir_exist = true;
      break;
    }
  }

  if (app_dir_exist == false)
  {
    printf ("make %s directory\n", app);

    snprintf (cmd, sizeof (cmd), "mkdir %s", app);
    system (cmd);

    snprintf (cmd, sizeof (cmd), "mkdir %s/bin", app);
    system (cmd);

    snprintf (cmd, sizeof (cmd), "mkdir %s/icons", app);
    system (cmd);

    snprintf (cmd, sizeof (cmd), "mkdir %s/include", app);
    system (cmd);

    snprintf (cmd, sizeof (cmd), "mkdir %s/src", app);
    system (cmd);

    snprintf (cmd, sizeof (cmd), "mkdir %s/tools", app);
    system (cmd);

    snprintf (cmd, sizeof (cmd), "cp etc/open.sh %s", app);
    system (cmd);

    snprintf (cmd, sizeof (cmd), "cp etc/setup.sh %s", app);
    system (cmd);

    snprintf (cmd, sizeof (cmd), "cp etc/readme %s", app);
    system (cmd);

    snprintf (cmd, sizeof (cmd), "cp etc/main.c %s/src", app);
    system (cmd);

    Create_CMakeList_file (app); // cmakefile is create here

    snprintf (cmakefilepath, sizeof (cmakefilepath), "%s/%s", app, "tools/CMakeLists.txt");

    if ((file = fopen (cmakefilepath, "w")) != NULL)
    {
      fputs (cmakefile, file); // above Create_CMakeList_file function create cmakefile
      fclose (file);
    }
    else
    {
      printf ("Cannot open CMakeList.txt file\n");
    }
  }
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
      create_new_app (argv[2]);
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
