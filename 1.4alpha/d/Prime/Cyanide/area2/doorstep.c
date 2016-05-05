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
  "blue" : 1,
  "black" : 2,
  ]) );
   set( "short", "A Large Cave");
  set( "long", @EndText
This is a rather large, rough hewn cave... The stench here
reminds you of a cross between sulfur and dead
animal remains. Large and rancid dead animal remains...
You can see a red glow in the darkness to the east.
EndText
  );
  set( "exits", ([
  "east" : MAIN+"/lair.c",
  "south" : MAIN+"/crevasse.c",
 ]) );
  set ("author", "Gothmog");
}