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

/* This function do not affect copied variables each other */
void
Test_Var_Copy ()
{
    EC_Print_Error ("Test_Copy_Var: ", "BEGIN");

    Student *st1 = Student_Var ();
    EC_Print_Error ("Create new ec variable", "OK");

    st1->no = 1;
    strcpy(st1->name , "Malith");

    Student *st2 = Student_Var_Copy (st1);

    assert (st2->no == 1);
    assert (strcmp(st2->name, "Malith") == 0);

    EC_Print_Error ("Variable copied: ", "OK");

    st1->no = 2;
    strcpy(st2->name , "Geethike");

    assert (st2->no != 2);
    assert (strcmp(st1->name, "Geethike") != 0);

    EC_Print_Error ("Changing one array variable do not affect other array : ", "OK");

    EC_Print_Error ("Test_Copy_Var: ", "END");
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

    Test_Var_Copy ();
    printf ("\n");

    EC_Print_Error ("Test: ec_variable.h", "PASS");
    printf ("\n");
}
