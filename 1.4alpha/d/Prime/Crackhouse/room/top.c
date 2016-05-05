// QC Passed - Cyanide

#include "where.h"

inherit ROOM;

void create() {
    ::create();
    set("author","cattt");
    set("light", 1);
    set("short", "Top of stairs");
    set("long", wrap(
	"The stairs here lead back down to the first floor. The kitchen "+
	"is well lit to the north. A brief look to the west and you see a "+
	"bathroom. A doorway to a large bedroom is south."
      ) );
    set("item_desc", ([
      "doorway" : "A large doorway that seperates the bedroom from the hall.\n",
    ]) );
    set("exits", ([
      "down" : M_ROOM+"stairs.c",
      "south" : M_ROOM+"bedroom2.c",
   "east" : M_ROOM+"droom",
      "west" : M_ROOM+"bathroom.c",
      "north" : M_ROOM+"kitchen.c",
    ]) );
}
