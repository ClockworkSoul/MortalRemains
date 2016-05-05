#include <config.h>
#include <mudlib.h>
#include "oerth.h"

inherit ROOM;

void create()
{
  ::create();
   // Inspiral fears Root euid.  94-08-18
   seteuid(getuid());
   set("objects", ([ "guard1" : "/d/Prime/Oerth/ghcity/monster/guard.c", "guard2" : "/d/Prime/Oerth/ghcity/monster/guard.c" ]) );
   reset();
  set( "light", 1 );
   set( "short", "Highway Gate" );
  set( "long", @EndText
This is High Gate, one of many gates which lead into
the great city of Greyhawk. The road goes north to
The Processional, and south into the wilderness.
You notice a ladder leading up to the battlements.
EndText
  );
  set( "exits", ([
   "north" : Oerth+"/rooms/proc1",
"up" : Oerth+"/rooms/battlement1",
  ]) );
}
