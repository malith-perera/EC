#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "ec_ecs_test.h"


void
Test_ECS_Init ()
{
    EC_Test_Print_Title ("Test: ECS_Init", "BEGIN");

    // Call ECS_Init
    ECS_Init();

    Entity *entity_list = EC_Get_Entity_List ();

    assert (entity_list->max == 0);
    assert (entity_list->n == 0);
    assert (entity_list->active == false);
    assert (entity_list->next == NULL);
    EC_Test_Print_Msg ("entity_list members initialization", "OK");

    assert (entity_list->ids->i == 0);
    assert (entity_list->ids->n == 0);
    assert (entity_list->ids->next == NULL);
    EC_Test_Print_Msg ("entity_list->ids members initialization", "OK");

    assert (ec_entity_total == 0);
    EC_Test_Print_Msg ("ec_entity_total", "OK");

    EC_Test_Print_Title ("Test: ECS_Init", "END");
}


void 
Entity_Change_Id (int i, int j)
{
    EC_Entity_Change_Id(i, j);

    Entity_Change (velocity, i, j);
    Entity_Change (position, i, j);
}


void
Free_Components ()
{
    free (velocity);
    velocity = NULL;

    free (position);
    position = NULL;
}


void
Test_ECS_Create_New_Entites()
{
    /* Test create new entities */
    EC_Test_Print_Subtitle ("Test: Create_New_Entity", "BEGIN");

    Entity *entity_list = EC_Get_Entity_List ();

    // Create entities

    players = Init_Entity (players, 2, 5);

    assert (players->ids->i == 0);
    assert (players->ids->n == 2);
    EC_Test_Print_Msg ("player ids", "OK");

    assert (entity_list->ids->i == 5);
    assert (entity_list->ids->n == 5);
    assert (entity_list->ids->next == NULL);
    EC_Test_Print_Msg ("ec_entity_list->ids", "OK");

    assert (entity_list->max == 5);
    assert (entity_list->n == 2);
    /* assert (entity_list->active == true); */
    /* assert (entity_list->next == NULL); */
    EC_Test_Print_Msg ("ec_entity_list", "OK");

    /* enemies = Init_Entity (enemies, 5, 10); */
    /* bullets = Init_Entity (bullets, 5, 10); */





    /* EC_Test_Print_Msg ("Asign arguments to players", "OK"); */

    /* assert (enemies->ids->i == 1); */
    /* assert (enemies->ids->n == 5); */
    /* EC_Test_Print_Msg ("Asign arguments to enemies", "OK"); */

    /* assert (bullets->ids->i == 6); */
    /* assert (bullets->ids->n == 5); */
    /* EC_Test_Print_Msg ("Asign arguments to bullets", "OK"); */




    EC_Test_Print_Title ("Test: Create_New_Entity: ", "END");
}


void
Test_ECS_For_Loops ()
{
    EC_Test_Print_Title ("Test: Entity for loops", "BEGIN");

    for_entity (players, player_ids)
    {
        int player_id_i = player_ids->i;

        for_entity_ids (player_ids, player_id)
        {
            assert (player_id_i++ == player_id);
        }
    }

    EC_Test_Print_Msg ("Player for loop", "OK");

    for_entity (enemies, enemy_ids)
    {
        int enemy_id_i = enemy_ids->i;

        for_entity_ids (enemy_ids, enemy_id)
        {
            assert (enemy_id_i++ == enemy_id);
        }
    }

    EC_Test_Print_Msg ("Enemy for loop", "OK");

    for_entity (bullets, bullet_ids)
    {
        int bullet_id_i = bullet_ids->i;

        for_entity_ids (bullet_ids, bullet_id)
        {
            assert (bullet_id_i++ == bullet_id);
        }
    }

    EC_Test_Print_Msg ("Bullet for loop", "OK");

    EC_Test_Print_Title ("Test: Entity for loops ", "END");
}


void
Test_ECS_Foreach ()
{
    EC_Test_Print_Title ("Test: Entity foreach loops", "BEGIN");

    int player_id_i = players->ids->i;
    foreach_entity(players, player_id)
    {
        assert (player_id_i++ == player_id);
    }

    EC_Test_Print_Msg ("Player foreach loop", "OK");

    int enemy_id_i = enemies->ids->i;
    foreach_entity(enemies, enemy_id)
    {
        assert (enemy_id_i++ == enemy_id);
    }

    EC_Test_Print_Msg ("Enemy foreach loop", "OK");

    int bullet_id_i = bullets->ids->i;
    foreach_entity(bullets, bullet_id)
    {
        assert (bullet_id_i++ == bullet_id);
    }

    EC_Test_Print_Msg ("Bullet foreach loop", "OK");

    EC_Test_Print_Title ("Test: Entity foreach loops ", "END");
}


void
Test_ECS_Create_Components ()
{
    /* Test create new entities */
    EC_Test_Print_Title ("Test: Create_New_Components", "BEGIN");

    position = New_Component (Position);
    velocity = New_Component (Velocity);

    for (int i = 0; i < ec_entity_total; i++)
    {
    }

    EC_Components(Entity_Change_Id);

    EC_Test_Print_Msg ("component size is created for entity_total", "OK");

    EC_Test_Print_Title ("Test: Create_New_Components: ", "END");
}

void
Test_ECS_Resize_Component ()
{
    Realloc(Position, position, ec_entity_total)
}


void
Run_ECS_Test ()
{
    printf ("--------------\n");
    printf ("Test: ec_ecs.h\n");
    printf ("==============\n");

    Test_ECS_Init ();
    printf ("\n");

    Test_ECS_Create_New_Entites();
    printf ("\n");

    /* Test_ECS_For_Loops (); */
    /* printf ("\n"); */

    /* Test_ECS_Foreach (); */
    /* printf ("\n"); */

    /* Test_ECS_Create_Components (); */
    /* printf ("\n"); */

    // Create components

    /* EntityComponent entity_component[nEntity][nComponent]; */
    /* Init_Entity_Component (entity_component); */

    /* Add_Component (entity_component, players, &position); */
    /* Add_Component (entity_component, players, &velocity); */
    /* Add_Component (entity_component, players, &size); */

    /* Add_Component (entity_component, enemies, &position); */
    /* Add_Component (entity_component, enemies, &velocity); */

    /* Add_Component (entity_component, bullet, &position); */
    /* Add_Component (entity_component, bullet, &velocity); */
    /* Add_Component (entity_component, bullet, &size); */

    /* Print_Entity_Component (entity_component); */

    Free_Components ();

    EC_Error_Print_Msg ("Test: ec_ecs.h", "PASS");
    printf ("\n");
}
