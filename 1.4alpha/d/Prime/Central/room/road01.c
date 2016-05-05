#include <mudlib.h>
#include <path.h>

inherit ROOM;
void create(){
  ::create();
  set("light", 0);
  set("outside", "vieillere");
  set("short", "An old house");
  set("long", @Endtext
You are in a dark alley between two buildings.  Garbage is piled
high around you.  There seems to be some rustling sounds ahead.
Endtext
 );
  set("item_desc", ([
    "garbage" : "It is damp and smelly.  What did these people throw away!?\n",
  ]) );
  set("exits", ([
    "east"  : ROOMS+"alley2.c",
    "west"  : ROOMS+"road11.c",
  ]) );
}
