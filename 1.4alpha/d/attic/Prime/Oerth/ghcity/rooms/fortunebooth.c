#include <mudlib.h>
#include "oerth.h"

inherit ROOM;
void create() {
     ::create();
          set ("light", 1) ;
seteuid(getuid());
set("objects", ([
"fortuneteller" : "/d/Prime/Oerth/ghcity/monster/fortuneteller.c",
"boy" : "/d/Prime/Oerth/ghcity/monster/smallboy.c",
   ]) );
reset();
     set ("long",
"This small clearing houses a booth operated by Madam\n"+
"Serena. She is reputed to be a seer of some reknown.\n");
set("short", "Madam Serena's Fortunetelling");
     set ("exits", ([
"east" : Oerth+"/rooms/proc8",
     ]) );
}
