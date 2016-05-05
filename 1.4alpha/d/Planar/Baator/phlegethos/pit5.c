#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"phlegethos/pitstd.c";

void create() {
    ::create();
    set ("long", wrap("You are on a ridge of volcanic rock "+
	"overlooking a vast pool of lava. Flames dance upon its "+
	"surface. To the east, a path leads down toward the "+
	"edge of the fiery lake.") );
    set ("exits", ([   
      "north" : BAATOR+"phlegethos/pit1.c",
      "south" : BAATOR+"phlegethos/pit8.c",
      "east" : BAATOR+"phlegethos/pit6.c"
    ]));
    reset();
}


