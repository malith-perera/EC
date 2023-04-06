#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "ec_stack_test.h"


void
Test_New_Stack ()
{
    EC_Test_Print_Title (__func__);

    EC_Test_Print_Subtitle ("Create student stack");

    StudentStack *stk = Student_Stack ();
    EC_Error_Print_Msg ("Create new stack", "OK");

    assert (stk != NULL);
    EC_Test_Print_Msg ("stack created", "OK", __LINE__);
    assert (stk->first == NULL);
    EC_Test_Print_Msg ("Test: stl->first == NULL", "OK", __LINE__);
    assert (stk->var == NULL);
    EC_Test_Print_Msg ("Test: stl->var == NULL", "OK", __LINE__);
}


void
Test_Push_Stack ()
{
    EC_Test_Print_Title (__func__);
    int i = 0;

    EC_Test_Print_Subtitle ("Create student stack and push");

    StudentStack *stk = Student_Stack ();
    EC_Test_Print_Msg ("Create new stack", "OK", __LINE__);

    Student_Push (stk, st0);
    assert (Student_Compare(stk->first->var, st0)); 
    assert (stk->first->next == NULL); 
    EC_Test_Print_Msg ("st0 is in stk", "OK", __LINE__);

    Student_Push (stk, st1);
    assert (Student_Compare(stk->first->var, st1)); 
    assert (Student_Compare(stk->first->next->var, st0)); 
    assert (stk->first->next->next == NULL); 
    EC_Test_Print_Msg ("st1 ... st0 is in stk", "OK", __LINE__);

    Student_Push (stk, st2);
    assert (Student_Compare(stk->first->var, st2)); 
    assert (Student_Compare(stk->first->next->var, st1)); 
    assert (Student_Compare(stk->first->next->next->var, st0)); 
    assert (stk->first->next->next->next == NULL); 
    EC_Test_Print_Msg ("st2 ... st0 is in stk", "OK", __LINE__);

    i = 2;
    for_stack(stk)
    {
        assert (Student_Compare(stk->var, &students[i])); 
        i--;
    }
    assert(i == -1);
    EC_Test_Print_Msg ("for_stack check st2 ... st0 is in stk", "OK", __LINE__);
}


void
Test_Pop_Stack ()
{
    EC_Test_Print_Title (__func__);
    int i = 0;

    StudentStack* stk = Student_Stack ();
    EC_Error_Print_Msg ("Create new stack", "OK");

    StudentStackVar* st1 = Student_Stack_Var ();
    StudentStackVar* st2 = Student_Stack_Var ();

    EC_Error_Print_Msg ("Create stack variables", "OK");

    st1->no = 1;
    st1->name = "Malith";

    st2->no = 2;
    st2->name = "Geethike";

    EC_Error_Print_Msg ("Assign stack variable attributes", "OK");

    Student_Push (stk, st1);
    Student_Push (stk, st2);

    StudentStackVar* pop_st2 = Student_Pop(stk);

    if (pop_st2)
    {
        assert (pop_st2->no == 2);
        assert (!strcmp (pop_st2->name, "Geethike"));
    }

    EC_Error_Print_Msg ("Pop fist stack variable", "OK");

    StudentStackVar* pop_st1 = Student_Pop(stk);

    if (pop_st1)
    {
        assert (pop_st1->no == 1);
        assert (!strcmp (pop_st1->name, "Malith"));
    }

    EC_Error_Print_Msg ("Pop second stack variable", "OK");

    StudentStackVar* pop_null = Student_Pop(stk);

    if (!pop_null)
    {
        EC_Error_Print_Msg ("Pop empty stack", "OK");
    }

    EC_Error_Print_Msg ("Pop stack variables from stack", "OK");
}



#if 0

void
Test_Stack_Copy ()
{
    EC_Error_Print_Msg ("Test_Stack_Copy: ", "BEGIN");

    StudentStack *stq1 = Student_Stack ();

    StudentStackVar *st1 = Student_Stack_Var ();
    st1->no = 1;
    st1->name = "Malith";
    Student_Push (stq1, st1);

    StudentStackVar *st2 = Student_Stack_Var ();
    st2->no = 2;
    st2->name = "Geethike";
    Student_Push (stq1, st2);

    StudentStack* stq2 = Student_Stack_Copy (stq1);

    assert (stq2->first->no = 1);
    assert (strcmp(stq2->first->name ,"Malith") == 0 );

    assert (stq2->first->next->no == 2);
    assert (strcmp(stq2->first->next->name ,"Geethike") == 0 );

    EC_Error_Print_Msg ("Stack Copy Variables", "OK");

    st1->no = 3;
    st1->name = "Malshi";
    assert (stq2->first->no != 3);
    assert (strcmp(stq2->first->name ,"Malshi") != 0 );

    st2->no = 4;
    st2->name = "Prisenthi";
    assert (stq1->first->next->no != 4);
    assert (strcmp(stq1->first->next->name ,"Prisenthi") != 0 );

    EC_Error_Print_Msg ("Copied list do not affect other list", "OK");

    EC_Error_Print_Msg ("Test_Stack_Copy: ", "END");
}

#endif

void
Run_Stack_Test ()
{
    EC_Test_Print_Header ("Test: ec_stack.h");
    printf ("\n");

    Test_New_Stack ();
    printf ("\n");

    Test_Push_Stack ();
    printf ("\n");

#if 0
    Test_Pop_Stack ();
    printf ("\n");

    Test_Stack_Copy ();
    printf ("\n");

    EC_Error_Print_Msg ("Test: ec_stack.h", "PASS");
    printf ("\n");
#endif
}
