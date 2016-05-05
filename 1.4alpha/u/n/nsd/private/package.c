// File: package.c

#include <mudlib.h>

inherit CONTAINER ;

object ob1;

void create()
{
    ::create();
    set("author", "?");
    set("id", ({ "package", "small package"}));
    set("short", "a small package");
    set_closed_long("A small package that reads 'Toy-ann'. It's closed.\n");
    set_open_long("A small package that reads 'Toy-ann'. It's open.\n");
    set_possible_to_close(1);
    set ("capacity", 1);
    toggle_closed();
    ob1 = clone_object("/u/n/nsd/private/glove.c");
    ob1->move(this_object());
    set("mass", 0);
}
void init() {
    object ob = environment(this_object() );
    ::init();
    if (!living(ob)) call_out("remove", 1);
}
void remove() {
    object ob = environment(this_object() );
    if (ob) tell_room(environment(this_object() ),
	  "To colaborate with the recycling program,"+
	  " this solid waste has vanished...\n");
    ::remove();
}
