#include <stdio.h>
#include <string.h>

#include "ec_main_test.h"

#include "ec_var_test.h"
#include "ec_array_test.h"
#include "ec_list_test.h"
#include "ec_queue_test.h"
#include "ec_stack_test.h"
#include "ec_ecs_test.h"
#include "ec_loc_test.h"

#include "ec_var_ref_test.h"
#include "ec_array_ref_test.h"
#include "ec_list_ref_test.h"
#include "ec_queue_ref_test.h"
#include "ec_stack_ref_test.h"


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
        printf ("Test: All           0\n");
        printf ("Test: Var           1\n");
        printf ("Test: Array         2\n");
        printf ("Test: List          3\n");
        printf ("Test: Queue         4\n");
        printf ("Test: Stack         5\n");
        printf ("Test: Ref Var       6\n");
        printf ("Test: Ref Array     7\n");
        printf ("Test: Ref List      8\n");
        printf ("Test: Ref Queue     9\n");
        printf ("Test: Ref Stack     10\n");
        printf ("Test: ECS           11\n");
        printf ("Test: Lines Of Code 12\n");
        printf ("Test: Exit          -1\n");
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
        Run_Var_Test ();
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
        Run_Queue_Test ();
    }

    if (no == 5 || no == 0)
    {
        Run_Stack_Test ();
    }

    if (no == 6 || no == 0)
    {
        Run_Var_Ref_Test ();
    }

    if (no == 7 || no == 0)
    {
        Run_Ref_Array_Test ();
    }

    if (no == 8 || no == 0)
    {
        Run_Ref_List_Test ();
    }

    if (no == 9 || no == 0)
    {
        Run_Ref_Queue_Test ();
    }

    if (no == 10 || no == 0)
    {
        Run_Ref_Stack_Test ();
    }

    if (no == 11 || no == 0)
    {
        Run_ECS_Test ();
    }

    if (no == 12 || no == 0)
    {
        Run_Loc_Test ();
    }

    EC_Error_Print_Msg ("EC_Clean", "BEGIN");
    EC_Clean ();
    EC_Test_Print_Msg ("EC_Clean", "OK");
    EC_Error_Print_Msg ("EC_Clean", "END");

    printf ("\n");
    printf ("Test: EClib Successful\n\n");

    return 0;
}
