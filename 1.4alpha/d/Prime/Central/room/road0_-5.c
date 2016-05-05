#include <mudlib.h>
#include "central.h"

inherit ROOM;

void create() {
    set("light", 1);
    set("author", "cyanide");
    set("short", RD_Y);
    set("long", @Endtext
The road intersects with another trash filled road to the east and 
west. A modest building, under construction, stands to the south.
Piles of garbage continue to line the sides of the road. A tall pole
stands on the side pavement, with swiveling camera mounted on the top.
Endtext
    );
    set("item_desc", ([
      "building" : "It is small, and still under construction.\n",
      "garbage" : "Nothing seem to be too interesting about the trash.\n",
      "pole" : "It is about the height of an average street light.\n",
      "camera": "It is moving back and forth slowly... watching.\n",
    ]) );
    set("exits", ([
      "north" : M_ROOM+"road0_-4.c",
      "east"  : M_ROOM+"road11",
      "west" : M_ROOM+"road-1_-5.c",
    ]) );
   ::create() ;
   reset() ; 
}

void reset() {
  if (sizeof(children(TOWNSFOLK))<6) {
     clone_object(TOWNSFOLK)->move(TO) ;
   }
 ::reset() ;
} 
/* EOF */
