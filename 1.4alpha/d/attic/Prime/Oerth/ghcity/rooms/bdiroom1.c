#include <mudlib.h>
#include "oerth.h"

inherit ROOM;
void create() {
     ::create();
          set ("light", 1) ;
seteuid(getuid());
set("objects", ([ "renoblade" : "/d/Prime/Oerth/ghcity/monster/renostar.c" ]) );
reset();
     set ("long",
"This is a plain bedroom, It's got a bed, and a small desk.\n");
set("short", "A bedroom");
     set ("exits", ([
"east" : Oerth+"/rooms/bdihall2",
     ]) );
}
