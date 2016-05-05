// QC Passed - Cyanide

#include <mudlib.h>
#include <where.h>

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("author","cattt");
    set("light", 1);
    set("short", "A small bedroom");
    set("long", wrap(
	"This room consists mearly of a mattress on the floor, a small "+
	"chest that looks more tattered than not, and trash. "+
	"The room is cold, as a breeze blows in from the boarded "+
	"window. "
      ) );
    set("item_desc", ([
      "mattress" : "A bare mattress that has seen better days. \n",
      "floor" : "Paper and trash line the floor.\n",
      "chest" : "The old chest with a big padlock on it.\n",
      "trash" : wrap("Trash is EVERYWHERE!  Among the papers "+
	"and obvious junk you can easily see drug paraphanalia."),
      "window" : "Just another boarded up window.\n",
      "paper" : "Paper that should just be in the garbage.\n",
      "padlock" : "A large padlock that is closed tight.\n",
      "junk" : "Pushing around the junk reveals just more trash.\n",
      "paraphanalia" : wrap("Drug syringes and roach clips are scattered"+
	" about.\n"),
      "breeze" : "A slight breeze blows in from the window.\n",
      "syringes" : "Dirty syringes are all over. \n",
      "clips" : "Clips used for drugs are all about. They look used.\n",
    ]) );
    set("exits", ([
      "east" : M_ROOM+"hall2.c",
    ]) );
    set("objects", ([
      "chest" : M_OBJ+"slumchest.c",
    ]) );
    reset ();
}
