#include <config.h>
#include <mudlib.h>

inherit PRIVATE_ROOM;
void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
   set("short", "Darkgoth's Love Shack");
   set("c_long", @ENDTEXT
You are in the Love shack baby....whips and chains clutter the walls.
There are a few leather outfits and some strange thingies. There is
a dresser that holds all of Darkgoth's make-up and hair products.
ENDTEXT
  );
  set( "exits", ([
    "start" : START,
    "void"  : VOID,
     "south" : "/u/d/darkgoth/room/porn.c",
 "portal" : "/u/d/darkgoth/room/town/street1.c",
  ]) );
   set("item_desc", ([
      "dresser" : "A place to put things.\n",
  ]) );
}
