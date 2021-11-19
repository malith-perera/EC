#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "ec_list_test.h"

#define EC_GARBAGE
#include "ec.h"

//#define NDEBUG

#define class(Student)   \
  int no;                \
  char *name;
expand(Student);
#undef class

#define EC_LIST Student
#define EC_SORT Student
#define EC_SORT_WITH no
#define EC_SEARCH_WITH no
#include "ec_list.h"


void
Print_Student_List (StudentList *stl)
{
    /*
    StudentListObj *current = stl->first;

    while (current != NULL)
    {
    printf ("%d ", current->no);
    current = current->next;
    }
    */

    foreach_list (StudentListObj, stl)
    {
    printf ("%d ", item->no);
    }

    printf ("\n");
}


void
Test_New_List ()
{
    EC_Print_Error ("Test_New_List: ", "BEGIN");

    StudentList *stl = Student_List ();
    EC_Print_Error ("Create new list", "OK");

    StudentListObj *st1 = Student_List_Object ();

    StudentListObj *st2 = Student_List_Object ();

    EC_Print_Error ("Create list objects", "OK");

    st1->no = 1;
    st1->name = "Malith";
    st2->no = 2;
    st2->name = "Geethike";

    EC_Print_Error ("Assign list object attributes", "OK");

    stl->first = st1;
    st1->previous = NULL;
    st1->next = NULL;
    stl->last = st1;

    st2->previous = stl->last;
    st2->next = NULL;
    stl->last->next = st2;

    assert (stl->first->no == 1);
    assert (!strcmp (stl->first->name, "Malith"));

    assert (stl->first->next->no == 2);
    assert (!strcmp (stl->first->next->name, "Geethike"));

    EC_Print_Error ("link objects to list", "OK");

    EC_Print_Error ("Test_New_List: ", "END");
}


void
Test_Append_List ()
{
    EC_Print_Error ("Append_List: ", "BEGIN");

    StudentList *stl = Student_List ();

    StudentListObj *st1 = Student_List_Object ();
    st1->no = 1;
    st1->name = "Malith";

    StudentListObj *st2 = Student_List_Object ();
    st2->no = 2;
    st2->name = "Geethike";

    Append_Student (stl, st1);

    assert (stl->first->no == 1);
    assert (!strcmp (stl->first->name, "Malith")); // strcmp return 0 when equal so ! used
    assert (stl->first->next == NULL);
    assert (stl->first->previous == NULL);
    assert (stl->first->next == NULL);
    assert (stl->first->previous == NULL);
    assert (stl->last == st1);

    EC_Print_Error ("Append list fist object", "OK");

    Append_Student (stl, st2);

    assert (stl->first->no == 1);
    assert (!strcmp (stl->first->name, "Malith")); // strcmp return 0 when equal so ! used
    assert (stl->first->previous == NULL);
    assert (stl->first->next == st2);
    assert (stl->first->next->no = 2);
    assert (!strcmp (stl->first->next->name, "Geethike")); // strcmp return 0 when equal so ! used
    assert (stl->first->next->previous == st1);
    assert (stl->last == st2);
    assert (st2->next == NULL);
    assert (stl->last->next == NULL);

    EC_Print_Error ("Append list fist object", "OK");

    EC_Print_Error ("Append_List: ", "END");
}


void
Test_Insert_List ()
{
    EC_Print_Error ("Test_Insert_List: ", "BEGIN");

    StudentList *stl = Student_List ();

    StudentListObj *st1 = Student_List_Object ();
    st1->no = 1;
    st1->name = "Malith";
    Append_Student (stl, st1);

    StudentListObj *st2 = Student_List_Object ();
    st2->no = 2;
    st2->name = "Geethike";
    Append_Student (stl, st2);

    StudentListObj *st3 = Student_List_Object ();
    st3->no = 3;
    st3->name = "Perera";
    Insert_Student (stl, st3, st1, -1);
    assert (stl->first->no == 3);
    assert (!strcmp (stl->first->name, "Perera")); // strcmp return 0 when equal use !

    EC_Print_Error ("Insert as fist item", "OK");

    StudentListObj *st4 = Student_List_Object ();
    st4->no = 4;
    st4->name = "Malshi";
    Insert_Student (stl, st4, st3, 1);
    assert (stl->first->next->no == 4);
    assert (!strcmp (stl->first->next->name, "Malshi")); // strcmp return 0 when equal use !

    EC_Print_Error ("Insert next to fist item", "OK");

    StudentListObj *st5 = Student_List_Object ();
    st5->no = 5;
    st5->name = "Prisenthi";
    Insert_Student (stl, st5, st2, -1);
    assert (stl->last->previous->no == 5);
    assert (!strcmp (stl->last->previous->name, "Prisenthi")); // strcmp return 0 when equal use !

    EC_Print_Error ("Insert before last item", "OK");

    StudentListObj *st6 = Student_List_Object ();
    st6->no = 6;
    st6->name = "Fernando";
    Insert_Student (stl, st6, st2, 1);
    assert (stl->last->no == 6);
    assert (!strcmp (stl->last->name, "Fernando")); // strcmp return 0 when equal use !

    EC_Print_Error ("Insert as last item", "OK");

    StudentListObj *st7 = Student_List_Object ();
    st7->no = 7;
    st7->name = "Rohasha";
    Insert_Student (stl, st7, st4, 1);
    assert (st4->next->no == 7);
    assert (!strcmp (st4->next->name, "Rohasha")); // strcmp return 0 when equal use !

    EC_Print_Error ("Insert as after mid item", "OK");

    StudentListObj *st8 = Student_List_Object ();
    st8->no = 8;
    st8->name = "Magret";
    Insert_Student (stl, st8, st4, -1);
    assert (st4->previous->no == 8);
    assert (!strcmp (st4->previous->name, "Magret")); // strcmp return 0 when equal use !

    EC_Print_Error ("Insert as before mid item", "OK");

    EC_Print_Error ("Test_Insert_List: ", "END");
}


void
Test_Replace_List ()
{
    EC_Print_Error ("Test_Replace_List: ", "BEGIN");

    StudentList *stl = Student_List ();

    StudentListObj *st1 = Student_List_Object ();
    st1->no = 1;
    st1->name = "Malith";
    Append_Student (stl, st1);

    StudentListObj *st2 = Student_List_Object ();
    st2->no = 2;
    st2->name = "Geethike";
    Append_Student (stl, st2);

    StudentListObj *st3 = Student_List_Object ();
    st3->no = 3;
    st3->name = "Perera";

    Replace_Student (stl, st1, st3);
    assert (stl->first->no = 3);
    assert (stl->first->name = "Perera");

    Replace_Student (stl, st2, st1);
    assert (stl->last->no = 1);
    assert (stl->last->name = "Malith");

    EC_Print_Error ("Replace last item", "OK");

    EC_Print_Error ("Test_Replace_List: ", "END");
}


void
Test_Sort_List ()
{
    EC_Print_Error ("Test_Sort_List: ", "BEGIN");

    StudentList *stl = Student_List ();

    StudentListObj *st6 = Student_List_Object ();
    st6->no = 6;
    st6->name = "Fernando";
    Append_Student (stl, st6);

    StudentListObj *st5 = Student_List_Object ();
    st5->no = 5;
    st5->name = "Prisenthi";
    Append_Student (stl, st5);

    StudentListObj *st2 = Student_List_Object ();
    st2->no = 2;
    st2->name = "Geethike";
    Append_Student (stl, st2);

    StudentListObj *st4 = Student_List_Object ();
    st4->no = 4;
    st4->name = "Malshi";
    Append_Student (stl, st4);

    StudentListObj *st3 = Student_List_Object ();
    st3->no = 3;
    st3->name = "Perera";
    Append_Student (stl, st3);

    StudentListObj *st1 = Student_List_Object ();
    st1->no = 1;
    st1->name = "Malith";
    Append_Student (stl, st1);

    Sort_Student_List_With_no (stl);

    int i = 1;

    char *names[6] = {"Malith", "Geethike", "Perera", "Malshi", "Prisenthi", "Fernando"};

    foreach_list (StudentListObj, stl)
    {
    assert (item->no == i);
    assert (!strcmp (item->name, names[i-1]));
    i++;
    }

    EC_Print_Error ("List sort with object attribute", "OK");

    EC_Print_Error ("Test_Sort_List: ", "END");
}


void
Run_List_Test ()
{
    printf ("---------------\n");
    printf ("Test: ec_list.h\n");
    printf ("===============\n");

    Test_New_List ();
    printf ("\n");

    Test_Append_List ();
    printf ("\n");

    Test_Insert_List ();
    printf ("\n");

    Test_Replace_List ();
    printf ("\n");

    Test_Sort_List ();
    printf ("\n");

    EC_Print_Error ("Test: ec_list.h", "PASS");
    printf ("\n");
}

/*
  Print_Student_List (stl);

  printf ("Student Number ");
  scanf ("%d", &no);

  while (no > 0)
  {
    st = Student_List_Object ();
    st->no = no;
    Append_Student (stl, st);
    Print_Student_List (stl);
    printf ("Student Number ");
    scanf ("%d", &no);
  }

  StudentListObj *st3 = Student_List_Object ();
  st3->no = 1;
  st3->name = "Perera";

  Insert_Student (stl, st3, st2, -1);
*/

  /*Replace_Student (stl, st1, st3);*/

  /*Drop_Student (stl, st2);*/

  /*Sort_Studentno (stl);*/

  /*Print_Student_List (stl);*/

