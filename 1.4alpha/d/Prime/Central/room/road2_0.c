// A room in the starting area, as yet unnamed.
// Blame goes to Cyanide, 22 May 1999

inherit ROOM;

#include "central.h"

void create() {
    ::create();
    set("author", "cyanide");
    set("light", 1);
    set ("short", RD_X);
    set("long", wrap(
	"You are in the Financial Quarter of "+MUD_NAME+", definitely "+
	"one of the cleaner parts of the city. Well-dressed dwarves "+
	"gnomes scurry between huge buildings containing numerous "+
	"banks, insurance companies, accounting firms, and gem traders. "+
	"To the north is the "+CITY_NAME+" branch of the Bank of "+
	MUD_NAME+", and to the south is a small burnt-out church, "+
	"its windows boarded shut."       
      ) );
    set("exits", ([
      "south" : "/d/class/priest/stormlord/rooms/priest_guild.c",
      "west" : M_ROOM+"road1_0.c",
      "east" : M_ROOM+"road3_0.c",
      "north" : M_ROOM+"bank.c",
    ]) );
    set("item_desc", ([
      "church" : "A sign out front reads: \"taLos hAtes yoU.\".\n",
    ]) );
}

void reset() {
  if (sizeof(children(TOWNSFOLK))<12) {
     clone_object(TOWNSFOLK)->move(TO) ;
   }
 ::reset() ;
}
// EOF
