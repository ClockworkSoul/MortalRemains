#include <config.h>
#include <mudlib.h>
#include "fuckstick.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
  set("short", "adventurers Guild");
  set( "exits", ([
          "south" : AROOM+"street17.c",
  ]) );
}
