
#include "macrosoft.h"

inherit MS_STD_ROOM;

void create() {
    ::create();
    set("short", "A hallway");
    set("long", wrap(
	"You have entered a dark chamber, completely undecorated. In "+
	"the center of the room is a single sturdy wooden chair, "+
	"upon which a bright spotlight is focused. The chair sems "+
	"to contain a recently dead corpse. Next to this "+
	"chair is a simple wooden table, upon which many instruments "+
	"are arranged in almost surgical organization."
      ) );
    set("exits", ([
      "east" : FLOOR_7("tjunction.c"),
    ]) );
    set("item_desc", ([
      "chamber" : "You are standing within it.\n",
      "chair" : wrap("It has been furnished with thick leather "+
	"straps for the arms, legs and head. Parts of the chair "+
	"are deeply blood stained."),
      "spotlight" : "It comes from the ceiling somewhere.\n",
      "ceiling" : "Its way above you, in the darkness.\n",
      "table" : wrap("Horrific instruments of torture are "+
	"carefully arrayed upon it."),
      "instruments" : wrap("Many of the are unidentifiable, and seem to "+
	"have no other purpose than to inflict horrible pain."),  
      "corpse" : wrap("It is the corpse of a man wearing what "+
	"appears to have once been casual office attire. The "+
	"remains of an adhesive name tag read \"Hello, My Name "+
	"Is: Linus Torvalds\"."),
    ]) );
    reset();
}

/* EOF */
