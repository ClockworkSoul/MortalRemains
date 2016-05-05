#include "mall.h"
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "Herself");
    set("short" , "The Ladies' Room");
    set("long", wrap(
	"You enter the ladies' lavatory. The walls are a puke "+
	"pink color. Three stalls are at the far end, they appear "+
	"to be occupied. "
      ) );
    set("item_desc", ([
      "stall" : "You peek under the stall door. What a pervert! \n",
      "stalls" : "There's three of them. \n",
      "sink" : "Oddly, it looks like it's never been used. \n",
      "wall" : "Pukey pink. \n", 
      "walls" : "Puky pink.\n",
      "floor" : "It is white and looks freshly waxed. \n",
      "walkway" : "It is white and looks freshly waxed. \n",
      "walk" : "It is white and looks freshly waxed. \n",
      "toilet" : "Someone is using it. \n",
      "door" : wrap("There's a heart drawn on the door, inside "+
	"someone scribbled 'I Love Donnie' "),
    ]) );
    set( "exits", ([
      "west" : MALL+"hall3.c",
    ]) );
}
void reset(){
    object ob;
    if(!present("teen")){
	ob = clone_object(MALL+"mons/teen.c");
	ob->move(TO);
	ob = clone_object(MALL+"mons/teen.c");
	ob->move(TO);
    }
}
