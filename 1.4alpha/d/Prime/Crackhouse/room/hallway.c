// QC Passed - Cyanide

#include "where.h"

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("author","cattt");
    set("light", 1);
    set("short", "A stinky, dark hallway");
    set("long", wrap(
	"This narrow hallway looks like a bomb just hit it. "+
	"There is trash thrown all around the floor making it "+
	"hard for you to even pass through."
      ) );

    set("item_desc", ([
      "hallway" : "Trash covers the floor and almost climbs the walls.\n",
      "trash" : wrap("From a quick glance you can notice bottles, empty "+
	"wrappers, paper, among other things."),
      "walls" : "The hall walls are dark and dirty.\n",
      "floor" : "Floor? Oh you mean all this trash?\n",
      "bottles" : "Mostly glass bottles of alcohol.\n",
      "wrappers" : "Junk food wrappers are everywhere. \n",
      "paper" : wrap("In this darkness you can't make out what kind of "+
	"trash it is."),
    ]) );
    set("exits", ([
      "west" : M_ROOM+"entrance.c",
      "north" : M_ROOM+"hall2.c",
    ]) );



    set("objects", ([
      "bum" : M_MON+"orcbum.c",
    ]));
    reset();
}

