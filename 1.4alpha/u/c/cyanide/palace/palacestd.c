// The standard Palace Hall.
// Cyanide, 4 Jan 2000

#include "/u/c/cyanide/debug.h"

inherit "/u/c/cyanide/workroom.c";

void create() {
    ::create();
    seteuid(getuid());
    set("light", 1);
    set("author", "cyanide");
}

void init () {
    ::init();
    add_action ("exits","exits");
}

int exits() {
    if (TPN=="Cyanide") return 0;

    write ("You begin to get a nasty headache.\n");
    say (TPN+" begins to look very confused.\n");
    return 1;
}

int receive_object(object ob) {

    object workroom = find_object_or_load("/u/c/cyanide/workroom.c");   
    string obname = ob->query("name");

    return 1;
    if (!userp(ob) || getuid(ob) == getuid(TO))
	return 1;

    if (workroom->query_invited(obname) || 
      workroom->query_banned(obname)) {
	tell_object(ob, wrap("Sorry, the gates of Cyanide's Palace are "+ 
	    "currently locked. Please try again later.") );
	DEBUG(ob->query("cap_name")+" just tried to enter the Palace room "+
	  "\""+TO->query("short")+"\".\n");
	return 0;
    } else {
	DEBUG(ob->query("cap_name")+" has entered the palace complex.\n");
	return 1;
    }
}

void guest_add(mixed str) {
    object workroom = find_object_or_load("/u/c/cyanide/workroom.c");   

    if (workroom) 
	workroom->guest_add(str);
    else
	write("(Workroom) Error loading workroom prime.\n");
}

void guest_unban(mixed str) {
    object workroom = find_object_or_load("/u/c/cyanide/workroom.c"); 

    if (workroom)
	workroom->guest_unban(str);
    else
	write("(Workroom) Error loading workroom prime.\n");  
}

void guest_remove(mixed str) {
    object workroom = find_object_or_load("/u/c/cyanide/workroom.c");   

    if (workroom) 
	workroom->guest_remove(str);
    else 
	write("(Workroom) Error loading workroom prime.\n"); 
}

void guest_ban(mixed str) {
    object workroom = find_object_or_load("/u/c/cyanide/workroom.c");   

    if (workroom) 
	workroom->guest_ban(str);
    else
	write("(Workroom) Error loading workroom prime.\n"); 
}

void guest_list() {
    object workroom = find_object_or_load("/u/c/cyanide/workroom.c");

    if (workroom)
	workroom->guest_list();
    else
	write("(Workroom) Error loading workroom prime.\n");
}

/* EOF */
