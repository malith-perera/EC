#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "ec_list_test.h"

Student students[5] = {{1, "Malith"}, {2, "Geethike"}, {3, "Perera"}, {4, "Rohasha"}, {5, "Malshi"}};



void
Test_New_List ()
{
    EC_Test_Print_Title ("Test: New_List", "BEGIN");

    /* Test list with zero list variables */
    EC_Test_Print_Subtitle ("Test: New list with zero variables", "Begin");

    StudentList *stl = Student_List ();
    EC_Test_Print_Msg ("Call: New_List", "OK");

    assert (stl != NULL);
    EC_Test_Print_Msg ("Test: stl != NULL", "OK");
    assert (stl->list == NULL);
    EC_Test_Print_Msg ("Test: stl->list == NULL", "OK");
    assert (stl->last == NULL);
    EC_Test_Print_Msg ("Test: stl->last == NULL", "OK");
    assert (stl->var == NULL);
    EC_Test_Print_Msg ("Test: stl->var == NULL", "OK");

    EC_Test_Print_End_Subtitle ("Test: new list with zero variables", "OK");

    // Test list with three variables
    EC_Test_Print_Subtitle ("Test: New list with three variables", "Begin");

    Student *st1 = Student_Var();
    *st1 = students[0];
    Student *st2 = Student_Var();
    *st2 = students[1];
    Student *st3 = Student_Var();
    *st3 = students[2];

    Student_Append (stl, st1);
    EC_Test_Print_Msg ("Append: st1 to stl", "OK");
    Student_Append (stl, st2);
    EC_Test_Print_Msg ("Append: st2 to stl", "OK");
    Student_Append (stl, st3);
    EC_Test_Print_Msg ("Append: st3 to stl", "OK");

    assert (stl->list->var->no == 1);
    assert (!strcmp (stl->list->var->name, "Malith"));
    EC_Test_Print_Msg ("Test: st1 in stl", "OK");

    assert (stl->list->next->var->no == 2);
    assert (!strcmp (stl->list->next->var->name, "Geethike"));
    EC_Test_Print_Msg ("Test: st2 in stl", "OK");

    assert (stl->list->next->next->var->no == 3);
    assert (!strcmp (stl->list->next->next->var->name, "Perera"));
    EC_Test_Print_Msg ("Test: st3 in stl", "OK");

    assert (stl->list->next->next->next == NULL);
    EC_Test_Print_Msg ("Test: last ->next should be NULL", "OK");

    assert (stl->last->next == NULL);
    EC_Test_Print_Msg ("Text: stl->last->next should be NULL", "OK");

    EC_Test_Print_End_Subtitle ("Test: New list with three variables", "OK");

    EC_Test_Print_Title ("Test: New_List", "END");
}


#if 0

void
Test_List_Append_New ()
{
    /* Test append new list vars */
    EC_Test_Print_Subtitle ("Test new list with three variables", "Begin");

    StudentList *stl3 = Student_List (0);

    StudentListVar *st1 = Student_List_Var (stl3);
    StudentListVar *st2 = Student_List_Var (stl3);
    StudentListVar *st3 = Student_List_Var (stl3);
    EC_Test_Print_Msg ("Create list variables", "OK");

    st1->no = 1;
    st1->name = "Malith";
    st2->no = 2;
    st2->name = "Geethike";
    st3->no = 3;
    st3->name = "Perera";

    EC_Test_Print_Msg ("Assign list variable attributes", "OK");

    assert (stl3->list->no == 1);
    assert (!strcmp (stl3->list->name, "Malith"));

    assert (stl3->list->next->no == 2);
    assert (!strcmp (stl3->list->next->name, "Geethike"));

    assert (stl3->list->next->next->no == 3);
    assert (!strcmp (stl3->list->next->next->name, "Perera"));

    EC_Test_Print_Msg ("List variables exist", "OK");

    assert (stl3->list->next->next->next == NULL);
    assert (stl3->last->next == NULL);
    EC_Test_Print_Msg ("List last next NULL", "OK");

    EC_Test_Print_Title ("Test New_List: ", "END");
}


void
Test_Append_List ()
{
/*    EC_Test_Print_Msg ("Append_List: ", "BEGIN");*/

    /*StudentList *stl = Student_List ();*/

    /*StudentListVar *st1 = Student_List_Var ();*/
    /*st1->no = 1;*/
    /*st1->name = "Malith";*/

    /*StudentListVar *st2 = Student_List_Var ();*/
    /*st2->no = 2;*/
    /*st2->name = "Geethike";*/

    /*Append_Student (stl, st1);*/

    /*assert (stl->list->no == 1);*/
    /*assert (!strcmp (stl->list->name, "Malith")); // strcmp return 0 when equal so ! used*/
    /*assert (stl->list->next == NULL);*/
    /*assert (stl->list->previous == NULL);*/
    /*assert (stl->list->next == NULL);*/
    /*assert (stl->list->previous == NULL);*/
    /*assert (stl->last == st1);*/

    /*EC_Test_Print_Msg ("Append list first variable", "OK");*/

    /*Append_Student (stl, st2);*/

    /*assert (stl->list->no == 1);*/
    /*assert (!strcmp (stl->list->name, "Malith")); // strcmp return 0 when equal so ! used*/
    /*assert (stl->list->previous == NULL);*/
    /*assert (stl->list->next == st2);*/
    /*assert (stl->list->next->no = 2);*/
    /*assert (!strcmp (stl->list->next->name, "Geethike")); // strcmp return 0 when equal so ! used*/
    /*assert (stl->list->next->previous == st1);*/
    /*assert (stl->last == st2);*/
    /*assert (st2->next == NULL);*/
    /*assert (stl->last->next == NULL);*/

    /*EC_Test_Print_Msg ("Append list second variable", "OK");*/

    /*EC_Test_Print_Msg ("Append_List: ", "END");*/
}


void
Test_Insert_List ()
{
    EC_Test_Print_Msg ("Test_Insert_List: ", "BEGIN");

    StudentList *stl = Student_List (0);

    StudentListVar *st1 = Student_List_Var (stl);
    st1->no = 1;
    st1->name = "Malith";

    StudentListVar *st2 = Student_List_Var (stl);
    st2->no = 2;
    st2->name = "Geethike";

    StudentListVar *st3 = Student_List_Var (stl);
    st3->no = 3;
    st3->name = "Perera";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    /*Student_Insert (stl, st3, st1, -1);*/
    /*assert (stl->list->no == 3);*/
    /*assert (!strcmp (stl->list->name, "Perera")); // strcmp return 0 when equal use !*/

    /*EC_Test_Print_Msg ("Insert as fist item", "OK");*/

    /*StudentListVar *st4 = Student_List_Var ();*/
    /*st4->no = 4;*/
    /*st4->name = "Malshi";*/
    /*Insert_Student (stl, st4, st3, 1);*/
    /*assert (stl->list->next->no == 4);*/
    /*assert (!strcmp (stl->list->next->name, "Malshi")); // strcmp return 0 when equal use !*/

    /*EC_Test_Print_Msg ("Insert next to fist item", "OK");*/

    /*StudentListVar *st5 = Student_List_Var ();*/
    /*st5->no = 5;*/
    /*st5->name = "Prisenthi";*/
    /*Insert_Student (stl, st5, st2, -1);*/
    /*assert (stl->last->previous->no == 5);*/
    /*assert (!strcmp (stl->last->previous->name, "Prisenthi")); // strcmp return 0 when equal use !*/

    /*EC_Test_Print_Msg ("Insert before last item", "OK");*/

    /*StudentListVar *st6 = Student_List_Var ();*/
    /*st6->no = 6;*/
    /*st6->name = "Fernando";*/
    /*Insert_Student (stl, st6, st2, 1);*/
    /*assert (stl->last->no == 6);*/
    /*assert (!strcmp (stl->last->name, "Fernando")); // strcmp return 0 when equal use !*/

    /*EC_Test_Print_Msg ("Insert as last item", "OK");*/

    /*StudentListVar *st7 = Student_List_Var ();*/
    /*st7->no = 7;*/
    /*st7->name = "Rohasha";*/
    /*Insert_Student (stl, st7, st4, 1);*/
    /*assert (st4->next->no == 7);*/
    /*assert (!strcmp (st4->next->name, "Rohasha")); // strcmp return 0 when equal use !*/

    /*EC_Test_Print_Msg ("Insert as after mid item", "OK");*/

    /*StudentListVar *st8 = Student_List_Var ();*/
    /*st8->no = 8;*/
    /*st8->name = "Magret";*/
    /*Insert_Student (stl, st8, st4, -1);*/
    /*assert (st4->previous->no == 8);*/
    /*assert (!strcmp (st4->previous->name, "Magret")); // strcmp return 0 when equal use !*/

    /*EC_Test_Print_Msg ("Insert as before mid item", "OK");*/

    /*EC_Test_Print_Msg ("Test_Insert_List: ", "END");*/
}


/* Test_Replace_List function tested only for max 5 vars */

void
Test_Replace_List ()
{
    EC_Test_Print_Msg ("Test_Replace_List: ", "BEGIN");

    /* Test for 0 vars */
    EC_Test_Print_Msg ("Test for empty vars", "Begin");

    /* if list is empty */
    StudentList *stl = Student_List (0);

    StudentListVar *st0 = NULL;
    Student_Replace (stl, st0, st0);
    EC_Test_Print_Msg ("empty listi warn", "OK");

    /* Test for 1 var */
    EC_Test_Print_Msg ("Test for 1 var", "Begin");

    /* create first list var */
    StudentListVar *st1 = Student_List_Var (stl);
    st1->no = 1;
    st1->name = "Malith";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    Student_Replace (stl, st1, st1);
    EC_Test_Print_Msg ("Replace same var warn", "OK");

    /* --------------- */
    /* Test for 2 vars */
    /* --------------- */

    EC_Test_Print_Msg ("Test for 2 vars", "Begin");

    /* create and add second list var */
    StudentListVar *st2 = Student_List_Var (stl);
    st2->no = 2;
    st2->name = "Geethike";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    /* list -> 1, 2 */

    /* Replace left adjecent rep */
    Student_Replace (stl, st1, st2);
    assert (stl->list == st2);
    assert (stl->list->next == NULL);
    assert (stl->last == st2);
    assert (stl->last->previous == NULL);
    EC_Test_Print_Msg ("Replace left adjecent rep by var", "OK");

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    /* create and add new list var (now 2 vars available st2 and st3) */
    st1 = Student_List_Var (stl);
    st1->no = 1;
    st1->name = "Malith";

    /* list -> 2, 1 */

    /* Replace right adjecent rep */
    Student_Replace (stl, st1, st2);
    assert (stl->list == st2);
    assert (stl->list->next == NULL);
    assert (stl->last == st2);
    assert (stl->last->previous == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace right adjecent rep by var", "OK");

    /* --------------- */
    /* Test for 3 vars */
    /* --------------- */

    /* assign new 2 vars now available vars are st2, st1 and st3 */
    st1 = Student_List_Var (stl);
    st1->no = 1;
    st1->name = "Malith";

    StudentListVar *st3 = Student_List_Var (stl);
    st3->no = 3;
    st3->name = "Perera";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    /* list -> 2, 1, 3 */

    /* Replace left adjecent var by mid var */
    Student_Replace (stl, st2, st1);
    assert (stl->list == st1);
    assert (stl->list->next == st3);
    assert (stl->list->next->next == NULL);
    assert (stl->last == st3);
    assert (stl->last->previous == st1);
    assert (stl->last->previous->previous == NULL);

    EC_Test_Print_Msg ("Replace left adjecent var by mid var", "OK");

    st2 = Student_List_Var (stl);
    st2->no = 2;
    st2->name = "Geethike";
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Append new var. Now 3 vars available", "OK");

    /* list -> 1, 3, 2 */

    /* Replace right adjecent var by mid var */
    Student_Replace (stl, st2, st3);
    assert (stl->list == st1);
    assert (stl->list->next == st3);
    assert (stl->list->previous == NULL);
    assert (stl->last->previous == st1);
    assert (stl->last == st3);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace right adjecent var by mid var", "OK");

    /* Append new var */
    st2 = Student_List_Var (stl);
    st2->no = 2;
    st2->name = "Geethike";
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Append new var. Now 3 vars available", "OK");

    /* list -> 1, 3, 2 */

    /* Replace first var by last for 3 vars available */
    Student_Replace (stl, st1, st2);
    assert (stl->list == st2);
    assert (stl->list->next == st3);
    assert (stl->list->previous == NULL);
    assert (stl->last == st3);
    assert (stl->last->previous == st2);
    assert (stl->last->next == NULL);
    assert (stl->last->previous == st2);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace first var by last for 3 vars", "OK");

    /* append new var */
    st1 = Student_List_Var (stl);
    st1->no = 1;
    st1->name = "Malith";
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Append new var. Now 3 vars available", "OK");

    /* list -> 2, 3, 1 */

    /* Replace last var by first for 3 vars available */
    Student_Replace (stl, st1, st2);
    assert (stl->list == st3);
    assert (stl->list->next == st2);
    assert (stl->list->previous == NULL);
    assert (stl->last == st2);
    assert (stl->last->previous == st3);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace last var by first for 3 vars", "OK");

    /* append new var */
    st1 = Student_List_Var (stl);
    st1->no = 1;
    st1->name = "Malith";
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Append new var. Now 3 vars available", "OK");

    /* list -> 3, 2, 1 */

    /* Replace mid by first for 3 vars available */
    Student_Replace (stl, st2, st3);
    assert (stl->list == st3);
    assert (stl->list->next == st1);
    assert (stl->list->previous == NULL);
    assert (stl->last == st1);
    assert (stl->last->previous == st3);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace mid by first var for 3 vars", "OK");

    /* append new var */
    st2 = Student_List_Var (stl);
    st2->no = 2;
    st2->name = "Geethike";
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Append new var. Now 3 vars available", "OK");

    /* list -> 3, 1, 2 */

    /* Replace mid by last for 3 vars available */
    Student_Replace (stl, st1, st2);
    assert (stl->list == st3);
    assert (stl->list->next == st2);
    assert (stl->list->previous == NULL);
    assert (stl->last == st2);
    assert (stl->last->previous == st3);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace mid by last var for 3 vars", "OK");

    /* --------------- */
    /* Test for 4 vars */
    /* --------------- */

    EC_Test_Print_Msg ("Test for 4 vars", "Begin");

    st1 = Student_List_Var (stl);
    st1->no = 1;
    st1->name = "Malith";

    StudentListVar *st4 = Student_List_Var (stl);
    st4->no = 4;
    st4->name = "Rohasha";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    /* list -> 3, 2, 1, 4 */

    EC_Test_Print_Msg ("Append new 2 vars. Now 4 vars available", "OK");

    /* Replace second var by first var */
    Student_Replace (stl, st2, st3);
    assert (stl->list == st3);
    assert (stl->list->next == st1);
    assert (stl->list->next->next == st4);
    assert (stl->list->previous == NULL);
    assert (stl->last == st4);
    assert (stl->last->previous == st1);
    assert (stl->last->previous->previous == st3);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace second var by first var", "OK");

    /* append new var. now 4 vars available */
    st2 = Student_List_Var (stl);
    st2->no = 2;
    st2->name = "Geethike";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 4 vars available", "OK");

    /* list -> 3, 1, 4, 2 */

    /* Replace third var by first var */
    Student_Replace (stl, st4, st3);
    assert (stl->list == st1);
    assert (stl->list->next == st3);
    assert (stl->list->next->next == st2);
    assert (stl->list->previous == NULL);
    assert (stl->last == st2);
    assert (stl->last->previous == st3);
    assert (stl->last->previous->previous == st1);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace third var by first var", "OK");

    /* append new var. 4 vars available */
    st4 = Student_List_Var (stl);
    st4->no = 4;
    st4->name = "Rohasha";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 4 vars available", "OK");

    /* list -> 1, 3, 2, 4 */

    /* Replace fourth var by first var */
    Student_Replace (stl, st4, st1);
    assert (stl->list == st3);
    assert (stl->list->next == st2);
    assert (stl->list->next->next == st1);
    assert (stl->list->previous == NULL);
    assert (stl->last == st1);
    assert (stl->last->previous == st2);
    assert (stl->last->previous->previous == st3);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace forth var by first var ", "OK");

    /* Append new var. 4 vars available */
    st4 = Student_List_Var (stl);
    st4->no = 4;
    st4->name = "Rohasha";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 4 vars available", "OK");

    /* list -> 3, 2, 1, 4 */

    /* Replace 3rd var by second var */
    Student_Replace (stl, st1, st2);
    assert (stl->list == st3);
    assert (stl->list->next == st2);
    assert (stl->list->next->next == st4);
    assert (stl->list->previous == NULL);
    assert (stl->last == st4);
    assert (stl->last->previous == st2);
    assert (stl->last->previous->previous == st3);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace 3rd var by second var", "OK");

    /* Append new var and now 4 vars available */
    st1 = Student_List_Var (stl);
    st1->no = 1;
    st1->name = "Malith";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 4 vars available", "OK");

    /*list -> 3, 2, 4, 1 */

    /* Replace last var by 2nd var */
    Student_Replace (stl, st1, st2);
    assert (stl->list == st3);
    assert (stl->list->next == st4);
    assert (stl->list->next->next == st2);
    assert (stl->list->previous == NULL);
    assert (stl->last == st2);
    assert (stl->last->previous == st4);
    assert (stl->last->previous->previous == st3);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace last var by 2nd var", "OK");

    /*Append new var and now 4 vars available*/
    st1 = Student_List_Var (stl);
    st1->no = 1;
    st1->name = "Malith";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 4 vars available", "OK");

    /* list -> 3, 4, 2, 1 */

    /* Replace last var by 3rd var */
    Student_Replace (stl, st1, st2);
    assert (stl->list == st3);
    assert (stl->list->next == st4);
    assert (stl->list->next->next == st2);
    assert (stl->list->previous == NULL);
    assert (stl->last == st2);
    assert (stl->last->previous == st4);
    assert (stl->last->previous->previous == st3);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace last var by 3rd var", "OK");

    /*Append new var and now 4 vars available*/
    st1 = Student_List_Var (stl);
    st1->no = 1;
    st1->name = "Malith";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 4 vars available", "OK");

    /* list -> 3, 4, 2, 1 */

    /* Replace 3rd var by last var */
    Student_Replace (stl, st2, st1);
    assert (stl->list == st3);
    assert (stl->list->next == st4);
    assert (stl->list->next->next == st1);
    assert (stl->list->previous == NULL);
    assert (stl->last == st1);
    assert (stl->last->previous == st4);
    assert (stl->last->previous->previous == st3);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace 3rd var by last var", "OK");

    /*Append new var and now 4 vars available*/
    st2 = Student_List_Var (stl);
    st2->no = 2;
    st2->name = "Geethike";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 4 vars available", "OK");

    /* list -> 3, 4, 1, 2 */

    /* Replace 2nd var by last var */
    Student_Replace (stl, st4, st2);
    assert (stl->list == st3);
    assert (stl->list->next == st2);
    assert (stl->list->next->next == st1);
    assert (stl->list->previous == NULL);
    assert (stl->last == st1);
    assert (stl->last->previous == st2);
    assert (stl->last->previous->previous == st3);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace 2nd var by last var", "OK");

    /*Append new var and now 4 vars available*/
    st4 = Student_List_Var (stl);
    st4->no = 4;
    st4->name = "Rohasha";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 4 vars available", "OK");

    /* list -> 3, 2, 1, 4 */

    /* Replace first var by last var */
    Student_Replace (stl, st3, st4);
    assert (stl->list == st4);
    assert (stl->list->next == st2);
    assert (stl->list->next->next == st1);
    assert (stl->list->previous == NULL);
    assert (stl->last == st1);
    assert (stl->last->previous == st2);
    assert (stl->last->previous->previous == st4);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace first var by last var", "OK");

    /*Append new var and now 4 vars available*/
    st3 = Student_List_Var (stl);
    st3->no = 3;
    st3->name = "Geethike";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 4 vars available", "OK");

    /* list -> 4, 2, 1, 3 */

    /* Replace 2nd var by 3rd var */
    Student_Replace (stl, st2, st1);
    assert (stl->list == st4);
    assert (stl->list->next == st1);
    assert (stl->list->next->next == st3);
    assert (stl->list->previous == NULL);
    assert (stl->last == st3);
    assert (stl->last->previous == st1);
    assert (stl->last->previous->previous == st4);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace first var by last var", "OK");

    /*Append new var and now 4 vars available*/
    st2 = Student_List_Var (stl);
    st2->no = 2;
    st2->name = "Geethike";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 4 vars available", "OK");

    /* list -> 4, 1, 3, 2 */

    /* Replace first var by 3rd var */
    Student_Replace (stl, st4, st3);
    assert (stl->list == st3);
    assert (stl->list->next == st1);
    assert (stl->list->next->next == st2);
    assert (stl->list->previous == NULL);
    assert (stl->last == st2);
    assert (stl->last->previous == st1);
    assert (stl->last->previous->previous == st3);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace first var by 3rd var", "OK");

    /*Append new var and now 4 vars available*/
    st4 = Student_List_Var (stl);
    st4->no = 4;
    st4->name = "Rohasha";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 4 vars available", "OK");

    /* list -> 3, 1, 2, 4 */

    /* Replace first var by 2nd var */
    Student_Replace (stl, st3, st1);
    assert (stl->list == st1);
    assert (stl->list->next == st2);
    assert (stl->list->next->next == st4);
    assert (stl->list->previous == NULL);
    assert (stl->last == st4);
    assert (stl->last->previous == st2);
    assert (stl->last->previous->previous == st1);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace first var by 2nd var", "OK");


    /* --------------- */
    /* Test for 5 vars */
    /* --------------- */

    EC_Test_Print_Msg ("Test for 4 vars", "Begin");

    st3 = Student_List_Var (stl);
    st3->no = 3;
    st3->name = "Perera";

    StudentListVar *st5 = Student_List_Var (stl);
    st5->no = 5;
    st5->name = "Malshi";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    /* list -> 1, 2, 4, 3, 5 */

    EC_Test_Print_Msg ("Append new 2 vars. Now 5 vars available", "OK");

    /* Replace second var by first var */
    Student_Replace (stl, st2, st1);
    assert (stl->list == st1);
    assert (stl->list->next == st4);
    assert (stl->list->next->next == st3);
    assert (stl->list->next->next->next == st5);
    assert (stl->list->previous == NULL);
    assert (stl->last == st5);
    assert (stl->last->previous == st3);
    assert (stl->last->previous->previous == st4);
    assert (stl->last->previous->previous->previous == st1);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace second var by first var", "OK");

    /* append new var. now 5 vars available */
    st2 = Student_List_Var (stl);
    st2->no = 2;
    st2->name = "Geethike";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 4 vars available", "OK");

    /* list -> 1, 4, 3, 5, 2 */

    /*Replace third var by first var */
    Student_Replace (stl, st3, st1);
    assert (stl->list == st4);
    assert (stl->list->next == st1);
    assert (stl->list->next->next == st5);
    assert (stl->list->next->next->next == st2);
    assert (stl->list->previous == NULL);
    assert (stl->last == st2);
    assert (stl->last->previous == st5);
    assert (stl->last->previous->previous == st1);
    assert (stl->last->previous->previous->previous == st4);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace third var by first var", "OK");

    /* append new var. 5 vars available */
    st3 = Student_List_Var (stl);
    st3->no = 3;
    st3->name = "Perera";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 5 vars available", "OK");

    /* list -> 4, 1, 5, 2, 3 */

    /* Replace fourth var by first var */
    Student_Replace (stl, st2, st4);
    assert (stl->list == st1);
    assert (stl->list->next == st5);
    assert (stl->list->next->next == st4);
    assert (stl->list->next->next->next == st3);
    assert (stl->list->previous == NULL);
    assert (stl->last == st3);
    assert (stl->last->previous == st4);
    assert (stl->last->previous->previous == st5);
    assert (stl->last->previous->previous->previous == st1);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace forth var by first var ", "OK");

    /* Append new var. 5 vars available */
    st2 = Student_List_Var (stl);
    st2->no = 2;
    st2->name = "Perera";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 5 vars available", "OK");

    /* list -> 1, 5, 4, 3, 2 */

    /* Replace fifth var by first var */
    Student_Replace (stl, st2, st1);
    assert (stl->list == st5);
    assert (stl->list->next == st4);
    assert (stl->list->next->next == st3);
    assert (stl->list->next->next->next == st1);
    assert (stl->list->previous == NULL);
    assert (stl->last == st1);
    assert (stl->last->previous == st3);
    assert (stl->last->previous->previous == st4);
    assert (stl->last->previous->previous->previous == st5);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace forth var by first var ", "OK");

   /* Append new var. 5 vars available */
    st2 = Student_List_Var (stl);
    st2->no = 2;
    st2->name = "Geethike";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 5 vars available", "OK");

    /* list -> 5, 4, 3, 1, 2 */

    /* Replace 3rd var by 2nd var */
    Student_Replace (stl, st3, st4);
    assert (stl->list == st5);
    assert (stl->list->next == st4);
    assert (stl->list->next->next == st1);
    assert (stl->list->next->next->next == st2);
    assert (stl->list->previous == NULL);
    assert (stl->last == st2);
    assert (stl->last->previous == st1);
    assert (stl->last->previous->previous == st4);
    assert (stl->last->previous->previous->previous == st5);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace 3rd var by 2nd var ", "OK");

    /* Append new var. 5 vars available */
    st3 = Student_List_Var (stl);
    st3->no = 3;
    st3->name = "Perera";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 5 vars available", "OK");

    /* list -> 5, 4, 1, 2, 3 */

    /* Replace 4th var by 2nd var */
    Student_Replace (stl, st2, st4);
    assert (stl->list == st5);
    assert (stl->list->next == st1);
    assert (stl->list->next->next == st4);
    assert (stl->list->next->next->next == st3);
    assert (stl->list->previous == NULL);
    assert (stl->last == st3);
    assert (stl->last->previous == st4);
    assert (stl->last->previous->previous == st1);
    assert (stl->last->previous->previous->previous == st5);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace 3rd var by 2nd var ", "OK");

    /* Append new var. 5 vars available */
    st2 = Student_List_Var (stl);
    st2->no = 2;
    st2->name = "Geethike";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 5 vars available", "OK");

    /* list -> 5, 1, 4, 3, 2 */

    /* Replace last var by 2nd var */
    Student_Replace (stl, st2, st1);
    assert (stl->list == st5);
    assert (stl->list->next == st4);
    assert (stl->list->next->next == st3);
    assert (stl->list->next->next->next == st1);
    assert (stl->list->previous == NULL);
    assert (stl->last == st1);
    assert (stl->last->previous == st3);
    assert (stl->last->previous->previous == st4);
    assert (stl->last->previous->previous->previous == st5);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace last var by 2nd var ", "OK");

    /* Append new var. 5 vars available */
    st2 = Student_List_Var (stl);
    st2->no = 2;
    st2->name = "Geethike";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 5 vars available", "OK");

    /* list -> 5, 4, 3, 1, 2 */

     /*Replace 4th var by 3rd var */
    Student_Replace (stl, st1, st3);
    assert (stl->list == st5);
    assert (stl->list->next == st4);
    assert (stl->list->next->next == st3);
    assert (stl->list->next->next->next == st2);
    assert (stl->list->previous == NULL);
    assert (stl->last == st2);
    assert (stl->last->previous == st3);
    assert (stl->last->previous->previous == st4);
    assert (stl->last->previous->previous->previous == st5);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace last var by 3rd var ", "OK");

    /* Append new var. 5 vars available */
    st1 = Student_List_Var (stl);
    st1->no = 1;
    st1->name = "Malith";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 5 vars available", "OK");

    /* list -> 5, 4, 3, 2, 1 */

     /*Replace last var by 3rd var */
    Student_Replace (stl, st1, st3);
    assert (stl->list == st5);
    assert (stl->list->next == st4);
    assert (stl->list->next->next == st2);
    assert (stl->list->next->next->next == st3);
    assert (stl->list->previous == NULL);
    assert (stl->last == st3);
    assert (stl->last->previous == st2);
    assert (stl->last->previous->previous == st4);
    assert (stl->last->previous->previous->previous == st5);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace last var by 3rd var ", "OK");

    /* Append new var. 5 vars available */
    st1 = Student_List_Var (stl);
    st1->no = 1;
    st1->name = "Malith";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 5 vars available", "OK");

    /* list -> 5, 4, 2, 3, 1 */

     /*Replace last var by 4th var */
    Student_Replace (stl, st1, st3);
    assert (stl->list == st5);
    assert (stl->list->next == st4);
    assert (stl->list->next->next == st2);
    assert (stl->list->next->next->next == st3);
    assert (stl->list->previous == NULL);
    assert (stl->last == st3);
    assert (stl->last->previous == st2);
    assert (stl->last->previous->previous == st4);
    assert (stl->last->previous->previous->previous == st5);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace last var by 4th var ", "OK");

    /* Append new var. 5 vars available */
    st1 = Student_List_Var (stl);
    st1->no = 1;
    st1->name = "Malith";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 5 vars available", "OK");

    /* list -> 5, 4, 2, 3, 1 */

     /*Replace 4th var by last var */
    Student_Replace (stl, st3, st1);
    assert (stl->list == st5);
    assert (stl->list->next == st4);
    assert (stl->list->next->next == st2);
    assert (stl->list->next->next->next == st1);
    assert (stl->list->previous == NULL);
    assert (stl->last == st1);
    assert (stl->last->previous == st2);
    assert (stl->last->previous->previous == st4);
    assert (stl->last->previous->previous->previous == st5);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace 4th var by last var ", "OK");

    /* Append new var. 5 vars available */
    st3 = Student_List_Var (stl);
    st3->no = 3;
    st3->name = "Perera";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 5 vars available", "OK");

    /* list -> 5, 4, 2, 1, 3 */

     /* Replace 3rd var by last var */
    Student_Replace (stl, st2, st3);
    assert (stl->list == st5);
    assert (stl->list->next == st4);
    assert (stl->list->next->next == st3);
    assert (stl->list->next->next->next == st1);
    assert (stl->list->previous == NULL);
    assert (stl->last == st1);
    assert (stl->last->previous == st3);
    assert (stl->last->previous->previous == st4);
    assert (stl->last->previous->previous->previous == st5);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace 3rd var by last var ", "OK");

    /* Append new var. 5 vars available */
    st2 = Student_List_Var (stl);
    st2->no = 2;
    st2->name = "Geethike";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 5 vars available", "OK");

    /* list -> 5, 4, 3, 1, 2 */

     /* Replace 2nd var by last var */
    Student_Replace (stl, st4, st2);
    assert (stl->list == st5);
    assert (stl->list->next == st2);
    assert (stl->list->next->next == st3);
    assert (stl->list->next->next->next == st1);
    assert (stl->list->previous == NULL);
    assert (stl->last == st1);
    assert (stl->last->previous == st3);
    assert (stl->last->previous->previous == st2);
    assert (stl->last->previous->previous->previous == st5);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace 2nd var by last var ", "OK");

    /* Append new var. 5 vars available */
    st4 = Student_List_Var (stl);
    st4->no = 4;
    st4->name = "Geethike";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 5 vars available", "OK");

    /* list -> 5, 2, 3, 1, 4 */

     /* Replace first var by last var */
    Student_Replace (stl, st5, st4);
    assert (stl->list == st4);
    assert (stl->list->next == st2);
    assert (stl->list->next->next == st3);
    assert (stl->list->next->next->next == st1);
    assert (stl->list->previous == NULL);
    assert (stl->last == st1);
    assert (stl->last->previous == st3);
    assert (stl->last->previous->previous == st2);
    assert (stl->last->previous->previous->previous == st4);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace first var by last var ", "OK");

    /* Append new var. 5 vars available */
    st5 = Student_List_Var (stl);
    st5->no = 5;
    st5->name = "Malshi";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 5 vars available", "OK");

    /* list -> 4, 2, 3, 1, 5 */

     /* Replace 3rd var by 4th var */
    Student_Replace (stl, st3, st1);
    assert (stl->list == st4);
    assert (stl->list->next == st2);
    assert (stl->list->next->next == st1);
    assert (stl->list->next->next->next == st5);
    assert (stl->list->previous == NULL);
    assert (stl->last == st5);
    assert (stl->last->previous == st1);
    assert (stl->last->previous->previous == st2);
    assert (stl->last->previous->previous->previous == st4);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace 3rd var by 4th var ", "OK");

    /* Append new var. 5 vars available */
    st3 = Student_List_Var (stl);
    st3->no = 3;
    st3->name = "Perera";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 5 vars available", "OK");

    /* list -> 4, 2, 1, 5, 3 */

     /* Replace 2nd var by 4th var */
    Student_Replace (stl, st2, st5);
    assert (stl->list == st4);
    assert (stl->list->next == st5);
    assert (stl->list->next->next == st1);
    assert (stl->list->next->next->next == st3);
    assert (stl->list->previous == NULL);
    assert (stl->last == st3);
    assert (stl->last->previous == st1);
    assert (stl->last->previous->previous == st5);
    assert (stl->last->previous->previous->previous == st4);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace 2nd var by 4th var ", "OK");

    /* Append new var. 5 vars available */
    st2 = Student_List_Var (stl);
    st2->no = 2;
    st2->name = "Geethike";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 5 vars available", "OK");

    /* list -> 4, 5, 1, 3, 2 */

     /* Replace first var by 4th var */
    Student_Replace (stl, st4, st3);
    assert (stl->list == st3);
    assert (stl->list->next == st5);
    assert (stl->list->next->next == st1);
    assert (stl->list->next->next->next == st2);
    assert (stl->list->previous == NULL);
    assert (stl->last == st2);
    assert (stl->last->previous == st1);
    assert (stl->last->previous->previous == st5);
    assert (stl->last->previous->previous->previous == st3);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace first var by 4th var ", "OK");

    /* Append new var. 5 vars available */
    st4 = Student_List_Var (stl);
    st4->no = 4;
    st4->name = "Rohasha";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 5 vars available", "OK");

    /* list -> 3, 5, 1, 2, 4 */

     /* Replace 2nd var by 3rd var */
    Student_Replace (stl, st5, st1);
    assert (stl->list == st3);
    assert (stl->list->next == st1);
    assert (stl->list->next->next == st2);
    assert (stl->list->next->next->next == st4);
    assert (stl->list->previous == NULL);
    assert (stl->last == st4);
    assert (stl->last->previous == st2);
    assert (stl->last->previous->previous == st1);
    assert (stl->last->previous->previous->previous == st3);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace 2nd var by 3rd var ", "OK");

    /* Append new var. 5 vars available */
    st5 = Student_List_Var (stl);
    st5->no = 5;
    st5->name = "Malshi";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 5 vars available", "OK");

    /* list -> 3, 1, 2, 4, 5 */

     /* Replace first var by 3rd var */
    Student_Replace (stl, st3, st2);
    assert (stl->list == st2);
    assert (stl->list->next == st1);
    assert (stl->list->next->next == st4);
    assert (stl->list->next->next->next == st5);
    assert (stl->list->previous == NULL);
    assert (stl->last == st5);
    assert (stl->last->previous == st4);
    assert (stl->last->previous->previous == st1);
    assert (stl->last->previous->previous->previous == st2);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace first var by 3rd var ", "OK");

    /* Append new var. 5 vars available */
    st3 = Student_List_Var (stl);
    st3->no = 3;
    st3->name = "Perera";

    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }

    EC_Test_Print_Msg ("Append new 1 var. Now 5 vars available", "OK");

    /* list -> 2, 1, 4, 5, 3 */

     /* Replace first var by 2nd var */
    Student_Replace (stl, st2, st1);
    assert (stl->list == st1);
    assert (stl->list->next == st4);
    assert (stl->list->next->next == st5);
    assert (stl->list->next->next->next == st3);
    assert (stl->list->previous == NULL);
    assert (stl->last == st3);
    assert (stl->last->previous == st5);
    assert (stl->last->previous->previous == st4);
    assert (stl->last->previous->previous->previous == st1);
    assert (stl->last->next == NULL);
    for_list (stl)
    {
        printf ("%d %s\n", stl->var->no, stl->var->name);
    }
    EC_Test_Print_Msg ("Replace first var by 2nd var ", "OK");

    EC_Test_Print_Msg ("Test_Replace_List: ", "END");
}


void
Test_Sort_List ()
{
/*    EC_Test_Print_Msg ("Test_Sort_List: ", "BEGIN");*/

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

    /*EC_Test_Print_Msg ("Test_Sort_List: ", "END");*/
}


void
Test_List_Copy ()
{
/*    EC_Test_Print_Msg ("Test_List_Copy: ", "BEGIN");*/

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

    /*assert (stl2->list->no == 1);*/
    /*assert (strcmp(stl2->list->name ,"Malith") == 0 );*/

    /*assert (stl2->list->next->no == 2);*/
    /*assert (strcmp(stl2->list->next->name, "Geethike") == 0 );*/

    /*EC_Test_Print_Msg ("List Copy Variables", "OK");*/

    /*st1->no = 3;*/
    /*st1->name = "Malshi";*/
    /*assert (stl2->list->no != 3);*/
    /*assert (strcmp(stl2->list->name ,"Malshi") != 0 );*/

    /*st2->no = 4;*/
    /*st2->name = "Prisenthi";*/
    /*assert (stl1->list->no != 4);*/
    /*assert (strcmp(stl1->list->name ,"Prisenthi") != 0 );*/

    /*EC_Test_Print_Msg ("Copied list do not affect other list", "OK");*/

    /*EC_Test_Print_Msg ("Test_List_Copy: ", "END");*/
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
    EC_Test_Print_Msg ("Test_List_Var_Move_Up: ", "BEGIN");


    int i = 0;

    /* Test for 0 list vars */
    StudentList *stl0 = Student_List (0);
    EC_Test_Print_Msg ("Create new list with 0 list vars", "OK");

    stl0->var = stl0->list;

    Student_List_Var_Move_Up (stl0, stl0->var, 1);
    assert (stl0->list == NULL);
    assert (stl0->last == NULL);
    EC_Test_Print_Msg ("List with 0 list vars", "OK");

    /* Test for 1 list var */
    StudentList *stl1 = Student_List (0);
    EC_Test_Print_Msg ("Create new list with 1 list vars", "OK");

    StudentListVar *stl1v = Student_List_Var (stl1);
    stl1v->no = students[0].no;
    stl1v->name = students[0].name;
    stl1->var = stl1->list;
    EC_Test_Print_Msg ("Assign list 1 variable", "OK");

    Student_List_Var_Move_Up (stl1, stl1->var, 1);
    assert (stl1->list == stl1v);
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
    stl2->var = stl2->list;
    StudentListVar *stl2v1 = stl2->list;
    StudentListVar *stl2v2 = stl2->list->next;

    Student_List_Var_Move_Up (stl2, stl2v1, 1);
    assert (stl2->list == stl2v1);
    assert (stl2->last == stl2v2);
    assert (stl2->list->next == stl2v2);
    assert (stl2->list->previous == NULL);
    assert (stl2->last->previous == stl2v1);
    assert (stl2->last->next == NULL);
    EC_Test_Print_Msg ("List with 2 vars. First var up", "OK");

    Student_List_Var_Move_Up (stl2, stl2v2, 1);
    assert (stl2->list == stl2v2);
    assert (stl2->last == stl2v1);
    assert (stl2->list->next == stl2v1);
    assert (stl2->list->previous == NULL);
    assert (stl2->last->previous == stl2v2);
    assert (stl2->last->next == NULL);

    for_list (stl2)
    {
        printf ("%d %s\n", stl2->var->no, stl2->var->name);
    }

    EC_Test_Print_Msg ("List with 3 vars move first var up", "OK");

    EC_Test_Print_Msg ("List with 2 vars second var up", "OK");

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
    stl3->var = stl3->list;
    StudentListVar *stl3v1 = stl3->list;
    StudentListVar *stl3v2 = stl3->list->next;
    StudentListVar *stl3v3 = stl3->list->next->next;

    /* move first var */
    Student_List_Var_Move_Up (stl3, stl3v1, 1);
    assert (stl3->list == stl3v1);
    assert (stl3->last == stl3v3);
    assert (stl3->list->next == stl3v2);
    assert (stl3->list->previous == NULL);
    assert (stl3->last->previous == stl3v2);
    assert (stl3->last->next == NULL);

    for_list (stl3)
    {
        printf ("%d %s\n", stl3->var->no, stl3->var->name);
    }

    EC_Test_Print_Msg ("List with 3 vars move first var up", "OK");

    /* move second var up */
    Student_List_Var_Move_Up (stl3, stl3v2, 1);
    assert (stl3->list == stl3v2);
    assert (stl3->last == stl3v3);
    assert (stl3->list->next == stl3v1);
    assert (stl3->list->next->previous == stl3v2);
    assert (stl3->list->next->next == stl3v3);
    assert (stl3->list->previous == NULL);
    assert (stl3->last->previous == stl3v1);
    assert (stl3->last->next == NULL);

    for_list (stl3)
    {
        printf ("%d %s\n", stl3->var->no, stl3->var->name);
    }

    EC_Test_Print_Msg ("List with 3 vars move second var up", "OK");

    /* move third var up 1 step*/
    Student_List_Var_Move_Up (stl3, stl3v3, 1);
    assert (stl3->list == stl3v2);
    assert (stl3->list->next == stl3v3);
    assert (stl3->list->previous == NULL);
    assert (stl3->last == stl3v1);
    assert (stl3->last->previous == stl3v3);
    assert (stl3->last->next == NULL);

    for_list (stl3)
    {
        printf ("%d %s\n", stl3->var->no, stl3->var->name);
    }

    EC_Test_Print_Msg ("List with 3 vars move third var up", "OK");

    /* move third var up 2 steps*/
    Student_List_Var_Move_Up (stl3, stl3v1, 2);
    assert (stl3->list == stl3v1);
    assert (stl3->last == stl3v3);
    assert (stl3->list->next == stl3v2);
    assert (stl3->list->previous == NULL);
    assert (stl3->last->previous == stl3v2);
    assert (stl3->last->previous->previous == stl3v1);
    assert (stl3->last->next == NULL);

    for_list (stl3)
    {
        printf ("%d %s\n", stl3->var->no, stl3->var->name);
    }

    EC_Test_Print_Msg ("List with 3 vars move third var up", "OK");

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
    stl5->var = stl5->list;
    StudentListVar *stl5v1 = stl5->list;
    StudentListVar *stl5v2 = stl5->list->next;
    StudentListVar *stl5v3 = stl5->list->next->next;
    StudentListVar *stl5v4 = stl5->list->next->next->next;
    StudentListVar *stl5v5 = stl5->list->next->next->next->next;

    for_list (stl5)
    {
        printf ("%d %s\n", stl5->var->no, stl5->var->name);
    }

    EC_Test_Print_Msg ("Assign list 5 variable", "OK");

    /* move fifth var up 3 steps*/
    Student_List_Var_Move_Up (stl5, stl5v5, 2);
    assert (stl5->list == stl5v1);
    assert (stl5->last == stl5v4);
    assert (stl5->list->next->next == stl5v5);
    assert (stl5->list->previous == NULL);
    assert (stl5->last->previous == stl5v3);
    assert (stl5->last->previous->previous == stl5v5);
    assert (stl5->last->next == NULL);

    for_list (stl5)
    {
        printf ("%d %s\n", stl5->var->no, stl5->var->name);
    }

    EC_Test_Print_Msg ("List with 5 vars move last var up 2 steps", "OK");

    /* move fifth var up 5 steps*/
    Student_List_Var_Move_Up (stl5, stl5v4, 4);
    assert (stl5->list == stl5v4);
    assert (stl5->last == stl5v3);
    assert (stl5->list->next == stl5v1);
    assert (stl5->list->previous == NULL);
    assert (stl5->last->previous == stl5v5);
    assert (stl5->last->previous->previous == stl5v2);
    assert (stl5->last->next == NULL);

    for_list (stl5)
    {
        printf ("%d %s\n", stl5->var->no, stl5->var->name);
    }

    EC_Test_Print_Msg ("List with 5 vars move mid var up 4 steps", "OK");

   /* move fifth var up 3 steps for mid vars */
    Student_List_Var_Move_Up (stl5, stl5v5, 2);
    assert (stl5->list == stl5v4);
    assert (stl5->last == stl5v3);
    assert (stl5->list->next == stl5v5);
    assert (stl5->list->previous == NULL);
    assert (stl5->last->previous == stl5v2);
    assert (stl5->last->previous->previous == stl5v1);
    assert (stl5->last->next == NULL);

    for_list (stl5)
    {
        printf ("%d %s\n", stl5->var->no, stl5->var->name);
    }

    EC_Test_Print_Msg ("List with 5 vars move mid var up 2 steps", "OK");

    EC_Test_Print_Msg ("Test_List_Var_Move_Up", "END");
}


void
Test_List_Var_Move_Down ()
{
    EC_Test_Print_Msg ("Test_List_Var_Move_Down: ", "BEGIN");

    struct Stu {
        int no;
        char* name;
    };

    struct Stu students[5] = {{1, "Malith"}, {2, "Geethike"}, {3, "Perera"}, {4, "Rohasha"}, {5, "Malshi"}};

    int i = 0;

    /* Test for 0 list vars */
    StudentList *stl0 = Student_List (0);
    EC_Test_Print_Msg ("Create new list with 0 list vars", "OK");

    stl0->var = stl0->list;

    Student_List_Var_Move_Down (stl0, stl0->var, 1);
    assert (stl0->list == NULL);
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
    assert (stl1->list == stl1v);
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
    stl2->var = stl2->list;
    StudentListVar *stl2v1 = stl2->list;
    StudentListVar *stl2v2 = stl2->list->next;

    Student_List_Var_Move_Down (stl2, stl2v1, 1);
    assert (stl2->list == stl2v2);
    assert (stl2->last == stl2v1);
    assert (stl2->list->next == stl2v1);
    assert (stl2->list->previous == NULL);
    assert (stl2->last->previous == stl2v2);
    assert (stl2->last->next == NULL);

    for_list (stl2)
    {
        printf ("%d %s\n", stl2->var->no, stl2->var->name);
    }

    EC_Test_Print_Msg ("List with 2 vars. First var down", "OK");

    Student_List_Var_Move_Down (stl2, stl2v1, 1);
    assert (stl2->list == stl2v2);
    assert (stl2->last == stl2v1);
    assert (stl2->list->next == stl2v1);
    assert (stl2->list->previous == NULL);
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
    stl3->var = stl3->list;
    StudentListVar *stl3v1 = stl3->list;
    StudentListVar *stl3v2 = stl3->list->next;
    StudentListVar *stl3v3 = stl3->list->next->next;

    /* move first var */
    Student_List_Var_Move_Down (stl3, stl3v1, 1);
    assert (stl3->list == stl3v2);
    assert (stl3->list->next == stl3v1);
    assert (stl3->list->previous == NULL);
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
    assert (stl3->list == stl3v2);
    assert (stl3->list->next == stl3v3);
    assert (stl3->list->next->next == stl3v1);
    assert (stl3->list->previous == NULL);
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
    assert (stl3->list == stl3v2);
    assert (stl3->last == stl3v1);
    assert (stl3->list->next == stl3v3);
    assert (stl3->list->previous == NULL);
    assert (stl3->last->previous == stl3v3);
    assert (stl3->last->next == NULL);

    for_list (stl3)
    {
        printf ("%d %s\n", stl3->var->no, stl3->var->name);
    }

    EC_Test_Print_Msg ("List with 3 vars move third var down", "OK");

    /* move first var down 2 steps*/
    Student_List_Var_Move_Down (stl3, stl3v2, 2);
    assert (stl3->list == stl3v3);
    assert (stl3->list->next == stl3v1);
    assert (stl3->list->previous == NULL);
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
    stl5->var = stl5->list;
    StudentListVar *stl5v1 = stl5->list;
    StudentListVar *stl5v2 = stl5->list->next;
    StudentListVar *stl5v3 = stl5->list->next->next;
    StudentListVar *stl5v4 = stl5->list->next->next->next;
    StudentListVar *stl5v5 = stl5->list->next->next->next->next;

    for_list (stl5)
    {
        printf ("%d %s\n", stl5->var->no, stl5->var->name);
    }

    EC_Test_Print_Msg ("Assign list 5 variable", "OK");

    /* move first var down 3 steps*/
    Student_List_Var_Move_Down (stl5, stl5v1, 3);
    assert (stl5->list == stl5v2);
    assert (stl5->last == stl5v5);
    assert (stl5->list->next->next == stl5v4);
    assert (stl5->list->previous == NULL);
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
    assert (stl5->list == stl5v3);
    assert (stl5->last == stl5v2);
    assert (stl5->list->next == stl5v4);
    assert (stl5->list->previous == NULL);
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
    assert (stl5->list == stl5v3);
    assert (stl5->last == stl5v2);
    assert (stl5->list->next == stl5v1);
    assert (stl5->list->previous == NULL);
    assert (stl5->last->previous == stl5v4);
    assert (stl5->last->previous->previous == stl5v5);
    assert (stl5->last->next == NULL);

    for_list (stl5)
    {
        printf ("%d %s\n", stl5->var->no, stl5->var->name);
    }

    EC_Test_Print_Msg ("List with 5 vars move mid var down 2 steps", "OK");

    EC_Test_Print_Msg ("Test_List_Var_Move_Down", "END");
}


void
Test_List_Var_Delete ()
{
    EC_Test_Print_Msg ("Test_List_Var_Delete: ", "BEGIN");

   /* Test for 0 list vars */
    StudentList *stl0 = Student_List (0);
    EC_Test_Print_Msg ("Create new list with 0 list vars", "OK");

    stl0->var = stl0->list;

    Student_List_Var_Delete (stl0, stl0->var);
    assert (stl0->list == NULL);
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
    assert (stl1->list == NULL);
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
    StudentListVar *stl2v1 = stl2->list;
    StudentListVar *stl2v2 = stl2->list->next;

    Student_List_Var_Delete (stl2, stl2v1);
    assert (stl2->list == stl2v2);
    assert (stl2->last == stl2v2);
    assert (stl2->list->next == NULL);
    assert (stl2->list->previous == NULL);
    assert (stl2->last->previous == NULL);
    assert (stl2->last->next == NULL);

    for_list (stl2)
    {
        printf ("%d %s\n", stl2->var->no, stl2->var->name);
    }

    EC_Test_Print_Msg ("List with 2 vars. Delete first var", "OK");

    Student_List_Var_Delete (stl2, stl2v2);
    assert (stl2->list == NULL);
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
    assert (stl2->list == stl2v3);
    assert (stl2->last == stl2v3);
    assert (stl2->list->next == NULL);
    assert (stl2->list->previous == NULL);
    assert (stl2->last->previous == NULL);
    assert (stl2->last->next == NULL);

    for_list (stl2)
    {
        printf ("%d %s\n", stl2->var->no, stl2->var->name);
    }

    EC_Test_Print_Msg ("List with 2 vars. Delete second var", "OK");

    Student_List_Var_Delete (stl2, stl2v3);
    assert (stl2->list == NULL);
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
    stl3->var = stl3->list;
    StudentListVar *stl3v1 = stl3->list;
    StudentListVar *stl3v2 = stl3->list->next;
    StudentListVar *stl3v3 = stl3->list->next->next;

    /* Delete first var */
    Student_List_Var_Delete (stl3, stl3v1);
    assert (stl3->list == stl3v2);
    assert (stl3->list->next == stl3v3);
    assert (stl3->list->previous == NULL);
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
    assert (stl3->list == stl3v2);
    assert (stl3->list->next == NULL);
    assert (stl3->list->previous == NULL);
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
    assert (stl3->list == NULL);
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
    assert (stl3->list == stl3v4);
    assert (stl3->list->next == stl3v6);
    assert (stl3->list->previous == NULL);
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
    stl5->var = stl5->list;
    StudentListVar *stl5v1 = stl5->list;
    StudentListVar *stl5v2 = stl5->list->next;
    StudentListVar *stl5v3 = stl5->list->next->next;
    StudentListVar *stl5v4 = stl5->list->next->next->next;
    StudentListVar *stl5v5 = stl5->list->next->next->next->next;

    Student_List_Var_Delete (stl5, stl5v3);
    assert (stl5->list->next->next == stl5v4);
    assert (stl5->last->previous->previous == stl5v2);

    for_list (stl5)
    {
        printf ("%d %s\n", stl5->var->no, stl5->var->name);
    }

    EC_Test_Print_Msg ("List with 5 vars move mid var down 2 steps", "OK");

    Student_List_Var_Delete (stl5, stl5v4);
    assert (stl5->list->next->next == stl5v5);
    assert (stl5->last == stl5v5);
    assert (stl5->last->previous == stl5v2);

    for_list (stl5)
    {
        printf ("%d %s\n", stl5->var->no, stl5->var->name);
    }

    EC_Test_Print_Msg ("List with 5 vars move mid var down 2 steps", "OK");

    EC_Test_Print_Msg ("Test_List_Var_Delete", "END");
}


void
Test_List_Change_Var ()
{
}


void
Test_List_Exchange_Var ()
{
}


void
Test_List_Var_Drop ()
{
    EC_Test_Print_Msg ("Test_List_Var_Drop: ", "BEGIN");
    EC_Test_Print_Msg ("Test_List_Var_Drop", "END");
}

#endif 

void
Run_List_Test ()
{
    printf ("---------------\n");
    printf ("Test: ec_list.h\n");
    printf ("===============\n");

    Test_New_List ();
    printf ("\n");

/*    Test_List_Var_Move_Up ();*/
    /*printf ("\n");*/

    /*Test_List_Var_Move_Down ();*/
    /*printf ("\n");*/

    /*Test_List_Var_Delete ();*/
    /*printf ("\n");*/

    /*Test_Append_List ();*/
    /*printf ("\n");*/

    /*Test_Insert_List ();*/
    /*printf ("\n");*/

    /*Test_Replace_List ();*/
    /*printf ("\n");*/

    /*Test_List_Var_Drop ();*/
    /*printf ("\n");*/

    /*Test_Sort_List ();*/
    /*printf ("\n");*/

    /*Test_List_Copy ();*/
    /*printf ("\n");*/

    /*Test_List_Change_Var ();*/
    /*printf ("\n");*/

    /*Test_List_Exchange_Var ();*/
    /*printf ("\n");*/

    /*EC_Test_Print_Msg ("Test: ec_list.h", "PASS");*/
    /*printf ("\n");*/
}
