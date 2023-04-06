/*Todo */
/* ***************** should do a empty queue dequeue test */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "ec_queue_test.h"

void
Test_New_Queue ()
{
    EC_Test_Print_Title (__func__);

    EC_Test_Print_Subtitle ("Create student stack");

    StudentQueue* stq = Student_Queue ();
    EC_Error_Print_Msg ("Create new queue", "OK");

    assert (stq != NULL);
    EC_Test_Print_Msg ("Initaial stack == NULL", "OK", __LINE__);

    assert (stq->first == NULL);
    EC_Test_Print_Msg ("stq->first == NULL", "OK", __LINE__);

    assert (stq->last == NULL);
    EC_Test_Print_Msg ("stq->last == NULL", "OK", __LINE__);

    assert (stq->var == NULL);
    EC_Test_Print_Msg ("stq->var == NULL", "OK", __LINE__);
}


void
Test_Enqueue_Queue ()
{

    EC_Test_Print_Title (__func__);

    EC_Test_Print_Subtitle ("Create student stack");

    StudentQueue* stq = Student_Queue ();

}

#if 0

void
Test_Dequeue_Queue ()
{
    EC_Error_Print_Msg ("Deque_Queue: ", "BEGIN");

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

        EC_Error_Print_Msg ("Dequeue queue fist variable", "OK");
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

        EC_Error_Print_Msg ("Dequeue queue second variable", "OK");
    }
    else
    {
        printf ("Test written wrong\n");
        exit(0);
    }


    /* ***************** should do a empty queue dequeue test */


    EC_Error_Print_Msg ("Dequeue_Queue: ", "END");
}


void
Test_Queue_Copy ()
{
    EC_Error_Print_Msg ("Test_Queue_Copy: ", "BEGIN");

    StudentQueue *stq1 = Student_Queue ();

    StudentQueueVar *st1 = Student_Queue_Var ();
    st1->no = 1;
    st1->name = "Malith";
    Student_Enqueue (stq1, st1);

    StudentQueueVar *st2 = Student_Queue_Var ();
    st2->no = 2;
    st2->name = "Geethike";
    Student_Enqueue (stq1, st2);

    StudentQueue* stq2 = Student_Queue_Copy (stq1);

    assert (stq2->first->no = 1);
    assert (strcmp(stq2->first->name ,"Malith") == 0 );

    assert (stq2->first->next->no = 2);
    assert (strcmp(stq2->first->next->name ,"Geethike") == 0 );

    EC_Error_Print_Msg ("Queue Copy Variables", "OK");

    st1->no = 3;
    st1->name = "Malshi";
    assert (stq2->first->no != 3);
    assert (strcmp(stq2->first->name ,"Malshi") != 0 );

    st2->no = 4;
    st2->name = "Prisenthi";
    assert (stq1->first->no != 4);
    assert (strcmp(stq1->first->name ,"Prisenthi") != 0 );

    EC_Error_Print_Msg ("Copied list do not affect other list", "OK");

    EC_Error_Print_Msg ("Test_Queue_Copy: ", "END");
}

#endif

void
Run_Queue_Test ()
{

    EC_Test_Print_Header ("Test: ec_queue.h");
    printf ("\n");

    Test_New_Queue ();
    printf ("\n");

#if 0
    Test_Enqueue_Queue ();
    printf ("\n");

    Test_Dequeue_Queue ();
    printf ("\n");

    Test_Queue_Copy ();
    printf ("\n");

    EC_Error_Print_Msg ("Test: ec_queue.h", "PASS");
    printf ("\n");
#endif
}
