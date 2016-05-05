// Cyanide coded this.
// 27 Feb 2000   Cyanide added find_call_out()'s to make sure...

#include "/u/c/cyanide/debug.h"
#include "macrosoft.h"

inherit MS_STD_ROOM;

int *floor_queue, current_floor, access;
object out;

void add_floor_to_queue( int );
void open_doors();
void close_doors();

void create() {
    floor_queue = ({});
    current_floor = random(7) + 1;
    access = -1;

    ::create();
    set("short", "The Elevators");
    set("long", "@@query_long");
    set("exits", ([ 
    ]) );
    set("item_desc", ([
      "swiper" : "@@query_swiper",
    ]) );
}

void init() {
    add_action("swipe_func", "swipe");
    add_action("swipe_func", "slide");
    add_action("button_func", "push");
    add_action("button_func", "press");
}

int button_func( string str ) {
    int button;

    if (!str || (sscanf(str, "button %d", button) != 1) ||
      (button < 1) || (button > 7) ) 
    {
	write(wrap("You may want to try: push button #. Try to keep "+
	    "in mind that there are only 7 buttons, okay sport?") );
	return 1;
    }

    // Check to see if the current access levels allows selection of 
    // that floor.Note that floor 0 requires level 0 or level 8 
    // access ONLY.
    if (((access<button) || (!button&&(access>0 && access<8)))
      && (button > current_floor) ) {
	write("Nothing happens.\n");
	return 1;
    }

    if (member_array(button, floor_queue)!=-1) {
	write(wrap("That button is already lit up, but of course "+
	    "you press it anyway, just because you're impatient."));
    } else {
	add_floor_to_queue(button);
    }        

    return 1;
}

int swipe_func(string str) {
    object card;
    int val;

    if (!str) {
	write("What do you want to swipe?\n");
	return 1;
    }

    card = present(str, TP);

    if (!card || !card->id("card")) {
	write("You can't swipe that.\n");
	return 1;
    }

    // Ensure they're swiping one of OUR cards.
    if (card->id("#CARD#"))
	val = card->query_access();
    else
	val = -1;

    access = val;

    if (val > -1) {
	message("info", "The light on the card swiper lights "+
	  "green.\n", all_inventory(TO));
    } else {
	message("info", "The light on the card swiper lights "+
	  "red.\n", all_inventory(TO));
	return 1;
    }

    if (find_call_out("clear_access") == -1)
	call_out("clear_access", 10);
    return 1;
}

void clear_access() {
    access = -1;
    message("info", "The light on the card swiper changes back "+
      "to red.\n", all_inventory(TO));
}

string query_long() {
    string long;

    long = "You are inside a large steel elevator, almost "+
    "featureless except for a series of numbered buttons, a "+
    "card swiper, and a digital floor indicator. The indicator "+
    "currently reads: " + current_floor + ", and ";

    long += "the elevator doors are currently " + 
    (query("exit/out") ? "open." : "closed.");

    return wrap(long);
}

string query_swiper() {
    string str;

    str = "It appears to be something you swipe a magnetic card "+
    "key through. A small status light on the swiper glows "+
    ((access > -1 ) ? "green." : "red.");

    return wrap(str);
}

string query_indicator() {
    string str = "A small arrow on the display is currently pointing ";

    if (sizeof(floor_queue)) {
	if (floor_queue[0] < current_floor) {
	    str += "down.";
	} else {
	    str += "up.";
	}
    } else {
	str = "";
    }

    str = ("The indicator currently reads: " + current_floor + ". ") 
    + str;

    return wrap(str);
}

// This is the function to be called to start the whole thing
// going.

void check_queue() {
    int i;
    object room;

    if (!sizeof(floor_queue)) return;

    if (member_array(current_floor, floor_queue)!=-1) {
	if (find_call_out("open_doors") == -1)
	    call_out("open_doors", 4);
    } else {
	if (current_floor < floor_queue[0]) 
	    current_floor++;
	else
	    current_floor--;

	message("info", "The floor indicator changes to "+
	  current_floor+"\n", all_inventory(TO));

	for (i=7; i>0; i--) {
	    room = find_object_or_load(MS_BASE+i+"/elevators.c");
	    if (!room) continue;

	    message("info", wrap("A soft chime sounds, and the "+
		"digital readout changes to "+current_floor+"."),
	      all_inventory(room) );
	}

	if (find_call_out("check_queue") == -1 )
	    call_out("check_queue", 6);
    }

    return;
}

void open_doors() {
    if (!sizeof(floor_queue)) {
	DEBUG("Open_doors() called on a 0-sized array");
	return;
    }

    if (file_exists(MS_BASE+floor_queue[0]+"/elevators.c"))
	out = find_object_or_load(MS_BASE+floor_queue[0]
	  +"/elevators.c");

    if (!out) {
	DEBUG("open_doors() cannot find correct room.\n");
	return;
    }

    set("exits/out", MS_BASE+floor_queue[0]+"/elevators.c");
    out->set("exits/west", base_name( this_object() ) );

    message("info", "The elevator doors slide open.\n",
      all_inventory(TO)+all_inventory(out));

    if (find_call_out("close_doors") == -1)
	call_out("close_doors", 8);

    return;
}

void close_doors() {
    floor_queue = filter_array(floor_queue, "filter_floor",
      TO);

    remove_exit("out");
    out->remove_exit("west");

    message("info", "The elevator doors slide closed.\n",
      all_inventory(TO)+all_inventory(out));  

    if (find_call_out("check_queue")==-1)
	call_out("check_queue", 4);
}

void add_floor_to_queue( int to_add ) {
    if (member_array(to_add, floor_queue)==-1) {
	floor_queue = floor_queue + ({ to_add });

	message("info", "The number "+to_add+" button lights up.\n",
	  all_inventory(TO) );

	if (find_call_out("check_queue")==-1) check_queue();
    }   
}

int *query_floor_queue() { return floor_queue; }

int filter_floor(int floor) {
    return (floor != current_floor);
}

/* EOF */
