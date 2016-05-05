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
"guard1" : "/d/Prime/Oerth/ghcity/monster/guard.c",
"guard2" : "/d/Prime/Oerth/ghcity/monster/guard.c",
]) );
   reset();
  set( "light", 1 );
set("short" , "The Battlements" );
  set( "long", @EndText
Your standing upon the walls surrounding the City
of GreyHawk. You can get a decent view of the city
from this vantage point and for the area surrounding
the city.
EndText
  );
  set( "exits", ([
"south" : Oerth+"/rooms/battlement6",
"north" : Oerth+"/rooms/watchtower1",
  ]) );
}
