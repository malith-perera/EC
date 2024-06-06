# EC
<hr>
  
 * EC (Extended C) is a simple library and a tool kit that provide you a rapid way to develop C programs more easily.
 * Also it make the space you to optimize the code and gain the maximum performance after that.
 * It let you to create dynamic variables, arrays, lists, queues, stacks and their relevant functions without much effort.
 * EC allows you to think about the programs with objects in mind.
 * And it also supports Data Oriented Design using inbuilt Entity Component System (ECS).
 * Further more EC can manages dynamic memory and minimize  errors and memory leaks if you are interested in.

## Overview

```c
typedef struct Student {
   int  index;
   char *name;
} Student;

EC(Student)
```
Declare the Student and pass it to EC.  

### Create a dynamic variable
```c
Student *student = Student_Var();

student->index = 101;
student->name = "Arnold";
```
Create student and initialize the student values.  

### Create a List variable

```c
StudentList *student_list = Student_List();
```
Create a student_list.  

### Append student into a list
```c
Student_Append(student_list, student);
```
Append student at end of the list  

### Insert student into a list
```c
Student_Insert(student_list, student, 5);
```

Insert student as the 5th list item. 

### Move student inside the list

```c
Student_Move(student_list, student, 5);
```
move student 5 places left.  

### Exchange students in the list
```c
Student_Exchange(student_list, student, student2);
```
exchange student with student2.  

### Replace list student from one another
```c
Student_Replace(student_list, student, student2);
```
Replace student by student2.  

### Remove student from the list

```c
Student_Remove(student_list, student);
```
Remove student from the list.  

### Loop in the list

```c
for_list(student_list) {
  printf("Name %s\n", student_list->var->name);
}
```
Go through list one by one.  

Not only these. EC does many things for you. It's purposely written so that you can customize it to write optimized C code to get it's maximum performance. And it's always let you to make changes and improvements on It. Hope you will enjoy with EC programming.  
  
Happy Programming!
  
For binary downloads, manuals, documentations, tutorials please visit:  

<http://www.extendedc.org>  

![Logo, Extended C logo ](ec.png)  

