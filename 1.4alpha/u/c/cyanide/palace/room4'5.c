#include "main.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();//<- gets all the information from the original create()
  seteuid( getuid());
  set( "light", 1 );
set("area_type", ([
"black" : 2,
]) );
set("short", "Crossroad");
  set( "long", @EndText
You are on the northern part of a road in the Dead City of Urborg. To
the south is what looks like some kind of temple, and there is a huge
palace to the east, barely visible in the darkness. There is a large arch of
some kind to the west, and a residential neighborhood to the north.
EndText
  );
set("arena", 1);
  set( "exits", ([
"east" : MAIN+"/room5'5.c",
"west" : MAIN+"/room3'5.c",
"north" : MAIN+"/room4'6.c",
"south" : MAIN+"/room4'4.c",
  ]) );
}
