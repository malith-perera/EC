#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "ec_queue_test.h"


/*void*/
/*Print_Student_Queue (StudentQueue *stq)*/
/*{*/
    /*
    StudentQueueVar *current = stq->first;

    while (current != NULL)
    {
    printf ("%d ", current->no);
    current = current->next;
    }
    */

/*    foreach_queue (stq)*/
    /*{*/
        /*printf ("%d ", stq->var->no);*/
    /*}*/

    /*printf ("\n");*/
/*}*/


void
Test_New_Queue ()
{
    EC_Print_Error ("Test_New_Queue: ", "BEGIN");

    StudentQueue* stq = Student_Queue ();
    EC_Print_Error ("Create new queue", "OK");

    StudentQueueVar *st1 = Student_Queue_Var ();

    StudentQueueVar *st2 = Student_Queue_Var ();

    EC_Print_Error ("Create queue variables", "OK");

    st1->no = 1;
    st1->name = "Malith";
    st2->no = 2;
    st2->name = "Geethike";

    EC_Print_Error ("Assign queue variable attributes", "OK");

    stq->first = st1;
    st1->next = NULL;
    stq->last = st1;

    stq->last->next = st2;
    st2->next = NULL;

    assert (stq->first->no == 1);
    assert (!strcmp (stq->first->name, "Malith"));

    assert (stq->first->next->no == 2);
    assert (!strcmp (stq->first->next->name, "Geethike"));

    EC_Print_Error ("link variables to queue", "OK");

    EC_Print_Error ("Test_New_Queue: ", "END");
}


void
Test_Enqueue_Queue ()
{
    EC_Print_Error ("Enqueue_Queue: ", "BEGIN");

    StudentQueue* stq = Student_Queue ();

    StudentQueueVar* st1 = Student_Queue_Var ();
    st1->no = 1;
    st1->name = "Malith";

    StudentQueueVar *st2 = Student_Queue_Var ();
    st2->no = 2;
    st2->name = "Geethike";

    Student_Enqueue (stq, st1);

    assert (stq->first->no == 1);
    assert (!strcmp (stq->first->name, "Malith")); // strcmp return 0 when equal so ! used
    assert (stq->first->next == NULL);
    assert (stq->last == st1);
    assert (stq->last->next == NULL);

    EC_Print_Error ("Enqueue queue fist variable", "OK");

    Student_Enqueue (stq, st2);

    assert (stq->first->no == 1);
    assert (!strcmp (stq->first->name, "Malith")); // strcmp return 0 when equal so ! used
    assert (stq->first->next == st2);
    assert (stq->first->next->no = 2);
    assert (!strcmp (stq->first->next->name, "Geethike")); // strcmp return 0 when equal so ! used
    assert (stq->last == st2);
    assert (st2->next == NULL);
    assert (stq->last->next == NULL);

    EC_Print_Error ("Enqueue queue second variable", "OK");

    EC_Print_Error ("Enqueue_Queue: ", "END");
}


void
Test_Dequeue_Queue ()
{
    EC_Print_Error ("Deque_Queue: ", "BEGIN");

    StudentQueue *stq = Student_Queue ();

    StudentQueueVar *st1 = Student_Queue_Var ();
    st1->no = 1;
    st1->name = "Malith";
    Student_Enqueue (stq, st1);

    StudentQueueVar *st2 = Student_Queue_Var ();
    st2->no = 2;
    st2->name = "Geethike";
    Student_Enqueue (stq, st2);

    StudentQueueVar* dequeued_var = Student_Dequeue (stq);

    if (dequeued_var)
    {
        assert (dequeued_var->no == 1);
        assert (!strcmp (dequeued_var->name, "Malith")); // strcmp return 0 when equal so ! used
        assert (stq->last->next == NULL);

        assert (stq->first->no == 2);
        assert (!strcmp (stq->first->name, "Geethike")); // strcmp return 0 when equal so ! used
        assert (stq->first->next == NULL);
        assert (stq->first = st2);
        assert (stq->last == st2);

        EC_Print_Error ("Dequeue queue fist variable", "OK");
    }
    else
    {
        printf ("Test written wrong\n");
        exit(0);
    }

    StudentQueueVar* dequeued_var2 = Student_Dequeue (stq);

    if (dequeued_var2)
    {
        assert (dequeued_var2->no == 2);
        assert (!strcmp (dequeued_var2->name, "Geethike")); // strcmp return 0 when equal so ! used
        assert (stq->first == NULL);
        assert (stq->last == NULL);

        EC_Print_Error ("Dequeue queue second variable", "OK");
    }
    else
    {
        printf ("Test written wrong\n");
        exit(0);
    }


    /* ***************** should do a empty queue dequeue test */


    EC_Print_Error ("Dequeue_Queue: ", "END");
}


void
Run_Queue_Test ()
{
    printf ("----------------\n");
    printf ("Test: ec_queue.h\n");
    printf ("================\n");

    Test_New_Queue ();
    printf ("\n");

    Test_Enqueue_Queue ();
    printf ("\n");

    Test_Dequeue_Queue ();
    printf ("\n");

    EC_Print_Error ("Test: ec_queue.h", "PASS");
    printf ("\n");
}
