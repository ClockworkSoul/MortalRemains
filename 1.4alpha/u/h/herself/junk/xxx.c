#include "mall.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "Herself");
    set("objects" , (["man" : MALL+"mons/bondage.c" ]) );
    reset();
    set("short" , "The Sex Shop");
    set("long", wrap(
	"This shop is for all the perverts of the world. "+
	"An abundant supply of sex toys are all around you. "+
	"A glimpse of the stores stock makes "+
	"you blush. I sincerely hope you are at least 18."
      ) );
    set("item_desc", ([
      "floor" : "It is white and looks freshly waxed. \n",
      "sign" : "It says 'Sex Shop'.\n",
      "shoes" : "There are many different styles. \n",
      "walkway" : "It is white and looks freshly waxed. \n",
    ]) );
    set("listen" , "You hear a faint moaning sound. \n");
    set("smell" , "It smells like some exotic oils. \n");
    set("objects" , (["shopper" : MALL+("mons/shopper.c") ]) );
reset();
set( "exits", ([
  "east" : MALL+"mall6.c",
]) );
}
