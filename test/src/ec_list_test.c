#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "ec_list_test.h"

struct Stu {
    int no;
    char* name;
};

struct Stu students[5] = {{1, "Malith"}, {2, "Geethike"}, {3, "Perera"}, {4, "Rohasha"}, {5, "Malshi"}};

void
Print_Student_List (StudentList *stl)
{
    /*
    StudentListVar *current = stl->first;

    while (current != NULL)
    {
    printf ("%d ", current->no);
    current = current->next;
    }
    */

    /*foreach_list (stl)*/
    /*{*/
        /*printf ("%d ", stl->var->no);*/
    /*}*/

    /*printf ("\n");*/
}


void
Test_New_List ()
{
    EC_Error_Print_Msg ("Test_New_List: ", "BEGIN");

    StudentList *stl = Student_List (0);
    EC_Error_Print_Msg ("Create new list", "OK");

    StudentListVar *st1 = Student_List_Var (stl);
    StudentListVar *st2 = Student_List_Var (stl);
    StudentListVar *st3 = Student_List_Var (stl);
    EC_Error_Print_Msg ("Create list variables", "OK");

    st1->no = 1;
    st1->name = "Malith";
    st2->no = 2;
    st2->name = "Geethike";
    st3->no = 3;
    st3->name = "Perera";

    EC_Error_Print_Msg ("Assign list variable attributes", "OK");

    assert (stl->first->no == 1);
    assert (!strcmp (stl->first->name, "Malith"));

    assert (stl->first->next->no == 2);
    assert (!strcmp (stl->first->next->name, "Geethike"));

    assert (stl->first->next->next->no == 3);
    assert (!strcmp (stl->first->next->next->name, "Perera"));

    EC_Error_Print_Msg ("List variables exist ok", "OK");

    assert (stl->first->next->next->next == NULL);
    assert (stl->last->next == NULL);
    EC_Error_Print_Msg ("List last next NULL", "OK");

    EC_Error_Print_Msg ("Test_New_List: ", "END");
}


void
Test_New_List2 ()
{
    EC_Error_Print_Msg ("Test_New_List2: ", "BEGIN");

    StudentList *stl = Student_List (3);
    EC_Error_Print_Msg ("Create new list with 3 list vars", "OK");

    stl->first->no = 1;
    stl->first->name = "Malith";
    stl->first->next->no = 2;
    stl->first->next->name = "Geethike";
    stl->first->next->next->no = 3;
    stl->first->next->next->name = "Perera";

    EC_Error_Print_Msg ("Assign list variable attributes", "OK");

    assert (stl->first->no == 1);
    assert (!strcmp (stl->first->name, "Malith"));

    assert (stl->first->next->no == 2);
    assert (!strcmp (stl->first->next->name, "Geethike"));

    assert (stl->first->next->next->no == 3);
    assert (!strcmp (stl->first->next->next->name, "Perera"));

    EC_Error_Print_Msg ("List variables exist ok", "OK");

    assert (stl->first->next->next->next == NULL);
    assert (stl->last->next == NULL);
    EC_Error_Print_Msg ("List last next NULL", "OK");

    EC_Error_Print_Msg ("Test_New_List2: ", "END");
}


void
Test_Append_List ()
{
/*    EC_Error_Print_Msg ("Append_List: ", "BEGIN");*/

    /*StudentList *stl = Student_List ();*/

    /*StudentListVar *st1 = Student_List_Var ();*/
    /*st1->no = 1;*/
    /*st1->name = "Malith";*/

    /*StudentListVar *st2 = Student_List_Var ();*/
    /*st2->no = 2;*/
    /*st2->name = "Geethike";*/

    /*Append_Student (stl, st1);*/

    /*assert (stl->first->no == 1);*/
    /*assert (!strcmp (stl->first->name, "Malith")); // strcmp return 0 when equal so ! used*/
    /*assert (stl->first->next == NULL);*/
    /*assert (stl->first->previous == NULL);*/
    /*assert (stl->first->next == NULL);*/
    /*assert (stl->first->previous == NULL);*/
    /*assert (stl->last == st1);*/

    /*EC_Error_Print_Msg ("Append list first variable", "OK");*/

    /*Append_Student (stl, st2);*/

    /*assert (stl->first->no == 1);*/
    /*assert (!strcmp (stl->first->name, "Malith")); // strcmp return 0 when equal so ! used*/
    /*assert (stl->first->previous == NULL);*/
    /*assert (stl->first->next == st2);*/
    /*assert (stl->first->next->no = 2);*/
    /*assert (!strcmp (stl->first->next->name, "Geethike")); // strcmp return 0 when equal so ! used*/
    /*assert (stl->first->next->previous == st1);*/
    /*assert (stl->last == st2);*/
    /*assert (st2->next == NULL);*/
    /*assert (stl->last->next == NULL);*/

    /*EC_Error_Print_Msg ("Append list second variable", "OK");*/

    /*EC_Error_Print_Msg ("Append_List: ", "END");*/
}


void
Test_Insert_List ()
{
/*    EC_Error_Print_Msg ("Test_Insert_List: ", "BEGIN");*/

    /*StudentList *stl = Student_List ();*/

    /*StudentListVar *st1 = Student_List_Var ();*/
    /*st1->no = 1;*/
    /*st1->name = "Malith";*/
    /*Append_Student (stl, st1);*/

    /*StudentListVar *st2 = Student_List_Var ();*/
    /*st2->no = 2;*/
    /*st2->name = "Geethike";*/
    /*Append_Student (stl, st2);*/

    /*StudentListVar *st3 = Student_List_Var ();*/
    /*st3->no = 3;*/
    /*st3->name = "Perera";*/
    /*Insert_Student (stl, st3, st1, -1);*/
    /*assert (stl->first->no == 3);*/
    /*assert (!strcmp (stl->first->name, "Perera")); // strcmp return 0 when equal use !*/

    /*EC_Error_Print_Msg ("Insert as fist item", "OK");*/

    /*StudentListVar *st4 = Student_List_Var ();*/
    /*st4->no = 4;*/
    /*st4->name = "Malshi";*/
    /*Insert_Student (stl, st4, st3, 1);*/
    /*assert (stl->first->next->no == 4);*/
    /*assert (!strcmp (stl->first->next->name, "Malshi")); // strcmp return 0 when equal use !*/

    /*EC_Error_Print_Msg ("Insert next to fist item", "OK");*/

    /*StudentListVar *st5 = Student_List_Var ();*/
    /*st5->no = 5;*/
    /*st5->name = "Prisenthi";*/
    /*Insert_Student (stl, st5, st2, -1);*/
    /*assert (stl->last->previous->no == 5);*/
    /*assert (!strcmp (stl->last->previous->name, "Prisenthi")); // strcmp return 0 when equal use !*/

    /*EC_Error_Print_Msg ("Insert before last item", "OK");*/

    /*StudentListVar *st6 = Student_List_Var ();*/
    /*st6->no = 6;*/
    /*st6->name = "Fernando";*/
    /*Insert_Student (stl, st6, st2, 1);*/
    /*assert (stl->last->no == 6);*/
    /*assert (!strcmp (stl->last->name, "Fernando")); // strcmp return 0 when equal use !*/

    /*EC_Error_Print_Msg ("Insert as last item", "OK");*/

    /*StudentListVar *st7 = Student_List_Var ();*/
    /*st7->no = 7;*/
    /*st7->name = "Rohasha";*/
    /*Insert_Student (stl, st7, st4, 1);*/
    /*assert (st4->next->no == 7);*/
    /*assert (!strcmp (st4->next->name, "Rohasha")); // strcmp return 0 when equal use !*/

    /*EC_Error_Print_Msg ("Insert as after mid item", "OK");*/

    /*StudentListVar *st8 = Student_List_Var ();*/
    /*st8->no = 8;*/
    /*st8->name = "Magret";*/
    /*Insert_Student (stl, st8, st4, -1);*/
    /*assert (st4->previous->no == 8);*/
    /*assert (!strcmp (st4->previous->name, "Magret")); // strcmp return 0 when equal use !*/

    /*EC_Error_Print_Msg ("Insert as before mid item", "OK");*/

    /*EC_Error_Print_Msg ("Test_Insert_List: ", "END");*/
}


void
Test_Replace_List ()
{
/*    EC_Error_Print_Msg ("Test_Replace_List: ", "BEGIN");*/

    /*StudentList *stl = Student_List ();*/

    /*StudentListVar *st1 = Student_List_Var ();*/
    /*st1->no = 1;*/
    /*st1->name = "Malith";*/
    /*Append_Student (stl, st1);*/

    /*StudentListVar *st2 = Student_List_Var ();*/
    /*st2->no = 2;*/
    /*st2->name = "Geethike";*/
    /*Append_Student (stl, st2);*/

    /*StudentListVar *st3 = Student_List_Var ();*/
    /*st3->no = 3;*/
    /*st3->name = "Perera";*/

    /*Replace_Student (stl, st1, st3);*/
    /*assert (stl->first->no = 3);*/
    /*assert (stl->first->name = "Perera");*/

    /*Replace_Student (stl, st2, st1);*/
    /*assert (stl->last->no = 1);*/
    /*assert (stl->last->name = "Malith");*/

    /*EC_Error_Print_Msg ("Replace last item", "OK");*/

    /*EC_Error_Print_Msg ("Test_Replace_List: ", "END");*/
}


void
Test_Sort_List ()
{
/*    EC_Error_Print_Msg ("Test_Sort_List: ", "BEGIN");*/

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

    /*EC_Error_Print_Msg ("List sort with variable attribute", "OK");*/

    /*EC_Error_Print_Msg ("Test_Sort_List: ", "END");*/
}


void
Test_List_Copy ()
{
/*    EC_Error_Print_Msg ("Test_List_Copy: ", "BEGIN");*/

    /*StudentList* stl1 = Student_List ();*/

    /*StudentListVar* st1 = Student_List_Var ();*/
    /*st1->no = 1;*/
    /*st1->name = "Malith";*/
    /*Append_Student (stl1, st1);*/

    /*StudentListVar* st2 = Student_List_Var ();*/
    /*st2->no = 2;*/
    /*st2->name = "Geethike";*/
    /*Append_Student (stl1, st2);*/

    /*StudentList* stl2 = Student_List_Copy (stl1);*/

    /*assert (stl2->first->no == 1);*/
    /*assert (strcmp(stl2->first->name ,"Malith") == 0 );*/

    /*assert (stl2->first->next->no == 2);*/
    /*assert (strcmp(stl2->first->next->name, "Geethike") == 0 );*/

    /*EC_Error_Print_Msg ("List Copy Variables", "OK");*/

    /*st1->no = 3;*/
    /*st1->name = "Malshi";*/
    /*assert (stl2->first->no != 3);*/
    /*assert (strcmp(stl2->first->name ,"Malshi") != 0 );*/

    /*st2->no = 4;*/
    /*st2->name = "Prisenthi";*/
    /*assert (stl1->first->no != 4);*/
    /*assert (strcmp(stl1->first->name ,"Prisenthi") != 0 );*/

    /*EC_Error_Print_Msg ("Copied list do not affect other list", "OK");*/

    /*EC_Error_Print_Msg ("Test_List_Copy: ", "END");*/
}


/* new list functions */

    /*foreach (stl2)*/
    /*{*/
        /*stl2->var->no = students[i].no;*/
        /*stl2->var->name = students[i].name;*/
        /*i++;*/
    /*}*/

void
Test_List_Var_Move_Up ()
{
    EC_Error_Print_Msg ("Test_List_Var_Move_Up: ", "BEGIN");


    int i = 0;

    /* Test for 0 list vars */
    StudentList *stl0 = Student_List (0);
    EC_Error_Print_Msg ("Create new list with 0 list vars", "OK");

    stl0->var = stl0->first;

    Student_List_Var_Move_Up (stl0, stl0->var, 1);
    assert (stl0->first == NULL);
    assert (stl0->last == NULL);
    EC_Error_Print_Msg ("List with 0 list vars", "OK");

    /* Test for 1 list var */
    StudentList *stl1 = Student_List (0);
    EC_Error_Print_Msg ("Create new list with 1 list vars", "OK");

    StudentListVar *stl1v = Student_List_Var (stl1);
    stl1v->no = students[0].no;
    stl1v->name = students[0].name;
    stl1->var = stl1->first;
    EC_Error_Print_Msg ("Assign list 1 variable", "OK");

    Student_List_Var_Move_Up (stl1, stl1->var, 1);
    assert (stl1->first == stl1v);
    assert (stl1->last == stl1v);
    EC_Error_Print_Msg ("List with 1 list var", "OK");

    /* Test for 2 list vars */
    StudentList *stl2 = Student_List (2);
    EC_Error_Print_Msg ("Create new list with 2 list vars", "OK");

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

    EC_Error_Print_Msg ("Assign list 2 variable", "OK");

    /* set current var */
    stl2->var = stl2->first;
    StudentListVar *stl2v1 = stl2->first;
    StudentListVar *stl2v2 = stl2->first->next;

    Student_List_Var_Move_Up (stl2, stl2v1, 1);
    assert (stl2->first == stl2v1);
    assert (stl2->last == stl2v2);
    assert (stl2->first->next == stl2v2);
    assert (stl2->first->previous == NULL);
    assert (stl2->last->previous == stl2v1);
    assert (stl2->last->next == NULL);
    EC_Error_Print_Msg ("List with 2 vars. First var up", "OK");

    Student_List_Var_Move_Up (stl2, stl2v2, 1);
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

    EC_Error_Print_Msg ("List with 3 vars move first var up", "OK");

    EC_Error_Print_Msg ("List with 2 vars second var up", "OK");

    /* Test for 3 list vars */
    StudentList *stl3 = Student_List (3);
    EC_Error_Print_Msg ("Create new list with 3 list vars", "OK");

    i = 0;
    for_list (stl3)
    {
        stl3->var->no = students[i].no;
        stl3->var->name = students[i].name;
        i++;
    }
    EC_Error_Print_Msg ("Assign list 3 variable", "OK");

    /* set current var */
    stl3->var = stl3->first;
    StudentListVar *stl3v1 = stl3->first;
    StudentListVar *stl3v2 = stl3->first->next;
    StudentListVar *stl3v3 = stl3->first->next->next;

    /* move first var */
    Student_List_Var_Move_Up (stl3, stl3v1, 1);
    assert (stl3->first == stl3v1);
    assert (stl3->last == stl3v3);
    assert (stl3->first->next == stl3v2);
    assert (stl3->first->previous == NULL);
    assert (stl3->last->previous == stl3v2);
    assert (stl3->last->next == NULL);

    for_list (stl3)
    {
        printf ("%d %s\n", stl3->var->no, stl3->var->name);
    }

    EC_Error_Print_Msg ("List with 3 vars move first var up", "OK");

    /* move second var up */
    Student_List_Var_Move_Up (stl3, stl3v2, 1);
    assert (stl3->first == stl3v2);
    assert (stl3->last == stl3v3);
    assert (stl3->first->next == stl3v1);
    assert (stl3->first->next->previous == stl3v2);
    assert (stl3->first->next->next == stl3v3);
    assert (stl3->first->previous == NULL);
    assert (stl3->last->previous == stl3v1);
    assert (stl3->last->next == NULL);

    for_list (stl3)
    {
        printf ("%d %s\n", stl3->var->no, stl3->var->name);
    }

    EC_Error_Print_Msg ("List with 3 vars move second var up", "OK");

    /* move third var up 1 step*/
    Student_List_Var_Move_Up (stl3, stl3v3, 1);
    assert (stl3->first == stl3v2);
    assert (stl3->first->next == stl3v3);
    assert (stl3->first->previous == NULL);
    assert (stl3->last == stl3v1);
    assert (stl3->last->previous == stl3v3);
    assert (stl3->last->next == NULL);

    for_list (stl3)
    {
        printf ("%d %s\n", stl3->var->no, stl3->var->name);
    }

    EC_Error_Print_Msg ("List with 3 vars move third var up", "OK");

    /* move third var up 2 steps*/
    Student_List_Var_Move_Up (stl3, stl3v1, 2);
    assert (stl3->first == stl3v1);
    assert (stl3->last == stl3v3);
    assert (stl3->first->next == stl3v2);
    assert (stl3->first->previous == NULL);
    assert (stl3->last->previous == stl3v2);
    assert (stl3->last->previous->previous == stl3v1);
    assert (stl3->last->next == NULL);

    for_list (stl3)
    {
        printf ("%d %s\n", stl3->var->no, stl3->var->name);
    }

    EC_Error_Print_Msg ("List with 3 vars move third var up", "OK");

    /* Test for 5 list vars */
    StudentList *stl5 = Student_List (5);
    EC_Error_Print_Msg ("Create new list with 5 list vars", "OK");

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

    EC_Error_Print_Msg ("Assign list 5 variable", "OK");

    /* move fifth var up 3 steps*/
    Student_List_Var_Move_Up (stl5, stl5v5, 2);
    assert (stl5->first == stl5v1);
    assert (stl5->last == stl5v4);
    assert (stl5->first->next->next == stl5v5);
    assert (stl5->first->previous == NULL);
    assert (stl5->last->previous == stl5v3);
    assert (stl5->last->previous->previous == stl5v5);
    assert (stl5->last->next == NULL);

    for_list (stl5)
    {
        printf ("%d %s\n", stl5->var->no, stl5->var->name);
    }

    EC_Error_Print_Msg ("List with 5 vars move last var up 2 steps", "OK");

    /* move fifth var up 5 steps*/
    Student_List_Var_Move_Up (stl5, stl5v4, 4);
    assert (stl5->first == stl5v4);
    assert (stl5->last == stl5v3);
    assert (stl5->first->next == stl5v1);
    assert (stl5->first->previous == NULL);
    assert (stl5->last->previous == stl5v5);
    assert (stl5->last->previous->previous == stl5v2);
    assert (stl5->last->next == NULL);

    for_list (stl5)
    {
        printf ("%d %s\n", stl5->var->no, stl5->var->name);
    }

    EC_Error_Print_Msg ("List with 5 vars move mid var up 4 steps", "OK");

   /* move fifth var up 3 steps for mid vars */
    Student_List_Var_Move_Up (stl5, stl5v5, 2);
    assert (stl5->first == stl5v4);
    assert (stl5->last == stl5v3);
    assert (stl5->first->next == stl5v5);
    assert (stl5->first->previous == NULL);
    assert (stl5->last->previous == stl5v2);
    assert (stl5->last->previous->previous == stl5v1);
    assert (stl5->last->next == NULL);

    for_list (stl5)
    {
        printf ("%d %s\n", stl5->var->no, stl5->var->name);
    }

    EC_Error_Print_Msg ("List with 5 vars move mid var up 2 steps", "OK");

    EC_Error_Print_Msg ("Test_List_Var_Move_Up", "END");
}


void
Test_List_Var_Move_Down ()
{
    EC_Error_Print_Msg ("Test_List_Var_Move_Down: ", "BEGIN");

    struct Stu {
        int no;
        char* name;
    };

    struct Stu students[5] = {{1, "Malith"}, {2, "Geethike"}, {3, "Perera"}, {4, "Rohasha"}, {5, "Malshi"}};

    int i = 0;

    /* Test for 0 list vars */
    StudentList *stl0 = Student_List (0);
    EC_Error_Print_Msg ("Create new list with 0 list vars", "OK");

    stl0->var = stl0->first;

    Student_List_Var_Move_Down (stl0, stl0->var, 1);
    assert (stl0->first == NULL);
    assert (stl0->last == NULL);
    EC_Error_Print_Msg ("List with 0 list vars", "OK");

    /* Test for 1 list var */
    StudentList *stl1 = Student_List (0);
    EC_Error_Print_Msg ("Create new list with 1 list vars", "OK");

    StudentListVar *stl1v = Student_List_Var (stl1);
    stl1v->no = students[0].no;
    stl1v->name = students[0].name;
    EC_Error_Print_Msg ("Assign list 1 variable", "OK");

    Student_List_Var_Move_Down (stl1, stl1v, 1);
    assert (stl1->first == stl1v);
    assert (stl1->last == stl1v);
    EC_Error_Print_Msg ("List with 1 list var", "OK");

    /* Test for 2 list vars */
    StudentList *stl2 = Student_List (2);
    EC_Error_Print_Msg ("Create new list with 2 list vars", "OK");

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

    EC_Error_Print_Msg ("Assign list 2 variable", "OK");

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

    EC_Error_Print_Msg ("List with 2 vars. First var down", "OK");

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

    EC_Error_Print_Msg ("List with 2 vars second var down", "OK");

    /* Test for 3 list vars */
    StudentList *stl3 = Student_List (3);
    EC_Error_Print_Msg ("Create new list with 3 list vars", "OK");

    i = 0;
    for_list (stl3)
    {
        stl3->var->no = students[i].no;
        stl3->var->name = students[i].name;
        i++;
    }
    EC_Error_Print_Msg ("Assign list 3 variable", "OK");

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

    EC_Error_Print_Msg ("List with 3 vars move first var down", "OK");

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

    EC_Error_Print_Msg ("List with 3 vars move second var down", "OK");

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

    EC_Error_Print_Msg ("List with 3 vars move third var down", "OK");

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

    EC_Error_Print_Msg ("List with 3 vars move third var down", "OK");

    /* Test for 5 list vars */
    StudentList *stl5 = Student_List (5);
    EC_Error_Print_Msg ("Create new list with 5 list vars", "OK");

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

    EC_Error_Print_Msg ("Assign list 5 variable", "OK");

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

    EC_Error_Print_Msg ("List with 5 vars move last var down 3 steps", "OK");

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

    EC_Error_Print_Msg ("List with 5 vars move mid var down 4 steps", "OK");

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

    EC_Error_Print_Msg ("List with 5 vars move mid var down 2 steps", "OK");

    EC_Error_Print_Msg ("Test_List_Var_Move_Down", "END");
}


void
Test_List_Var_Delete ()
{
    EC_Error_Print_Msg ("Test_List_Var_Delete: ", "BEGIN");

   /* Test for 0 list vars */
    StudentList *stl0 = Student_List (0);
    EC_Error_Print_Msg ("Create new list with 0 list vars", "OK");

    stl0->var = stl0->first;

    Student_List_Var_Delete (stl0, stl0->var);
    assert (stl0->first == NULL);
    assert (stl0->last == NULL);
    EC_Error_Print_Msg ("List with 0 list vars", "OK");

    /* Test for 1 list var */
    StudentList *stl1 = Student_List (0);
    EC_Error_Print_Msg ("Create new list with 1 list vars", "OK");

    StudentListVar *stl1v = Student_List_Var (stl1);
    stl1v->no = students[0].no;
    stl1v->name = students[0].name;
    EC_Error_Print_Msg ("Assign list 1 variable", "OK");

    Student_List_Var_Delete (stl1, stl1v);
    assert (stl1->first == NULL);
    assert (stl1->last == NULL);
    EC_Error_Print_Msg ("List with 1 list var", "OK");

    /* Test for 2 list vars */
    StudentList *stl2 = Student_List (2);
    EC_Error_Print_Msg ("Create new list with 2 list vars", "OK");

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

    EC_Error_Print_Msg ("Assign list 2 variable", "OK");

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

    EC_Error_Print_Msg ("List with 2 vars. Delete first var", "OK");

    Student_List_Var_Delete (stl2, stl2v2);
    assert (stl2->first == NULL);
    assert (stl2->last == NULL);

    for_list (stl2)
    {
        printf ("%d %s\n", stl2->var->no, stl2->var->name);
    }

    EC_Error_Print_Msg ("List with 2 vars delete second var", "OK");

    StudentListVar *stl2v3 = Student_List_Var (stl2);
    StudentListVar *stl2v4 = Student_List_Var (stl2);

    EC_Error_Print_Msg ("List with 2 vars append 2 new vars", "OK");

    i = 0;
    for_list (stl2)
    {
        stl2->var->no = students[i].no;
        stl2->var->name = students[i].name;
        i++;
    }

    EC_Error_Print_Msg ("Initialize list with 2 vars", "OK");

    for_list (stl2)
    {
        printf ("%d %s\n", stl2->var->no, stl2->var->name);
    }

    EC_Error_Print_Msg ("List with 2 vars. Delete first var", "OK");

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

    EC_Error_Print_Msg ("List with 2 vars. Delete second var", "OK");

    Student_List_Var_Delete (stl2, stl2v3);
    assert (stl2->first == NULL);
    assert (stl2->last == NULL);

    for_list (stl2)
    {
        printf ("%d %s\n", stl2->var->no, stl2->var->name);
    }

    EC_Error_Print_Msg ("List with 2 vars delete last var", "OK");

    /* Test for 3 list vars */
    StudentList *stl3 = Student_List (3);
    EC_Error_Print_Msg ("Create new list with 3 list vars", "OK");

    i = 0;
    for_list (stl3)
    {
        stl3->var->no = students[i].no;
        stl3->var->name = students[i].name;
        i++;
    }
    EC_Error_Print_Msg ("Assign list 3 variable", "OK");

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

    EC_Error_Print_Msg ("List with 3 vars delete first var", "OK");

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

    EC_Error_Print_Msg ("List with 3 vars delete second (last) var", "OK");

    /* Delete third final var */
    Student_List_Var_Delete (stl3, stl3v2);
    assert (stl3->first == NULL);
    assert (stl3->last == NULL);

    for_list (stl3)
    {
        printf ("%d %s\n", stl3->var->no, stl3->var->name);
    }

    EC_Error_Print_Msg ("List with 3 vars delete last var", "OK");

     /*Check is it ok with delete middle var with 3 vars */

    StudentListVar *stl3v4 = Student_List_Var (stl3);
    StudentListVar *stl3v5 = Student_List_Var (stl3);
    StudentListVar *stl3v6 = Student_List_Var (stl3);

    EC_Error_Print_Msg ("List with 3 vars append 3 new vars", "OK");

    i = 0;
    for_list (stl3)
    {
        stl3->var->no = students[i].no;
        stl3->var->name = students[i].name;
        i++;
    }

    EC_Error_Print_Msg ("Initialize list with 3 vars", "OK");

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

    EC_Error_Print_Msg ("List with 3 vars delete mid var", "OK");

    /* Test for 5 list vars */
    StudentList *stl5 = Student_List (5);
    EC_Error_Print_Msg ("Create new list with 5 list vars", "OK");

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

    EC_Error_Print_Msg ("List with 5 vars move mid var down 2 steps", "OK");

    Student_List_Var_Delete (stl5, stl5v4);
    assert (stl5->first->next->next == stl5v5);
    assert (stl5->last == stl5v5);
    assert (stl5->last->previous == stl5v2);

    for_list (stl5)
    {
        printf ("%d %s\n", stl5->var->no, stl5->var->name);
    }

    EC_Error_Print_Msg ("List with 5 vars move mid var down 2 steps", "OK");

    EC_Error_Print_Msg ("Test_List_Var_Delete", "END");
}


void
Test_List_Var_Drop ()
{
    EC_Error_Print_Msg ("Test_List_Var_Drop: ", "BEGIN");
    EC_Error_Print_Msg ("Test_List_Var_Drop", "END");
}


void
Run_List_Test ()
{
    printf ("---------------\n");
    printf ("Test: ec_list.h\n");
    printf ("===============\n");

    /*Test_New_List ();*/
    /*printf ("\n");*/

    /*Test_New_List2 ();*/
    /*printf ("\n");*/

    /*Test_List_Var_Move_Up ();*/
    /*printf ("\n");*/

    /*Test_List_Var_Move_Down ();*/
    /*printf ("\n");*/

    Test_List_Var_Delete ();
    printf ("\n");

    /*Test_List_Var_Drop ();*/
    /*printf ("\n");*/

    /*Test_Append_List ();*/
    /*printf ("\n");*/

    /*Test_Insert_List ();*/
    /*printf ("\n");*/

    /*Test_Replace_List ();*/
    /*printf ("\n");*/

    /*Test_Sort_List ();*/
    /*printf ("\n");*/

    /*Test_List_Copy ();*/
    /*printf ("\n");*/

    /*EC_Error_Print_Msg ("Test: ec_list.h", "PASS");*/
    /*printf ("\n");*/
}
