#include <mudlib.h>
#include "main.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
set ("author", " -{ CYANIDE }- ");
set ("arena" ,1);
set ("light", 0);
set ("area_type", ([
  "black" : 2,
  ]) );
  set ("short", "A Hairpin Loop");
  set( "long", @EndText
You are at a sharp turn on a narrow and steeply sloping path strewn with
boulders of various sizes. The path climbs sharply toward a desolate plain
to the southeast. Southwest of here the path winds down to the base of a
cliff.
EndText
  );
  set( "exits", ([
"east" : MAIN+"/barren.c",
"west" : MAIN+"/clbase.c",
  ]) );

set ("item_desc", ([
  "boulders" : "There's nothing interesting about the rubble.\n",
]) );
}
