/*
// This file contains the code for a generic workroom.
// It is used by _home.c if your own workroom won't load.
// It is used by _sponsor.c to provide new wizards
//   with a basic home that they can edit to their own taste.
*/

// config.h only included here for the defines of START and VOID
// it doesn't need to be included in most rooms.
#include <config.h>
#include <mudlib.h>

inherit ROOM;
int violet_here;

void create()
{
  ::create();
  seteuid( getuid() );
violet_here=1;
  set( "light", 1 );
set( "author", "sophia");
set( "short", "A Meadow" );
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
The path has led into a wide open meadow bursting with colour.
Flowers bloom everywhere and small animals scurry out of
your way as you walk towards a blanket laid out between
mounds of wild violets.
EndText );
  set( "exits", ([
"north" : "/u/s/sophia/herbgarden.c",
  ]) );
set("item_desc", ([
"violets" : "little wild violets that bloom in profusion. 
You could probably pick one or two without harming the plant.\n",
]) );
}
void init() {
add_action("pick", "pick");
}
int pick (string str) {
object violet ;
if (str=="violet") {
if (violet_here) {
violet=clone_object("/u/s/sophia/violet.c");
violet->move(TP);
write("You pick one of the beautiful violets.\n");
say(TPN+"picks a violet.\n");
violet_here=0;
return 1;
}
return 0;
}
}
