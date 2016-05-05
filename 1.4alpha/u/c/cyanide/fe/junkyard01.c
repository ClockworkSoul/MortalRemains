#include <mudlib.h>
#include <path.h>

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("light", 1);
    set("short", "A small junkyard");
    set("long", @Endtext
A gigantic mound of trash stands here.  Most of the debris consist of
mechanical parts, metal platings and motor engines.  A lot of the
metallic items have been rusted beyond recovery.  Stacks of broken
down robots are also here, waiting to be reused as spare parts.
Endtext
    );
    set("item_desc", ([
      "trash" : "A big pile of junk.\n",
      "parts" : "A few of the parts may still be useful yet.\n",
      "platings" : "They can be useful as armor plating on machines.\n",
      "engines" : "These engines are no longer operational.\n",
      "robots" : "They have been tossed away after malfunctioning many times.\n",
    ]) );
    set("exits", ([
      "east"  : ROOMS+"road03",
    ]) );
}

