#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
    ::create();
    set ("light", 1) ;
    set ("long",
@ENDLONG
You stand on the second level of Chirpers Pub in Sigil.  The pub actually
seems quite larger on the inside than it does on the outside.  There are
many tables here to sit at, and plenty more in the rooms all around you.
A rickety staircase leads down, to the ground level of the bar.
ENDLONG
    ) ;
    set("short", "Chirpers.") ;
    set("smell", ([
      "default" : "The smell of stale beer and vomit is quite intense to the south.\n",
    ]) ) ;
    set("item_desc", ([
      "tables" : "There are plenty of tables up here.\n",
      "staircase" : "Stairs are used for travelling up and down in buildings.\n",
    ]) ) ;
    set ("exits", ([
      "down" : SIGIL+"chirpers.c",
      "north" : SIGIL+"chirpers1.c",
      "south" : SIGIL+"chirpers4.c",
      "east" : SIGIL+"chirpers3.c" ]));
    set("exit_msg", ([
      "down" : "$N heads down to the ground level of the bar.\n",
    ]) ) ;
}

