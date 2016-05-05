#include <mudlib.h>
#include "/d/Dark/High/high.h"

inherit ROOM;

void create()
{
  seteuid(geteuid());
  set("author","highlander");
  set( "light", 1 );
  set_outside("Dark");
  set("short","-=The Town Square of Cho'gall=-");
  set( "long", @EndText
    You are standing at the intersection Zuljin Street and Sargeras Road,
in the center of the town of Cho'gall.  The village is small, yet bustling 
with travellers and businessmen.  The roads are either of some wierd red
rock, or they have been stained with blood from the decades of war that this
town has seen. Either way its kind of unsettling.  The business district 
lies to the east and west along Zuljin Street, while Sargeras Road appears 
to lead north to a residential area, and south to some sort of shrine.  
     There is a statue here.

EndText
  );
  set( "exits", ([
	"north":HIGHRM"/sn1.c",
	"south":HIGHRM"/ss1.c",
	"east":HIGHRM"/ze1.c",
	"west":HIGHRM"/zw1.c",
    ]) );
     set("item_desc", ([
     "zuljin street":"The main road leading east/west through Cho'gall.\n",
     "sageras road":"The main north/south road through Cho'gall.\n",
     "road":"A cobblestone road made out of red rock, or maybe its blood-stained.\n",
     "statue":"It is a statue of Cyanide, the God of Darkness.\n",
     "zuljin":"This is the main east/west road through town.\n",
     "sargeras":"This is the main north/south road through town.\n",
       ]) );
  ::create(); // this also resets the room! :)
}
