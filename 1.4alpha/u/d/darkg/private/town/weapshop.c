#include <config.h>
#include <mudlib.h>
#include "fuckstick.h"

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
   set ("objects", ([ "blacksmith" : "/u/d/darkgoth/monsters/blacksmith.c" ]) );
     reset();
  set( "light", 1 );
   set("short", "Zed's Weapon-o-Rama");
   set("long", @ENDTEXT
The sound of metal being hammered is almost deafing..
The forge gives off alot of heat. You can see Zed working hard making 
assorted weapons.
ENDTEXT
);
   set( "exits", ([
       "north" : AROOM+"street12.c",
  ]) );
}
