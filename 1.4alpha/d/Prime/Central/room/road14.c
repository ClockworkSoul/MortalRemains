#include <mudlib.h>
#include <central.h>

inherit ROOM;

void create() {
    set("light", 1);
    set("author", "cyanide");
   set("short", "A concrete road.") ;
    set("long", @Endtext
Piles of junk are stacked to the sides of the street. Strangely, the
trash heaps thin out to the south. Apparently, somebody is cleaning
up the trash, but still have a lot to do. A small alley is to the
east between two apartment buildings.
Endtext
    );
    set("item_desc", ([
      "junk" : "They are piled up like hills on the street sides.\n",
      "alley" : "It is very dirty and messy in there.\n",
      "buildings" :
      "Each one is six stories high.  Some of the windows on the buildings\n"+
      "are shattered.  This place has been rendered unfit for occupancy.\n",
    ]) );
    set("exits", ([
      "north" : M_ROOM+"road12",
      "east"  : M_ROOM+"alley1",
      "south" : M_ROOM+"road18",
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

