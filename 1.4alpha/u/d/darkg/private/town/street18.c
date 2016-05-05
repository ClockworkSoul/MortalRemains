#include <config.h>
#include <mudlib.h>
#include "fuckstick.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
   set("short", "Dracinmire Road");
  set( "exits", ([
          "west" : AROOM+"street17.c",
          "south" : AROOM+"street11.c",
  ]) );
}
