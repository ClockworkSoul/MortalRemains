#include "mall.h"

inherit ROOM;

object shopper;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "Herself");
    set("short" , "The Foot Locker");
    set("long", wrap(
	"You are in the Foot Locker. Shoes line the display "+
	"shelves. As you catch a glimpe of the prices, you "+
	"almost have a coronary! No self respecting person "+
	"would pay that much for a pair of shoes! "
      ) );
    set("item_desc", ([
      "floor" : "It is white and looks freshly waxed. \n",
      "pair of shoes" : "There are two shoes. One left, one right. \n",
      "shelves" : "Why you lookin there, you planning on buying something? \n",
      "display shelves" : "They have stuff on them.\n",
      "sign" : "It says 'Foot Locker'. \n",
      "shoes" : "There are many different styles. \n",
      "prices" : "You feel faint as you glimpse the price tag. \n",
      "walkway" : "It is white and looks freshly waxed. \n",
      "shoelaces" : "They are plain white. \n",
      "tag#price tag" : "You don't want to look at it... it's scary. \n",
      "counter" : wrap("A few display shelves hold shoelaces "+
	"and other small items. There is a clerk standing here, "+
	"he looks quite like a referee, with his striped shirt. "),
    ]) );
    set("listen" , "You hear a sports announcer. \n");
    set("smell" , "It smells faintly of feet in here. Ew. \n");
    set("objects" , ([
      "unhappy" : MALL+"mons/unhappy.c",
      "clerk" : MALL+"mons/clerk.c",
    ]) );
    reset();
    set( "exits", ([
      "east" : MALL+"mall.c"
    ]) );
}
void reset() {
    if (!shopper) {
	shopper = clone_object(MALL+"mons/shopper.c");
	if (shopper) shopper->move(TO);
    }
    return ::reset();
}
