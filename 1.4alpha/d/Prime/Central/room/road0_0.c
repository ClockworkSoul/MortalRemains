// A room in the starting area, as yet unnamed.
// Blame goes to Cyanide, 22 May 1999

inherit ROOM;

#include "central.h"

object helper;

void create() {
    seteuid(getuid());
    set("author", "cyanide");
    set("light", 1);
    set("short", "The Intersection of "+RD_Y+" and "+RD_X);
    set("long", wrap(
	"You stand at the intersection of Main Street and Intercity"+
	" Highway 4, which is in a terrible state of disrepair. Trash "+
	"and old newspapers blow in the wind here, and the acrid smell "+
	"of urine occasionally drifts past you. Things look a bit "+
	"cleaner to the north, by the Elven District, but appear to be "+
	"considerably worse down by the docks to the south, where the "+
	"Orc District lay. To the east is the arena and the Financial "+
	"Quarter."
      ) );
    set("smell", "You faintly smell trash and the reek of urine.\n");
    set("exits", ([
      "north" : M_ROOM+"road0_1.c",
      "west" : M_ROOM+"startroom.c",
      "east" : M_ROOM+"road1_0.c",
      "south" : M_ROOM+"road0_-1.c",
    ]) );
    set("item_desc", ([
      "newspapers" : "They have yesterday's date.\n",
      "trash" : "Mostly old styrofoam cups and papers.\n",
      "intersection" : "Where two streets meet.\n",
      "elven district" : "You can't quite make it out from here.\n",
      "docks" : "You can't see them from here!\n",
      "street" : "It is plagued by deep cracks and potholes.\n",
    ]) );

   ::create() ;
    reset() ;
}

void reset() {
  if (!helper) {
    helper = clone_object("/u/c/chronos/alucard.c") ;
      helper->move(TO) ;
  }
  ::reset() ;
}
// EOF
