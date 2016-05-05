#include <mudlib.h>
#include "main.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( 0 );
    set ("author", " -{ CYANIDE }- ");
    set ("arena" ,1);
    set ("light", 1);
    set ("area_type", ([
      "blue" : 3,
      "black" : 2,
    ]) );
    set ("short", "On The Lake");
    set( "long", @EndText
You are floating on the surface of the lake. The water is ice cold,
and your ability to survive here for long is very questionable. A
swim north puts you at your starting point. Conditions to the
east are poor where the lake turns into a swamp. The south shore
is suitable for walking, however.
EndText
    );
    set( "exits", ([
      "north" : MAIN+"/lakeshore.c",
      "south" : MAIN+"/southshore.c",
      "dive" : MAIN+"/underwater.c"
    ]) );
    set ("exit_suppress", ({"dive"}) );
    set ("exit_msg", ([
      "north" : "$N swims out towards the north shore.\n",
      "south" : "$N swims out towards the south shore.\n",
      "dive" : "$N gulps some air and dives down under the water.\n",
    ]) );
    set ("item_desc", ([
      "water" : "It's REAL cold! In fact, you can't feel your toes anymore...\n",
    ]) );
}

void init()
{
    add_action ("south", "down");
    add_action ("south", "d");
}
int south()
{
    write (
      "If you want to dive, just say so.\n");
    return 1;
}
