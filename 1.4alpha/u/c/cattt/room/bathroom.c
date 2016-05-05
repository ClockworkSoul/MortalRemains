// QC Passed - Cyanide

#include <mudlib.h>
#include <where.h>

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("author","cattt");
    set("light", 1);
    set("short", "Bathroom");
    set("long", wrap(
	"As you walk into the bathroom the grime all around disgusts you. "+
	"The smell of urine and vomit penetrate your senses. Water drips "+
	"from the faucet and try as you might, tighting the handles doesn't "+
	"help. You wonder how anyone could attempt to get clean here. "+
        "The toliet and tub look to not have been cleaned in years. "
      ) );
    set("item_desc", ([
      "grime" : "Inches upon inches of dirty and grime cover this room.\n",
      "water" : "The water color is brown. Eeew.\n",
      "drip" : wrap("The drip is most annoying. More so because "+
	"you can't stop it."),
      "faucet" : "A dirty faucet that drips constantly.\n",
      "handles" : "Rusty handles that can't seem to turn off the water.\n",
      "tub" : "From a quick glance all that's evident is grime.\n",
      "toliet" : "There's no cover to it and the water looks scary!\n",
      "cover" : "Discustingly enought, there isn't any cover.\n",
          ]) );
    set("smell", ([
      "water" : "It smells like the inside of a sewer! Yuck!\n",
      "default" : "You almost vomit as you smell the air in here.\n",
    ]) );
    set("exits", ([
      "east" : M_ROOM+"top.c",
    ]) );
}
void init () {
    add_action ("search", "search");
}

int search (string str) {
    object bmon;

    if (!str) {
        return 0;
    }

    bmon = clone_object(M_MON+"bmon.c");

    if (str=="tub") {
        write ("Out of nowhere a big ole creature appears.\n");
        say(wrap(TPN+" disturbs something and out appears Bmon!\n"));
        bmon->move(this_object());
   } else {
        write ("You search around but find nothing of intrest.\n");
    }
    return 1;
}

