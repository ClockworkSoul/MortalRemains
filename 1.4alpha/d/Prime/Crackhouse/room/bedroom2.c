// QC Passed - Cyanide

#include <mudlib.h>
#include <where.h>

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("author","cattt");
    set("light", 1);
    set("short", "A large bedroom");
    set("long", wrap(
	"As you walk in you step in a puddle. Instictively you look up and "+
	"notice the skylight, or rather the hole added to the ceiling by the "+
	"tenants. Uselessly dangling next to the skylight is a swinging light "+
	"socket. A bed butts up against the far wall flanked by a pair of "+
	"nightstands. Atop one of them you see something you wish you "+
	"hadn't. "
      ) );
    set("item_desc", ([
      "puddle" : "A rain puddle that gathers on the dirty floor. \n",
      "skylight":"This makeshift skylight sure lets in a lot of light.\n",
      "hole":"This makeshift skylight sure lets in a lot of light.\n",
      "ceiling":"Pieces of the ceiling fall to the floor.\n",
      "socket":"The light socket is missing a bulb.\n",
      "bed":"A large bed, unmade and in disarray.\n",
      "wall":"Chipped and stained, the walls surely need a paint job.\n",
      "nightstands":"The two drawer style stands add storage to the room.\n",
      "nightstand":"Whats that? Right on top you see a used condom! Ick!\n",
      "drawers":"Each stand has 2 drawers. One of them is open.\n",
      "drawer":"An array of various condoms and sexual toys "+
      "fill this drawer.\n",
      "condom":"You wonder how long it has been sitting "+
      "there as goo drips out.\n",
      "condoms":wrap("Large, small, lubricated, even glo-n-dark "+
	"types for a variety."),
      "toys":wrap("A fearfully large vibrator, handcuffs, "+
	"gag and blindfold are noticable here."), 
      "vibrator":"It must be 10\" long, not to mention 4\" wide.\n",
      "handcuffs":"Furry little handcuffs.\n",
      "gag":wrap("A gag looks like it has been used a lot. You "+
	"wonder if it was for pleasure or pain."),  
      "blindfold":"A leather blindfold.\n",
    ]) );
    set("exits", ([
      "north" : M_ROOM+"top.c",
    ]) );

    set("objects", ([
      "ulga" : M_MON+"ulga.c",
    ]) );
    reset();
}
