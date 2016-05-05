// QC Passed - Cyanide

#include <mudlib.h>
#include <where.h>

int bmon_flag;

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
	"The toilet and tub look to not have been cleaned in years. "
      ) );
    set("item_desc", ([
      "grime" : "Inches upon inches of dirty and grime cover this room.\n",
      "water" : "The water color is brown. Eeew.\n",
      "drip" : wrap("The drip is most annoying. More so because "+
	"you can't stop it."),
      "faucet" : "A dirty faucet that drips constantly.\n",
      "handles" : "Rusty handles that can't seem to turn off the water.\n",
      "tub" : "From a quick glance all that's evident is grime.\n",
      "toilet" : "There's no cover to it and the water looks scary!\n",
      "cover" : "Discustingly enought, there isn't any cover.\n",
    ]) );
    set("smell", ([
      "water" : "It smells like the inside of a sewer! Yuck!\n",
      "default" : "You almost vomit as you smell the air in here.\n",
    ]) );
    set("exits", ([
      "east" : M_ROOM+"top.c",
    ]) );
    bmon_flag = 1;
   set("objects", ([ 
  ]) ) ;
  ::reset() ;
}

void init () {
    add_action ("search", "search");
}

int search (string str) {
    object bmon;

    if (!str) {
	return 0;
    }

    if (str=="tub" && bmon_flag) {
	bmon = clone_object(M_MON+"bmon.c");
	write ("Out of nowhere a big ole creature appears.\n");
	say(wrap(TPN+" disturbs something and out appears Bmon!\n"));
	bmon->move(this_object());
	bmon_flag = 0;
    } else {
	write ("You search around but find nothing of intrest.\n");
    }
    return 1;
}

void reset() {
    ::reset();
    bmon_flag = 1;
}
