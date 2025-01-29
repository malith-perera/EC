#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "ec_code_test.h"


void
Test_Lines_Of_Code ()
{
    EC_Lines_Of_Code ("../testdata/ec_file_test_file1.c");
}


void
Run_Code_Test ()
{
    printf ("------------------\n");
    printf ("Test: ec_code     \n");
    printf ("==================\n");

    Test_Lines_Of_Code ();
    printf ("\n");

    EC_Print_Error ("Test: ec_code", "PASS");
    printf ("\n");
}
