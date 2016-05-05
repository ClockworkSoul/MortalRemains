#include "mall.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "Herself");
    set("short" , "Harmony House");
    set("long", wrap(
	"This is the local Harmony House. There are different "+
	"sections for the different music genres. CD's and Tapes "+
	"but oddly enough, no records. "
      ) );
    set("item_desc", ([
      "floor" : "It is white and looks freshly waxed. \n",
      "sign" : "It says 'Foot Locker'. \n",
      "CD" : "You see a Brittney Spears CD, and you gag. \n",
      "cd" : "You see a Brittney Spears CD, and you gag. \n",
      "prices" : "The prices are a bit high, but not too bad. \n",
      "tapes" : "You pick up a Metallica tape... Master of Puppets! \n",
      "tape" : "You pick up a Metallica tape... Master of Puppets! \n",
      "record" : "Duh! There aren't any here! \n",
      "records" : "Duh! There aren't any here! \n",
      "walkway" : "It is white and looks freshly waxed. \n",
      "section" : "Theres a bunch of em. \n",
      "sections" : "All the ones you'd see in any music store. \n",
      "genre" : "Country, Alternative, Rap, Pop...\n",
      "genres" : "Country, Pop, Alternative, Rap, Rock... \n",
    ]) );
    set("listen" , "You hear a funky dance mix playing. \n");
    set("objects" , ([
      "clerk" : MALL+"mons/clerk.c",
      "teen" : MALL+"mons/teeny.c",
    ]) );
    reset();
    set( "exits", ([
      "west" : MALL+"mall.c",
    ]) );
}
