#include <config.h>
#include <mudlib.h>
#include "fuckstick.h"

inherit PUB;

void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
   set("short", "Gideon's Bar and Grill");
  set("long", @ENDTEXT
The smell of burnt meat fills your nostrils, as does the thick
smoke from the candles.
Commands are: menu, drink <drinkname>, powerheal <drinkname> .
ENDTEXT
);
  set( "exits", ([
         "east" : AROOM+"street9.c",
  ]) );
}
