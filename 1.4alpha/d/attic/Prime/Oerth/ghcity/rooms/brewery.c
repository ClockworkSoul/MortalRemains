#include <mudlib.h>
#include "oerth.h"

inherit ROOM;
void create() {
     ::create();
          set ("light", 1) ;
seteuid(getuid());
set("objects", ([ 
"brewer" : "/d/Prime/Oerth/ghcity/monster/brewer.c",
"helper" : "/d/Prime/Oerth/ghcity/monster/helper1.c",
"helper2" : "/d/Prime/Oerth/ghcity/monster/helper2.c",
"helper3" : "/d/Prime/Oerth/ghcity/monster/helper3.c",
   ]) );
reset();
     set ("long",
"This is the cities brewery. It is in this building\n"+
"that brews, and ages all the fine beers and wines\n"+
"that supply the cities pubs, inns, and restaurants.\n");
set("short", "The City Brewery.");
     set ("exits", ([
"southwest" : Oerth+"/rooms/proc8",
     ]) );
}
