#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "ec_array_test.h"

#if 0
/* Test: New_Array
 * This function test create new array and array access*/
void
Test_New_Array ()
{
    EC_Error_Print_Msg ("Test_New_Array: ", "BEGIN");

    StudentArray *sta = Student_Array (2);
    EC_Error_Print_Msg ("Create new array", "OK");

    sta->index[0].no    = 1;
    sta->index[0].name  = "Malith";

    sta->index[1].no    = 2;
    sta->index[1].name  = "Geethike";

    EC_Error_Print_Msg ("Assign array variables", "OK");

    assert (sta->index[0].no == 1);
    assert (strcmp(sta->index[0].name, "Malith") == 0);
    assert (sta->index[1].no == 2);
    assert (strcmp(sta->index[1].name, "Geethike") == 0);

    EC_Error_Print_Msg ("Access arry variables", "OK");

    assert (sta->length == 2);
    EC_Error_Print_Msg ("Array length exist", "OK");

    EC_Error_Print_Msg ("Test_New_Array: ", "END");
}


/* Test: Array_Copy
 * This function test copied array have the same variables and
 * Change of copy or original array does not affect each other */
void
Test_Array_Copy ()
{
    EC_Error_Print_Msg ("Test_Copy_Array: ", "BEGIN");

    StudentArray* sta1 = Student_Array (2);
    EC_Error_Print_Msg ("Create new ec array", "OK");

    sta1->index[0].no = 1;
    sta1->index[0].name = "Malith";

    sta1->index[1].no = 2;
    sta1->index[1].name = "Geethike";

    StudentArray* sta2 = Student_Array_Copy (sta1);

    assert (sta2->index[0].no == 1);
    assert (strcmp(sta2->index[0].name, "Malith") == 0);

    assert (sta2->index[1].no == 2);
    assert (strcmp(sta2->index[1].name, "Geethike") == 0);

    EC_Error_Print_Msg ("Array variable copied: ", "OK");

    assert (sta1->length == sta2->length);

    EC_Error_Print_Msg ("Array length copied: ", "OK");

    sta1->index[0].no = 3;
    sta1->index[0].name = "Malshi";
    assert (sta2->index[0].no != 3);
    assert (strcmp(sta2->index[0].name, "Geethike") != 0);

    sta2->index[1].no = 4;
    sta2->index[1].name = "Presenthi";
    assert (sta1->index[1].no != 4);
    assert (strcmp(sta1->index[1].name, "Presenthi") != 0);

    EC_Error_Print_Msg ("Changing one array variable do not affect other array: ", "OK");

    EC_Error_Print_Msg ("Test_Copy_Array: ", "END");
}


/* Test: Array_Free
 * This function test Array_Free function */
void
Test_Array_Free ()
{
    EC_Error_Print_Msg ("Test_Array_Free: ", "BEGIN");

    StudentArray* sta = Student_Array (2);
    EC_Error_Print_Msg ("Create new ec array", "OK");

    sta->index[0].no = 1;
    sta->index[0].name = "Malith";

    sta->index[1].no = 2;
    sta->index[1].name = "Geethike";

    assert (sta->index[1].no == 2);
    assert (strcmp(sta->index[1].name, "Geethike") == 0);
    EC_Error_Print_Msg ("Create assign array", "OK");

    Student_Array_Free (sta);
    EC_Error_Print_Msg ("Array_Free function", "OK");

    EC_Error_Print_Msg ("Test_Array_Free: ", "END");
}


/* Test: Array_Free
 * This function test Array_Free function */
void
Test_Array_Free_One ()
{
}


/* Test: Array_Unlock
 * This function test Array_Unlock function
 * Unlock just unlock ec_memory var and release to free when needed*/
void
Test_Array_Unlock ()
{
    EC_Error_Print_Msg ("Test_Array_Unlock: ", "BEGIN");

    StudentArray* sta = Student_Array (2);
    EC_Error_Print_Msg ("Create new ec array", "OK");

    sta->index[0].no = 1;
    sta->index[0].name = "Malith";

    sta->index[1].no = 2;
    sta->index[1].name = "Geethike";

    EC_Error_Print_Msg ("Create assign array", "OK");

    Student_Array_Unlock (sta);

    EC_Error_Print_Msg ("Array_Unlock function", "OK");

    assert (sta->ec_mem->lock == EC_UNLOCK);
    EC_Error_Print_Msg ("lock unlocked", "OK");

    EC_Error_Print_Msg ("Test_Array_Unlock: ", "END");
}


void
Test_Array_Sort ()
{
    EC_Error_Print_Msg ("Test_Array_Sort: ", "BEGIN");

    StudentArray *sta = Student_Array (4);
    sta->index[0].no = 1;
    sta->index[0].name = "Malith";
    sta->index[1].no = 2;
    sta->index[1].name = "Geethike";
    sta->index[2].no = 3;
    sta->index[2].name = "Perera";
    sta->index[3].no = 4;
    sta->index[3].name = "Malshi";

    Student_Array_Sort_With_no (sta);


    foreach_array (sta)
    {
        assert (sta->var->no == sta->i + 1); // sta->i is an array internal variable to loop array
    }

    EC_Error_Print_Msg ("Sort when no sort needed ", "OK");

    // minimum is last
    sta->index[0].no = 4;
    sta->index[0].name = "Malith";
    sta->index[1].no = 2;
    sta->index[1].name = "Geethike";
    sta->index[2].no = 3;
    sta->index[2].name = "Perera";
    sta->index[3].no = 1;
    sta->index[3].name = "Malshi";

    Student_Array_Sort_With_no (sta);

    char *names1[] = {"Malshi", "Geethike", "Perera", "Malith"};

    foreach_array(sta)
    {
        assert (sta->var->no == sta->i + 1);
        assert (!strcmp (sta->var->name, names1[sta->i])); // strcmp return 0 when equal. assert fail when 0. so use !
    }

    EC_Error_Print_Msg ("Sort when minimum is last element", "OK");

    // maximum is first
    sta->index[0].no = 4;
    sta->index[0].name = "Malith";
    sta->index[1].no = 2;
    sta->index[1].name = "Geethike";
    sta->index[2].no = 3;
    sta->index[2].name = "Perera";
    sta->index[3].no = 1;
    sta->index[3].name = "Malshi";

    Student_Array_Sort_With_no (sta);

    char *names2[] = {"Malshi", "Geethike", "Perera", "Malith"};

    foreach_array(sta)
    {
        assert (sta->var->no == sta->i + 1);
        assert (!strcmp (sta->var->name, names2[sta->i])); // strcmp return 0 when equal. assert fail when 0. so use !
    }

    EC_Error_Print_Msg ("Sort when maximum is first element ", "OK");

    EC_Error_Print_Msg ("Test_Array_Sort: ", "END");
}


void
Test_Array_Reverse ()
{
    EC_Error_Print_Msg ("Test_Array_Reverse: ", "BEGIN");

    char* names[] = {"Malith", "Geethike", "Perera", "Malshi"};

    StudentArray *sta = Student_Array (4);
    sta->index[0].no = 1;
    sta->index[0].name = names[0];
    sta->index[1].no = 2;
    sta->index[1].name = names[1];
    sta->index[2].no = 3;
    sta->index[2].name = names[2];
    sta->index[3].no = 4;
    sta->index[3].name = names[3];

    EC_Error_Print_Msg ("Array created and assigned", "OK");

    Student_Array_Reverse (sta);
    EC_Error_Print_Msg ("Reverse array function call", "OK");

    foreach_array(sta)
    {
        assert (sta->var->no == 4 - sta->i);
        assert (!strcmp (sta->var->name, names[3 - sta->i])); // strcmp return 0 when equal. assert fail when 0. so use !
    }

    EC_Error_Print_Msg ("Array_Reverse", "OK");

    EC_Error_Print_Msg ("Test_Array_Reverse: ", "END");
}


void
Test_Array_Int ()
{
    EC_Error_Print_Msg ("Test_Array_Search_Var: ", "BEGIN");

    StudentArray* sta = Student_Array (4);
    sta->index[0].no = 1;
    sta->index[0].name = "Malith";
    sta->index[1].no = 2;
    sta->index[1].name = "Geethike";
    sta->index[2].no = 3;
    sta->index[2].name = "Perera";
    sta->index[3].no = 4;
    sta->index[3].name = "Malshi";

    EC_Error_Print_Msg ("Array created and assigned", "OK");

    int index = Student_Array_Int_no (sta, 3);

    EC_Error_Print_Msg ("Array_Search function call", "OK");

    assert (index == 2);

    assert (sta->index[index].no == 3);

    EC_Error_Print_Msg ("Array_Int", "OK");

    EC_Error_Print_Msg ("Test_Array_Search_Var: ", "END");
}


void
Test_Array_Str ()
{
    EC_Error_Print_Msg ("Test_Array: ", "BEGIN");

    StudentArray* sta = Student_Array (4);
    sta->index[0].no = 1;
    sta->index[0].name = "Malith";
    sta->index[1].no = 2;
    sta->index[1].name = "Geethike";
    sta->index[2].no = 3;
    sta->index[2].name = "Perera";
    sta->index[3].no = 4;
    sta->index[3].name = "Malshi";

    EC_Error_Print_Msg ("Array created and assigned", "OK");

    int index = Student_Array_Str_name (sta, "Perera");

    EC_Error_Print_Msg ("Array_Search function call", "OK");

    assert (index == 2);

    assert (sta->index[index].no == 3);

    EC_Error_Print_Msg ("Array_Str", "OK");

    EC_Error_Print_Msg ("Test_Array_Search_Str: ", "END");
}


void
Test_Array_Max ()
{
    EC_Error_Print_Msg ("Test_Array_Max: ", "BEGIN");

    Student* st_max;

    StudentArray* sta = Student_Array (4);
    sta->index[0].no = 4;
    sta->index[0].name = "Malith";
    sta->index[1].no = 3;
    sta->index[1].name = "Geethike";
    sta->index[2].no = 2;
    sta->index[2].name = "Perera";
    sta->index[3].no = 1;
    sta->index[3].name = "Malshi";

    // max found in array first
    st_max = Student_Array_Max_no (sta);
    assert (st_max->no == 4);
    assert (!strcmp (st_max->name, "Malith")); // strcmp 0 when equel assert fail when 0 thats why ! used
    EC_Error_Print_Msg ("Max found in array first", "OK");

    // max found in array last
    sta->index[0].no = 1;
    sta->index[3].no = 4;

    st_max = Student_Array_Max_no (sta);
    assert (st_max->no == 4);
    assert (!strcmp (st_max->name, "Malshi")); // strcmp 0 when equel assert fail when 0 thats why ! used
    EC_Error_Print_Msg ("Max found in array last", "OK");

    // max found in array mid
    sta->index[0].no = 3;
    sta->index[1].no = 4;

    st_max = Student_Array_Max_no (sta);
    assert (st_max->no == 4);
    assert (!strcmp (st_max->name, "Geethike")); // strcmp 0 when equel assert fail when 0 thats why ! used
    EC_Error_Print_Msg ("Max found in array mid", "OK");

    EC_Error_Print_Msg ("Test_Array_Max: ", "END");
}

void
Test_Array_Min ()
{
    EC_Error_Print_Msg ("Test_Array_Min: ", "BEGIN");

    Student* st_min;

    StudentArray *sta = Student_Array (4);
    sta->index[0].no = 1;
    sta->index[0].name = "Malith";
    sta->index[1].no = 2;
    sta->index[1].name = "Geethike";
    sta->index[2].no = 3;
    sta->index[2].name = "Perera";
    sta->index[3].no = 4;
    sta->index[3].name = "Malshi";

    // min found in array first
    st_min = Student_Array_Min_no (sta);
    assert (st_min->no == 1);
    assert (!strcmp (st_min->name, "Malith")); // strcmp 0 when equel assert fail when 0 thats why ! used
    EC_Error_Print_Msg ("Min found in array first", "OK");

    // min found in array last
    sta->index[0].no = 4;
    sta->index[3].no = 1;

    st_min = Student_Array_Min_no (sta);
    assert (st_min->no == 1);
    assert (!strcmp (st_min->name, "Malshi")); // strcmp 0 when equel assert fail when 0 thats why ! used
    EC_Error_Print_Msg ("Min found in array last", "OK");

    // min found in array mid
    sta->index[0].no = 2;
    sta->index[1].no = 1;

    st_min = Student_Array_Min_no (sta);
    assert (st_min->no == 1);
    assert (!strcmp (st_min->name, "Geethike")); // strcmp 0 when equel assert fail when 0 thats why ! used
    EC_Error_Print_Msg ("Min found in array mid", "OK");

    EC_Error_Print_Msg ("Test_Array_Min: ", "END");
}



/* integer arrays */

void
Test_Int_Array_Reverse ()
{
    EC_Error_Print_Msg ("Test_Int_Array_Reverse: ", "BEGIN");

    int array[] = {4, 3, 2, 1};

    Int_Array_Reverse (array, 4);

    for (int i = 0; i < 4; i++)
    {
        assert (array[i] == i + 1);
    }

    EC_Error_Print_Msg ("Reverse_Int_Array", "OK");

    EC_Error_Print_Msg ("Test_Int_Array_Reverse: ", "END");
}


void
Test_Int_Array_Search ()
{
    EC_Error_Print_Msg ("Test_Search_Int_Array: ", "BEGIN");

    int array[8] = {1, 3, 4, 2, 7, 6, 8, 2};

    int *result = Int_Array_Search (array, 8, 1, 1);

    EC_Error_Print_Msg ("Method state", "UNFINISHED");

    EC_Error_Print_Msg ("Test_Search_Int_Array: ", "END");
}


void
Test_Int_Sorted_Array_Search ()
{
    EC_Error_Print_Msg ("Test_Search_Sorted_Int_Array: ", "BEGIN");

    int array[1] = {1};

    Int_Sorted_Array_Search (array, 1, 1);

    EC_Error_Print_Msg ("Array has only one element and matched", "UNFINISHED");

    EC_Error_Print_Msg ("Array has only one element but not matched", "UNFINISHED");


    int array2[2] = {1, 2};

    Int_Sorted_Array_Search (array2, 2, 1);

    EC_Error_Print_Msg ("Array has only two elements and first matched", "UNFINISHED");

    EC_Error_Print_Msg ("Array has only two elements and last matched", "UNFINISHED");

    EC_Error_Print_Msg ("Array has only two elements but not matched", "UNFINISHED");

    EC_Error_Print_Msg ("Method state", "UNFINISHED");


    int array3[8] = {1, 3, 4, 2, 7, 6, 8, 2};

    Int_Sorted_Array_Search (array3, 8, 1);

    EC_Error_Print_Msg ("Search first element", "UNFINISHED");

    EC_Error_Print_Msg ("Search last element", "UNFINISHED");

    EC_Error_Print_Msg ("Search any element", "UNFINISHED");

    EC_Error_Print_Msg ("Random number", "UNFINISHED");

    EC_Error_Print_Msg ("Test_Search_Sorted_Int_Array: ", "END");
}


void
Test_Int_Array_Max ()
{
    EC_Error_Print_Msg ("Test_Int_Array_Max: ", "BEGIN");

    int max;

    int a[] = {5, 3, 2, 4, 1};
    max = Int_Array_Max (a, 5);
    assert (max == 5);
    EC_Error_Print_Msg ("Max found in array first", "OK");

    int a1[] = {2, 3, 5, 4, 1};
    max = Int_Array_Max (a1, 5);
    assert (max == 5);
    EC_Error_Print_Msg ("Max found in array mid", "OK");

    int a2[] = {2, 3, 1, 4, 5};
    max = Int_Array_Max (a2, 5);
    assert (max == 5);
    EC_Error_Print_Msg ("Max found in array end", "OK");

    EC_Error_Print_Msg ("Test_Max_Int_Array: ", "END");
}


void
Test_Int_Array_Min ()
{
    EC_Error_Print_Msg ("Test_Int_Array_Min: ", "BEGIN");

    int min;

    int a[] = {1, 3, 2, 4, 5};
    min = Int_Array_Min (a, 5);
    assert (min == 1);
    EC_Error_Print_Msg ("Min found in array first", "OK");

    int a1[] = {5, 3, 1, 4, 2};
    min = Int_Array_Min (a1, 5);
    assert (min == 1);
    EC_Error_Print_Msg ("Min found in array mid", "OK");

    int a2[] = {2, 3, 5, 4, 1};
    min = Int_Array_Min (a2, 5);
    assert (min == 1);
    EC_Error_Print_Msg ("Min found in array end", "OK");

    EC_Error_Print_Msg ("Test_Min_Int_Array: ", "END");
}


#endif

void
Run_Array_Test ()
{
#if 0
    printf ("------------------\n");
    printf ("Test: ec_array.h\n");
    printf ("==================\n");

    Test_New_Array ();
    printf ("\n");

    Test_Array_Copy ();
    printf ("\n");

    Test_Array_Free ();
    printf ("\n");

    /*Test_Array_Unlock ();*/
    /*printf ("\n");*/

    Test_Array_Reverse ();
    printf ("\n");

    Test_Array_Sort ();
    printf ("\n");

    Test_Array_Int ();
    printf ("\n");

    Test_Array_Str ();
    printf ("\n");

    Test_Array_Max ();
    printf ("\n");

    Test_Array_Min ();
    printf ("\n");

    Test_Int_Array_Reverse ();
    printf ("\n");

    Test_Int_Array_Search ();
    printf ("\n");

    Test_Int_Sorted_Array_Search ();
    printf ("\n");

    Test_Int_Array_Max ();
    printf ("\n");

    Test_Int_Array_Min ();
    printf ("\n");

    /*EC_Error_Print_Msg ("Test: ec_array.h", "PASS");*/
    /*printf ("\n");*/

#endif

}


/*
 foreach_array (sta)
  {
    printf ("Number %d Name %s\n", sta->var->no,  sta->var->name);
  }
  */



 /* Binary array search */
 /*int a[1000000];*/

  /*for (int i = 0; i < 1000000; i++)*/
  /*{*/
    /*a[i] = i;*/
  /*}*/

  /*int n = Search (a, 1000000,  atoi(argv[1]));*/

  /*printf ("index %d ", n);*/


/*
// search
// max
// min
  int array[] = {1, 2, 3, 4, 5, 6, 3, 6, 7, 3};

  int *ai;

  ai = Search_Int_Array (array, 10, 3, 3);

  for (int i = 0; i < 3; i++)
  {
    printf ("%d ", ai[i]);
  }

  printf ("\n");


  // maximum number in array
  printf ("%d \n", Max_Int_Array (array, 10));

  // reverse
  Reverse_Int_Array (array, 10);

  for (int i = 0 ; i < 10; i++)
  {
    printf ("%d ", array[i]);
  }
  printf ("\n");

*/



/*

  Resize_Student_Array (&student, &student_size, 3);

  student[2].number = 3;
  strcpy (student[2].name, "Perera");

  for (int i = 0; i < student_size; i++)
  {
    printf ("Number %d Name %s\n", student[i].number,  student[i].name);
  }

  Resize_Student_Array (&student, &student_size, 2);

  for (int i = 0; i < student_size; i++)
  {
    printf ("Number %d Name %s\n", student[i].number,  student[i].name);
  }

  Free_Student (&student);

  free (student);



  int number_size = 5;
  int *number = New_int_Array (number_size);

  number[0] = 4;
  number[1] = 7;
  number[2] = 5;
  number[3] = 6;
  number[4] = 2;

  for (int i = 0; i < number_size; i++)
  {
    printf ("%d ", number[i]);
  }

  printf ("\n");

  Sort_int_Array (&number, number_size);

  for (int i = 0; i < number_size; i++)
  {
    printf ("%d ", number[i]);
  }

  Free_int (&number);
  free(number);
*/




/********* implement test foreach_array */
/*void*/
/*Print_Student_Array*/
/*(*/
    /*StudentArray *sta*/
/*)*/
/*{*/
    /*foreach_array (sta)*/
    /*{*/
        /*printf ("%d ", sta->var->no);*/
    /*}*/
/*}*/


