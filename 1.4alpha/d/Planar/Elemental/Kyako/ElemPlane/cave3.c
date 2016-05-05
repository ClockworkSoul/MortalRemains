#include <mudlib.h>
#include "plane.h"

inherit ROOM;

void create()
{
  seteuid(getuid()) ;
    ::create();
    seteuid(geteuid());
    set("light", 1);
    set ("objects", ([ "panel" : PLANE+"obj/panel" ]) );
    set("short", "Panel");
    set( "long", @EndText
You have come to the end of the underwater passageway.
The panel here may be of use for helping you get out.
EndText
    );
    set( "exits", ([
      "east" : PLANE+"cave2.c",
    ]) );
  reset() ;
}
