#include <mudlib.h>

inherit ROOM;

void create(){
     ::create();
  seteuid(getuid());
   set("light", 1);
  set("short", "The Negative Material Plane");
  set("long", @Room
You are walking through the negative material plane. Portals to
other realms are all over this place.
Room
);
  set("exits", ([
    "portal" : "/d/Prime/Toril/Arabel/city/mainst1.c",
    "north" : "/d/class/rogue/Assasins/rooms/negrm1.c",
 ]) );
}


