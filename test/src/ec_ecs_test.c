#include "ec_ecs_test.h"

Component_Functions(Velocity, velocity)
Component_Functions(Position, position)


EntityType Player;
EntityType Enemy;
EntityType Bullet;
EntityType Box;
EntityType Empty;


Entity *player;
Entity *enemy;
Entity *bullet; 
Entity *box;
Entity *empty;


void
Test_Entity_Request ()
{
    EC_Test_Print_Title (__func__, __FILE__);

    player = Entity_Request (Player, 2, 5);
//    enemy = Entity_Request (Enemy, 2, 10);
//    bullet = Entity_Request (Bullet, 0, 5);
//    empty = Entity_Request (Empty, 0, 20);

    Entity *request_list = Get_Request_List ();

    Entity *current_request = request_list;

//    assert (current_request->n == 0);
//    assert (current_request->m == 20);
//    EC_Test_Print_Msg ("Test: bullet", "OK", __LINE__);
//
//    current_request = current_request->next;
//    assert (current_request->n == 2);
//    assert (current_request->m == 10);
//    EC_Test_Print_Msg ("Test: enemy", "OK", __LINE__);

    //current_request = current_request->next;
    assert (current_request->n == 2);
    assert (current_request->m == 5);
    EC_Test_Print_Msg ("Test: player", "OK", __LINE__);

    current_request = current_request->next;
    assert (current_request == NULL);
    EC_Test_Print_Msg ("Test: request_array end", "OK", __LINE__);
}


void
Test_Entity_Request_Warn ()
{
    EC_Test_Print_Title (__func__, __FILE__);

    Entity_Request (Player, 5, 10);

    Entity **request_array;
    request_array  = Get_Request_Array ();

    Entity *current_request = request_array[ENTITY_NEW];

    current_request = current_request->next;
    current_request = current_request->next;
    current_request = current_request->next;

    assert (current_request->n == 5);
    assert (current_request->m == 10);
    EC_Test_Print_Msg ("Test: Entity_Request warning", "OK", __LINE__);

}


void
Test_New_Component ()
{
    // New_Component function calls in ec_ecs_test.h
    EC_Test_Print_Title (__func__, __FILE__);

    assert (position_list == NULL);
    EC_Test_Print_Msg ("Test: position_list exist", "OK", __LINE__);

    assert (velocity_list == NULL);
    EC_Test_Print_Msg ("Test: velocity_list exist", "OK", __LINE__);

}


void
Test_Add_Component()
{
    EC_Test_Print_Title (__func__, __FILE__);

    Add_Component(player, Position, position);
    
    assert (player_position == NULL);
    EC_Test_Print_Msg ("Test: player_position exist", "OK", __LINE__);

    Add_Component(player, Velocity, velocity);

    assert (player_velocity == NULL);
    EC_Test_Print_Msg ("Test: player_velocity exist", "OK", __LINE__);

}


void
Run_ECS_Test ()
{
    printf ("--------------\n");
    printf ("Test: ec_ecs.h\n");
    printf ("==============\n");

    Test_Entity_Request ();

    Test_New_Component ();

    Test_Entity_Request_Warn ();

//    Entity_Free ();

    EC_Error_Print_Msg ("Test: ec_ecs.h", "PASS");
    printf ("\n");
}
