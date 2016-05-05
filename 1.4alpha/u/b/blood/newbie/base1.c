#include "newbie.h"
#include <config.h>
#include <mudlib.h>
#include <basement.h>
#define TUNNEL BSMNT+"rtunnel1.c"

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "blood");
    set("short", "The Basement");
    set("long", @EndText
This dreary room is filled with stagnant, damp air, and rotting 
objects are scattered all around this room. The ground is earth, and
is very soft. 
EndText
    );
    set( "exits", ([
      "up" : N_ROOM+"room8.c",
    ]) );
    set( "item_desc", ([
      "air" : "How do you propose to do that?\n",
      "objects" : "Mostly old, useless tools.\n",
      "tools" : "They're old. And useless.\n",
      "earth" : "That's another word for dirt. It's dirty.\n",
      "ground" : "You may be able to dig here, with the proper tools.\n",
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

/* EOF */
