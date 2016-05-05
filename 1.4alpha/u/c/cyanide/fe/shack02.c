#include <mudlib.h>
#include <path.h>

inherit ROOM;
inherit DOORS;

void create(){
  ::create();
  set("light", 1);
  set("short", "A small shack");
  set("long", @Endtext
This shack is quite well kept.  The windows are decorated with pink
curtains and paper snowflakes.  A bed is placed next to a window so
one can look outside while resting.  A small electric stove is on the
floor near the door, with a pot of stew slowly simmering on it.
Endtext
 );
  set("item_desc", ([
    "windows" : "The view of Vieillere is not too impressive.\n",
    "curtains" : "They add a homely feeling to the small shack.\n",
    "snowflakes" : "Probably made by a child cutting paper.\n",
    "bed" : "It is a comfortable twin bed which is kept in good condition.\n",
    "stove" : "It's made by some company called GE.\n",
    "pot" : "A wonderful smelling stew is simmering inside.\n",
    "stew" : "Looks really good.  You might want to try some.\n",
  ]) );
  set("exits", ([
    "west"  : ROOMS+"road00",
  ]) );
  create_door("west", "east", "A wooden door with a standard lock", "locked", "shack_key");
}
