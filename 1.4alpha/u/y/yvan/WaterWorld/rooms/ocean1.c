
#include <mudlib.h>
#include "../ww.h"
#include "/u/d/dragoon/include/format.h"
#include "drown.h"

inherit ROOM ;

void create() {
    ::create() ;
    seteuid(getuid()) ;
    set("short", "ocean floor") ;
    set("long", format(
        "Very little light penetrates this far beneath the ocean's surface. "
        "There is just enough to make out the assortment of seaweed that covers "
        "and grows out of the rock which forms the substance of the ocean floor. "
        "Just east of here, the water seems to end suddenly, as if held back "
        "by unnatural forces. The ocean continues unchanging in all other directions. "
	"There is nothing out of the ordinary about it. "
      )) ;
    set("light", 1) ;
    set("item_desc", ([
      "water" : "Deep ocean water. Very little light gets down this far.\n",
      "floor" : "The bottom of the ocean. It is very rocky.\n",
      "rock" : "Average greyish brown stone.\n",
    ])) ;
    set("exits", ([
      "down" : "/u/y/yvan/workroom.c"
    ])) ;
    water_on = 0 ;
}

void init() {
    turn_on() ;
}

/* EOF */
