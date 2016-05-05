// A room in the starting area, as yet unnamed.
// Blame goes to Cyanide, 22 May 1999

inherit ROOM;

#include "/u/c/cyanide/debug.h"
#include "central.h"

void create() {
    ::create();
    set("author", "cyanide");
    set("light", 1);
    set("short", "Red Square");
    set("long", wrap(
	"You are standing in a very large red brick courtyard "+
	"at the center of "+CITY_NAME+" Community College "+
	"affectionately referred to as \"Red Square\" by the "+
	"students here. To the west is the massive Martial Center, "+
	"where the various arts of combat are taught, and to the "+
	"east is the college registrar, where a student can register "+
	"for more peaceful courses. To the north is the Student "+
	"Services Building, where academic advising is available."
      ) );
    set("exits", ([
      "west" : COLLEGE("martial"),
      "east" : COLLEGE("registrar"),
      "north" : COLLEGE("advisor"),
      "south" : M_ROOM+"road4_0.c",
    ]) );
    set("item_desc", ([
    ]) );
}

void reset() {
  if (sizeof(children(TOWNSFOLK))<12) {
     clone_object(TOWNSFOLK)->move(TO) ;
   }
 ::reset() ;
} 
// EOF
