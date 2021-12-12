#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "ec_var_ref_test.h"
#include "ec_var.h"

void
Test_New_Var_Ref ()
{
/*    EC_Print_Error ("Test_New_Var_Ref: ", "BEGIN");*/

    /*Student *st = Student_Var ();*/
    /*EC_Print_Error ("Create new ec var", "OK");*/

    /*st->no = 1;*/
    /*st->name = "Malith";*/
    /*EC_Print_Error ("Assign ec var attributes", "OK");*/

    /*StudentRefVar *st_rv = Student_Var_Ref ();*/
    /*EC_Print_Error ("Create new ec ref var", "OK");*/

    /*st_rv->ref = st;*/
    /*EC_Print_Error ("Assign ec var to ec ref var", "OK");*/

    /*assert (st_rv->ref->no == 1);*/
    /*assert (strcmp(st_rv->ref->name, "Malith") == 0);*/
    /*EC_Print_Error ("Access ec ref var", "OK");*/

    /*st->no = 2;*/
    /*st->name = "Geethike";*/

    /*assert (st_rv->ref->no == 2);*/
    /*assert (strcmp(st_rv->ref->name, "Geethike") == 0);*/
    /*EC_Print_Error ("Change var data affect ref var", "OK");*/

    /*st_rv->ref->no = 3;*/
    /*st_rv->ref->name = "Perera";*/
    /*EC_Print_Error ("Assign ref var values", "OK");*/

    /*assert (st->no == 3);*/
    /*assert (strcmp(st->name, "Perera") == 0);*/
    /*EC_Print_Error ("Change ref var affect ref data", "OK");*/

    /*EC_Print_Error ("Test_New_Var_Ref:", "END");*/
}


void
Test_New_Var_Ref_Memory_Free ()
{
    /*EC_Print_Error ("Test_New_Var_Ref_Memory_Free: ", "BEGIN");*/

    /*if (EC_MEMORY)*/
    /*{*/
        /*EC_Clean ();*/
        /*EC_Print_Error ("Call EC_Clean ()", "OK");*/
        /*st = NULL;*/
    /*}*/

    /*if (st == NULL)*/
    /*{*/
        /*EC_Print_Error ("EC_Clean free", "OK");*/
        /*EC_Print_Error ("Test_New_Var_Ref_Memory_Free:", "END");*/
    /*}*/
    /*else*/
    /*{*/
        /*EC_Print_Error ("Test_New_Var_Ref_Memory_Free:", "Fail");*/
        /*assert (st == NULL);*/
        /*exit (EXIT_FAILURE);*/
    /*}*/

    /*EC_Print_Error ("Test_New_Var_Ref_Memory_Free:", "END");*/
}

/* This function do not affect copied vars each other */
void
Test_Var_Ref_Copy ()
{
/*    EC_Print_Error ("Test_Var_Ref_Copy: ", "BEGIN");*/

    /*Student* st = Student_Var ();*/
    /*EC_Print_Error ("Create new ec var", "OK");*/

    /*st->no = 1;*/
    /*st->name = "Malith";*/

    /*StudentRefVar *st_rv = Student_Var_Ref ();*/
    /*EC_Print_Error ("Create new ec ref var", "OK");*/

    /*st_rv->ref = st;*/
    /*EC_Print_Error ("Assign ec var to ec ref var", "OK");*/

    /*assert (st_rv->ref->no == 1);*/
    /*assert (strcmp(st_rv->ref->name, "Malith") == 0);*/
    /*EC_Print_Error ("Access with ref var", "OK");*/

    /*StudentRefVar* st_rvc = Student_Var_Ref_Copy (st_rv);*/
    /*EC_Print_Error ("Var_Ref_Copy function: ", "OK");*/

    /*assert (st_rvc->ref->no == 1);*/
    /*assert (strcmp(st_rvc->ref->name, "Malith") == 0);*/
    /*EC_Print_Error ("Var_Ref copied: ", "OK");*/

    /*st->no = 2;*/
    /*st->name = "Geethike";*/
    /*assert (st_rvc->ref->no == 2);*/
    /*assert (strcmp(st_rvc->ref->name, "Geethike") == 0);*/
    /*EC_Print_Error ("Change ec var should affect ref var copy: ", "OK");*/

    /*st_rvc->ref->no = 3;*/
    /*st_rvc->ref->name = "Perera";*/
    /*assert (st->no == 3);*/
    /*assert (strcmp(st->name, "Perera") == 0);*/
    /*EC_Print_Error ("Change ref var copy should affect ec var: ", "OK");*/

    /*assert (st_rv->ref->no == 3);*/
    /*assert (strcmp(st_rv->ref->name, "Perera") == 0);*/
    /*EC_Print_Error ("Change ref var copy should affect ref var: ", "OK");*/

    /*EC_Print_Error ("Test_Copy_Var_Ref: ", "END");*/
}


void
Run_Var_Ref_Test ()
{
    printf ("------------------\n");
    printf ("Test: ec_ref_var\n");
    printf ("==================\n");

    Test_New_Var_Ref ();
    printf ("\n");

    Test_New_Var_Ref_Memory_Free ();
    printf ("\n");

    Test_Var_Ref_Copy ();
    printf ("\n");

    EC_Print_Error ("Test: ec_ref_var", "PASS");
    printf ("\n");
}
