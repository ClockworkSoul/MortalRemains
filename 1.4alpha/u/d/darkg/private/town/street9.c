#include <config.h>
#include <mudlib.h>
#include "fuckstick.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
   set("short", "Valor Road");
set("long", @ENDTEXT
To the west you hear laughter and music comming from the pub.
to the east the road twist about.
ENDTEXT
);
  set( "exits", ([
         "east" : AROOM+"street10.c",
         "west" : AROOM+"tavern.c",
         "north" : AROOM+"street15.c",
  ]) );
}
