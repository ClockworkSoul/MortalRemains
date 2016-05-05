#include <mudlib.h>
#include <where.h>

inherit ROOM;

void create() {
    ::create();
    set("author","cattt");
    set("light", 1);
    set("short", "Stairs");
    set("long", wrap(
	"You stand on some very creaky stairs. There is evidence that there "+
	"was once a railing, but now all that remains is the few bolts "+
	"screwed into the wall. "
      ) );
    set("item_desc", ([
      "stairs" : "You are standing on them, barely.\n",
      "railing" : "The railing is obviously missing.\n",
      "bolts" : "Bolt that once held the railings in place.\n",
      "wall" : "The wall is dark and covered in graffitti.\n",
      "graffitti" : "The writtings are in various colors and dialects.\n",
    ]) );
    set("exits", ([
      "up" : M_ROOM+"top.c",
      "down" : M_ROOM+"hall2.c",
    ]) );
}
