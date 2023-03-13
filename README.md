# Extended C 

 * Extended C (EC) is a library that help you to develop pure C programs more easily.
 * It allows you to create varibles, arrays, lists, queues, stacks and their relevent functions more quickly.
 * EC helps you to think programs with objects in mind.
 * It also supports data oriented desing using inbuilt entity component system.
 * Further more EC can manages memory and minimize memory errors and leaks if you are interested in.


Example:

Think you need to create a list of students in a classroom. Also think student has properties like name, grade and age.  

First what you have to do is define these property variables in a macro as below.  

<pre><code><i>
define STUDENT      \
   int  index;      \
   int  grade;
</i></code></pre>  

Next use EC_LIST macro in EC as below. Here 'Student' is new list type and 'student_vars' has defined above.  

<code><i>EC_LIST(Student, STUDENT)</i></code><br>

After that you will get many list functions freely available without writing them. Let's examine some of the functions created by EC for you.<br>

You can create a student list with 20 students as below.  

<code><i>StudentList *student_list = Student_List();</i></code><br>

You can create one by one student as below.  

<pre><code><i>
StudentListVar *student1 = Student_List_Var(student_list);
StudentListVar *student2 = Student_List_Var(student_list);
</i></code></pre>  

<pre><code><i>
student1->index = 1;  
student1->grade = 6;  
  
student2->index = 2;  
student2->grade = 6;  
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

&nbsp; &nbsp; Not only these. EC does many things for you. It's purposely written so that it's much more customizable to optimize your code to gain it's maximum performance. And it's always open you to make changes and improvements on it. Hope you will find this useful and enjoy with EC programming.  

For binary downloads, manuals, documentations, tutorials please visit:  

<http://www.extendedc.org>  

![Logo, Extended C logo ](ec.png)  

*(not working yet)*
