#include "mall.h"
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "Herself");
    set("short" , "The Security Office");
    set("long", wrap(
	"As you walk into the security office, an overweight "+
	"guard glances up at you. He makes a slight nod "+
	"in your direction, then goes back to watching tv. "
      ) );
    set("item_desc", ([
      "floor" : "It is white and looks freshly waxed. \n",
      "walkway" : "It is white and looks freshly waxed. \n",
      "walk" : "It is white and looks freshly waxed. \n",
      "door" : "It has some lame ass jokes scribbled on it. \n",
      "tv" : "An old rerun of The Andy Griffith Show is on. \n",
      "guard" : "He's pretty fat, and kinda stupid looking. \n",
    ]) );
    set("objects" , (["guard" : MALL+("mons/guard.c") ]) );
reset();
set( "exits", ([
  "south" : MALL+"hall2.c",
]) );
}
