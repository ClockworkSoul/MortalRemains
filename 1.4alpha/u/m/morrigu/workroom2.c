//Last edited by Morrigu 4/29/97
//from generic workroom "workroom.c"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
   // Inspiral fears Root euid.  94-08-18
seteuid(geteuid());
  set( "light", 1 );
set( "short", "A long tunnel");
set( "long" , @EndText
You are standing at one end of a long
white tunnel, with a light at the far
end.  Could this be a way out?
EndText
);
  set( "exits", ([
  "out" : "~morrigu/workroom.c",
  ]) );
}
