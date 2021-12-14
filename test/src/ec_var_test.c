#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "ec_var_test.h"
#include "ec_var.h"


/* Test: New Var
 * Creating and accessing a new variable */
void
Test_New_Var ()
{
    EC_Print_Error ("Test_New_Var: ", "BEGIN");

    StudentVar* st = Student_Var ();
    EC_Print_Error ("Create ec var", "OK");

    st->no = 1;
    st->name = "Malith";
    EC_Print_Error ("Assign ec var", "OK");

    assert (st->no == 1);
    assert (strcmp(st->name, "Malith") == 0);
    EC_Print_Error ("Access ec var", "OK");

    StudentVar st_on_stack;
    EC_Print_Error ("Create ec var on stack", "OK");

    st_on_stack.no = 2;
    st_on_stack.name = "Geethike";
    EC_Print_Error ("Assign ec var on stack", "OK");

    assert (st_on_stack.no == 2);
    assert (strcmp(st_on_stack.name, "Geethike") == 0);
    EC_Print_Error ("Access ec var on stack", "OK");

    EC_Print_Error ("Test_New_Var:", "END");
}


/* Test: Var_Copy
 * This function should not affect copied vars each other */
void
Test_Var_Copy ()
{
    EC_Print_Error ("Test_Var_Copy: ", "BEGIN");

    StudentVar* st1 = Student_Var ();
    StudentVar* st2 = Student_Var ();
    EC_Print_Error ("Create new ec var", "OK");

    st1->no = 1;
    st1->name = "Malith";
    EC_Print_Error ("Assign new ec var", "OK");

    *st2 = *st1;
    assert (st2->no == 1);
    assert (strcmp(st2->name, "Malith") == 0);
    EC_Print_Error ("Var copied: ", "OK");

    st1->no = 2;
    st2->name = "Geethike";

    assert (st2->no == 1);
    assert (strcmp(st1->name, "Geethike") != 0);

    EC_Print_Error ("Changing one var should not affect other", "OK");

    StudentVar st_on_stack;
    st_on_stack.no = 3;
    st_on_stack.name = "Perera";

    EC_Print_Error ("Create and assign ec var on stack", "OK");

    *st2 = st_on_stack;
    assert (st2->no == 3);
    assert (strcmp(st2->name, "Perera") == 0);

    EC_Print_Error ("Copy var on stack: ", "OK");

    st_on_stack = *st1;
    assert (st_on_stack.no == 2);
    assert (strcmp(st_on_stack.name, "Malith") == 0);

    EC_Print_Error ("Copy var to stack: ", "OK");

    EC_Print_Error ("Test_Var_Copy: ", "END");
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


void
Run_Var_Test ()
{
    printf ("------------------\n");
    printf ("Test: ec_var.h\n");
    printf ("==================\n");

    Test_New_Var ();
    printf ("\n");

    Test_Var_Copy ();
    printf ("\n");

    Test_New_Var_Memory_Free ();
    printf ("\n");

    EC_Print_Error ("Test: ec_var.h", "PASS");
    printf ("\n");
}
