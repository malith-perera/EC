## Extended C 

 * Extended C (EC) is a library that help you to develop pure C programs more easily.
 * It allows you to create dynamic variables, arrays, lists, queues, stacks and their relevant functions easily.
 * EC helps you to design programs with objects in mind.
 * And it also supports Data Oriented Design using inbuilt Entity Component System (ECS).
 * Further more EC can manages dynamic memory and minimize memory errors and leaks if you are interested in.


Example:

Think you need to create a list of students in a classroom. Also think student has properties like name, grade and age.  

First write a structure. If you wish to hand over memory management to EC add EC_MEMORY_REF macro as below.  


<pre><code>
typedef struct Student {  
   int  index;  
   int  grade;  
   EC_MEMORY_REF // <i>Optional</i>  
} Student;  
</code></pre>


Next turn Student to list as below.  

<pre><code>List(Student)</code></pre>

Now you can create a Student list as below.  

<pre><code><i>StudentList *student_list = Student_List();</i></code></pre>

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

&nbsp; &nbsp; Not only these. EC does many things for you. It's purposely written so that it's much more customized to optimize your code to gain it's maximum performance. And it's always open you to make changes and improvements on it. Hope you will find this useful and enjoy with EC programming.  

For binary downloads, manuals, documentations, tutorials please visit:  

<http://www.extendedc.org>  

![Logo, Extended C logo ](ec.png)  