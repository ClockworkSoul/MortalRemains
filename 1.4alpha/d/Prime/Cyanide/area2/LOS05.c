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
  "black" : 5,
  "blue" : 1,
  ]) );
set ("short", "Land of Shadow");
  set( "long", @EndText
You are at the southern end of a shadowy land. The ground here is quite
soft, and the area is surrounded by quicksand on most sides. North of here
is a terrain of shallow hills.
EndText
  );
  set( "exits", ([
"northeast" : MAIN+"/LOS01.c",
"north" : MAIN+"/LOS04.c",
"northwest" : MAIN+"/LOS06.c",
  ]) );

set ("exit_suppress", ([
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
