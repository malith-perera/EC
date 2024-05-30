# Extended C (EC)

 * Extended C (EC) is a library and a tool kit for write C programs easily.
 * It allows you to create dynamic variables, arrays, lists, queues, stacks and their relevant functions effortlessly.
 * EC helps you to design programs with objects in mind.
 * And it also supports Data Oriented Design using inbuilt Entity Component System (ECS).
 * Further more EC can manages dynamic memory and minimize memory errors and leaks if you are interested in.

## Overview
<pre><code>
typedef struct Student {
   int  index;
   char *name;
} Student;

EC(Student)
</code></pre>

### Create a dynamic variable
<pre><code>
Student *student = Student_Var();

student->index = 101;
student->name = "Arnold";
</code></pre>

### Create a List variable
<pre><code>List(Student)</code></pre>

<pre><code>
StudentList *student_list = Student_List();
</code></pre>

### Append student into a list
<pre><code>
Student_Append (student_list, student);
</code></pre>

### Insert student into a list
<pre><code>
Student_Insert (student_list, student, 5);
</code></pre>

Insert as the 5th item. 

### Move student inside the list

<pre><code>
Student_Move (student_list, student, 5);
</code></pre>

### Exchange students in the list
<pre><code>
Student_Exchange(student_list, student, student2);
</pre></code>

### Replace list student from one another
<pre><code>
Student_Replace (student_list, student, student2);
</code></pre>

### Remove student from the list

<pre><code>
Student_Remove(student_list, student);
</code></pre>

### Loop in the list

<pre><code>
foreach_list (student_list) {
  printf("Name %s\n", student_list->var->name);
}
</code></pre>  

&nbsp; &nbsp; Not only these. EC does many things for you. It's purposely written so that you can customize it to write optimized code to get it's maximum performance. And it's always open you to make changes and improvements on It. Hope you will enjoy with EC programming.  
  
Happy Programming!
  
For binary downloads, manuals, documentations, tutorials please visit:  

<http://www.extendedc.org>  

![Logo, Extended C logo ](ec.png)  