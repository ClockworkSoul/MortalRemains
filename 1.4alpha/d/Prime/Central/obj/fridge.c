// Portal to NM's food areea

inherit OBJECT;

int open = 0;

void create() {
    set("short", "an old refrigerator");
    set("id", ({ "fridge", "refrigerator" }) );
    set("prevent_get", 1);
    set("long", "@@query_long");
}

void init() {
    add_action("enter", "enter");
    add_action("close", "close");
    add_action("open", "open");
}

int close (string str) {
    if (!id(str)) return 0;

    if (!open) {
	write("The fridge is already closed.\n");
	return 1;
    }

    open = 0;
    write("You close the old fridge's door.\n");
    say(TPN+" closes the fridge door.\n");
    return 1;
}

string query_long() {
    string str = "This is an ancient and abondoned "+
    "fridge, throughly rusted wherever its white paint "+
    "has chipped away. ";

    if (open) str += "Its door is wide open, and appers "+
	"you can 'enter' the fridge if you liked.";
    else 
	str += "The fridge door is closed.";

    return wrap(str);
}

int open(string str) {
    if (!id(str)) return 0;

    if (open) {
	write("The fridge is already open.\n");
	return 1;
    }

    open = 1;
    write("You open the fridge door.\n");
    say(TPN+" opens the fridge door.\n");
    return 1;
}

int enter(string str) {
    if (!id(str)) {
	write("Enter what?\n");
	return 1;
    }

    if (!open) {
	write("The fridge door is closed.\n");
	return 1;
    }

    write("You climb into the old fridge...\n");
    say(TPN+" climbs into the old fridge.\n");
    TP->move_player("/d/Planar/Food/room/rm1.c", "SNEAK");

    return 1;
}

/* EOF */
