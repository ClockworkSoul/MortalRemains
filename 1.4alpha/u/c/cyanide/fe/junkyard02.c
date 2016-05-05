#include <mudlib.h>
#include <path.h>

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("light", 1);
    set("short", "A small junkyard");
    set("long", @Endtext
The mountain of rubble here is incredibly high.  It is a wonder how
trash can be stacked into such a towering structure.  The garbage
here consists mainly of smaller mechanical parts like gaskets, gears,
and socket connectors.  Stacked neatly on the north side of the yard
are many electrical components, which appears to be in good condition.
Endtext
    );
    set("item_desc", ([
      "rubble" : "The mountain of trash is as high as a building.\n",
      "components" : "They are blank circuit boards used by technicians.\n",
    ]) );
    set("exits", ([
      "west"  : ROOMS+"road03",
    ]) );
}

