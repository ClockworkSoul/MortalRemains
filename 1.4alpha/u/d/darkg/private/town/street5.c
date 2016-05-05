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
  set( "exits", ([
         "south" : AROOM+"street30.c",
         "west" : AROOM+"street4.c",
         "east" : AROOM+"street6.c",
  ]) );
}
