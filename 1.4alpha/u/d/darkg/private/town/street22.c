#include <config.h>
#include <mudlib.h>
#include "fuckstick.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
    set("short", "a Busy Bazarr");
  set( "exits", ([
       "south" : AROOM+"street19.c",
       "east" : AROOM+"street23.c",
  ]) );
}
