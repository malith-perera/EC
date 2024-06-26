# EC

## Introduction

EC is an extended C library and a tool kit for high performance, rapid applications development in C language.
+ Easy dynamic variables
+ Extended functions
+ Easy tool kit
+ Entity component system
+ Think with objects
+ Dynamic memory management
+ Optimizable code
+ High performance

## Overview

```c
typedef struct Student {
   int  index;
   char *name;
} Student;

EC(Student)
```
Declare a Student  

### Create a dynamic variable
```c
Student *student1 = Student_New();

student->index = 101;
student->name = "Arnold";
```
Create a new student and initialize the student variables.  

### Create a Student List

```c
StudentList *student_list = Student_List();
```
Create a new student_list.  

### Append student to a list
```c
Student_Append(student_list, student1);
```
Append student1 to the list  

### Insert student to a list
```c
Student_Insert(student_list, student1, 5);
```

Insert student1 as the 5th student of the list. 

### Move student inside the list

```c
Student_Move(student_list, student1, 5);
```
Move student1 5 steps towards end of the list.  

### Exchange students in the list
```c
Student_Exchange(student_list, student1, student2);
```
Exchange student1 with student2.  

### Replace list student from one another
```c
Student_Replace(student_list, student1, student2);
```
Replace student1 by student2.  

### Remove student from the list

```c
Student_Remove(student_list, student);
```
Remove student1 from the list.  

### Loop in the list

```c
for_list(student_list) {
  printf("Name %s\n", student_list->var->name);
}
```
Go through the list one by one.  

## Welcome!
> Not only these. EC does many things for you. For more  manuals, tutorials, examples and binary downloads please follow the link below. Also you are warmly welcome to upgrade EC to the next level. Hope you will enjoy with EC programming.  
  
Be EC!
  
![Logo, Extended C logo ](doc/logo.png)  
  
<http://www.eclab.org>  

