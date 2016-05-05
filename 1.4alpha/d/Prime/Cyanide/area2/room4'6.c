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
set("short", "North Road");
  set( "long", @EndText
This is a road in what what appears to have once been a residential
section of Urborg. Small stone houses line the street, and all appear
to have been abandoned.
EndText
  );
set("arena", 1);
  set( "exits", ([
"south" : MAIN+"/room4'5.c",
  ]) );
}
