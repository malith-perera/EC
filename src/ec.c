#include <stdio.h>
#include "ec.h"


void
EC_init()
{
    /*ec_memory = ECMemory_List();*/
}


void
EC_Clean()
{
    EC_Memory_Clean();
    ECS_Free();
}
