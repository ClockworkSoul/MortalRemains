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
	"Here "+RD_X+" meets up with the "+CITY_NAME+" River. "+
	"Years ago, a graceful suspension bridge spanned the river, "+
	"but after the quake, closed for safety reasons, it became "+
	"the de facto residence of the homeless of "+CITY_NAME+". From here "+
	"you can see the secondary construction, built piecemeal, with no "+
	"set plan, employing every imaginable technique and material."
	+" The other side of the river is all but unreachable."
      ) );
    set("exits", ([
      "east" : M_ROOM+"road6_0.c",
      "west" : M_ROOM+"road4_0.c"
    ]) );
    set("pre_exit_func", ([
      "east" : "bridge"
    ]) );
    set("item_desc", ([
      "construction" : "It is something amorphous, and startlingly "+
      "organic.\n",
      "bridge" : wrap("It is crowded with the population of a bustling "+
	"interstitial community. "),
    ]) );
}

int bridge() {
    if (!adminp(TP)) {
	write("Access to the bridge is blocked by a 20-foot high fence, "+
	  "\ntopped with miles of looped razor wire. You cannot cross.\n");
	return 1;
    }

   write("ADMIN NOTICE: This area is still closed to players.\n") ;
    return 0;
}
void reset() {
  if (sizeof(children(TOWNSFOLK))<12) {
     clone_object(TOWNSFOLK)->move(TO) ;
   }
 ::reset() ;
} 
//EOF
