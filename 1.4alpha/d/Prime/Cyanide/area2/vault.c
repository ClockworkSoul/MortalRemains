#include <mudlib.h>
#include "main.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
set ("author", "cyanide");
set ("arena" ,1);
set ("light", 0);
set ("short", "Cyanide's Vault of Fools");
  set( "long", @EndText
This is where Cyanide keeps the corpses of the foolish.

There is a large, black, pulsating portal here.
EndText
  );
  set( "exits", ([
"portal" : MAIN+"/topiary.c",
  ]) );

set ("item_desc", ([
]) );
}
