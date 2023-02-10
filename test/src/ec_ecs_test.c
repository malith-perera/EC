#include "ec_ecs_test.h"



void
Test_Entity_Request ()
{
    player = Entity_Request (player, 4, 10);
    enemy  = Entity_Request (enemy, 2, 10);
    bullet = Entity_Request (bullet, 0, 5);
    empty  = Entity_Request (empty, 0, 20);

    EntityRequest *request_list = Get_Request_List ();

    EntityRequest *current_request = request_list;

    assert (current_request->entity->n == 4);
    assert (current_request->entity->m == 10);
    assert (current_request->entity == player);
    assert (current_request->type == ENTITY_NEW);

    current_request = current_request->next;

    assert (current_request->entity->n == 2);
    assert (current_request->entity->m == 10);
    assert (current_request->entity == enemy);
    assert (current_request->type == ENTITY_NEW);

    current_request = current_request->next;
    assert (current_request->entity->n == 0);
    assert (current_request->entity->m == 5);
    assert (current_request->entity == bullet);
    assert (current_request->type == ENTITY_NEW);

    current_request = current_request->next;
    assert (current_request->entity->n == 0);
    assert (current_request->entity->m == 20);
    assert (current_request->entity == empty);
    assert (current_request->type == ENTITY_NEW);

    assert (current_request->next == NULL);
}


void
Run_ECS_Test ()
{
    printf ("--------------\n");
    printf ("Test: ec_ecs.h\n");
    printf ("==============\n");

    // Entity_Create ();
    Test_Entity_Request ();

    Entity_Free ();

    EC_Error_Print_Msg ("Test: ec_ecs.h", "PASS");
    printf ("\n");
}
