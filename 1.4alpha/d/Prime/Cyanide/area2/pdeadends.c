#include "main.h"

inherit ROOM;
clean_up () {
  remove () ;
}

void create()
{
  ::create();
  seteuid( 0 );
set ("author", "cyanide");
set ("arena" ,1);
set ("light", 0);
set ("area_type", ([
  "black" : 2,
  ]) );
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
void init () {
add_action ("exits","exits");
}
int exits() {
write ("You begin to get a nasty headache.\n");
say (NAME+" begins to look very confused.\n");
return 1;
}