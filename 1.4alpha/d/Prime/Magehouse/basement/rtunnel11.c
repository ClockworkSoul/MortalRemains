#include <config.h>
#include <mudlib.h>
#include "basement.h"

#define TUNNEL BSMNT+"wasylum1.c"

inherit ROOM;

void create()
{   
    ::create();
    seteuid( getuid() );
    set("objects",([
    "rat" : "/d/Prime/Magehouse/monsters/rat1.c",
    "rat" : "/d/Prime/Magehouse/monsters/rat1.c",
    ]) );
    reset();
    set( "light", 1 );
    set("author", "blood");
    set("short", "In the Rat Tunnels");
    set("long", @EndText
These grubby rodents have dug a series of tunnels, which you will have
to crawl through to proceed.
The ground here is earth, and is very soft.
EndText
    );
    set( "exits", ([
      "east" : BSMNT+"rtunnel10.c",
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
