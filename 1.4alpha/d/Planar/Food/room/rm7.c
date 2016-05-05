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
You are wandering in a village of food. The path leads north and south.
You also notice houses to the east and west, you can enter both.
EndText
    );
    set( "exits", ([
   "south" : RM+"rm6.c",
   "north" : RM+"rm10.c",
   "west" : RM+"rm11.c",
   "east" : RM+"rm12.c",
    ]) );
    set("item_desc", ([
   "village" : "A village of food, how odd.\n",
   "floor" : "Right there under you feet, what did you expect?\n",
   "houses" : "To the east and west.\n",
    ]) );
}
