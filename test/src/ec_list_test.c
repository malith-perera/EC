#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "ec_list_test.h"

Student students[7] = {{0, "Malith"}, {1, "Geethike"}, {2, "Perera"}, {3, "Rohasha"}, {4, "Malshi"}, {5, "Prisenthi"}, {6, "Magret"}};

Student *st0;
Student *st1;
Student *st2;
Student *st3;
Student *st4;
Student *st5;
Student *st6;


void
Test_List_Helpers ()
{
    EC_Test_Print_Title (__func__);

    EC_Test_Print_Subtitle ("Test: New list with zero variables");

    st0 = Student_Var();
    st1 = Student_Var();
    st2 = Student_Var();
    st3 = Student_Var();
    st4 = Student_Var();
    st5 = Student_Var();
    st6 = Student_Var();
    EC_TEST_PRINT_MSG ("Create: Create Student st0 ... st6", "OK")

    *st0 = students[0];
    *st1 = students[1];
    *st2 = students[2];
    *st3 = students[3];
    *st4 = students[4];
    *st5 = students[5];
    *st6 = students[6];
    EC_Test_Print_Msg ("Initialize: Assign values to Student st0 ... st6", "OK", __LINE__);
}


void
Test_New_List ()
{
    EC_Test_Print_Title (__func__);

    /* Test list with zero list variables */
    EC_Test_Print_Subtitle ("Test: New list with zero variables");

    StudentList *stl = Student_List ();
    EC_Test_Print_Msg ("Create: New list", "OK", __LINE__);

    assert (stl != NULL);
    EC_Test_Print_Msg ("Test: stl != NULL", "OK", __LINE__);
    assert (stl->first == NULL);
    EC_Test_Print_Msg ("Test: stl->first == NULL", "OK", __LINE__);
    assert (stl->last == NULL);
    EC_Test_Print_Msg ("Test: stl->last == NULL", "OK", __LINE__);
    assert (stl->var == NULL);
    EC_Test_Print_Msg ("Test: stl->var == NULL", "OK", __LINE__);
}


void
Test_List_Append()
{
    EC_Test_Print_Title (__func__);

    StudentList *stl = Student_List ();
    EC_Test_Print_Msg ("Create: New list", "OK", __LINE__);

    Student_Append (stl, st0);
    Student_Append (stl, st1);
    Student_Append (stl, st2);
    EC_Test_Print_Msg ("Append: st0, st1 and st3 to stl", "OK", __LINE__);

    assert (stl->first->var->no == students[0].no);
    assert (!strcmp (stl->first->var->name, "Malith"));
    EC_Test_Print_Msg ("Test: st0 in stl as list first", "OK", __LINE__);

    assert (stl->first->next->var->no == students[1].no);
    assert (!strcmp (stl->first->next->var->name, "Geethike"));
    EC_Test_Print_Msg ("Test: st1 in stl as list second", "OK", __LINE__);

    assert (stl->first->next->next->var->no == students[2].no);
    assert (!strcmp (stl->first->next->next->var->name, "Perera"));
    EC_Test_Print_Msg ("Test: st2 in stl as list third", "OK", __LINE__);

    assert (stl->first->next->next->next == NULL);
    EC_Test_Print_Msg ("Test: last StudentVar next should be NULL", "OK", __LINE__);

    assert (stl->last->next == NULL);
    EC_Test_Print_Msg ("Test: stl->last->next should be NULL", "OK", __LINE__);
}


void
Test_For_List()
{
    EC_Test_Print_Title (__func__);

    StudentList *stl = Student_List ();
    EC_Test_Print_Msg ("Create: New list", "OK", __LINE__);

    Student_Append (stl, st0);
    Student_Append (stl, st1);
    Student_Append (stl, st2);
    EC_Test_Print_Msg ("Append: st1, st2 and st3 to stl", "OK", __LINE__);

    int i = 0;
    char msg[32];

    for_list(stl)
    {
        strcpy(msg, "");
        assert (Student_Compare(stl->var, &students[i])); 
        sprintf(msg, "Test: Appended st%d in stl", i);
        EC_Test_Print_Msg (msg, "OK", __LINE__);
        i++;
    }
}


void
Test_Insert_Before_List ()
{
    EC_Test_Print_Title (__func__);

    int i = 0;

    StudentList *stl = Student_List ();
    EC_Test_Print_Msg ("Create: New list", "OK", __LINE__);

    // Insert_Before a non existing variable in an empty list
    EC_Test_Print_Subtitle ("Insert_Before empty list");

    Student_Insert_Before (stl, st2, st1); // st1 should not inserted because st2 is not in stl list

    if (stl->first == NULL)
        EC_Test_Print_Msg ("Call: Insert_Before none existing variable in an empty list", "OK", __LINE__);
    else
        EC_Test_Print_Msg ("Call: Insert_Before none existing variable in an empty list", "Failed", __LINE__);


    // Insert_Before NULL mean insert as the first variable
    EC_Test_Print_Subtitle ("Insert_Before Where ref arg NULL");

    Student_Insert_Before (stl, NULL, st4);
    EC_Test_Print_Msg ("Call: Student_Insert_Before where ref arg NULL", "OK", __LINE__);
    assert (Student_Compare (stl->first->var, &students[4])); 
    EC_Test_Print_Msg ("Test: Insert st4 into stl", "OK", __LINE__);

    Student_Insert_Before (stl, NULL, st2);
    EC_Test_Print_Msg ("Call: Student_Insert_Before where ref arg NULL", "OK", __LINE__);
    assert (Student_Compare (stl->first->var, &students[2])); 
    assert (Student_Compare (stl->first->next->var, &students[4])); 
    EC_Test_Print_Msg ("Test: Insert st2 into stl", "OK", __LINE__);


    // Insert_Before a variable in a list
    EC_Test_Print_Subtitle ("Insert_Before a variable in stl");

    Student_Insert_Before (stl, st4, st3);
    EC_Test_Print_Msg ("Call: Student_Insert_Before out of for_list", "OK", __LINE__);

    i = 2;
    for_list(stl)
    {
        assert (Student_Compare (stl->var, &students[i])); 
        i++;
    }

    EC_Test_Print_Msg ("Test: st3 inserted before st4", "OK", __LINE__);


    // Insert_Before in for_list
    EC_Test_Print_Subtitle ("Insert_Before in a for_list");

    for_list(stl)
    {
        if (stl->var == st2)
        {
            Student_Insert_Before (stl, st2, st1);
            EC_Test_Print_Msg ("Call: Insert_Before in for_list", "OK", __LINE__);
            break;
        }
        i++;
    }

    i = 1;
    for_list(stl)
    {
        assert (Student_Compare (stl->var, &students[i])); 
        i++;
    }

    EC_Test_Print_Msg ("Test: st1 inserted before st2 in for_list ", "OK", __LINE__);


    // Insert_Before at end of the list
    EC_Test_Print_Subtitle ("Insert_Before last variable");

    Student_Append (stl, st6);
    EC_Test_Print_Msg ("Append: st6 as list last variable", "OK", __LINE__);

    Student_Insert_Before (stl, stl->last->var, st5);
    EC_Test_Print_Msg ("Insert: st5 before st6", "OK", __LINE__);

    i = 1;
    for_list(stl)
    {
        assert (Student_Compare (stl->var, &students[i])); 
        i++;
    }

    EC_Test_Print_Msg ("Test: st5 inserted before list last variable", "OK", __LINE__);
}


void
Test_Insert_After_List ()
{
    EC_Test_Print_Title (__func__);

    int i = 0;

    StudentList *stl = Student_List ();
    EC_Test_Print_Msg ("Create: New list", "OK", __LINE__);

    Student_Insert_After (stl, NULL, st3);
    EC_Test_Print_Msg ("Call: Student_Insert_After arg ref = NULL in empty list", "OK", __LINE__);

    assert (Student_Compare (stl->first->var, &students[3])); 
    EC_Test_Print_Msg ("Test: Insert st3 into stl while arg ref = NULL in an empty list", "OK", __LINE__);

    Student_Insert_After (stl, NULL, st1);
    EC_Test_Print_Msg ("Call: Student_Insert_After arg ref = NULL in a none empty list", "OK", __LINE__);

    assert (Student_Compare (stl->first->var, st1)); 
    EC_Test_Print_Msg ("Test: ref = stl->first->var in a none empty list", "OK", __LINE__);
    assert (Student_Compare (stl->first->next->var, st3)); 
    EC_Test_Print_Msg ("Test: ref = stl->first->next->var in a none empty list", "OK", __LINE__);
    assert (Student_Compare (stl->last->var, st3)); 
    EC_Test_Print_Msg ("Test: ref = stl->last->var in a none empty list", "OK", __LINE__);
    assert (stl->last->next == NULL); 
    EC_Test_Print_Msg ("Test: stl->last->next should be NULL", "OK", __LINE__);
    assert (Student_Compare (stl->last->previous->var, st1)); 
    EC_Test_Print_Msg ("Test: stl->last->previous->var should equel to st1", "OK", __LINE__);

    Student_Insert_After (stl, stl->first, st2);
    EC_Test_Print_Msg ("Call: Student_Insert_After arg ref = stl->first in a none empty list", "OK", __LINE__);

    i = 1;
    for_list(stl)
    {
        assert (Student_Compare (stl->var, &students[i])); 
        i++;
    }
    EC_Test_Print_Msg ("Test: Insert st3 into stl while ref = stl->first in an empty list", "OK", __LINE__);

    Student_Insert_After (stl, stl->last, st6);
    EC_Test_Print_Msg ("Call: Student_Insert_After insert st6 as the last variable", "OK", __LINE__);

    i = 1;
    for_list(stl)
    {
        if (i == 4 || i == 5) {i++; continue;} // st4, st5 not still not exist
        assert (Student_Compare (stl->var, &students[i])); 
        i++;
    }
    EC_Test_Print_Msg ("Test: Insert st6 into stl", "OK", __LINE__);

    assert (stl->last->var == st6); 
    EC_Test_Print_Msg ("Test: stl->last->var should be st6", "OK", __LINE__);
    assert (stl->last->next == NULL); 
    EC_Test_Print_Msg ("Test: stl->last->next should be NULL", "OK", __LINE__);

    Student_Insert_After (stl, stl->last->previous, st4);
    EC_Test_Print_Msg ("Call: Student_Insert_After insert st4 before last variable", "OK", __LINE__);

    i = 1;
    for_list(stl)
    {
        if (i == 5) {i++; continue;} // st5 not still not exist
        assert (Student_Compare (stl->var, &students[i])); 
        i++;
    }
    EC_Test_Print_Msg ("Test: Insert st5 into stl", "OK", __LINE__);

    // Insert st5 after st4
    i = 1;
    for_list(stl)
    {
        if (stl->var == st4)
        {
            Student_Insert_After (stl, stl->list_var, st5);
        }
        i++;
    }

    i = 1;
    for_list(stl)
    {
        assert (Student_Compare (stl->var, &students[i])); 
        i++;
    }
    EC_Test_Print_Msg ("Test: Insert st1 ... st5 into stl", "OK", __LINE__);
}


void
Test_List_Var_Move_Up ()
{
    EC_Test_Print_Title (__func__);

    EC_Test_Print_Subtitle ("Create and initalize variables");

    int i = 0;
    StudentListVar none_existing_var1; // not a var in the list
    StudentListVar none_existing_var2; // not a var in the list
    StudentList *stl = Student_List ();
    EC_Test_Print_Msg ("Call: Student_List", "OK", __LINE__);

    /*-----------------*/
    /* Test empty list */
    /*-----------------*/
    EC_Test_Print_Subtitle ("Test empty list");

    Student_Move (stl, NULL, stl->first);
    EC_Test_Print_Msg ("Move stl->first in an empty list", "OK", __LINE__);
    assert (stl->first == NULL);
    EC_Test_Print_Msg ("Test: Move stl->first in an empyt list", "OK", __LINE__);

    Student_Move (stl, NULL, &none_existing_var1);
    EC_Test_Print_Msg ("Move none existing var var to ref = NULL in an empty list", "OK", __LINE__);
    assert (stl->first == NULL);
    EC_Test_Print_Msg ("Test: Move none existing var to ref = Null in an empty list", "OK", __LINE__);

    Student_Move (stl, &none_existing_var1, &none_existing_var2);
    EC_Test_Print_Msg ("Move none existing var to none existing ref in an empty list", "OK", __LINE__);
    assert (stl->first == NULL);
    EC_Test_Print_Msg ("Test: Move none existing var to none existing ref in an empty list", "OK", __LINE__);

    /*------------------------------*/
    /* Test list with one variables */
    /*------------------------------*/
    EC_Test_Print_Subtitle ("Test list with one variable");

    Student_Append(stl, st0);
    EC_Test_Print_Msg ("Call: Student_Append", "OK", __LINE__);

    assert (stl->first->var == st0);
    EC_Test_Print_Msg ("Test: st0 appended to stl", "OK", __LINE__);

    // Only one variable
    Student_Move (stl, NULL, stl->first);
    assert (stl->first->var == st0);
    EC_Test_Print_Msg ("Test: st0 remains as first in stl", "OK", __LINE__);

    // None existing ref 
    Student_Move (stl, &none_existing_var1, stl->first);
    Student_Move (stl, stl->first, &none_existing_var1);
    EC_Test_Print_Msg ("Test: None existing variables warnings", "OK", __LINE__);

    /*------------------------------*/
    /* Test list with two variables */
    /*------------------------------*/
    EC_Test_Print_Subtitle ("Test list with two variables");

    Student_Append(stl, st1);
    EC_Test_Print_Msg ("Append st1 to stl", "OK", __LINE__);

    // check stl order
    i = 0;
    for_list(stl)
    {
        assert (Student_Compare (stl->var, &students[i])); 
        i++;
    }
    assert (i == 2);
    EC_Test_Print_Msg ("Check stl st0 st1 order", "OK", __LINE__);

    // check reverse order
    assert (Student_Compare (stl->last->var, st1)); 
    assert (Student_Compare (stl->last->previous->var, st0)); 
    EC_Test_Print_Msg ("Check stl st0 st1 in reverse order", "OK", __LINE__);

    // stl->first->next to first
    Student_Move(stl, NULL, stl->first->next);
    EC_Test_Print_Msg ("Move st1 as first variable of stl", "OK", __LINE__);
    assert (Student_Compare (stl->first->var, st1)); 
    EC_Test_Print_Msg ("Test: Move st1 as first variable of stl", "OK", __LINE__);

    // reset stl->first->next to first again
    Student_Move(stl, NULL, stl->first->next);
    EC_Test_Print_Msg ("Move st0 back as first variable of stl", "OK", __LINE__);
    assert (Student_Compare (stl->first->var, st0));
    assert (Student_Compare (stl->last->var, st1));
    EC_Test_Print_Msg ("Test: Move st0 back as first variable of stl", "OK", __LINE__);

    // last to first
    Student_Move(stl, NULL, stl->last);
    EC_Test_Print_Msg ("Move stl->last as first variable of stl", "OK", __LINE__);
    assert (Student_Compare (stl->first->var, st1)); 
    assert (Student_Compare (stl->last->var, st0));
    EC_Test_Print_Msg ("Test: Move st1 first variable of stl", "OK", __LINE__);

    // last to after first
    Student_Move(stl, stl->first, stl->last);
    EC_Test_Print_Msg ("Move stl->last after first variable of stl", "OK", __LINE__);
    assert (Student_Compare (stl->first->var, st1)); 
    assert (Student_Compare (stl->last->var, st0));
    EC_Test_Print_Msg ("Test: Move stl->last after first variable of stl", "OK", __LINE__);

    // first to after last
    Student_Move(stl, stl->last, stl->first);
    EC_Test_Print_Msg ("Move stl->first as last variable of stl", "OK", __LINE__);
    assert (Student_Compare (stl->first->var, st0)); 
    assert (Student_Compare (stl->last->var, st1));
    EC_Test_Print_Msg ("Test: Move stl->first as last variable of stl", "OK", __LINE__);

    // check stl sequence
    i = 0;
    for_list(stl)
    {
        assert (Student_Compare (stl->var, &students[i])); 
        i++;
    }
    assert (i == 2);
    EC_Test_Print_Msg ("Test: st0 and st1 exist", "OK", __LINE__);

    // check reverse sequence
    i = 1;
    for_list_reverse(stl)
    {
        assert (Student_Compare (stl->var, &students[i])); 
        i--;
    }
    assert (i == -1);
    EC_Test_Print_Msg ("Check stl st0 st1 in reverse order", "OK", __LINE__);

    /*--------------------------------*/
    /* Test list with three variables */
    /*--------------------------------*/
    EC_Test_Print_Subtitle ("Test list with three variables");

    Student_Append(stl, st2);
    EC_Test_Print_Msg ("Append st1 to stl", "OK", __LINE__);

    // check list sequence
    i = 0;
    for_list(stl)
    {
        assert (Student_Compare (stl->var, &students[i])); 
        i++;
    }
    assert (i == 3);
    EC_Test_Print_Msg ("Test: st0, st1, st2 exist", "OK", __LINE__);

    // check reverse sequence
    assert (Student_Compare (stl->last->var, st2)); 
    assert (Student_Compare (stl->last->previous->var, st1)); 
    assert (Student_Compare (stl->last->previous->previous->var, st0)); 
    EC_Test_Print_Msg ("Check stl st0, st1, st2 in reverse order", "OK", __LINE__);

    // move last
    Student_Move(stl, NULL, stl->last);
    EC_Test_Print_Msg ("Move stl->last as first variable of stl", "OK", __LINE__);
    assert (Student_Compare (stl->first->var, st2)); 
    assert (Student_Compare (stl->first->next->var, st0)); 
    assert (Student_Compare (stl->first->next->next->var, st1));
    assert (Student_Compare (stl->last->var, st1)); 
    assert (Student_Compare (stl->last->previous->var, st0)); 
    assert (Student_Compare (stl->last->previous->previous->var, st2));
    EC_Test_Print_Msg ("Test: Move stl->last as first variable of stl", "OK", __LINE__);

    Student_Move(stl, stl->first, stl->last);
    EC_Test_Print_Msg ("Move stl->last to after first variable of stl", "OK", __LINE__);
    assert (Student_Compare (stl->first->var, st2)); 
    assert (Student_Compare (stl->first->next->var, st1)); 
    assert (Student_Compare (stl->first->next->next->var, st0));
    assert (Student_Compare (stl->last->var, st0)); 
    assert (Student_Compare (stl->last->previous->var, st1)); 
    assert (Student_Compare (stl->last->previous->previous->var, st2));
    EC_Test_Print_Msg ("Test: Move stl->last to after first variable of stl", "OK", __LINE__);

    // move first->next
    Student_Move(stl, NULL, stl->first->next);
    EC_Test_Print_Msg ("Move stl->first->next as first variable of stl", "OK", __LINE__);
    assert (Student_Compare (stl->first->var, st1)); 
    assert (Student_Compare (stl->first->next->var, st2)); 
    assert (Student_Compare (stl->first->next->next->var, st0));
    assert (Student_Compare (stl->last->var, st0)); 
    assert (Student_Compare (stl->last->previous->var, st2)); 
    assert (Student_Compare (stl->last->previous->previous->var, st1));
    EC_Test_Print_Msg ("Test: Move stl->first->next as after first variable of stl", "OK", __LINE__);

    Student_Move(stl, stl->last, stl->first->next);
    EC_Test_Print_Msg ("Move stl->last as first variable of stl", "OK", __LINE__);
    assert (Student_Compare (stl->first->var, st1)); 
    assert (Student_Compare (stl->first->next->var, st0)); 
    assert (Student_Compare (stl->first->next->next->var, st2));
    assert (Student_Compare (stl->last->var, st2)); 
    assert (Student_Compare (stl->last->previous->var, st0)); 
    assert (Student_Compare (stl->last->previous->previous->var, st1));
    EC_Test_Print_Msg ("Test: Move stl->first->next as after first variable of stl", "OK", __LINE__);

    // move first
    Student_Move(stl, stl->last->previous, stl->first);
    EC_Test_Print_Msg ("Move stl->last as first variable of stl", "OK", __LINE__);
    assert (Student_Compare (stl->first->var, st0)); 
    assert (Student_Compare (stl->first->next->var, st1)); 
    assert (Student_Compare (stl->first->next->next->var, st2));
    assert (Student_Compare (stl->last->var, st2)); 
    assert (Student_Compare (stl->last->previous->var, st1)); 
    assert (Student_Compare (stl->last->previous->previous->var, st0));
    EC_Test_Print_Msg ("Test: Move stl->first->next as after first variable of stl", "OK", __LINE__);

    Student_Move(stl, stl->last, stl->first);
    EC_Test_Print_Msg ("Move stl->last as first variable of stl", "OK", __LINE__);
    assert (Student_Compare (stl->first->var, st1)); 
    assert (Student_Compare (stl->first->next->var, st2)); 
    assert (Student_Compare (stl->last->var, st0));
    EC_Test_Print_Msg ("Test: Move stl->first->next as after first variable of stl", "OK", __LINE__);

    // move st0 as first
    Student_Move(stl, NULL, stl->last);

    i = 0;
    for_list(stl)
    {
        assert (Student_Compare (stl->var, &students[i])); 
        i++;
    }
    assert (i == 3);
    EC_Test_Print_Msg ("Test: st0, st1, st2 sequence", "OK", __LINE__);

    // check reverse sequence
    i = 2;
    for_list_reverse(stl)
    {
        assert (Student_Compare (stl->var, &students[i])); 
        i--;
    }
    assert (i == -1);
    EC_Test_Print_Msg ("Check stl st0, st1, st2 in reverse order", "OK", __LINE__);

    /*-------------------------------*/
    /* Test list with four variables */
    /*-------------------------------*/
    Student_Append(stl, st3);
    EC_Test_Print_Msg ("Append st3 to stl", "OK", __LINE__);

    i = 0;
    for_list(stl)
    {
        assert (Student_Compare (stl->var, &students[i])); 
        i++;
    }
    assert (i == 4);
    EC_Test_Print_Msg ("Test: st0, st1, st2, st3 sequence", "OK", __LINE__);

    // move last->previous
    Student_Move(stl, NULL, stl->last->previous);
    EC_Test_Print_Msg ("Move stl->last->previous as first variable in stl", "OK", __LINE__);
    assert (Student_Compare (stl->first->var, st2)); 
    assert (Student_Compare (stl->first->next->var, st0)); 
    assert (Student_Compare (stl->last->previous->var, st1));
    assert (Student_Compare (stl->last->var, st3));
    EC_Test_Print_Msg ("Test: stl->last->previous as first variabale in stl", "OK", __LINE__);

    Student_Move(stl, stl->first, stl->last->previous);
    EC_Test_Print_Msg ("Move stl->last->previous as after first variable in stl", "OK", __LINE__);
    assert (Student_Compare (stl->first->var, st2)); 
    assert (Student_Compare (stl->first->next->var, st1)); 
    assert (Student_Compare (stl->last->previous->var, st0));
    assert (Student_Compare (stl->last->var, st3));
    EC_Test_Print_Msg ("Test: stl->last->previous as after first variabale in stl", "OK", __LINE__);

    Student_Move(stl, stl->last, stl->last->previous);
    EC_Test_Print_Msg ("Move stl->last->previous as after last variable in stl", "OK", __LINE__);
    assert (Student_Compare (stl->first->var, st2)); 
    assert (Student_Compare (stl->first->next->var, st1)); 
    assert (Student_Compare (stl->last->previous->var, st3));
    assert (Student_Compare (stl->last->var, st0));
    EC_Test_Print_Msg ("Test: stl->last->previous as after last variabale in stl", "OK", __LINE__);

    // move first->next
    Student_Move(stl, NULL, stl->first->next);
    EC_Test_Print_Msg ("Move stl->first->next as first variable in stl", "OK", __LINE__);
    assert (Student_Compare (stl->first->var, st1)); 
    assert (Student_Compare (stl->first->next->var, st2)); 
    assert (Student_Compare (stl->last->previous->var, st3));
    assert (Student_Compare (stl->last->var, st0));
    EC_Test_Print_Msg ("Test: stl->first->next as first variable in stl", "OK", __LINE__);

    Student_Move(stl, stl->last->previous, stl->first->next);
    EC_Test_Print_Msg ("Move stl->first->next as before last variable in stl", "OK", __LINE__);
    assert (Student_Compare (stl->first->var, st1)); 
    assert (Student_Compare (stl->first->next->var, st3)); 
    assert (Student_Compare (stl->last->previous->var, st2));
    assert (Student_Compare (stl->last->var, st0));
    EC_Test_Print_Msg ("Test: Move stl->first->next as before last variable in stl", "OK", __LINE__);

    Student_Move(stl, stl->last, stl->first->next);
    EC_Test_Print_Msg ("Move stl->first->next as last variable in stl", "OK", __LINE__);
    assert (Student_Compare (stl->first->var, st1)); 
    assert (Student_Compare (stl->first->next->var, st2)); 
    assert (Student_Compare (stl->last->previous->var, st0));
    assert (Student_Compare (stl->last->var, st3));
    EC_Test_Print_Msg ("Test: Move stl->first->next as last variable in stl", "OK", __LINE__);

    // reorder list
    Student_Move(stl, NULL, stl->last->previous);

    // check list sequence
    i = 0;
    for_list(stl)
    {
        assert (Student_Compare (stl->var, &students[i])); 
        i++;
    }
    assert (i == 4);
    EC_Test_Print_Msg ("Test: st0, st1, st2, st3 sequence", "OK", __LINE__);

    i = 3;
    for_list_reverse(stl)
    {
        assert (Student_Compare (stl->var, &students[i])); 
        i--;
    }
    assert (i == -1);
    EC_Test_Print_Msg ("Test: st0, st1, st2, st3 reverse sequence", "OK", __LINE__);

    /*-------------------------------*/
    /* Test list with five variables */
    /*-------------------------------*/
    
    // Append st4 variable
    Student_Append(stl, st4);

    // move stl->first->next->next variable
    Student_Move(stl, NULL, stl->first->next->next);
    EC_Test_Print_Msg ("Move stl->first->next->next as last variable in stl", "OK", __LINE__);
    assert (Student_Compare (stl->first->var, st2)); 
    assert (Student_Compare (stl->first->next->var, st0)); 
    assert (Student_Compare (stl->first->next->next->var, st1)); 
    assert (Student_Compare (stl->last->previous->var, st3));
    assert (Student_Compare (stl->last->var, st4));
    EC_Test_Print_Msg ("Test: Move stl->first->next as last variable in stl", "OK", __LINE__);

    Student_Move(stl, stl->first, stl->first->next->next);
    EC_Test_Print_Msg ("Move stl->first->next->next as second variable in stl", "OK", __LINE__);
    assert (Student_Compare (stl->first->var, st2)); 
    assert (Student_Compare (stl->first->next->var, st1)); 
    assert (Student_Compare (stl->first->next->next->var, st0)); 
    assert (Student_Compare (stl->last->previous->var, st3));
    assert (Student_Compare (stl->last->var, st4));
    EC_Test_Print_Msg ("Test: Move stl->first->next as second variable in stl", "OK", __LINE__);

    Student_Move(stl, stl->last->previous, stl->first->next->next);
    EC_Test_Print_Msg ("Move stl->first->next->next before last variable in stl", "OK", __LINE__);
    assert (Student_Compare (stl->first->var, st2)); 
    assert (Student_Compare (stl->first->next->var, st1)); 
    assert (Student_Compare (stl->first->next->next->var, st3)); 
    assert (Student_Compare (stl->last->previous->var, st0));
    assert (Student_Compare (stl->last->var, st4));
    EC_Test_Print_Msg ("Test: Move stl->first->next before last variable in stl", "OK", __LINE__);


    Student_Move(stl, stl->last, stl->first->next->next);
    EC_Test_Print_Msg ("Move stl->first->next->next as last variable in stl", "OK", __LINE__);
    assert (Student_Compare (stl->first->var, st2)); 
    assert (Student_Compare (stl->first->next->var, st1)); 
    assert (Student_Compare (stl->first->next->next->var, st0)); 
    assert (Student_Compare (stl->last->previous->var, st4));
    assert (Student_Compare (stl->last->var, st3));
    EC_Test_Print_Msg ("Test: Move stl->first->next as last variable in stl", "OK", __LINE__);

    // test forward sequence
    assert (Student_Compare (stl->first->var, st2)); 
    assert (Student_Compare (stl->first->next->var, st1)); 
    assert (Student_Compare (stl->first->next->next->var, st0)); 
    assert (Student_Compare (stl->first->next->next->next->var, st4));
    assert (Student_Compare (stl->first->next->next->next->next->var, st3));
    EC_Test_Print_Msg ("Test: list sequence", "OK", __LINE__);

    // test reverse sequence
    assert (Student_Compare (stl->last->previous->previous->previous->previous->var, st2)); 
    assert (Student_Compare (stl->last->previous->previous->previous->var, st1)); 
    assert (Student_Compare (stl->last->previous->previous->var, st0)); 
    assert (Student_Compare (stl->last->previous->var, st4));
    assert (Student_Compare (stl->last->var, st3));
    EC_Test_Print_Msg ("Test: list reverse order", "OK", __LINE__);

    // ******* auto test for more variables should implement to prove this work correctly
}

void
Test_List_Exchange_Var ()
{
    EC_Test_Print_Title (__func__);

    EC_Test_Print_Subtitle ("Create and initalize variables");

    int i = 0;
    StudentList *stl = Student_List ();
    EC_Test_Print_Msg ("Create stl", "OK", __LINE__);

    Student_Insert_After(stl, stl->last, st0);
    Student_Insert_After(stl, stl->last, st1);
    Student_Insert_After(stl, stl->last, st2);
    EC_Test_Print_Msg ("Insert to stl as last var", "OK", __LINE__);

    StudentList *stl2 = Student_List ();
    EC_Test_Print_Msg ("Create stl2", "OK", __LINE__);

    Student_Append(stl2, st3);
    Student_Append(stl2, st4);
    Student_Append(stl2, st5);
    EC_Test_Print_Msg ("Append to stl2", "OK", __LINE__);
    
    // Exchange within same list
    EC_Test_Print_Subtitle ("Exchange within same list");

    Student_Exchange(stl->first, stl->first->next);
    EC_Test_Print_Msg ("Call: Student_Exchange", "OK", __LINE__);
    assert (Student_Compare (stl->first->var, st1)); 
    assert (Student_Compare (stl->first->next->var, st0)); 
    assert (Student_Compare (stl->first->next->next->var, st2)); 

    Student_Exchange(stl->first, stl->last);
    EC_Test_Print_Msg ("Call: Student_Exchange", "OK", __LINE__);
    assert (Student_Compare (stl->first->var, st2)); 
    assert (Student_Compare (stl->first->next->var, st0)); 
    assert (Student_Compare (stl->first->next->next->var, st1)); 

    EC_Test_Print_Msg ("exchange within same list", "OK", __LINE__);

    // move back to position
    Student_Move(stl, stl->last, stl->first);

    // Exchange within same list
    EC_Test_Print_Subtitle ("Exchange within different lists");

    Student_Exchange(stl->first, stl2->first);
    EC_Test_Print_Msg ("Call: Student_Exchange with var first", "OK", __LINE__);
    assert (Student_Compare (stl->first->var, st3)); 
    assert (Student_Compare (stl2->first->var, st0)); 

    Student_Exchange(stl->last, stl2->last);
    EC_Test_Print_Msg ("Call: Student_Exchange with var last", "OK", __LINE__);
    assert (Student_Compare (stl->last->var, st5)); 
    assert (Student_Compare (stl2->last->var, st2)); 

    EC_Test_Print_Msg ("exchange within different lists", "OK", __LINE__);
}


/* Test_Replace_List function tested only for max 5 vars */
void
Test_Replace_List ()
{
    EC_Test_Print_Title (__func__);

    /* Init variables */
    EC_Test_Print_Subtitle ("Initialize variables");
    int i = 0;

    /* if list is empty */
    StudentList *stl = Student_List ();
    EC_Test_Print_Msg ("Create: stl", "OK", __LINE__);

    /* Test empty list */
    EC_Test_Print_Subtitle ("Replece empty list");

    EC_Warn_Print_Msg ("Should test with empty list", "Not fineshed yet", __LINE__);

    EC_Test_Print_Subtitle ("Replece list with 2 variables");

    Student_Append(stl, st0);
    Student_Append(stl, st1);
    EC_Test_Print_Msg ("st0, st1 append to stl", "OK", __LINE__);

    Student_Replace(stl, stl->last, stl->first);
    assert (Student_Compare (stl->first->var, st0)); 
    assert (Student_Compare (stl->last->var, st0)); 
    assert (stl->first->next == NULL); 
    EC_Test_Print_Msg ("stl->first replace stl->last", "OK", __LINE__);

    Student_Append(stl, st1);
    EC_Test_Print_Msg ("st1 append againt to stl", "OK", __LINE__);

    Student_Replace(stl, stl->first, stl->last);
    assert (Student_Compare (stl->first->var, st1)); 
    assert (Student_Compare (stl->last->var, st1)); 
    assert (stl->first->next == NULL); 
    EC_Test_Print_Msg ("stl->last replace stl->first", "OK", __LINE__);

    EC_Test_Print_Subtitle ("Replece list with 3 vars");
    // fill list again for 2 vers
    Student_Insert_After (stl, NULL, st0);
    Student_Append (stl, st2);

    // check list ok
    i = 0;
    for_list(stl)
    {
        assert (Student_Compare (stl->var, &students[i])); 
        i++;
    }
    assert (i == 3);
    EC_Test_Print_Msg ("stl list exist st0, st2, st3", "OK", __LINE__);

    // replace with first var
    Student_Replace(stl, stl->first->next, stl->first);
    assert (Student_Compare (stl->first->var, st0)); 
    assert (Student_Compare (stl->first->next->var, st2)); 
    assert (Student_Compare (stl->last->var, st2)); 
    EC_Test_Print_Msg ("stl->first->next replace with stl->first", "OK", __LINE__);

    Student_Insert_After (stl, stl->first, st1); // insert st1 again

    // check list ok
    i = 0;
    for_list(stl)
    {
        assert (Student_Compare (stl->var, &students[i])); 
        i++;
    }
    assert (i == 3);
    EC_Test_Print_Msg ("stl list exist st0, st2, st3", "OK", __LINE__);

    // replace last with first 
    Student_Replace(stl, stl->last, stl->first);
    assert (Student_Compare (stl->first->var, st1)); 
    assert (Student_Compare (stl->first->next->var, st0)); 
    assert (Student_Compare (stl->last->var, st0)); 
    EC_Test_Print_Msg ("replace stl->last with stl->first", "OK", __LINE__);

    Student_Append(stl, st2); // append st2 again

    // replace first with last
    Student_Replace(stl, stl->first, stl->last);
    assert (Student_Compare (stl->first->var, st2)); 
    assert (Student_Compare (stl->first->next->var, st0)); 
    assert (Student_Compare (stl->last->var, st0)); 
    EC_Test_Print_Msg ("replace stl->first with stl->last", "OK", __LINE__);

    Student_Append(stl, st1); // append st1 again

    // replace with second
    Student_Replace(stl, stl->first, stl->first->next);
    assert (Student_Compare (stl->first->var, st0)); 
    assert (Student_Compare (stl->first->next->var, st1)); 
    assert (Student_Compare (stl->last->var, st1)); 
    EC_Test_Print_Msg ("replace first with second", "OK", __LINE__);

    Student_Append(stl, st2);

    Student_Replace(stl, stl->last, stl->first->next);
    assert (Student_Compare (stl->first->var, st0)); 
    assert (Student_Compare (stl->first->next->var, st1)); 
    assert (Student_Compare (stl->last->var, st1)); 
    EC_Test_Print_Msg ("replace last with second", "OK", __LINE__);
}


void
Test_List_Copy ()
{
    EC_Test_Print_Title (__func__);

    /* Init variables */
    EC_Test_Print_Subtitle ("Initialize variables");
    int i = 0;

    StudentList *stl = Student_List ();
    StudentList* stl2 = Student_List ();

    Student_Append(stl, st0);
    Student_Append(stl, st1);
    Student_Append(stl, st2);
    Student_Append(stl, st3);
    Student_Append(stl, st4);
    Student_Append(stl, st5);
    EC_Test_Print_Msg ("Append st0 ... st5 to stl", "OK", __LINE__);

    i = 0;
    for_list (stl)
    {
        assert (Student_Compare (stl->var, &students[i])); 
        i++;
    }
    assert (i == 6);
    EC_Test_Print_Msg ("st0 ... st5 variables exist in stl", "OK", __LINE__);

    stl2 = Student_List_Copy(stl);
    EC_Test_Print_Msg ("Copy stl to stl2", "OK", __LINE__);

    i = 0;
    for_list (stl2)
    {
        assert (Student_Compare (stl2->var, &students[i])); 
        i++;
    }
    assert (i == 6);
    EC_Test_Print_Msg ("stl copied to stl2", "OK", __LINE__);
}


#if 0

void
Test_Sort_List ()
{
/*    EC_Test_Print_Msg ("Test_Sort_List: ");*/

    /*StudentList *stl = Student_List ();*/

    /*StudentListVar *st6 = Student_List_Var ();*/
    /*st6->no = 6;*/
    /*st6->name = "Fernando";*/
    /*Append_Student (stl, st6);*/

    /*StudentListVar *st5 = Student_List_Var ();*/
    /*st5->no = 5;*/
    /*st5->name = "Prisenthi";*/
    /*Append_Student (stl, st5);*/

    /*StudentListVar *st2 = Student_List_Var ();*/
    /*st2->no = 2;*/
    /*st2->name = "Geethike";*/
    /*Append_Student (stl, st2);*/

    /*StudentListVar *st4 = Student_List_Var ();*/
    /*st4->no = 4;*/
    /*st4->name = "Malshi";*/
    /*Append_Student (stl, st4);*/

    /*StudentListVar *st3 = Student_List_Var ();*/
    /*st3->no = 3;*/
    /*st3->name = "Perera";*/
    /*Append_Student (stl, st3);*/

    /*StudentListVar *st1 = Student_List_Var ();*/
    /*st1->no = 1;*/
    /*st1->name = "Malith";*/
    /*Append_Student (stl, st1);*/

    /*Sort_Student_List_With_no (stl);*/

    /*int i = 1;*/

    /*char *names[6] = {"Malith", "Geethike", "Perera", "Malshi", "Prisenthi", "Fernando"};*/

    /*foreach (stl)*/
    /*{*/
        /*assert (stl->var->no == i);*/
        /*assert (!strcmp (stl->var->name, names[i-1]));*/
        /*i++;*/
    /*}*/

    /*EC_Test_Print_Msg ("List sort with variable attribute", "OK");*/
}




/* new list functions */

    /*foreach (stl2)*/
    /*{*/
        /*stl2->var->no = students[i].no;*/
        /*stl2->var->name = students[i].name;*/
        /*i++;*/
    /*}*/



void
Test_List_Var_Move_Down ()
{
    EC_Test_Print_Msg ("Test_List_Var_Move_Down: ");

    struct Stu {
        int no;
        char* name;
    };

    struct Stu students[5] = {{1, "Malith"}, {2, "Geethike"}, {3, "Perera"}, {4, "Rohasha"}, {5, "Malshi"}};

    int i = 0;

    /* Test for 0 list vars */
    StudentList *stl0 = Student_List (0);
    EC_Test_Print_Msg ("Create new list with 0 list vars", "OK");

    stl0->var = stl0->first;

    Student_List_Var_Move_Down (stl0, stl0->var, 1);
    assert (stl0->first == NULL);
    assert (stl0->last == NULL);
    EC_Test_Print_Msg ("List with 0 list vars", "OK");

    /* Test for 1 list var */
    StudentList *stl1 = Student_List (0);
    EC_Test_Print_Msg ("Create new list with 1 list vars", "OK");

    StudentListVar *stl1v = Student_List_Var (stl1);
    stl1v->no = students[0].no;
    stl1v->name = students[0].name;
    EC_Test_Print_Msg ("Assign list 1 variable", "OK");

    Student_List_Var_Move_Down (stl1, stl1v, 1);
    assert (stl1->first == stl1v);
    assert (stl1->last == stl1v);
    EC_Test_Print_Msg ("List with 1 list var", "OK");

    /* Test for 2 list vars */
    StudentList *stl2 = Student_List (2);
    EC_Test_Print_Msg ("Create new list with 2 list vars", "OK");

    i = 0;
    for_list (stl2)
    {
        stl2->var->no = students[i].no;
        stl2->var->name = students[i].name;
        i++;
    }

    for_list (stl2)
    {
        printf ("%d %s\n", stl2->var->no, stl2->var->name);
    }

    EC_Test_Print_Msg ("Assign list 2 variable", "OK");

    /* set current var */
    stl2->var = stl2->first;
    StudentListVar *stl2v1 = stl2->first;
    StudentListVar *stl2v2 = stl2->first->next;

    Student_List_Var_Move_Down (stl2, stl2v1, 1);
    assert (stl2->first == stl2v2);
    assert (stl2->last == stl2v1);
    assert (stl2->first->next == stl2v1);
    assert (stl2->first->previous == NULL);
    assert (stl2->last->previous == stl2v2);
    assert (stl2->last->next == NULL);

    for_list (stl2)
    {
        printf ("%d %s\n", stl2->var->no, stl2->var->name);
    }

    EC_Test_Print_Msg ("List with 2 vars. First var down", "OK");

    Student_List_Var_Move_Down (stl2, stl2v1, 1);
    assert (stl2->first == stl2v2);
    assert (stl2->last == stl2v1);
    assert (stl2->first->next == stl2v1);
    assert (stl2->first->previous == NULL);
    assert (stl2->last->previous == stl2v2);
    assert (stl2->last->next == NULL);

    for_list (stl2)
    {
        printf ("%d %s\n", stl2->var->no, stl2->var->name);
    }

    EC_Test_Print_Msg ("List with 2 vars second var down", "OK");

    /* Test for 3 list vars */
    StudentList *stl3 = Student_List (3);
    EC_Test_Print_Msg ("Create new list with 3 list vars", "OK");

    i = 0;
    for_list (stl3)
    {
        stl3->var->no = students[i].no;
        stl3->var->name = students[i].name;
        i++;
    }
    EC_Test_Print_Msg ("Assign list 3 variable", "OK");

    /* set current var */
    stl3->var = stl3->first;
    StudentListVar *stl3v1 = stl3->first;
    StudentListVar *stl3v2 = stl3->first->next;
    StudentListVar *stl3v3 = stl3->first->next->next;

    /* move first var */
    Student_List_Var_Move_Down (stl3, stl3v1, 1);
    assert (stl3->first == stl3v2);
    assert (stl3->first->next == stl3v1);
    assert (stl3->first->previous == NULL);
    assert (stl3->last == stl3v3);
    assert (stl3->last->previous == stl3v1);
    assert (stl3->last->next == NULL);

    for_list (stl3)
    {
        printf ("%d %s\n", stl3->var->no, stl3->var->name);
    }

    EC_Test_Print_Msg ("List with 3 vars move first var down", "OK");

    /* move second var down */
    Student_List_Var_Move_Down (stl3, stl3v1, 1);
    assert (stl3->first == stl3v2);
    assert (stl3->first->next == stl3v3);
    assert (stl3->first->next->next == stl3v1);
    assert (stl3->first->previous == NULL);
    assert (stl3->last == stl3v1);
    assert (stl3->last->previous == stl3v3);
    assert (stl3->last->next == NULL);

    for_list (stl3)
    {
        printf ("%d %s\n", stl3->var->no, stl3->var->name);
    }

    EC_Test_Print_Msg ("List with 3 vars move second var down", "OK");

    /* move third var down 1 step*/
    Student_List_Var_Move_Down (stl3, stl3v1, 1);
    assert (stl3->first == stl3v2);
    assert (stl3->last == stl3v1);
    assert (stl3->first->next == stl3v3);
    assert (stl3->first->previous == NULL);
    assert (stl3->last->previous == stl3v3);
    assert (stl3->last->next == NULL);

    for_list (stl3)
    {
        printf ("%d %s\n", stl3->var->no, stl3->var->name);
    }

    EC_Test_Print_Msg ("List with 3 vars move third var down", "OK");

    /* move first var down 2 steps*/
    Student_List_Var_Move_Down (stl3, stl3v2, 2);
    assert (stl3->first == stl3v3);
    assert (stl3->first->next == stl3v1);
    assert (stl3->first->previous == NULL);
    assert (stl3->last == stl3v2);
    assert (stl3->last->previous == stl3v1);
    assert (stl3->last->previous->previous == stl3v3);
    assert (stl3->last->next == NULL);

    for_list (stl3)
    {
        printf ("%d %s\n", stl3->var->no, stl3->var->name);
    }

    EC_Test_Print_Msg ("List with 3 vars move third var down", "OK");

    /* Test for 5 list vars */
    StudentList *stl5 = Student_List (5);
    EC_Test_Print_Msg ("Create new list with 5 list vars", "OK");

    i = 0;
    for_list (stl5)
    {
        stl5->var->no = students[i].no;
        stl5->var->name = students[i].name;
        i++;
    }

    /* set current var */
    stl5->var = stl5->first;
    StudentListVar *stl5v1 = stl5->first;
    StudentListVar *stl5v2 = stl5->first->next;
    StudentListVar *stl5v3 = stl5->first->next->next;
    StudentListVar *stl5v4 = stl5->first->next->next->next;
    StudentListVar *stl5v5 = stl5->first->next->next->next->next;

    for_list (stl5)
    {
        printf ("%d %s\n", stl5->var->no, stl5->var->name);
    }

    EC_Test_Print_Msg ("Assign list 5 variable", "OK");

    /* move first var down 3 steps*/
    Student_List_Var_Move_Down (stl5, stl5v1, 3);
    assert (stl5->first == stl5v2);
    assert (stl5->last == stl5v5);
    assert (stl5->first->next->next == stl5v4);
    assert (stl5->first->previous == NULL);
    assert (stl5->last->previous == stl5v1);
    assert (stl5->last->previous->previous == stl5v4);
    assert (stl5->last->next == NULL);

    for_list (stl5)
    {
        printf ("%d %s\n", stl5->var->no, stl5->var->name);
    }

    EC_Test_Print_Msg ("List with 5 vars move last var down 3 steps", "OK");

    /* move first var down 4 steps*/
    Student_List_Var_Move_Down (stl5, stl5v2, 4);
    assert (stl5->first == stl5v3);
    assert (stl5->last == stl5v2);
    assert (stl5->first->next == stl5v4);
    assert (stl5->first->previous == NULL);
    assert (stl5->last->previous == stl5v5);
    assert (stl5->last->previous->previous == stl5v1);
    assert (stl5->last->next == NULL);

    for_list (stl5)
    {
        printf ("%d %s\n", stl5->var->no, stl5->var->name);
    }

    EC_Test_Print_Msg ("List with 5 vars move mid var down 4 steps", "OK");

    /* move second var down 2 steps for mid vars */
    Student_List_Var_Move_Down (stl5, stl5v4, 2);
    assert (stl5->first == stl5v3);
    assert (stl5->last == stl5v2);
    assert (stl5->first->next == stl5v1);
    assert (stl5->first->previous == NULL);
    assert (stl5->last->previous == stl5v4);
    assert (stl5->last->previous->previous == stl5v5);
    assert (stl5->last->next == NULL);

    for_list (stl5)
    {
        printf ("%d %s\n", stl5->var->no, stl5->var->name);
    }

    EC_Test_Print_Msg ("List with 5 vars move mid var down 2 steps", "OK");
}


void
Test_List_Var_Delete ()
{
    EC_Test_Print_Msg ("Test_List_Var_Delete: ");

   /* Test for 0 list vars */
    StudentList *stl0 = Student_List (0);
    EC_Test_Print_Msg ("Create new list with 0 list vars", "OK");

    stl0->var = stl0->first;

    Student_List_Var_Delete (stl0, stl0->var);
    assert (stl0->first == NULL);
    assert (stl0->last == NULL);
    EC_Test_Print_Msg ("List with 0 list vars", "OK");

    /* Test for 1 list var */
    StudentList *stl1 = Student_List (0);
    EC_Test_Print_Msg ("Create new list with 1 list vars", "OK");

    StudentListVar *stl1v = Student_List_Var (stl1);
    stl1v->no = students[0].no;
    stl1v->name = students[0].name;
    EC_Test_Print_Msg ("Assign list 1 variable", "OK");

    Student_List_Var_Delete (stl1, stl1v);
    assert (stl1->first == NULL);
    assert (stl1->last == NULL);
    EC_Test_Print_Msg ("List with 1 list var", "OK");

    /* Test for 2 list vars */
    StudentList *stl2 = Student_List (2);
    EC_Test_Print_Msg ("Create new list with 2 list vars", "OK");

    int i = 0;
    for_list (stl2)
    {
        stl2->var->no = students[i].no;
        stl2->var->name = students[i].name;
        i++;
    }

    for_list (stl2)
    {
        printf ("%d %s\n", stl2->var->no, stl2->var->name);
    }

    EC_Test_Print_Msg ("Assign list 2 variable", "OK");

    /* set current var */
    StudentListVar *stl2v1 = stl2->first;
    StudentListVar *stl2v2 = stl2->first->next;

    Student_List_Var_Delete (stl2, stl2v1);
    assert (stl2->first == stl2v2);
    assert (stl2->last == stl2v2);
    assert (stl2->first->next == NULL);
    assert (stl2->first->previous == NULL);
    assert (stl2->last->previous == NULL);
    assert (stl2->last->next == NULL);

    for_list (stl2)
    {
        printf ("%d %s\n", stl2->var->no, stl2->var->name);
    }

    EC_Test_Print_Msg ("List with 2 vars. Delete first var", "OK");

    Student_List_Var_Delete (stl2, stl2v2);
    assert (stl2->first == NULL);
    assert (stl2->last == NULL);

    for_list (stl2)
    {
        printf ("%d %s\n", stl2->var->no, stl2->var->name);
    }

    EC_Test_Print_Msg ("List with 2 vars delete second var", "OK");

    StudentListVar *stl2v3 = Student_List_Var (stl2);
    StudentListVar *stl2v4 = Student_List_Var (stl2);

    EC_Test_Print_Msg ("List with 2 vars append 2 new vars", "OK");

    i = 0;
    for_list (stl2)
    {
        stl2->var->no = students[i].no;
        stl2->var->name = students[i].name;
        i++;
    }

    EC_Test_Print_Msg ("Initialize list with 2 vars", "OK");

    for_list (stl2)
    {
        printf ("%d %s\n", stl2->var->no, stl2->var->name);
    }

    EC_Test_Print_Msg ("List with 2 vars. Delete first var", "OK");

    Student_List_Var_Delete (stl2, stl2v4);
    assert (stl2->first == stl2v3);
    assert (stl2->last == stl2v3);
    assert (stl2->first->next == NULL);
    assert (stl2->first->previous == NULL);
    assert (stl2->last->previous == NULL);
    assert (stl2->last->next == NULL);

    for_list (stl2)
    {
        printf ("%d %s\n", stl2->var->no, stl2->var->name);
    }

    EC_Test_Print_Msg ("List with 2 vars. Delete second var", "OK");

    Student_List_Var_Delete (stl2, stl2v3);
    assert (stl2->first == NULL);
    assert (stl2->last == NULL);

    for_list (stl2)
    {
        printf ("%d %s\n", stl2->var->no, stl2->var->name);
    }

    EC_Test_Print_Msg ("List with 2 vars delete last var", "OK");

    /* Test for 3 list vars */
    StudentList *stl3 = Student_List (3);
    EC_Test_Print_Msg ("Create new list with 3 list vars", "OK");

    i = 0;
    for_list (stl3)
    {
        stl3->var->no = students[i].no;
        stl3->var->name = students[i].name;
        i++;
    }
    EC_Test_Print_Msg ("Assign list 3 variable", "OK");

    /* Set current var */
    stl3->var = stl3->first;
    StudentListVar *stl3v1 = stl3->first;
    StudentListVar *stl3v2 = stl3->first->next;
    StudentListVar *stl3v3 = stl3->first->next->next;

    /* Delete first var */
    Student_List_Var_Delete (stl3, stl3v1);
    assert (stl3->first == stl3v2);
    assert (stl3->first->next == stl3v3);
    assert (stl3->first->previous == NULL);
    assert (stl3->last == stl3v3);
    assert (stl3->last->previous == stl3v2);
    assert (stl3->last->next == NULL);

    for_list (stl3)
    {
        printf ("%d %s\n", stl3->var->no, stl3->var->name);
    }

    EC_Test_Print_Msg ("List with 3 vars delete first var", "OK");

    /* Delete second (last) var */
    Student_List_Var_Delete (stl3, stl3v3);
    assert (stl3->first == stl3v2);
    assert (stl3->first->next == NULL);
    assert (stl3->first->previous == NULL);
    assert (stl3->last == stl3v2);
    assert (stl3->last->previous == NULL);
    assert (stl3->last->next == NULL);

    for_list (stl3)
    {
        printf ("%d %s\n", stl3->var->no, stl3->var->name);
    }

    EC_Test_Print_Msg ("List with 3 vars delete second (last) var", "OK");

    /* Delete third final var */
    Student_List_Var_Delete (stl3, stl3v2);
    assert (stl3->first == NULL);
    assert (stl3->last == NULL);

    for_list (stl3)
    {
        printf ("%d %s\n", stl3->var->no, stl3->var->name);
    }

    EC_Test_Print_Msg ("List with 3 vars delete last var", "OK");

     /*Check is it ok with delete middle var with 3 vars */

    StudentListVar *stl3v4 = Student_List_Var (stl3);
    StudentListVar *stl3v5 = Student_List_Var (stl3);
    StudentListVar *stl3v6 = Student_List_Var (stl3);

    EC_Test_Print_Msg ("List with 3 vars append 3 new vars", "OK");

    i = 0;
    for_list (stl3)
    {
        stl3->var->no = students[i].no;
        stl3->var->name = students[i].name;
        i++;
    }

    EC_Test_Print_Msg ("Initialize list with 3 vars", "OK");

    for_list (stl3)
    {
        printf ("%d %s\n", stl3->var->no, stl3->var->name);
    }

    Student_List_Var_Delete (stl3, stl3v5);
    assert (stl3->first == stl3v4);
    assert (stl3->first->next == stl3v6);
    assert (stl3->first->previous == NULL);
    assert (stl3->last == stl3v6);
    assert (stl3->last->previous == stl3v4);
    assert (stl3->last->next == NULL);

    EC_Test_Print_Msg ("List with 3 vars delete mid var", "OK");

    /* Test for 5 list vars */
    StudentList *stl5 = Student_List (5);
    EC_Test_Print_Msg ("Create new list with 5 list vars", "OK");

    i = 0;
    for_list (stl5)
    {
        stl5->var->no = students[i].no;
        stl5->var->name = students[i].name;
        i++;
    }

    for_list (stl5)
    {
        printf ("%d %s\n", stl5->var->no, stl5->var->name);
    }

    /* set current var */
    stl5->var = stl5->first;
    StudentListVar *stl5v1 = stl5->first;
    StudentListVar *stl5v2 = stl5->first->next;
    StudentListVar *stl5v3 = stl5->first->next->next;
    StudentListVar *stl5v4 = stl5->first->next->next->next;
    StudentListVar *stl5v5 = stl5->first->next->next->next->next;

    Student_List_Var_Delete (stl5, stl5v3);
    assert (stl5->first->next->next == stl5v4);
    assert (stl5->last->previous->previous == stl5v2);

    for_list (stl5)
    {
        printf ("%d %s\n", stl5->var->no, stl5->var->name);
    }

    EC_Test_Print_Msg ("List with 5 vars move mid var down 2 steps", "OK");

    Student_List_Var_Delete (stl5, stl5v4);
    assert (stl5->first->next->next == stl5v5);
    assert (stl5->last == stl5v5);
    assert (stl5->last->previous == stl5v2);

    for_list (stl5)
    {
        printf ("%d %s\n", stl5->var->no, stl5->var->name);
    }

    EC_Test_Print_Msg ("List with 5 vars move mid var down 2 steps", "OK");
}


void
Test_List_Change_Var ()
{
}





void
Test_List_Var_Drop ()
{
    EC_Test_Print_Msg ("Test_List_Var_Drop: ");
}

#endif 

void
Run_List_Test ()
{
    EC_Test_Print_Header ("Test: ec_list.h");
    printf ("\n");

    Test_List_Helpers ();
    printf ("\n");

    Test_New_List ();
    printf ("\n");

    Test_List_Append();
    printf ("\n");

    Test_For_List();
    printf ("\n");

    Test_Insert_Before_List ();
    printf ("\n");

    Test_Insert_After_List ();
    printf ("\n");

    Test_List_Var_Move_Up ();
    printf ("\n");

    Test_List_Exchange_Var ();
    printf ("\n");

    Test_Replace_List ();
    printf ("\n");

    Test_List_Copy ();
    printf ("\n");

    /*Test_List_Var_Move_Down ();*/
    /*printf ("\n");*/

    /*Test_List_Var_Delete ();*/
    /*printf ("\n");*/

    /*Test_List_Var_Drop ();*/
    /*printf ("\n");*/

    /*Test_Sort_List ();*/
    /*printf ("\n");*/

    /*Test_List_Change_Var ();*/
    /*printf ("\n");*/

    /*EC_Test_Print_Msg ("Test: ec_list.h", "PASS");*/
    /*printf ("\n");*/
}
