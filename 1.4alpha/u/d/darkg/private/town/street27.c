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
       "north" : AROOM+"street25.c",
       "west" : AROOM+"street26.c",
       "east" : AROOM+"street28.c",
       "south" : AROOM+"street31.c",
  ]) );
}
