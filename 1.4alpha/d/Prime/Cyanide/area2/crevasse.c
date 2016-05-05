#include "main.h"
#include <config.h>
#include <mudlib.h>
inherit ROOM;
void create()
{
  ::create();//<- gets all the information from the original create()
  seteuid( getuid());
   set ("light", 0);
set ("area_type", ([
  "black" : 2,
  "blue" : 2,
  "red" : 1,
  ]) );
   set("short", "Crevasse Bottom" );
  set( "long", @EndText
You have entered a dark crevasse. You think you might be
able to manage a scurry back up if necessary. However,
directly to your north, seems to be a large hole in the
cliff face... you may be able to enter it.
A good sized river is flowing over your ankles.
EndText
  );
  set( "exits", ([
    "north" : MAIN+"/doorstep.c",
    "up" : MAIN+"/nartunn.c"
  ]) );
   set ("author", "Cyanide and Gothmog");
}