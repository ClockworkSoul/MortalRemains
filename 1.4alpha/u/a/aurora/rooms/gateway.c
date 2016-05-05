#include <std.h>

inherit ROOM;

void init() {
    ::init();
    add_action("go_north", "north");
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
	set_property("pking",0);
    set_property("no castle", 1);
    set("short", "Aurora's Gateway");
    set("long",
    "This is a gateway room.  You can go many places in Circle from here "
    "just by entering a portal.");
    set_items(
	(["portals" : "Swirling portals lead to other places.",
      ]) );
    set_exits( 
      ([
         "west" : "/wizards/aurora/workroom.c",
         "kataan" : "/d/standard/kataan_hall.c",
         "mage" : "/d/standard/mage_hall.c",
           "cleric" : "/d/standard/cleric_hall.c",
         "rogue" : "/d/standard/rogue_hall.c",
         "fighter" : "/d/standard/fighter_hall.c",
        "square" : "/d/standard/square.c",
        "supply" : "/d/standard/supply.c",
       "gidgo" : "/d/vampire/newbiestart.c",
        "advguild" : "/d/standard/adv_main.c",
   ]) );
    set_property("no castle", 1);
}

int go_north() {
    if(!wizardp(this_player())) {
	message("my_action", "You can't go that way..",this_player());
	message("other_action", (string)this_player()->query_cap_name()+
	  " tries to go east but can't.", this_object(),
	  ({ this_player() }));
	return 1;
    }
    message("other_action", (string)this_player()->query_cap_name()+
      " is allowed to go east.", this_object(),
      ({ this_player() }));
    this_player()->move_player("~aurora/rooms/gateway", "east");
    return 1;
}
