// Cyanide coded this.

#include "school.h"

inherit S_STD_ROOM;

void create() {
    ::create();
    set("short", "Security Gate");
    set("long", @EndLong
The road here is divided into two seperate roads, one per lane it would
seem. Between the two roads is a small little gatehouse, barely large 
enough for one man to sit in. To the west is the school parking lot. There
is a large concrete sign here.
EndLong
    );
    set("objects", ([
      "earl" : S_MON("earl.c")
    ]) );
set("exits", ([
  "southeast" : "/d/Prime/Central/room/road-2_-6.c",
  "west" : S_ROOM("parkloteast.c"),
]) );
set("item_desc", ([
  "road" : "It is divided into two roads.\n",
  "roads" : "Each one is a different direction of traffic.\n",
  "gatehouse" : "It looks a place where a guard would normally reside.\n",
  "sign" : "@@query_sign",
]) );
reset();
}

string query_sign() {
    return sprintf("Brainwash Senior High School\n", "%|75s");
}


/* EOF */         
