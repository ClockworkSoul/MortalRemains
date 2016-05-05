// A room in the starting area, as yet unnamed.
// Blame goes to Cyanide, 22 May 1999

inherit ROOM;

#include "central.h"

void create() {
    set("author", "cyanide");
    set("light", 1);
    set("short", RD_Y);
    set("long", wrap(
	"You are in the heart of the Elven District. "+
	"To your direct east is an ornate wooden archway leading "+
	"to the popular Balitor Park"
      ) );
    set("smell", ([
      "default" : "A sweet natural smell wafts from the park.\n",
    ]) );
    set("listen", ([
      "default" : "You hear the sounds of birds chirping to the east.\n",
    ]) );
    set("exits", ([
      "east" : "/d/Prime/Park/room/enter.c",
      "north" : M_ROOM+"road0_4.c",
      "south" : M_ROOM+"road0_2.c",
    ]) );
    set("item_desc", ([
      "heart" : "It's not REALLY a heart...\n",
      "archway" : wrap("It is elaborately carved with "+
	"stylized depictions of forest creatures."),
      "park" : "Is is to your east.\n",
      "balitor park" : "It is to your east.\n",
      "depictions" : "Mostly squirrels and deer. Even a few elves.\n",
      "creatures" : "Mostly squirrels and deer. Even a few elves.\n",
    ]) );
   ::create() ;
   reset() ; 
}

// EOF
