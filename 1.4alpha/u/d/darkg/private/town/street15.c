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
You come upon the cross street of Valor and Dracinmire.
Nothing is going on here
ENDTEXT
);
  set("exits",([
          "east" : AROOM+"street16.c",
          "south" : AROOM+"street9.c",
          "west" : AROOM+"street14.c",
  ]) );
}
