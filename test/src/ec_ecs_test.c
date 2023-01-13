#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "ec_ecs_test.h"


void
Test_ECS_Create_Components ()
{
    /* Test create new entities */
    EC_Test_Print_Subtitle ("Test Create_New_Components", "Begin");

    position = New_Component (Position);
    velocity = New_Component (Velocity);

    EC_Error_Print_Msg ("position size", "OK");

    EC_Test_Print_Title ("Test Create_New_Components: ", "END");
}


void
Test_ECS_Resize_Component ()
{
    Entity *new_position = realloc (position, ec_entity_max);
    if (new_position == NULL) goto end;

    Entity *new_velocity = realloc (velocity, ec_entity_max);
    if (new_velocity == NULL) goto end;

    end:
    EC_Entity_Reset ();
}


void
Test_ECS_Create_New_Entites()
{
    /* Test create new entities */
    EC_Test_Print_Subtitle ("Test Create_New_Entity", "Begin");

    // Create entities
    players = New_Entity (1, 2);
    enemies = New_Entity (5, 10);
    bullets = New_Entity (5, 10);

    assert (players->i == 0);
    assert (players->n == 1);
    EC_Error_Print_Msg ("Asign arguments to players", "OK");

    assert (enemies->i == 1);
    assert (enemies->n == 5);
    EC_Error_Print_Msg ("Asign arguments to enemies", "OK");

    assert (bullets->i == 6);
    assert (bullets->n == 5);
    EC_Error_Print_Msg ("Asign arguments to bullets", "OK");

    EC_Test_Print_Title ("Test Create_New_Entity: ", "END");
}


void
Run_ECS_Test ()
{
    printf ("--------------\n");
    printf ("Test: ec_ecs.h\n");
    printf ("==============\n");


    Test_ECS_Create_New_Entites();
    printf ("\n");

    Test_ECS_Create_Components ();
    printf ("\n");

    // Create components
    /* position = (Position *) malloc (sizeof (Position) * nEntity); */
    /* velocity = (Velocity *) malloc (sizeof (Velocity) * nEntity); */

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

    EC_Error_Print_Msg ("Test: ec_ecs.h", "PASS");
    printf ("\n");
}
