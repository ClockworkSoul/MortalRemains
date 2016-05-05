/*
** File: nachobowl.c
** Author: Lady Nsd
*/

#include <mudlib.h>
#include "fair.h"

inherit CONTAINER ;
object s1, s2, s3, s4, s5, s6, s7, s8, s9;

void create()
{
    ::create();
    seteuid(getuid());
    set("author", "nsd");
    set("id", ({"bowl", "bowl of nachos" }));
    set("short", "a bowl of hot nachos");
    set_open_long (wrap(
	"A bowl full of nachos and melted cheddar cheese.\n"+
	"Get your nachos from the bowl, 'dip' them, and 'munch' them. :-q\n"));
    set("mass", 0);
    set ("capacity", 100) ;
    set("value", 100);
    s1 = clone_object(FAIR_OBJ+"nacho.c");
    s1->move(this_object());
    s2 = clone_object(FAIR_OBJ+"nacho.c");
    s2->move(this_object());
    s3 = clone_object(FAIR_OBJ+"nacho.c");
    s3->move(this_object());
    s4 = clone_object(FAIR_OBJ+"nacho.c");
    s4->move(this_object());
    s5 = clone_object(FAIR_OBJ+"nacho.c");
    s5->move(this_object());
    s6 = clone_object(FAIR_OBJ+"nacho.c");
    s6->move(this_object());
    s7 = clone_object(FAIR_OBJ+"nacho.c");
    s7->move(this_object());
    s8 = clone_object(FAIR_OBJ+"nacho.c");
    s8->move(this_object());
    s9 = clone_object(FAIR_OBJ+"nacho.c");
    s9->move(this_object());
}
void init() {
    object ob = environment(this_object());
    // You forgot this line:
    ::init();

    if (!living(ob)) call_out("remove", 1);
}
void remove() {
    object ob = environment(this_object());
    if (ob) tell_room(environment(this_object()),
	  "To colaborate with the recycling program,"+
	  " this solid waste has vanished...\n");
    ::remove();
}
