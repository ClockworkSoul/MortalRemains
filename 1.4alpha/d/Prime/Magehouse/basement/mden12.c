#include <config.h>
#include <mudlib.h>
#include "basement.h"
    
#define TUNNEL BSMNT+"groom.c"
    
inherit ROOM;
    
void create()
{
    ::create();
    seteuid( getuid() );
    set("objects",(["mole" : "/d/Prime/Magehouse/monsters/mole1.c",]) );
    reset();
    set( "light", 1 );
    set("author", "blood");
    set("short", "Mole Den");
    set("long", @EndText
These particular rodents seem to have more culture and class than their
relations above. Larger, more comfortable passages with less twists and
turns make journey much easier on this level.
EndText
    );
    set( "exits", ([
       "up" : BSMNT+"mden11.c",
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
