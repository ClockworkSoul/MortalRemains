#include <config.h>
#include <mudlib.h>
#include "fuckstick.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
    set("short", "a Dead-End");
  set( "exits", ([
       "east" : AROOM+"street27.c",
  ]) );
}
