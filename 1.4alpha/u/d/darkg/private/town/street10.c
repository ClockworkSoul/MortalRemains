#include <config.h>
#include <mudlib.h>
#include "fuckstick.h"
inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
   set("short", "Valor Road");
   set("long", @ENDTEXT
Little children play in the streets. As the main crowd of poeple 
walk around heading south towards the Mainstreet.
ENDTEXT
);
  set( "exits", ([
         "west" : AROOM+"street9.c",
         "south" : AROOM+"street2.c",
  ]) );
}
