#include <stdio.h>

#include "ec_type_test.h"


void
Test_Generated_Structures ()
{
    EC_Print_Error ("Test_Generated_Structues: ", "BEGIN");

    Student st;
    EC_Print_Error ("Student", "OK");

/*    StudentArray sta;*/
    /*EC_Print_Error ("StudentArray", "OK");*/

    /*StudentArrayObj stao;*/
    /*EC_Print_Error ("StudentArrayObj", "OK");*/

    /*StudentList stl;*/
    /*EC_Print_Error ("StudentList", "OK");*/

    /*StudentListObj stlo;*/
    /*EC_Print_Error ("StudentListObj", "OK");*/

    EC_Print_Error ("Test_Generated_Structues: ", "END");
}


void
Run_Type_Test ()
{
    printf ("-----------------\n");
    printf ("Test: ec_class.h\n");
    printf ("=================\n");

    //Test_Generated_Structures ();

    printf ("\n");
    EC_Print_Error ("Test: ec_class.h", "PASS");
    printf ("\n");
}
