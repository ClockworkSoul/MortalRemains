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
   set("short", "Black Gate" );
  set( "long", @EndText
This is Black Gate. One of the inner gates
of GreyHawk City. To the south is the Old
City and to the north the New City.
There is a ladder leading up to the battlements here.
EndText
  );
  set( "exits", ([
"north" : Oerth+"/rooms/proc11",
"south" : Oerth+"/rooms/proc10",
"up" : Oerth+"/rooms/battlement20",
  ]) );
}
