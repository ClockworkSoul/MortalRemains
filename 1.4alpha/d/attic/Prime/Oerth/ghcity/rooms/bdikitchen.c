#include <mudlib.h>
#include "oerth.h"

inherit ROOM;
void create() {
     ::create();
          set ("light", 1) ;
seteuid(getuid());
set("objects", ([ "cook" : "/d/Prime/Oerth/ghcity/monster/cook.c" ]) );
reset();
     set ("long",
"This is the kitchen area of the Brass Dragon Inn.\n"+
"This is where the cook makes all the food for the guests.\n");
set("short", "Kitchen of the Brass Dragon Inn");
     set ("exits", ([
"doors" : Oerth+"/rooms/brassdragoninn",
     ]) );
}
