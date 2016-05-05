#include <config.h>
#include <mudlib.h>

inherit ROOM;

object frostguard;

void create()
{
    ::create();
    seteuid( getuid() );
    set("author", "shya");
    set( "light", 1 );
    set("short", " Entrance Hall (e,w)");
    set( "long", @EndText
This is a connecting corridor leading through the castle wall.
It leads to the interior of the castle through a portcullis to the south. 
EndText
);

    set( "item_desc", ([
        "corridor"   : "A simple stone corridor.\n",
        "portcullis" : "A heavy iron gate suspended by chains.\n",
        "passages"   : "They lead into darkness.\n",
        "passage"    : "They lead into darkness.\n"
                      ]) );
    set( "exits", ([
        "north"  : "/d/Arctic/Shya/rooms/castle/eh1.c", 
        "south"  : "/d/Arctic/Shya/rooms/castle/wall13.c",

                  ]) );
    frostguard = clone_object("/d/Arctic/Shya/monsters/frostguard.c");
    frostguard->move(this_object());
}
