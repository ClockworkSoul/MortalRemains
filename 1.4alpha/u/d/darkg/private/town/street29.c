#include <config.h>
#include <mudlib.h>
#include "fuckstick.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
    set("short", "Robin Blvd");
  set( "exits", ([
       "west" : AROOM+"street28.c",
       "east" : AROOM+"street30.c",
  ]) );
}
