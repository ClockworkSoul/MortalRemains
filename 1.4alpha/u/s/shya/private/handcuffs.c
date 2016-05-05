//Created by Shya May 2000 for her exclusive use.  You must get permission from her to use.\\


#include <mudlib.h>

inherit OBJECT;
inherit LOCK;

int locked;

void create() {
	set ("author", "Shya");
	set ("id", ({"handcuffs", "cuffs"}) );
	set ("short", "A pair of police handcuffs");
	set ("long", @EndText
This pair of handcuffs belong to Shya, for her personal use.
These cuffs are police standard issue.
EndText
);
	set ("max_lock", 10);
	set ("lock", 3);
	set ("key", "handcuff key");
	set ("mass", 0);
	set ("value", 0);
	set ("prevent_drop", 1);
	set ("prevent_insert", 1);
	set ("prevent_give", 1);
	locked = 0;
}

void init () {
	lock::init ();
	if (!locked)
		add_action ("handcuff", "handcuff");
}

int handcuff (string str) {
	object victim;

	if (!str) {
		write ("Handcuff who?\n");
		return 1;
	}
	victim = find_player(str);
	if (!victim) {
		write("There's no player named "+capitalize(str)+
			" on the mud!\n");
		return 1;
	}
	locked = 1;
	tell_object (victim, this_player()->query("cap_name")+
		" slaps a pair of handcuffs on you!\n");
	tell_object (victim, "You are now a prisoner of "+
		this_player()->query("cap_name")+
		".\n");
	tell_object (victim, "You are no longer where you were.\n");
	say (this_player()->query("cap_name")+
		" handcuffs "+
		victim->query("cap_name")+
		" and drags "+
		objective(victim->query("gender"))+
		" from sight.\n", victim);
	write ("You handcuff " +
		victim->query("cap_name")+
		" and drag "+
		objective(victim->query("gender"))+
		" to your bedroom.\n");
	this_player()->move_player("u/s/shya/bedroom.c", "SNEAK");
	victim->move_player("u/s/shya/bedroom.c", "SNEAK");
	move(victim);
	return 1;
}

void pick_lock(object me, int n) {
	/* Don't allow this lock to be picked! */
}

int unlock_object(string str) {
	::unlock_object(str);
	if (query("lock") == -1) {
		destruct(this_object());
	}
	return 1;
 
 set("pre_exit_func", ([
        "start" : "handcuff_check",  
        "home" : "handcuff_check",
    ]) );
}

int handcuff_check() {
    if (present("handcuff", TO)) {
        write("There is only one place for you to go while Shya's"+
              "prisoner.\n");
        return 1;
    }

else {
    return 0;
}
}







