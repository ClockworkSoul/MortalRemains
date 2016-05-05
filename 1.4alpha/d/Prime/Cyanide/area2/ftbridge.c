#include <mudlib.h>
#include "main.h"
inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
set ("author", " -[ Cyanide ]- " );
set ("light", 0);
set ("arena", 1);
set ("area_type", ([
  "black" : 2,
  ]) );
set ("short","Foot Bridge") ;
  set( "long", @EndText
You are standing on a crude but sturdy wooden foot bridge
crossing a deep ravine. The path runs north and south here.
EndText
  );
  set( "exits", ([
"south" : MAIN+"/gr8cav.c",
"north" : MAIN+"/nartunn.c",
"down" : MAIN+"/crevasse.c",
  ]) );
set ("exit_suppress", ({"down"}) );
set ("item_desc", ([
  "bridge" : "Well, it looks sturdy enough to hold you.\n",
  "ravine" : "To go down from here would be suicide.\n",
   ]) );
}
