// Cyanide created this file
// August 2, 1999
// It is inherited by all the elevator waiting areas, and
// ensures that they all share the same properties.

#include "/u/c/cyanide/debug.h"
#include "macrosoft.h"

inherit MS_STD_ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("short", "The Elevator Reception Area");
    set("long", "@@query_long");
    set("item_desc", ([
      "doors" : "You see nothing special about the "+
      "elevator doors.\n",
      "palm plant" : "It's just a potted palm.\n",
      "palm" : "It's just a potted palm.\n",
      "button" : "You may wish to 'press' it.\n",
    ]) );
}

void init() {
    add_action("button", "press");
    add_action("button", "push");
}

int is_button_lit() {
    int floor;                  

    if (query("floor")) floor = query("floor");

    if (!floor) return 0;
    else
	return (member_array(floor, 
	    find_object_or_load(MS_BASE+"elev/lift.c")->
	    query_floor_queue() ) != -1);
}

int button() {
    int num = 0;
    string name = base_name(TO);

    num = strlen(MS_BASE);
    if (strlen(name) >= num) name = name[num..num];
    sscanf(name, "%d", num);

    find_object_or_load(MS_BASE+"elev/lift.c")->
    add_floor_to_queue(num);

    write("You press the elevator button.\n");
    say(TPN+" presses the button for the elevator.\n");

    return 1;
}

string query_long() {
    string str;

    str = "You are in a modest elevator waiting area, decorated "+
    "with little more than a small potted palm plant. There is "+
    "an elevator door to the west. Directly to the door's right, "+
    "is a small button"+(is_button_lit() ? ", which is lit." : ".");

    return wrap(str);
}

/* EOF */
