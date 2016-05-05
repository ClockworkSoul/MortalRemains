#include "main.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();//<- gets all the information from the original create()
  seteuid( getuid());
  set ("light", -1000);
set("area_type", ([
"black" : 2,
"blue" : 1,
]) );
set ("short", "Underwater");
  set( "long", @EndText
You are under the surface of the stagnant pool. There is an
almost unnatural inky blackness here, and the only sense
you have is touch. Occasionally you bump into something
soft and squishy in the awater. Your lungs are burning
and you feel desperately that you must surface soon.
EndText
  );
set("arena", 1);
  set( "exits", ([
"up" : MAIN+"/room8'3.c",
  ]) );
}

void init()
{
  add_action("dark", "smell");
  }

int dark()
  {
  write ("You would probably drown.\n");
  return 1;
}
