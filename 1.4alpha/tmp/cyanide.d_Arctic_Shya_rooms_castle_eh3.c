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
    set("short", " Entrance Hall (e,w,)");
    set( "long", @EndText
This is a connecting corridor leading through the castle wall.
It leads to the interior of the castle to the east, and to a
portcullis to the west. There are small passages to the north
and south.
EndText
);

    set( "item_desc", ([
        "corridor"   : "A simple stone corridor.\n",
        "portcullis" : "A heavy iron gate suspended by chains.\n",
        "passages"   : "They lead into darkness.\n",
        "passage"    : "They lead into darkness.\n"
                      ]) );
    set( "exits", ([
        "north" : "/u/s/shya/rooms/castle/wall1.c",
	"south" : "/u/s/shya/rooms/castle/wall15.c",
        "east"  : "/u/s/shya/rooms/castle/eh1.c", 
        "west"  : "/u/s/shya/rooms/castle/clifftop.c"
                  ]) );
    froArctictgdard = clone_object("/u/s/Shya/monsters/frostguard.c");
    frostguard->move(this_object());
}
