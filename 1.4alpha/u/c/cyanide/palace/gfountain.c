#include "main.h"

inherit MAIN+"/gardenstd.c";

void create() {
    ::create();
    set("short", "By A Garden Fountain");
    set("long", @EndLong
You find yourself in a small corner of Cyanide's Garden where a
large pink marble foutain is located. All around the area huge palm
fronds and small trees with metallic leaves of gold, silver, blue
and green. In the very center of the fountain, standing majestically,
is a statue of Cyanide himself, a plume of water pouring from the
tip of his outstretched staff into the large basin.
EndLong
    );
    set("item_desc", ([
      "fountain" : "It is basically a large statue "+
      "standing over a basin.\n",
      "basin" : wrap("It is about three feet deep, and inhabited "+
	"by some rather nasty-looking toothed fish.\nThere is"+
	"some writing carved into the front of the basin."),
      "writing" : "It reads: Why are you reading my basin?\n",
      "plume" : "The just succeed in getting soaking wet.\n",
      "fronds" : "They seem to be normal palms, just very large.\n",
      "trees" : "They have metallic leaves of every color imaginable.\n",
      "statue" : wrap("A rather good likeness, you think, "+
	"except he's balder in real life."),
    ]) );
    set("exits", ([
      "north" : MAIN+"/gpathe.c",
      "west" : MAIN+"/topiary.c",
    ]) );
}
