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
       "north" : AROOM+"street22.c",
       "south" : AROOM+"street12.c",
  ]) );
}
