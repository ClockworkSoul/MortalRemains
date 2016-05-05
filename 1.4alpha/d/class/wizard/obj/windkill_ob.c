/*
** File:  winkill_ob.c
** Purpose:  To take over the world
*/

#include <magic.h>

inherit OBJECT;
inherit SPELL;

object master;

void create() {
    seteuid(getuid());
    set("doneroom", ({ environment() }));
    set("schools", ({ "summoning" }) );
    set("id", ({ "#WINDKILL_OB#", "wind" }) );
    set("short", "Killing Wind");
    set("long", "Run for your life!, Tis a magical killing wind!\n");
    set("prevent_get", 1);
}

varargs int start_spell (object ob) {
    int i;
    mapping nextroom;
    object nextone, *doroom, *doneroom;

    seteuid(getuid());
    if (ob) {
	master = ob;
	//this is the rediculous function that spreads the wind.
	nextroom = (environment()->query("exits"));
	doroom = values(nextroom);
	doneroom = this_object()->query("doneroom");

	for(i=0;i<sizeof(doroom);i++){
	    if ((member_array(doroom[i], doneroom)) == -1){
		nextone = clone_object("/d/class/wizard/obj/windkill_ob.c");
		nextone -> move(doroom[i]);
		nextone -> set("doneroom", (doneroom + doroom));
		nextone -> start_spell(ob);
	    }
	}

	return 1;
    }


    return 0;
}

void init() {
    if ((master) && living(TP) && (TP!=master)) { 
	tell_room(environment(), "A killing wind fills the room!\n");
	if (!check_magic_resist(master, TP, 1000, 1000)){
	    if (!(TP->save_throw())){
		TP->receive_damage(1000, "poison", master);
		TP->set("last_attacker", master);
	    }
	}
    }


    call_out("remove", 1);
}

string query_master() {
    if (master) return (master->query("cap_name"));
    else return ("NONE");
}
