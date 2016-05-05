#include "main.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;
inherit DOORS;

void create()
{
    ::create();
    seteuid( getuid());
    set("short", "Entry Gates");
    set( "long", @EndText
Giant roaring dragons of stone stand to either side of Urborgs's
thirty-foot-tall, black iron gates. The statue on the left of the gate
has been shattered, and most of its upper half is missing.
EndText
    );
    set("author", "cyanide");
    set("forbidden", 1);
    set("item_desc", ([
      "statue" : "There are two of them, remember?\n",
      "dragon" : "There are two of them... kinda.\n",
      "gates" : wrap("The gates are of some kind of unusually "+
	"dark and dense metal. It is deeply pitted, as if "+
	"subjected to a great heat."),
      "statues" : wrap("They appear to be constructed of a black "+
	"glass-like stone. The one which is damaged also shows "+
	"the evidence of being heated greatly."),
      "dragons" : wrap("They are ancient works of incredible "+
	"are, and are remarkably detailed."),
    ]) );
    set( "exits", ([
      "phase" : MAIN+"/room3'5.c",
      "west" : MAIN+"/topiary.c",
    ]) );
    set ("exit_suppress", ({ "phase" }) );
    set ("exit_msg", ([
      "phase" : "$N passes through the iron gates.\n",
    ]) );
    /*
	create_door ("east", "west", "Great black iron gates", 
	  "locked", "sooty_key", 50);
    */
}

void reset()
{
    object guard, guard2;
    ::reset();
    seteuid( getuid());
    if (present("guard", this_object())) return;
    guard=clone_object(MONST+"/dreadguard.c");
    guard->move(this_object());
    if (present("guard2", this_object())) return;
    guard2=clone_object(MONST+"/dreadguard2.c");
    guard2->move(this_object());
}

void init () {
    add_action("is_guard_here", "bash");
    add_action ("exits","exits");
}

int exits() {
    write ("You begin to get a nasty headache.\n");
    say (NAME+" begins to look very confused.\n");
    return 1;
}

int is_guard_here() {
    object ob;

    ob = present("dreadguard", this_object());

    if (ob) {
	write("You can't do that with the Dreadguards right there.\n");
	return 1;
    }

    return 0;
}
