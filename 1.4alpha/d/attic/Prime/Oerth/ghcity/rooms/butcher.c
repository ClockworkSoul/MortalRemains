#include <mudlib.h>
#include "oerth.h"

inherit ROOM;
void create() {
     ::create();
          set ("light", 1) ;
seteuid(getuid());
set("objects", ([ "butcher" : "/d/Prime/Oerth/ghcity/monster/butcher.c" ]) );
reset();
     set ("long",
"This is the Cities Slaughterhouse. It is in here\n"+
"where the butcher kills livestock to supply food\n"+
"to the marketplace and various restaurants.\n");
set("short", "The City Slaughterhouse.");
     set ("exits", ([
"east" : Oerth+"/rooms/proc5",
     ]) );
}
