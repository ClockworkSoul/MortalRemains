#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid());
    set ("objects", ([ "koe" : "/d/Outer/Sigil/monsters/koe" ]) );
    set ("light", 1) ;
    set("long", wrap("You are in the steam room of the bathhouse, "+
    "and the air is thick with hot, green, purfumed steam. The "+
    "source of the heat seems to be a large pile of red-hot stones "+
    "sitting to one side of the room.\nAll in all, this seems like "+
    "a nice place to relax.") );
    set("item_desc", ([
    "steam" : "There's an awful lot of it in here.\n",
    "rocks" : "They are glowing with heat.\n",
    "stones" : "They are glowing with heat.\n",
    ]) );
    set("smell", "All you smell is the purfumed steam.\n");
    set("short", "The Baths.") ;
    set ("exits", ([
        "down" : SIGIL+"baths.c" 
    ]));
    reset();
}

void init() {
    add_action("relax", "relax");
}

int relax() {
    write(wrap("You sit in relax in the steam for a while. "+
     "You find it quite refreshing."));
    say(wrap(TPN+" sits back and relaxes, enjoying the steam.") );

    return 1;
}

/* EOF */
