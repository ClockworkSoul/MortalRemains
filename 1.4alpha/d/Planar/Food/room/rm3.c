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
EndText
    );
    set( "exits", ([
   "north" : RM+"rm6.c",
   "south" : RM+"rm2.c",
   "west" : RM+"rm15.c",
   "east" : RM+"rm16.c",
    ]) );
    set("item_desc", ([
   "village" : "A village of food, how odd.\n",
   "floor" : "Right there under you feet, what did you expect?\n",
    ]) );
}
