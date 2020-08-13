#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "ec_array_test.h"

#define EC_GARBAGE
#include "ec.h"

/*
#define EC_OBJECT Student
#include "ec_object.h"

#define EC_ARRAY Student
#define EC_ARRAY_RESIZE Student
#include "ec_array.h"


#define EC_OBJECT int
#include "ec_object.h"
*/

#define class(Student)   \
  int no;                \
  char *name;
expand(Student);
#undef class

#define EC_ARRAY Student
#define EC_SORT_WITH no
#define EC_SEARCH_WITH no
#include "ec_array.h"

/*
#define EC_ARRAY int
#define EC_ARRAY_SORT int
#include "ec_array.h"
*/


/********* implement test foreach_array */
void
Print_Student_Array
(
StudentArray *sta
)
{
  foreach_array (StudentArrayObj, sta)
  {
    printf ("%d ", item->no);
  }
}


void
Test_New_Array ()
{
  EC_Print_Error ("Test_New_Array: ", "BEGIN");

  StudentArray *sta = Student_Array (2);
  EC_Print_Error ("Create new array", "OK");

  sta->array[0].no = 1;
  sta->array[0].name = "Malith";

  sta->array[1].no = 2;
  sta->array[1].name = "Geethike";

  EC_Print_Error ("Assign array elements", "OK");

  assert (sta->count == 2);
  EC_Print_Error ("Array count exist", "OK");

  EC_Print_Error ("Test_New_Array: ", "END");
}


void
Test_Sort_Array ()
{
  EC_Print_Error ("Test_Array_Sort: ", "BEGIN");

  int i;

  StudentArray *sta = Student_Array (4);
  sta->array[0].no = 1;
  sta->array[0].name = "Malith";
  sta->array[1].no = 2;
  sta->array[1].name = "Geethike";
  sta->array[2].no = 3;
  sta->array[2].name = "Perera";
  sta->array[3].no = 4;
  sta->array[3].name = "Malshi";

  Sort_Student_Array (sta);

  i = 1;
  foreach_array(Student, sta)
  {
    assert (item->no == i);
    i++;
  }

  EC_Print_Error ("Sort when no sort needed ", "OK");

  // minimum is last
  sta->array[0].no = 4;
  sta->array[0].name = "Malith";
  sta->array[1].no = 2;
  sta->array[1].name = "Geethike";
  sta->array[2].no = 3;
  sta->array[2].name = "Perera";
  sta->array[3].no = 1;
  sta->array[3].name = "Malshi";

  Sort_Student_Array (sta);

  char *names1[] = {"Malshi", "Geethike", "Perera", "Malith"};

  i = 0;
  foreach_array(Student, sta)
  {
    assert (item->no == i + 1);
    assert (!strcmp (item->name, names1[i])); // strcmp return 0 when equal. assert fail when 0. so use !
    i++;
  }

  EC_Print_Error ("Sort when minimum is last element", "OK");

  // maximum is first
  sta->array[0].no = 4;
  sta->array[0].name = "Malith";
  sta->array[1].no = 2;
  sta->array[1].name = "Geethike";
  sta->array[2].no = 3;
  sta->array[2].name = "Perera";
  sta->array[3].no = 1;
  sta->array[3].name = "Malshi";

  Sort_Student_Array (sta);

  char *names2[] = {"Malshi", "Geethike", "Perera", "Malith"};

  i = 0;
  foreach_array(Student, sta)
  {
    assert (item->no == i + 1);
    assert (!strcmp (item->name, names2[i])); // strcmp return 0 when equal. assert fail when 0. so use !

    i++;
  }

  EC_Print_Error ("Sort when maximum is first element ", "OK");

  EC_Print_Error ("Test_Array_Sort: ", "END");
}


void
Test_Reverse_Array ()
{
  EC_Print_Error ("Test_Reverse_Array: ", "BEGIN");

  int i;

  StudentArray *sta = Student_Array (4);
  sta->array[0].no = 1;
  sta->array[0].name = "Malith";
  sta->array[1].no = 2;
  sta->array[1].name = "Geethike";
  sta->array[2].no = 3;
  sta->array[2].name = "Perera";
  sta->array[3].no = 4;
  sta->array[3].name = "Malshi";

  Reverse_Student_Array (sta);

  char *names[] = {"Malshi", "Perera", "Geethike",  "Malith"};

  i = 0;
  foreach_array(Student, sta)
  {
    assert (item->no == 4 - i);
    assert (!strcmp (item->name, names[i])); // strcmp return 0 when equal. assert fail when 0. so use !
    i++;
  }

  EC_Print_Error ("Reverse sorted array", "OK");

  EC_Print_Error ("Test_Reverse_Array: ", "END");
}


void
Test_Reverse_Int_Array ()
{
  EC_Print_Error ("Test_Reverse_Int_Array: ", "BEGIN");

  int array[] = {4, 3, 2, 1};

  Reverse_Int_Array (array, 4);

  for (int i = 0; i < 4; i++)
  {
    assert (array[i] == i + 1);
  }

  EC_Print_Error ("Reverse_Int_Array", "OK");

  EC_Print_Error ("Test_Reverse_Int_Array: ", "END");
}


void
Test_Search_Int_Array ()
{
  EC_Print_Error ("Test_Search_Int_Array: ", "BEGIN");

  int array[8] = {1, 3, 4, 2, 7, 6, 8, 2};

  int *result = Search_Int_Array (array, 8, 1, 1);

  EC_Print_Error ("Method state", "UNFINISHED");

  EC_Print_Error ("Test_Search_Int_Array: ", "END");
}


void
Test_Search_Sorted_Int_Array ()
{
  EC_Print_Error ("Test_Search_Sorted_Int_Array: ", "BEGIN");

  int array[1] = {1};

  Test_Search_Sorted_Int_Array (array, 1, 1);

  EC_Print_Error ("Array has only one element and matched", "UNFINISHED");

  EC_Print_Error ("Array has only one element but not matched", "UNFINISHED");


  int array2[2] = {1, 2};

  Test_Search_Sorted_Int_Array (array2, 2, 1);

  EC_Print_Error ("Array has only two elements and first matched", "UNFINISHED");

  EC_Print_Error ("Array has only two elements and last matched", "UNFINISHED");

  EC_Print_Error ("Array has only two elements but not matched", "UNFINISHED");

  EC_Print_Error ("Method state", "UNFINISHED");


  int array3[8] = {1, 3, 4, 2, 7, 6, 8, 2};

  Test_Search_Sorted_Int_Array (array3, 8, 1);

  EC_Print_Error ("Search first element", "UNFINISHED");

  EC_Print_Error ("Search last element", "UNFINISHED");

  EC_Print_Error ("Search any element", "UNFINISHED");

  EC_Print_Error ("Random number", "UNFINISHED");

  EC_Print_Error ("Test_Search_Sorted_Int_Array: ", "END");
}


void
Test_Search_Sorted_Array_With_Attr ()
{
  EC_Print_Error ("Test_Search_Sorted_Array_With_Attr: ", "BEGIN");

  StudentArray *sta = Student_Array (4);
  sta->array[0].no = 1;
  sta->array[0].name = "Malith";
  sta->array[1].no = 2;
  sta->array[1].name = "Geethike";
  sta->array[2].no = 3;
  sta->array[2].name = "Perera";
  sta->array[3].no = 4;
  sta->array[3].name = "Malshi";

  int index = Search_Sorted_Student_With_no (sta, 3);

  assert (sta->array[index].no == 3);

  EC_Print_Error ("Search sorted array", "OK");

  EC_Print_Error ("Test_Search_Sorted_Array_With_Attr: ", "END");
}


void
Test_Min_Object_With_Attr ()
{
  EC_Print_Error ("Test_Min_Object_With_Attr: ", "BEGIN");

  Student *st_min;

  StudentArray *sta = Student_Array (4);
  sta->array[0].no = 1;
  sta->array[0].name = "Malith";
  sta->array[1].no = 2;
  sta->array[1].name = "Geethike";
  sta->array[2].no = 3;
  sta->array[2].name = "Perera";
  sta->array[3].no = 4;
  sta->array[3].name = "Malshi";


  // min found in array first
  st_min = Min_Student_With_no (sta);
  assert (st_min->no == 1);
  assert (!strcmp (st_min->name, "Malith")); // strcmp 0 when equel assert fail when 0 thats why ! used
  EC_Print_Error ("Min found in array first", "OK");

  // min found in array last
  sta->array[0].no = 4;
  sta->array[3].no = 1;

  st_min = Min_Student_With_no (sta);
  assert (st_min->no == 1);
  assert (!strcmp (st_min->name, "Malshi")); // strcmp 0 when equel assert fail when 0 thats why ! used
  EC_Print_Error ("Min found in array first", "OK");

  // min found in array mid
  sta->array[0].no = 2;
  sta->array[1].no = 1;

  st_min = Min_Student_With_no (sta);
  assert (st_min->no == 1);
  assert (!strcmp (st_min->name, "Geethike")); // strcmp 0 when equel assert fail when 0 thats why ! used
  EC_Print_Error ("Min found in array first", "OK");

  EC_Print_Error ("Test_Min_Object_With_Attr: ", "END");
}


void
Test_Max_Object_With_Attr ()
{
  EC_Print_Error ("Test_Max_Object_With_Attr: ", "BEGIN");

  Student *st_max;

  StudentArray *sta = Student_Array (4);
  sta->array[0].no = 4;
  sta->array[0].name = "Malith";
  sta->array[1].no = 3;
  sta->array[1].name = "Geethike";
  sta->array[2].no = 2;
  sta->array[2].name = "Perera";
  sta->array[3].no = 1;
  sta->array[3].name = "Malshi";


  // max found in array first
  st_max = Max_Student_With_no (sta);
  assert (st_max->no == 4);
  assert (!strcmp (st_max->name, "Malith")); // strcmp 0 when equel assert fail when 0 thats why ! used
  EC_Print_Error ("Max found in array first", "OK");

  // max found in array last
  sta->array[0].no = 1;
  sta->array[3].no = 4;

  st_max = Max_Student_With_no (sta);
  assert (st_max->no == 4);
  assert (!strcmp (st_max->name, "Malshi")); // strcmp 0 when equel assert fail when 0 thats why ! used
  EC_Print_Error ("Max found in array first", "OK");

  // max found in array mid
  sta->array[0].no = 3;
  sta->array[1].no = 4;

  st_max = Max_Student_With_no (sta);
  assert (st_max->no == 4);
  assert (!strcmp (st_max->name, "Geethike")); // strcmp 0 when equel assert fail when 0 thats why ! used
  EC_Print_Error ("Max found in array first", "OK");

  EC_Print_Error ("Test_Max_Object_With_Attr: ", "END");
}


void
Test_Max_Int_Array ()
{
  EC_Print_Error ("Test_Max_Int_Array: ", "BEGIN");

  int max;

  int a[] = {5, 3, 2, 4, 1};
  max = Max_Int_Array (a, 5);
  assert (max == 5);
  EC_Print_Error ("Max found in array first", "OK");

  int a1[] = {2, 3, 5, 4, 1};
  max = Max_Int_Array (a1, 5);
  assert (max == 5);
  EC_Print_Error ("Max found in array mid", "OK");

  int a2[] = {2, 3, 1, 4, 5};
  max = Max_Int_Array (a2, 5);
  assert (max == 5);
  EC_Print_Error ("Max found in array end", "OK");

  EC_Print_Error ("Test_Max_Int_Array: ", "END");
}


void
Test_Min_Int_Array ()
{
  EC_Print_Error ("Test_Min_Int_Array: ", "BEGIN");

  int min;

  int a[] = {1, 3, 2, 4, 5};
  min = Min_Int_Array (a, 5);
  assert (min == 1);
  EC_Print_Error ("Min found in array first", "OK");

  int a1[] = {5, 3, 1, 4, 2};
  min = Min_Int_Array (a1, 5);
  assert (min == 1);
  EC_Print_Error ("Min found in array mid", "OK");

  int a2[] = {2, 3, 5, 4, 1};
  min = Min_Int_Array (a2, 5);
  assert (min == 1);
  EC_Print_Error ("Min found in array end", "OK");

  EC_Print_Error ("Test_Min_Int_Array: ", "END");
}


void
Run_Array_Test ()
{
  printf ("------------------\n");
  printf ("Test: ec_array.h\n");
  printf ("==================\n");

  Test_New_Array ();
  printf ("\n");

  Test_Sort_Array ();
  printf ("\n");

  Test_Reverse_Array ();
  printf ("\n");

  Test_Reverse_Int_Array ();
  printf ("\n");

  Test_Search_Int_Array ();
  printf ("\n");

  //Test_Search_Sorted_Int_Array ();
  //printf ("\n");

  Test_Search_Sorted_Array_With_Attr ();
  printf ("\n");

  Test_Max_Object_With_Attr ();
  printf ("\n");

  Test_Min_Object_With_Attr ();
  printf ("\n");

  Test_Max_Int_Array ();
  printf ("\n");

  Test_Min_Int_Array ();
  printf ("\n");

  EC_Print_Error ("Test: ec_array.h", "PASS");
  printf ("\n");
}

/*
 foreach_array (Student, sta)
  {
    printf ("Number %d Name %s\n", item->no,  item->name);
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
