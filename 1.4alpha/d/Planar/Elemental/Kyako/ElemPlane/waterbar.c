#include <mudlib.h>
#include "plane.h"

inherit PUB;

void create() {
     ::create();
     set ("light", 1) ;
     set ("long", @WaterBar
You are in the waterfront Bar.
The best bar in all of the planescape.
Commands are: menu , buy <drinkname>, powerheal <drinkname>
WaterBar
 );
     set ("short", "Waterfront Bar") ;
     set ("exits", ([
     "north" : PLANE+"pathw.c",
     "up" : PLANE+"barroom.c",
 ]) );
}
