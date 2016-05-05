#include "basement.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

#define TUNNEL BSMNT+"tvault.c"

void create()
{   
    ::create();
    seteuid( getuid() );
    set("objects",([
    "gnome" : "/d/Prime/Magehouse/monsters/gnome1.c",
    "gnome" : "/d/Prime/Magehouse/monsters/gnome1.c",
    "gnome" : "/d/Prime/Magehouse/monsters/gnome1.c",
    ]) );
    reset();
    set( "light", 1 );
    set("author","blood");
    set( "short", "Gnome Encampment" );
    set( "long", @EndText
This level has been painstakingly constructed to conform even with the
dwarven standards of mine construction. Veins of various types of precious
ore can be seen flowing through the walls and all of the gnomes here seem
to be hard at work constructing new areas and living space and for profit.
EndText
    );
    
    set( "exits", ([   
      "up" : BSMNT+"gcamp11.c",
    ]) );
    set( "item_desc", ([
      "earth" : "That's another word for dirt. It's dirty.\n",
      "ground" : "You may be able to dig here, with the proper tool.\n",
    ]) );
}
void init() {
    add_action("dig_func", "dig");
}

int dig_func ( string str ) {
    object tunnel;

    if (!present("shovel", TP)) {
        write("You don't seem to have a shovel.\n");

        return 1;
    }
    
    write("You dig a hole, and uncover a tunnel!\n");
    say(TPN+" digs a hole, and uncovers a tunnel!\n");
    
    tunnel = find_object_or_load( TUNNEL );
    if (!tunnel) {
        write("*ERROR* Notify a wizard, immediately!\n");
        return 1;
    }

    tunnel->add("exits", ([ "up" : base_name(TO) ]) );
message("info", "A shovel breaks through the earth in the "+
  "ceiling!\n", all_inventory(tunnel), ({}) );
add("exits", ([ "down" : TUNNEL ]) );
        
return 1;
}
