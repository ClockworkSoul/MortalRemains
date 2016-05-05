#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"bogstd.c" ;

int parts = 2;

void create() {    
    ::create();
    set("short", "In A Thicket");
    set("long", wrap(
	"You have wandered into a part of the lake densely packed with "+
	"a dense thicket of dead reeds and long vines coated with razor"+
	"-sharp thorns three inches long. To the east is a small "+
	"water-filled clearing made by some long-dead mangrove trees. "+
	"To the west is considerably less vegetation."
      ) );

    add("item_desc", ([
      "thorns" : "They are about three inches long, and cruelly barbed.\n",
      "thicket" : "It's a tangle of dead reeds and thorny vines.\n",
      "vines" : "They're covered with long, sharp thorns.\n",
      "pond" : "You would prefer to spend as little time here as possible.\n",
      "objects" : "They feel alot like... bodies.\n",
      "legs" : "You already know what THEY look like.\n",
      "water" : "It is thick and black. Completely opaque.\n",
      "clearing" : "You can't quite make it its details from here.\n",
      "vegetation" : "Most of it is dead or dying.\n",
      "thicket" : "A mangled mess of vines.\nThere seems to "+
      "be something in it...\n",
    ]) );
    set ("exits", ([     
      "east" : BAATOR+"minauros/bog28.c",
      "west" : BAATOR+"minauros/bog26.c"]));
    reset();
}

void init() {
    add_action("search", "search");
}

void populate() {;}

int search( string str ) {
    string *obs = get_dir(BAATOR+"items/parts/*.c");

    if ((str=="thicket" || str=="thorns") && (parts--) > 0) {
	object ob = clone_object(BAATOR+"items/parts/"+
	  obs[ random(sizeof(obs)) ]);
	if (ob) {
	    ob->move(TO);
	    write("You found "+ob->query("short")+"!\n");
	    return 1;
	}
    }

    return 0;
}

