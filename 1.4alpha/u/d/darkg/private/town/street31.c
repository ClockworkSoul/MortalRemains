#include <config.h>
#include <mudlib.h>
#include "fuckstick.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
    set("short", "Valor");
  set( "exits", ([
       "south" : AROOM+"street32.c",
       "north" : AROOM+"street27.c",
  ]) );
}
