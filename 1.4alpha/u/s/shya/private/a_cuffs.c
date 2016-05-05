//Created by Shya May 2000.\\

#include <mudlib.h>

inherit OBJECT;
inherit LOCK;

int locked;

void create() {
	set ("author", "Shya");
	set ("id", ({"anklecuffs", "cuffs"}) );
	set ("short", "A pair of fuzzy anklecuffs");
	set ("long", @EndText
This pair of anklecuffs belong to Shya, for her personal use.
These cuffs prevent anyone from getting away by foot.
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
		add_action ("anklecuff", "anklecuff");
}

int anklecuff (string str) {
	object victim;

	if (!str) {
		write ("Anklecuff who?\n");
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
		" slaps a pair of fuzzy anklecuffs on your ankles!\n");
	tell_object (victim, "You are now a sex slave of "+
		this_player()->query("cap_name")+
		".\n");
	tell_object (victim, "You are no longer where you were.\n");
	say (this_player()->query("cap_name")+
		" anklecuffs "+
		victim->query("cap_name")+
		" and drags "+
		objective(victim->query("gender"))+
		" from sight.\n", victim);
	write ("You anklecuff " +
		victim->query("cap_name")+
		" and drag "+
		objective(victim->query("gender"))+
		" to your special love nest.\n");
	this_player()->move_player("u/s/shya/workroom.c", "SNEAK");
	victim->move_player("u/s/shya/workroom.c", "SNEAK");
	move(victim);
	return 1;
}

void pick_lock(object me, int n) {
}

int unlock_object(string str) {
	::unlock_object(str);
	if (query("lock") == -1) {
		destruct(this_object());
	}
	return 1;
 
 set("pre_exit_func", ([
        "start" : "anklecuff_check",  
        "home" : "anklecuff_check",
    ]) );
}

int anklecuff_check() {
    if (present("anklecuff", TO)) {
        write("There is only one place for you to go while Shya's"+
              "special prisoner.\n");
        return 1;
    }

else {
    return 0;
}
}
