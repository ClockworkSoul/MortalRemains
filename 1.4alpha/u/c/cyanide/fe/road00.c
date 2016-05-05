#include <mudlib.h>
#include <path.h>

inherit ROOM;
inherit DOORS;

void create(){
    ::create();
    set("light", 1);
    set("short", "A Narrow Alley");
    set("long", @Endtext
You are in a dark alley between two buildings.  Garbage is piled
high around you.  There seems to be some rustling sounds ahead.
Endtext
    );
    set("item_desc", ([
      "garbage" : "It is damp and smelly.  What did these people throw away!?\n",
    ]) );
    set("exits", ([
      "east"  : ROOMS+"shack02",
      "west"  : ROOMS+"road11.c",
    ]) );
    create_door("east", "west", "A wooden door.\n", "locked", "shack_key");
    create_door("west", "east", "A wooden door", "closed");
}
