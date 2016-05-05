#include <mudlib.h>
#include <sewers.h>
#include "../generic/GenericLib.h"

inherit ROOM;
inherit GLibDir+"populate_generic_monsters.c"; 

void create() {
    ::create();
    set("author","cattt");
    set("light", 0);
    set("short", "A sewer intersection");
    set("long", wrap(
	"The dark and dreary sewer is wet and the smell is horendous.  "+
	"Water, or you hope its just water, is up to your calves.  "+
	"The paths never seem to end and you even wonder if there is a "+
	"way out of this hellhole. "
      ) );
    set("item_desc", ([
      "sewer ":"You are in the dark sewers.  \n",
      "water":"The water is dirty and dark and smells BAD! \n",
    ]) );
    set("smell", ([
      "water" : "The water smells putrid.\n",
      "default" : "You almost vomit as you smell the air in here.\n",
    ]) );
  populate_generic_monsters(TO);   
}

void reset_quest(){
  object obj;
  obj = find_object_or_load(M_OBJ+"skull");
  obj->move(M_ROOM+"sewer"+random(8)+""+random(8));
  obj = find_object_or_load(M_OBJ+"tooth");
  obj->move(M_ROOM+"sewer"+random(8)+""+random(8));
  obj = find_object_or_load(M_OBJ+"mug");
  obj->move(M_ROOM+"sewer"+random(8)+""+random(8));
  obj = find_object_or_load(M_OBJ+"gem");
  obj->move(M_ROOM+"sewer"+random(8)+""+random(8));
  obj = find_object_or_load(M_OBJ+"rock");
  obj->move(M_ROOM+"sewer"+random(8)+""+random(8));
  obj = find_object_or_load(M_OBJ+"paper");
}
