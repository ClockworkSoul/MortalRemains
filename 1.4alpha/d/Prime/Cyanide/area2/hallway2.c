#include <config.h>
#include <mudlib.h>
#include "main.h"

inherit DOORS;
inherit ROOM;

void create()
{
    ::create();
    set("author", "cyanide");
    set("light", 1);
    set ("short", "Hallway" );
    set( "long", @EndText
You are standing in a short, roughly hewn hallway leading only
southward, into blackness.  An large opening in the ceiling
above your head is the only alternative exit.
EndText
    );
    set( "exits", ([
      "up" : MAIN+"/o_clearing.c",
      "south" : MAIN+"/hallway.c",
    ]) );
    set ("item_desc", ([
    ]) );
    create_door("up", "down","A rusty iron grate","locked",
      "rus_key",15);
}

