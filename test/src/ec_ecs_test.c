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
    assert (entity_list->active == true);
    assert (entity_list->next == NULL);
    EC_Test_Print_Msg ("entity_list members initialization", "OK");

    assert (entity_list->id->i == 0);
    assert (entity_list->id->n == 0);
    assert (entity_list->id->next == NULL);
    EC_Test_Print_Msg ("entity_list->id members initialization", "OK");

    assert (ec_entity_total == 0);
    EC_Test_Print_Msg ("ec_entity_total", "OK");

    EC_Test_Print_Title ("Test: ECS_Init", "END");
}


void
Test_ECS_Create_New_Entites()
{
    /* Test create new entities */
    EC_Test_Print_Subtitle ("Test: Create_New_Entity", "BEGIN");

    Entity *entity_list = EC_Get_Entity_List ();

    // Init players 
    players = Init_Entity (players, 2, 5);

    assert (players->id->i == 0);
    assert (players->id->n == 2);
    EC_Test_Print_Msg ("player->id", "OK");

    assert (players->max == 5);
    assert (players->active == true);
    assert (players->next == NULL);
    EC_Test_Print_Msg ("players", "OK");

    assert (entity_list->id->i == 5);
    assert (entity_list->id->n == 2);
    assert (entity_list->id->next == NULL);
    EC_Test_Print_Msg ("ec_entity_list->id", "OK");

    assert (entity_list->max == 5);
    assert (entity_list->active == true);
    assert (entity_list->next != NULL);
    assert (entity_list->next->next == NULL);
    EC_Test_Print_Msg ("ec_entity_list", "OK");

    assert (entity_list->next == players);
    EC_Test_Print_Msg ("player add as the second entity", "OK");

    // Init enemies
    enemies = Init_Entity (enemies, 5, 10);

    assert (enemies->id->i == 5);
    assert (enemies->id->n == 5);
    EC_Test_Print_Msg ("enemies->id", "OK");

    assert (enemies->max == 10);
    assert (enemies->active == true);
    assert (enemies->next == players);
    EC_Test_Print_Msg ("enemies", "OK");

    assert (entity_list->id->i == 15);
    assert (entity_list->id->n == 7);
    assert (entity_list->id->next == NULL);
    EC_Test_Print_Msg ("ec_entity_list->id", "OK");

    assert (entity_list->max == 15);
    assert (entity_list->active == true);
    assert (entity_list->next != NULL);
    assert (entity_list->next->next->next == NULL);
    EC_Test_Print_Msg ("ec_entity_list", "OK");

    assert (entity_list->next == enemies);
    EC_Test_Print_Msg ("enemies add as the second entity", "OK");

    // Init bullets
    bullets = Init_Entity (bullets, 5, 10);

    assert (bullets->id->i == 15);
    assert (bullets->id->n == 5);
    EC_Test_Print_Msg ("bullets->id", "OK");

    assert (bullets->max == 10);
    assert (bullets->active == true);
    assert (bullets->next == enemies);
    EC_Test_Print_Msg ("enemies", "OK");

    assert (entity_list->id->i == 25);
    assert (entity_list->id->n == 12);
    assert (entity_list->id->next == NULL);
    EC_Test_Print_Msg ("ec_entity_list->id", "OK");

    assert (entity_list->max == 25);
    assert (entity_list->active == true);
    assert (entity_list->next != NULL);
    assert (entity_list->next->next->next->next == NULL);
    EC_Test_Print_Msg ("ec_entity_list", "OK");

    assert (entity_list->next == bullets);
    EC_Test_Print_Msg ("bullets add as the third entity", "OK");

    EC_Test_Print_Title ("Test: Create_New_Entity: ", "END");
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

    int player_id_i = players->id->i;
    foreach_entity(players, player_id)
    {
        assert (player_id_i++ == player_id);
    }

    EC_Test_Print_Msg ("Player foreach loop", "OK");

    int enemy_id_i = enemies->id->i;
    foreach_entity(enemies, enemy_id)
    {
        assert (enemy_id_i++ == enemy_id);
    }

    EC_Test_Print_Msg ("Enemy foreach loop", "OK");

    int bullet_id_i = bullets->id->i;
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
