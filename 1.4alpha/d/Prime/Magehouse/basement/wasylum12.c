#include <config.h>
#include <mudlib.h>
#include "basement.h"

#define TUNNEL BSMNT+"mden1.c"

inherit ROOM;

void create()
{   
    ::create();
    seteuid( getuid() );
    set("objects",([
    "worm" : "/d/Prime/Magehouse/monsters/worm1.c",
    "worm" : "/d/Prime/Magehouse/monsters/worm1.c",
    ]) );
    reset();
    set( "light", 1 );
    set("author", "blood");
    set("short", "Worm Asylum");
    set("long", @EndText
Twisty little passages and loops of tunnels lay before you. You imagine
that this is going to take a while to get through.
The ground here is earth, and is very soft.
EndText
    );
    set( "exits", ([
      "southeast-up" : BSMNT+"wasylum11.c",
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
