#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "ec_variable_test.h"
#include "ec_variable.h"


Student *st;


void
Test_New_Variable ()
{
    EC_Print_Error ("Test_New_Variable: ", "BEGIN");

    Student *st = Student_Var ();
    EC_Print_Error ("Create new ec variable", "OK");

    st->no = 1;
    st->name = "Malith";
    EC_Print_Error ("Assign ec variable attributes", "OK");

    EC_Print_Error ("Test_New_Variable:", "END");
}


void
Test_New_Variable_Memory_Free ()
{
    EC_Print_Error ("Test_New_Variable_Memory_Free: ", "BEGIN");

    if (EC_MEMORY)
    {
        EC_Clean ();
        EC_Print_Error ("Call EC_Clean ()", "OK");
        st = NULL;
    }

    if (st == NULL)
    {
        EC_Print_Error ("EC_Clean free", "OK");
        EC_Print_Error ("Test_New_Variable_Memory_Free:", "END");
    }
    else
    {
        EC_Print_Error ("Test_New_Variable_Memory_Free:", "Fail");
        assert (st == NULL);
        exit (EXIT_FAILURE);
    }

    EC_Print_Error ("Test_New_Variable_Memory_Free:", "END");
}


void
Run_Variable_Test ()
{
    printf ("------------------\n");
    printf ("Test: ec_variable.h\n");
    printf ("==================\n");

    Test_New_Variable ();
    printf ("\n");

    Test_New_Variable_Memory_Free ();
    printf ("\n");

    EC_Print_Error ("Test: ec_variable.h", "PASS");
    printf ("\n");
}
