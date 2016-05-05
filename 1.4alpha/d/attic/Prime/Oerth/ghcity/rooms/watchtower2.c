#include <config.h>
#include <mudlib.h>
#include "oerth.h"

inherit ROOM;

void create()
{
  ::create();
   // Inspiral fears Root euid.  94-08-18
   seteuid(getuid());
set("objects", ([
"guard1" : "/d/Prime/Oerth/ghcity/monster/nightguard1.c",
"guard2" : "/d/Prime/Oerth/ghcity/monster/nightguard2.c",
"guard3" : "/d/Prime/Oerth/ghcity/monster/nightguard3.c",
]) );
   reset();
  set( "light", 1 );
set("short", "A Watch Tower");
  set( "long", @EndText
This tower is used to guard the city from trouble,
both from without, and from within. It's guards
are noble and loyal to the city and will defend
her with their lives.
EndText
  );
  set( "exits", ([
"west" : Oerth+"/rooms/battlement7",
"northeast" : Oerth+"/rooms/battlement9",
  ]) );
}
