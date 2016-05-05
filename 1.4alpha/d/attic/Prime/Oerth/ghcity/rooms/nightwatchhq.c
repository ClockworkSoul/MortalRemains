#include <config.h>
#include <mudlib.h>
#include "oerth.h"

inherit ROOM;

void create()
{
  ::create();
   // Inspiral fears Root euid.  94-08-18
   seteuid(getuid());
set("objects", ([ "guard1" : "/d/Prime/Oerth/ghcity/monster/nightguard1.c", "guard2" : "/d/Prime/Oerth/ghcity/monster/nightguard2.c", "guard3" : "/d/Prime/Oerth/ghcity/monster/nightguard3.c" ]) );
   reset();
  set( "light", 1 );
   set("short", "Nightwatch Headquarters");
  set( "long", @EndText
This is the Headquarters for the Nightwatchmen.
It isn't a glorious sight, but it serves their
needs. To the west is the Captain's quarters.
EndText
  );
  set( "exits", ([
"west" : Oerth+"/rooms/nightwatchcapt",
"east" : Oerth+"/rooms/proc3",
  ]) );
}
