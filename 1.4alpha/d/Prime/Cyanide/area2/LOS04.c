#include <mudlib.h>
#include "main.h"

inherit MAIN+"/LOSmain.c";

void create()
{
  ::create();
  seteuid( 0 );
set ("author", " -{ CYANIDE }- ");
set ("arena" ,1);
set ("light", 0);
set ("area_type", ([
  "black" : 4,
  ]) );
set ("short", "Land of Shadow");
  set( "long", @EndText
You are in an ominously dark land of rolling hills. The ground becomes
softer to the south.
EndText
  );
  set( "exits", ([
"north" : MAIN+"/LOS03.c",
"east" : MAIN+"/LOS01.c",
"south" : MAIN+"/LOS05.c",
"west" : MAIN+"/LOS06.c",
"northwest" : MAIN+"/LOS07.c",
  ]) );
set ("exit_suppress", ([
  ]) );

set ("item_desc", ([
  "ground" : "It feels kinda cold, squishy, and wet.\n",
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
