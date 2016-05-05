/*
// The water plane general store.
*/

#include <mudlib.h>
#include "plane.h"

inherit SHOP;

void create() {
     ::create();
     set ("light", 1) ;
     set ("long", @Shop
You are in the general store of the island.
Commands are: <buy> <list> <sell> <appraise>
Shop
 );
     set ("short", "General Store") ;
     set ("exits", ([
     "north" : PLANE+"pathe2.c"
 ]) );
}
