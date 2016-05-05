// A room in the starting area, as yet unnamed.
// Blame goes to Cyanide, 22 May 1999

inherit ROOM;

#include "central.h"

void create() {
    set("author", "cyanide");
    set("light", 1);
    set("short", RD_Y);
    set("long", wrap(
	"As you get further from the heart of the city, the buildings "+
	"become smaller and further apart. "+RD_Y+" makes a turn to the "+
	"west, toward the to the city limits, and south back into the "+
	"heart of the city. Directly to the north is the Four Winds Mall, "+
	"its multi-floors stores dominating the local landscape."
      ) );
    set("exits", ([
      "east" : M_ROOM+"road1_5.c",
      "west" : M_ROOM+"road-1_5.c",
      "south" : M_ROOM+"road0_4.c",
      "north" : "/d/Prime/Mall/mall0.c"
    ]) );
    set("pre_exit_func", ([
      "west" : "west"
    ]) );
    set("item_desc", ([
    ]) );
   ::create() ;
   reset() ; 
}

int west() {
    write("You start to walk west, but think better of it "+
      "and return.\n");
    return 1;
}

void reset() {
  if (sizeof(children(TOWNSFOLK))<12) {
     clone_object(TOWNSFOLK)->move(TO) ;
   }
 ::reset() ;
} 
// EOF
