#include <stdio.h>
#include <string.h>

#include "ec_main_test.h"

#include "ec_var_test.h"
#include "ec_array_test.h"
#include "ec_list_test.h"
#include "ec_queue_test.h"
#include "ec_stack_test.h"
#include "ec_loc_test.h"
#include "ec_EC_test.h"

#include "ec_ecs_test.h"


void
Test_Variables()
{
    EC_Test_Print_Title(__func__, __FILE__);

    EC_Test_Print_Subtitle("Create student variables to help tests");

    st0 = Student_Var();
    st1 = Student_Var();
    st2 = Student_Var();
    st3 = Student_Var();
    st4 = Student_Var();
    st5 = Student_Var();
    st6 = Student_Var();
    EC_TEST_PRINT_MSG("Create: Create Student st0 ... st6", "OK")

    *st0 = students[0];
    *st1 = students[1];
    *st2 = students[2];
    *st3 = students[3];
    *st4 = students[4];
    *st5 = students[5];
    *st6 = students[6];
    EC_Test_Print_Msg("Initialize: Assign values to Student st0 ... st6", "OK", __LINE__);
}


int
main(int argc, char *argv[])
{
    int no;

    EC_Test_Print_Header("Test: EClib");
    printf("\n");

    // init variables
    Test_Variables();
    printf("\n");

    if(argc >= 2)
    {
        no = atoi(argv[1]);
    }
    else
    {
        printf("Select Test\n");
        printf("-----------\n");
        printf("Test: All           0\n");
        printf("Test: Var           1\n");
        printf("Test: Array         2\n");
        printf("Test: List          3\n");
        printf("Test: Queue         4\n");
        printf("Test: Stack         5\n");
        printf("Test: ECS           6\n");
        printf("Test: Lines Of Code 7\n");
        printf("Test: Exit          -1\n");
        printf("\n");

        printf("Test : ");
        scanf("%d", &no);
        printf("\n");
    }

    if(no == -1)
    {
        return 0;
    }

    if(no == 0)
    {
        printf("Run All Tests\n");
        Run_EC_Test();
    }

    if(no == 1 || no == 0)
    {
        Run_Var_Test();
    }

    if(no == 2 || no == 0)
    {
        Run_Array_Test();
    }

    if(no == 3 || no == 0)
    {
        Run_List_Test();
    }

    if(no == 4 || no == 0)
    {
        Run_Stack_Test();
    }

    if(no == 5 || no == 0)
    {
        Run_Queue_Test();
    }

    if(no == 6 || no == 0)
    {
        Run_ECS_Test();
    }
    
    if(no == 7 || no == 0)
    {
        Run_Loc_Test();
    }

    EC_Error_Print_Msg("EC_Clean", "BEGIN");
    //EC_Clean();
    Clean();
    EC_Test_Print_Msg("EC_Clean", "OK", __LINE__);
    EC_Error_Print_Msg("EC_Clean", "END");

    printf("Test: EClib Successful\n\n");

    return 0;
}
