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
This is the end of the street. There is a chapel to the
northwest. The bells of the chapel ring occasonally.
ENDTEXT
);
  set( "exits", ([
          "northwest" : AROOM+"chapel.c",
          "east" : AROOM+"street15.c",
  ]) );
}
