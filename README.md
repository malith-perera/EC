# Extended C  
---  

Extended C is a cross platform library and tools set for developing programs in pure C language with objects in mind. You can create arrays, lists, queues and stacks easily and gain their related functions without additional coding. Also you can manage memory automatically without leaks if you are interested in.

As an example think you need to create a list of students in a classroom.

### Example:  

>*\#define student_vars*     \  
    *int     no;*     \  
    *char   name[20]*;  

>*EC_LIST(Student, student_vars)*  

>*StudentList \*stl = Student_List ();*  

>*StudentListVar \*st1 = Student_List_Var ();*  
>*StudentListVar \*st2 = Student_List_Var ();*  

>*Student_Append (stl, st1);*  
>*Student_Append (stl, st2);*  


As Student_Append function above, using this few lines of code,  

- Student_Insert  
- Student_Replace  
- Student_Sort  
- Student_Delete  

and many other functions which related with lists are freely available for you now without coding them.  

![Logo, Extended C logo ](share/icons/ec96.png)





