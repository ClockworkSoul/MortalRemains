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
   set("long", @ENDTEXT
The same boring things happen here.
To the north is the guild hall.
ENDTEXT
);
  set( "exits", ([
          "east" : AROOM+"street18.c",
          "west" : AROOM+"street16.c",
          "north" : AROOM+"guild.c",
  ]) );
}
