#include <config.h>
#include <mudlib.h>
#include "fuckstick.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
set( "light", 1 );
  set("short", "Main Street");
  set("long", @ENDTEXT
The dirty path turns into a small village.
People scurry around.
ENDTEXT
);
  set( "exits", ([
   "west" : AROOM+"dirt4.c",
          "east" : AROOM+"street2.c",
  ]) );
}
