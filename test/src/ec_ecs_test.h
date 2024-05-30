#ifndef __EC_ECS_TEST_H__
#define __EC_ECS_TEST_H__

#include "ec_main_test.h"
#include "component.h"

typedef Velocity ActionVelocity;

/* Components */
EC_Component_H(Velocity)
EC_Component_H(Position)
EC_Component_H(Score)
EC_Component_H(ActionVelocity)

/* Player */
EC_Entity_H(Player)
EC_Entity_Component_H(Player, Velocity)
EC_Entity_Component_H(Player, Position)
EC_Entity_Component_H(Player, Score)
EC_Entity_Component_H(Player, ActionVelocity)
#define Player(n, component_type) EC_Component(Player, n, component_type) // Optional

/* Enemy */
EC_Entity_H(Enemy)
EC_Entity_Component_H(Enemy, Velocity)
EC_Entity_Component_H(Enemy, Position)
#define Enemy(n, component_type) EC_Component(Enemy, n, component_type) // Optional 

void
Run_ECS_Test();

#endif // __EC_ECS_TEST_H__
