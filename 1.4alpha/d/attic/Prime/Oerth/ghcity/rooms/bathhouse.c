#include <mudlib.h>
#include "oerth.h"

inherit ROOM;
void create() {
     ::create();
          set ("light", 1) ;
seteuid(getuid());
set("objects", ([
"bather1" : "/d/Prime/Oerth/ghcity/monster/bather.c",
"bather2" : "/d/Prime/Oerth/ghcity/monster/bather2.c",
"bather3" : "/d/Prime/Oerth/ghcity/monster/bather3.c",
"bather4" : "/d/Prime/Oerth/ghcity/monster/bather4.c",
      ]) );
reset();
     set ("long",
"This is the cities public bath house. People\n"+
"from this quarter come here to clean themsleves.\n");
set("short", "Public Bath House.");
     set ("exits", ([
"west" : Oerth+"/rooms/proc6",
     ]) );
}
