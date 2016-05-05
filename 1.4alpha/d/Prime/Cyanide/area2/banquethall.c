#include "main.h"

inherit ROOM;

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
  set ("short", "Collapsing Banquet Hall");
  set( "long", @EndText
This was once an ornate banquet hall, where the greatest of visiting royalty
of the time once dined. Time, however, has taken its toll here: the
entire eastern end of the hall seems to have collapsed, filling the room
with dust and debris. A mammoth cupboard against the south wall was once
full of ceramic plates and cups, but it has ben shattered and most of the
items smashed on the stone floor.
EndText
  );
  set( "exits", ([
  "west" : MAIN+"/phallcs.c",
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
