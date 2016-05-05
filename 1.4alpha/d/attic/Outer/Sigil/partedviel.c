#include <mudlib.h>
#include "sigil.h"
inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid());
    set ("objects", ([ "kesto" : "/d/Outer/Sigil/monsters/kesto" ]) );
    reset();
    set ("light", 1) ;
    set("long", @ENDLONG
You are in The Parted Veil, the most well-known bookstore in the city.
ENDLONG
    ) ;
    set("short", "The Parted Veil.") ;
    set ("exits", ([
      "west" : SIGIL+"berkst.c",
      "east" : "/d/class/wizard/diviner/rooms/diviner_guild.c",
        "south" : SIGIL+"thithe.c",
    ]) );
}
