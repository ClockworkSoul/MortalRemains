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
         "west" : AROOM+"street6.c",
  ]) );
}
