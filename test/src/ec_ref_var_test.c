#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "ec_ref_var_test.h"
#include "ec_var.h"

void
Test_New_Ref_Var ()
{
    EC_Print_Error ("Test_New_Ref_Var: ", "BEGIN");

    Student *st = Student_Var ();
    EC_Print_Error ("Create new ec var", "OK");

    st->no = 1;
    st->name = "Malith";
    EC_Print_Error ("Assign ec var attributes", "OK");

    StudentRefVar *st_rv = Student_Ref_Var ();
    EC_Print_Error ("Create new ec ref var", "OK");

    st_rv->ref = st;
    EC_Print_Error ("Assign ec var to ec ref var", "OK");

    assert (st_rv->ref->no == 1);
    assert (strcmp(st_rv->ref->name, "Malith") == 0);
    EC_Print_Error ("Access ec ref var", "OK");

    st->no = 2;
    st->name = "Geethike";

    assert (st_rv->ref->no == 2);
    assert (strcmp(st_rv->ref->name, "Geethike") == 0);
    EC_Print_Error ("Change var data affect ref var", "OK");

    st_rv->ref->no = 3;
    st_rv->ref->name = "Perera";
    EC_Print_Error ("Assign ref var values", "OK");

    assert (st->no == 3);
    assert (strcmp(st->name, "Perera") == 0);
    EC_Print_Error ("Change ref var affect ref data", "OK");

    EC_Print_Error ("Test_New_Ref_Var:", "END");
}


void
Test_New_Ref_Var_Memory_Free ()
{
    /*EC_Print_Error ("Test_New_Ref_Var_Memory_Free: ", "BEGIN");*/

    /*if (EC_MEMORY)*/
    /*{*/
        /*EC_Clean ();*/
        /*EC_Print_Error ("Call EC_Clean ()", "OK");*/
        /*st = NULL;*/
    /*}*/

    /*if (st == NULL)*/
    /*{*/
        /*EC_Print_Error ("EC_Clean free", "OK");*/
        /*EC_Print_Error ("Test_New_Ref_Var_Memory_Free:", "END");*/
    /*}*/
    /*else*/
    /*{*/
        /*EC_Print_Error ("Test_New_Ref_Var_Memory_Free:", "Fail");*/
        /*assert (st == NULL);*/
        /*exit (EXIT_FAILURE);*/
    /*}*/

    /*EC_Print_Error ("Test_New_Ref_Var_Memory_Free:", "END");*/
}

/* This function do not affect copied vars each other */
void
Test_Ref_Var_Copy ()
{
/*    EC_Print_Error ("Test_Copy_Ref_Var: ", "BEGIN");*/

    /*Student* st1 = Student_Var ();*/
    /*EC_Print_Error ("Create new ec var", "OK");*/

    /*st1->no = 1;*/
    /*st1->name = "Malith";*/

    /*Student *st2 = Student_Ref_Var_Copy (st1);*/

    /*assert (st2->no == 1);*/
    /*assert (strcmp(st2->name, "Malith") == 0);*/

    /*EC_Print_Error ("Ref_Var copied: ", "OK");*/

    /*st1->no = 2;*/
    /*st2->name = "Geethike";*/

    /*assert (st2->no == 1);*/
    /*assert (strcmp(st1->name, "Geethike") != 0);*/

    /*EC_Print_Error ("Changing one array should not affect other", "OK");*/

    /*EC_Print_Error ("Test_Copy_Ref_Var: ", "END");*/
}


void
Run_Ref_Var_Test ()
{
    printf ("------------------\n");
    printf ("Test: ec_ref_var\n");
    printf ("==================\n");

    Test_New_Ref_Var ();
    printf ("\n");

    Test_New_Ref_Var_Memory_Free ();
    printf ("\n");

    Test_Ref_Var_Copy ();
    printf ("\n");

    EC_Print_Error ("Test: ec_ref_var", "PASS");
    printf ("\n");
}
