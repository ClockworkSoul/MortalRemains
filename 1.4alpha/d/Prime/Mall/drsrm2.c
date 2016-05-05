#include "mall.h"
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "Herself");
    set("short" , "A Fitting Room");
    set("long", wrap(
	"A small room that contains only a tiny wooden stool, "+
	"and a shelf. A mirror covers one entire wall, and "+
	"an extremely bright light hangs overhead. A tailor is "+
	"waiting here to get you fit for your tuxedo."
      ) );
    set("item_desc", ([
      "mirror" : "It is huge and covers the whole wall. \n",
      "stool" : "It's really small, maybe 6inches high. \n",
      "wooden stool" : " A small stool made out of wood. \n",
      "tiny wooden stool" : "It's really small, and wooden. \n",
      "wall" : "Looks like a wall to me. \n",
      "light" : wrap("The light is extremely bright. "+
	"A bulb sticks out of a shadeless light fixture. "+
	"When you look away you still see spots for a second. "),
      "shelf" : wrap("Fixed to the wall is a shelf with all "+
	"the tailors tools. You see a tape measure, pin cushion, "+
	"complete with a wide selection of pins, and some scissors. "),
      "floor" : "It is white and looks freshly waxed. \n",
      "walkway" : "It is white and looks freshly waxed. \n",
      "walk" : "It is white and looks freshly waxed. \n",
      "scissors" : "They look sharp.\n",
      "pin cushion" : "There are pins stuck in it. \n",
      "pin" : "A regular straight pin.\n",
      "tape measure" : "To measure you with.\n",
      "cushion" : "Pins are stuck in it.\n",
      "tools" : "Just the regular stuff a tailor uses. \n",
    ]) );
    set("objects" , (["tailor" : MALL+("mons/tailor.c") ]) );
reset();
set( "exits", ([
  "west" : MALL+"store9.c",
]) );
}
