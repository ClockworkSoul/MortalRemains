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
         "west" : AROOM+"street3.c",
         "north" : AROOM+"street11.c",
         "east" : AROOM+"street5.c",
  ]) );
}
