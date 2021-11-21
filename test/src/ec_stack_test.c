#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "ec_stack_test.h"


void
Test_New_Stack ()
{
    EC_Print_Error ("Test_New_Stack: ", "BEGIN");

    StudentStack *st_stk = Student_Stack ();
    EC_Print_Error ("Create new stack", "OK");

    StudentStackVar *st1 = Student_Stack_Var ();

    StudentStackVar *st2 = Student_Stack_Var ();

    EC_Print_Error ("Create stack variables", "OK");

    st1->no = 1;
    st1->name = "Malith";

    st2->no = 2;
    st2->name = "Geethike";

    EC_Print_Error ("Assign stack variable attributes", "OK");

    st_stk->top = st1;
    st1->next = NULL;

    st2->next = st_stk->top;
    st_stk->top = st2;

    assert (st_stk->top->no == 2);
    assert (!strcmp (st_stk->top->name, "Geethike"));

    assert (st_stk->top->next->no == 1);
    assert (!strcmp (st_stk->top->next->name, "Malith"));

    EC_Print_Error ("Create new stack variables", "OK");

    EC_Print_Error ("Test_New_Stack: ", "END");
}


void
Test_Push_Stack ()
{
    EC_Print_Error ("Test_Push_Stack: ", "BEGIN");

    StudentStack *st_stk = Student_Stack ();
    EC_Print_Error ("Create new stack", "OK");

    StudentStackVar *st1 = Student_Stack_Var ();

    StudentStackVar *st2 = Student_Stack_Var ();

    EC_Print_Error ("Create stack variables", "OK");

    st1->no = 1;
    st1->name = "Malith";

    st2->no = 2;
    st2->name = "Geethike";

    EC_Print_Error ("Assign stack variable attributes", "OK");

    Student_Push (st_stk, st1);
    Student_Push (st_stk, st2);

    assert (st_stk->top->no == 2);
    assert (!strcmp (st_stk->top->name, "Geethike"));

    assert (st_stk->top->next->no == 1);
    assert (!strcmp (st_stk->top->next->name, "Malith"));

    EC_Print_Error ("Push stack variables to stack", "OK");

    EC_Print_Error ("Test_Push_Stack: ", "END");
}


void
Test_Pop_Stack ()
{
    EC_Print_Error ("Test_Pop_Stack: ", "BEGIN");

    StudentStack* st_stk = Student_Stack ();
    EC_Print_Error ("Create new stack", "OK");

    StudentStackVar* st1 = Student_Stack_Var ();
    StudentStackVar* st2 = Student_Stack_Var ();

    EC_Print_Error ("Create stack variables", "OK");

    st1->no = 1;
    st1->name = "Malith";

    st2->no = 2;
    st2->name = "Geethike";

    EC_Print_Error ("Assign stack variable attributes", "OK");

    Student_Push (st_stk, st1);
    Student_Push (st_stk, st2);

    StudentStackVar* pop_st2 = Student_Pop(st_stk);

    if (pop_st2)
    {
        assert (pop_st2->no == 2);
        assert (!strcmp (pop_st2->name, "Geethike"));
    }

    EC_Print_Error ("Pop fist stack variable", "OK");

    StudentStackVar* pop_st1 = Student_Pop(st_stk);

    if (pop_st1)
    {
        assert (pop_st1->no == 1);
        assert (!strcmp (pop_st1->name, "Malith"));
    }

    EC_Print_Error ("Pop second stack variable", "OK");

    StudentStackVar* pop_null = Student_Pop(st_stk);

    if (!pop_null)
    {
        EC_Print_Error ("Pop empty stack", "OK");
    }

    EC_Print_Error ("Pop stack variables from stack", "OK");

    EC_Print_Error ("Test_Pop_Stack: ", "END");

}


void
Run_Stack_Test ()
{
    printf ("---------------\n");
    printf ("Test: ec_stack.h\n");
    printf ("===============\n");

    Test_New_Stack ();
    printf ("\n");

    Test_Push_Stack ();
    printf ("\n");

    Test_Pop_Stack ();
    printf ("\n");

    EC_Print_Error ("Test: ec_stack.h", "PASS");
    printf ("\n");

}
