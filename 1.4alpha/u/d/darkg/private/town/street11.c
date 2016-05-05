#include <config.h>
#include <mudlib.h>
#include "fuckstick.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
   set("short", "Wade Road");
  set( "exits", ([
          "north" : AROOM+"street18.c",
          "south" : AROOM+"street4.c",
          "east" : AROOM+"street12.c",
  ]) );
}
