#include <config.h>
#include <mudlib.h>
#include "oerth.h"

inherit ROOM;

void create()
{
  ::create();
   // Inspiral fears Root euid.  94-08-18
   seteuid(getuid());
set("objects", ([ "capt" : "/d/Prime/Oerth/ghcity/monster/nightcapt.c" ]) );
   reset();
  set( "light", 1 );
   set("short", "Captain's Office");
  set( "long", @EndText
This is the office for the Captain of the
Nightwatchmen here in the Old City. This
room sports a desk and a chair.
EndText
  );
  set( "exits", ([
"east" : Oerth+"/rooms/nightwatchhq",
  ]) );
}
