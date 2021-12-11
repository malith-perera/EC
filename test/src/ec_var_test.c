#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "ec_var_test.h"
#include "ec_var.h"


void
Test_New_Var ()
{
    EC_Print_Error ("Test_New_Var: ", "BEGIN");

    Student *st = Student_Var ();
    EC_Print_Error ("Create new ec var", "OK");

    st->no = 1;
    st->name = "Malith";
    EC_Print_Error ("Assign ec var attributes", "OK");

    EC_Print_Error ("Test_New_Var:", "END");
}


void
Test_New_Var_Memory_Free ()
{
    EC_Print_Error ("Test_New_Var_Memory_Free: ", "BEGIN");

    if (EC_MEMORY)
    {
        EC_Clean ();
        EC_Print_Error ("Call EC_Clean ()", "OK");
    }

    EC_Print_Error ("Test_New_Var_Memory_Free:", "END");
}

/* This function do not affect copied vars each other */
void
Test_Var_Copy ()
{
    EC_Print_Error ("Test_Copy_Var: ", "BEGIN");

    Student* st1 = Student_Var ();
    EC_Print_Error ("Create new ec var", "OK");

    st1->no = 1;
    st1->name = "Malith";

    Student *st2 = Student_Var_Copy (st1);

    assert (st2->no == 1);
    assert (strcmp(st2->name, "Malith") == 0);

    EC_Print_Error ("Var copied: ", "OK");

    st1->no = 2;
    st2->name = "Geethike";

    assert (st2->no == 1);
    assert (strcmp(st1->name, "Geethike") != 0);

    EC_Print_Error ("Changing one array should not affect other", "OK");

    EC_Print_Error ("Test_Copy_Var: ", "END");
}


void
Run_Var_Test ()
{
    printf ("------------------\n");
    printf ("Test: ec_var.h\n");
    printf ("==================\n");

    Test_New_Var ();
    printf ("\n");

    Test_New_Var_Memory_Free ();
    printf ("\n");

    Test_Var_Copy ();
    printf ("\n");

    EC_Print_Error ("Test: ec_var.h", "PASS");
    printf ("\n");
}
