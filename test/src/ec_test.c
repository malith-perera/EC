#include <stdio.h>
#include <string.h>

#include "ec_test.h"

int
main (int argc, char *argv[])
{
    int no;

    printf ("\n");
    printf ("------------\n");
    printf ("Test: EClib\n");
    printf ("============\n");
    printf ("\n");

    if (argc >= 2)
    {
        no = atoi (argv[1]);
    }
    else
    {
        printf ("Select Test\n");
        printf ("-----------\n");
        printf ("Test: All      0\n");
        printf ("Test: Variable 1\n");
        printf ("Test: Array    2\n");
        printf ("Test: List     3\n");
        printf ("Test: Queue    4\n");
        printf ("Test: Exit    -1\n");
        printf ("\n");

        printf ("Test : ");
        scanf ("%d", &no);
        printf ("\n");
    }

    if (no == -1)
    {
        return 0;
    }

    if (no == 0)
    {
        printf ("Run All Tests\n");
    }

    if (no == 1 || no == 0)
    {
        Run_Variable_Test ();
    }

    if (no == 2 || no == 0)
    {
        Run_Array_Test ();
    }

    if (no == 3 || no == 0)
    {
        Run_List_Test ();
    }

    if (no == 4 || no == 0)
    {
        /*Run_Queue_Test ();*/
    }


    if (no == 5 || no == 0)
    {
    }


    EC_Clean ();

    printf ("Test: EClib    Successful\n");

    return 0;
}
