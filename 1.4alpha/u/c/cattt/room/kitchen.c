// QC Passed - Cyanide

#include "where.h"

inherit ROOM;

void create() {
    ::create();
    set("author","cattt");
    set("light", 1);
    set("short", "A bright kitchen");
    set("long", wrap(
	"The kitchen is surprisingly well lit. As you look around "+
	"though, you notice a lack of appliances. Many of the cabinets "+
	"have lost their doors and show how bare they are. Empty packages "+
	"and bottles still cover the floor but also now line the counters. "+
	"A small table sits in the corner. "
      ) );
    set("item_desc", ([
      "appliances" : "All thats left is a refridgerator. \n",
      "refridgerator" : "The outside of it is almost entirely grey.\n",
      "cabinets" : wrap("Dirty and damaged, the cabinets haven't been filled "
	+"in a long time from the looks of it."),
      "doors" : "Few doors are left on these empty cabinets.\n",
      "packages" : "Junk food packaging just tossed aside.\n",
      "bottles" : wrap("Bottles of soda, alcohol and other foods add to the "
	+"mess"),
      "table" : "A table cluttered with junk.\n",
    ]) );
    set("exits", ([
      "south" : M_ROOM+"top.c",
    ]) );
}
