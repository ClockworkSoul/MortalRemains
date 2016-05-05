// A room in the starting area, as yet unnamed.
// Blame goes to Cyanide, 22 May 1999

inherit ROOM;

#include "central.h"

void create() {
    set("author", "cyanide");
    set("light", 1);
    set("short", RD_Y);
    set("long", wrap(
	"As you walk north along "+RD_Y+", you notice it gets "+
	"cleaner, and the air gets fresher. You see fewer and fewer "+
	"orcs and humans, and more and more elves, gnomes, and a few "+
	"dwarves. To the direct west of you is the "+CITY_NAME+
	" Police Station, the source of the CopBots which patrol and "+
	"protect the city. To the east is the local Radio Hut."
      ) );
    set("exits", ([
      "east" : M_ROOM+"radiohut.c",
      "west" : M_ROOM+"policesta1.c",
      "north" : M_ROOM+"road0_2.c",
      "south" : M_ROOM+"road0_0.c",
    ]) );
    set("item_desc", ([
      "station" : "It seems to be run mostly by borgs and robots.\n",
      "radio hut" : "The best buys in electronics!\n",
      "orcs" : "Not too many of them here.\n",
      "humans" : "There are a few here, but not too many,\n",
      "dwarves" : "You see a bunch of them to the north.\n",
      "elves" : "There are a few of them here, too.\n",
    ]) );
   ::create() ;
   reset() ;

}

void reset() {
  if (sizeof(children(TOWNSFOLK))<4) {
     clone_object(TOWNSFOLK)->move(TO) ;
   }
 ::reset() ;
} 
// EOF
