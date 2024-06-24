# EC - Extended C

## Introduction

EC is a simple library and a tool kit that provide you a rapid way of developing C programs using EC variables, extended library functions without much effort.  

Also it helps you to think and develop the programs with objects in mind. And it also supports Data Oriented Design using inbuilt Entity Component System (ECS).  

Further more EC can manage dynamic memory and minimizes errors and memory leaks if you are interested in.  

Finally it extends the space you to optimize the code and purposely written so that you to gain it's the maximum performance.  

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
Student *student = Student_New();

student->index = 101;
student->name = "Arnold";
```
Create a new student and initialize the student values.  

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

Insert student as the 5th student of the list. 

### Move student inside the list

```c
Student_Move(student_list, student, 5);
```
Move student 5 places towards end of the list.  

### Exchange students in the list
```c
Student_Exchange(student_list, student, student2);
```
Exchange student with student2.  

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

> Not only these. EC does many things for you. And you are always welcome to step up EC to the next level. Hope you will enjoy with EC programming.  
  
Happy Programming!
  
For binary downloads, manuals, documentations, tutorials please visit:  

<http://www.extendedc.org>  

![Logo, Extended C logo ](doc/logo.png)  