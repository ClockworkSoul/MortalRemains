#include <mudlib.h>
#include "central.h"

inherit ROOM;
int i;

void create() {
    set("light", 1);
    set("short", "Main Street, Near the Orc District");
    set("author", "cyanide");
    set("long", wrap(
	"The sides of the road are stacked high with garbage. A few pieces of "+
	"trash look interesting, but upon closer inspection are utterly "+
	"useless. Small traces of a black substance is inside the cracks of "+
	"the damaged concrete. A shop to the east has a flickering pink "+
	"fluorescent sign which reads 'PAWN SHOP'. A seedy gunshop is to the west. "+
	"A manhole is in the "+
	"middle of the street. " 
      ) );
    set("item_desc", ([
      "garbage" : "It consists mainly broken machines and papers.\n",
      "substance" : "It appears to be gasoline.\n",
      "concrete" : "It has been quite some times since it was repaired.\n",
      "manhole" : "It leads underground into the city's sewer system.\n",
      "sign" : "North: City Center\nSouth: Docks\nEast: Orc District\n",
      "shop" : "You could probably sell stuff there.\n",
      "sign" : "Its quite old, it seems.\n",
      "bottles" : "Almost all 45 oz. bottles of Colt 45.\n",
      "trash" : wrap("Some old newspapers, a few empty beer bottles, "+
	"and a sticky orcish pornographic magazine"),
      "magazine" : "It seems to be a wart fetish magazine. Yuck!\n",
      "newspapers" : "They aren't worth your time.\n",
      "gunshop" : "It's called 'Grik's Armaments'.\n",
      "gun shop" : "It's called 'Grik's Armaments'.\n", 
    ]) );
    set("exits", ([
      "south" : M_ROOM+"road0_-5",
      "west" : M_ROOM+"armaments",
      "east" : M_ROOM+"pawnshop.c",
      "north" : M_ROOM+"road0_-3",
    ]) );
    i = 0;
   ::create() ;
   reset() ; 
}

void init() {
    add_action("open_hole", "open");
}

int open_hole(string str) {
    if(!str) return 0;
    if(str == "manhole") {

	/*
		// TEMPORARY
		write("It seems stuck.\n");
		return 1;
	*/

	if(i!=0) {
	    write("The manhole is already open.\n");
	    return 1;
	}
	write("With a little effort, you open the manhole cover.\n");
	say(TPN+" pulls open the manhole cover.\n");
	set("exits/down", "/d/Prime/Sewers/room/sewer00.c"); 
	i = 1;
	return 1;
    }
    return 0;
}

