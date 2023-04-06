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

    Student_Push (stk, st0);
    Student_Push (stk, st1);
    Student_Push (stk, st2);
    Student_Push (stk, st3);
    Student_Push (stk, st4);

    i = 4;
    for_stack(stk)
    {
        assert (Student_Compare(stk->var, &students[i])); 
        i--;
    }
    assert(i == -1);
    EC_Test_Print_Msg ("stk pushed with st4 ... st0", "OK", __LINE__);

    StudentStackVar *stkv;
    
    stkv = Student_Pop(stk);
    assert (Student_Compare(stkv->var, st4)); 
    EC_Test_Print_Msg ("pop st4 in stk", "OK", __LINE__);

    stkv = Student_Pop(stk);
    assert (Student_Compare(stkv->var, st3)); 
    EC_Test_Print_Msg ("pop st3 in stk", "OK", __LINE__);

    stkv = Student_Pop(stk);
    assert (Student_Compare(stkv->var, st2)); 
    EC_Test_Print_Msg ("pop st2 in stk", "OK", __LINE__);

    stkv = Student_Pop(stk);
    assert (Student_Compare(stkv->var, st1)); 
    EC_Test_Print_Msg ("pop st1 in stk", "OK", __LINE__);

    stkv = Student_Pop(stk);
    assert (Student_Compare(stkv->var, st0)); 
    assert (stk->first == NULL);
    EC_Test_Print_Msg ("pop st0 in stk", "OK", __LINE__);
}


void
Run_Stack_Test ()
{
    EC_Test_Print_Header ("Test: ec_stack.h");
    printf ("\n");

    Test_New_Stack ();
    printf ("\n");

    Test_Push_Stack ();
    printf ("\n");

    Test_Pop_Stack ();
    printf ("\n");
    
    EC_Test_Print_Msg ("Test: ec_stack.h", "PASS", __LINE__);
}
