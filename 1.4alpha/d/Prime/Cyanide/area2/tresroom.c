#include "main.h"
#include <config.h>
#include <mudlib.h>
inherit ROOM;
void create()
{
  ::create();//<- gets all the information from the original create()
  seteuid( getuid());
  set( "light", 1 );
set ("area_type", ([
  "red" : 1,
  "black" : 2,
]) );
set("short", "Treasure room");
  set( "long", @EndText
This is the claim of the balrog.
EndText
  );
  set( "exits", ([
"south" : MAIN+"/lair.c",
  ]) );
set("author","Gothmog");
}