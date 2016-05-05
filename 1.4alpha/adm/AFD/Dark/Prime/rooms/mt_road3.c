#include "../Prime.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;
object ogre;

void create()
{
  seteuid(getuid());  // need this line if your gonna clone anything.
  set( "light", 1 );
  set_outside("Dark");
  set ("short", "the end of a mountain road");
  set( "long", @EndText
You stand in front of a wall of rock.  The forest around you
looms within a field of heat and humidity.  There is a rocky
mountain road which leads steeply to the south.  Beside you
is a small rock dwelling, that perhaps could be called a cave
but was most certainly built by humanoid hands.
EndText
  );
  set ("author", "cyanide");
  set( "exits", ([
    "south" : D_PRIMER+"/mt_road2.c",
    "enter" : D_PRIMER+"/cave_house.c",
  ]) );
  ::create(); // this also resets the room! :)
  set("exit_suppress", ({ "enter" }));
  set ("item_desc", ([
     "cave" : "It looks more like a house built of volcanic rocks.  You might
     want to enter it and find out who lives there.\n",
     "dwelling" : "It looks more like a house built of volcanic rocks.  You might
     want to enter it and find out who lives there.\n",
     "wall" : "The wall of rock is the side of a large mountain.\n",
     "forest" : "It's quite dense with all kinds of vegetation.\n",
     "road" : "The road is relatively wide, with many different sizes of rocks\nblocking normal travel.\n",
   ]) );
   ::create();
}
void reset()
{
  if(!present("beldogar", TO))
  {
    ogre = clone_object(D_PRIMEM+"/ogre.c");
    ogre->move(TO);
    ::reset();
  }
 ::reset();
 }
