#include <mudlib.h>
#include "oerth.h"

inherit ROOM;
void create() {
     ::create();
          set ("light", 1) ;
seteuid(getuid());
set("objects", ([
"waitress" : "/d/Prime/Oerth/ghcity/monster/waitress2.c",
"patron" : "/d/Prime/Oerth/ghcity/monster/patron.c",
   ]) );
reset();
     set ("long",
"This is the common area of the White Horse Inn.\n"+
"People gather here for it's ordinary food, but you\n"+
"see, this inn makes its business by having cheap\n"+
"room rates.\n");
set("short", "White Horse Inn Common Room");
     set ("exits", ([
"east" : Oerth+"/rooms/proc9",
"doors" : Oerth+"/rooms/whihall1",
     ]) );
}
