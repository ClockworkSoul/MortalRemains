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
The street is plain and boring. But you hear the sound of bells in the far distance.
ENDTEXT
);
   set( "exits", ([
          "east" : AROOM+"street17.c",
          "west" : AROOM+"street15.c",
  ]) );
}
