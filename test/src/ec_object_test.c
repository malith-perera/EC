#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "ec_object_test.h"

#define EC_GARBAGE
#include "ec.h"


#define class(Student)   \
  int no;                \
  char *name;
expand(Student);
#undef class

#define EC_OBJECT Student
#include "ec_object.h"


void
Test_New_Object ()
{
  EC_Print_Error ("Test_New_Object: ", "BEGIN");

  Student *st = New_Student ();
  EC_Print_Error ("Create new object", "OK");

  st->no = 1;
  st->name = "Malith";
  EC_Print_Error ("Assign object attributes", "OK");

  EC_Print_Error ("Test_New_Object:", "END");
}

#if 0
void
Test_New_Object_Garbage_Free ()
{
  EC_Print_Error ("Test_New_Object_Garbage_Free: ", "BEGIN");

  Student *st = New_Student ();
  EC_Print_Error ("Create New Object", "OK");

#ifdef EC_GARBAGE
  //EC_Clean ();
  EC_Print_Error ("Call EC_Clean ()", "UNFINISHED");
#endif

  /*
  // ***** unsuccessfull try again
  if (st == NULL)
  {
    EC_Print_Error ("EC_Clean free", "OK");
    EC_Print_Error ("Test_New_Object_Garbage_Free:", "END");
  }
  else
  {
    EC_Print_Error ("Test_New_Object_Garbage_Free:", "Fail");
    assert (st == NULL);
    exit (EXIT_FAILURE);
  }
  */

    EC_Print_Error ("Test_New_Object_Garbage_Free:", "END");
}
#endif


void
Run_Object_Test ()
{
  printf ("------------------\n");
  printf ("Test: ec_object.h\n");
  printf ("==================\n");

  Test_New_Object ();
  printf ("\n");
  //Test_New_Object_Garbage_Free ();
  printf ("\n");

  EC_Print_Error ("Test: ec_object.h", "PASS");
  printf ("\n");
}
