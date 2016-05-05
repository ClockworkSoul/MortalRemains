#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
set ("objects", ([ "sphere" : "/u/r/rehnbi/items/sphere"]));
reset();
 set("short", "Entrance to a Floating Castle");
  set("long", @ENDTEXT
You enter through a rope that dangles about a mile down to
the ground.  You feel dizzy for a moment and then regain your
composure.  You look around and see a large crystal ball
floating seemingly unsuspended about 13 feet off the ground
from the domed ceiling.  You then see that a thin magical
wire holds the sphere from a shattering doom.  
ENDTEXT
);
  set( "exits", ([
"east" : "/u/r/rehnbi/rooms/halleast1.c",
"west" : "/u/r/rehnbi/rooms/hallwest1.c",
  ]) );
  set("item_desc", ([
 ]) );
}


