# Extended C 

Extended C is a C library and a tool kit to write C programs easily with extended variables, functions, automated memory and C objects in mind.

Example:

Think you need to create a list of students in a classroom. Also think student has properties like name, grade and age.  

First what you have to do is define these property variables in a macro as below.  

<pre><code><i>
define student_vars  \
   char name[20];    \
   int  grade;       \
   int  age;
</i></code></pre>  

Next use EC_LIST macro in EC as below. Here 'Student' is new list type and 'student_vars' has defined above.  

<code><i>EC_LIST(Student, student_vars)</i></code><br>

After that you will get many list functions freely available without writing them. Let's examine some of the functions created by EC for you.<br>

You can create a student list with 20 students as below.  

<code><i>StudentList *student_list = Student_List(20);</i></code><br>

You can create one by one student as below.  

<pre><code><i>
StudentListVar *student1 = Student_List_Var();
StudentListVar *student2 = Student_List_Var();
</i></code></pre>  

You can append student1 into the student_list as below.  

<code><i>Student_Append (student_list, student1);</i></code><br>

You can insert student2 as the fifth student in the student_list as below.  

<code><i>Student_Insert (student_list, student2, 5);</i></code><br>

You can move student1 as the fifth student in the student_list as below.  

<code><i>Student_Move (student_list, student1, 5);</i></code><br>

You can replace students1 with student2 in the student_list as below.  

<code><i>Student_Replace (student_list, student1, student2);<br>

You can delete student2 in the student_list as below.  

<code><i>Student_Delete (student_list, student2);</i></code><br>

You can access each student in the student_list with foreach_list as below.  

<pre><code><i>
foreach_list (student_list) {
  printf("Name %s\n", student_list->var->name);
}
</i></code></pre>  

&nbsp; &nbsp; Not only these EC does many things for you. It's purposely written so that it's much more customizable to optimize your code to gain it's maximum performance. Some times it may not necessary but possibilities may arise if you wish. Hope you will enjoy with EC coding.  

For binary downloads, manuals, documentations, tutorials please visit:  

<http://www.extendedc.org>  

![Logo, Extended C logo ](ec.png)  

*(not working yet)*
