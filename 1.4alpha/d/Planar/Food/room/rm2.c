#include <config.h>
#include <mudlib.h>

inherit ROOM;

#include "../food.h"

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
   set("short", "The Village of Foodsburg");
    set( "long", @EndText
You are wandering around in a village of food. The path continues to
the north, and back south, you can enter a house to the east or west.
EndText
    );
    set( "exits", ([
   "south" : RM+"rm1.c",
   "north" : RM+"rm3.c",
   "west" : RM+"rm5.c",
   "east" : RM+"rm4.c",
    ]) );
    set("item_desc", ([
     "house" : "A dwelling, things live there./n",
   "village" : "A village of food, how odd.\n",
   "floor" : "Right there under you feet, what did you expect?\n",
    ]) );
}
