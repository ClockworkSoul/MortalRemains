#include <config.h>
#include <mudlib.h>
#include "fuckstick.h"

inherit ROOM;

void create()

{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
  set("short", "Crossroads of Mainstreet and Valor");
  set( "exits", ([
          "west" : AROOM+"street1.c",
          "south" : AROOM+"street25.c",
          "north" : AROOM+"street10.c",
          "east" : AROOM+"street3.c",
  ]) );
}
