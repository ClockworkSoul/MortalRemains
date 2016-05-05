#include <mudlib.h>
#include <central.h>

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("light", 1);
    set("short", "A small junkyard");
    set("long", wrap("The mountain of rubble here is incredibly "+
	"high. It is a wonder how trash can be stacked into such a "+
	"towering structure. The garbage here consists mainly of "+
	"smaller mechanical parts like gaskets, gears, and socket "+
	"connectors. Stacked neatly on the north side of the yard "+
	"are many electrical components, which appears to be in good "+
	"condition. There seems to be a small opening in the rubble "+
	"to the east.") );
    set("item_desc", ([
      "rubble" : "The mountain of trash is as high as a building.\n",
      "components" : "They are blank circuit boards used by technicians.\n",
      "opening" : "There seems to be some sort of clearing behind it.\n",
    ]) );
    set("exits", ([
      "east" : M_ROOM+"portalrm",
      "west"  : M_ROOM+"road03",
    ]) );
}

