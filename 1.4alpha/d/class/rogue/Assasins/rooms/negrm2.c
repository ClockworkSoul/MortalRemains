#include <mudlib.h>

inherit ROOM;

void create(){
     ::create();
  seteuid(getuid());
   set("light", 1);
  set("short", "The Negative Material Plane");
  set("long", @Room
You are walking through the negative material plane. Portals are 
everywhere, leading toother realms.
Room
);
  set("exits", ([
    "portal" : "/d/Outer/Sigil/mainst1.c",
    "south" : "/d/class/rogue/Assasins/rooms/negrm1.c",
    "north" : "/d/class/rogue/Assasins/rooms/negrm3.c",
 ]) );
}


