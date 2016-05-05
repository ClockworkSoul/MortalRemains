#include <mudlib.h>
#include "/d/Dark/High/high.h"

inherit ROOM;

void create()
{
  seteuid(geteuid());
  set("author","highlander");
  set( "light", 1 );
  set("short","-=Kilrogg's House=-");
  set( "long", @EndText
This house could pass for a shrine to death, with the heads and skeletons 
of every possible animal mounted on the wall, and dead birds suspended
from the ceiling.  There is a desk and chair made out of various bones 
in one corner of the room, and a big pile of furs along the west wall.
The only other thing of interest in this small house is the large red-brick
fireplace in the northwest corner of the house.
EndText
  );
  set( "exits", ([
    "east":HIGHRM"/ss1.c",
    ]) );
     set("item_desc", ([
     "heads" : "Wolf, bear, moose and other heads line the walls, along with more exotic animals.\n"
       ]) );
  set("search_desc", ([
	]) );
  ::create();
}
