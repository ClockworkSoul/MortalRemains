#include "/u/c/cyanide/debug.h"

inherit MONSTER;

object cyanide;

void create() {
    ::create();

    set("short", "Loretta, Cyanide's minidragon");
    set("long", @EndText
This is the infamous Loretta, Cyanide's beloved pet minidragon.
Her hide is a flawless series of obsidian scales, and her eyes
glow a fearsome red. She is known to protect Cyanide, as well as
be protected by him.
EndText
    );
    set("id", ({ "loretta", "minidragon" }) );
    set_name("loretta");
    set("race", "minidragon");
    set("lore_type", "monster");
    set("gender", "female");
    set("prevent_summon", 1);
    set_level(10);

    cyanide = find_player("cyanide");
}

void init() {
    add_action("permit", "lore");
    add_action("permit", "look");
    add_action("to_who", "");
    add_action("no", "ruffle");
    add_action("no", "kick");
    add_action("permit", "lore");
    add_action("permit", "look");
}

int permit(string str) { return 0; }

int to_who(string str) {
    if (id(str) && TPN!="Cyanide") {
	write("Loretta snaps at your hand, almost getting your fingers.\n");
	say(TPN+" tries to do something to Loretta, but almost loses\n"+
	  "a hand in the process.\n");
	return 1;

    }

    return 0;
}

int no ( string str ) {
    if (str=="cyanide") {
	write("Cyanide's minidragon won't let you do that.\n");
	return 1;
    }

    return 0;
}

varargs int receive_damage(int dam, string type, object ob, int weap) {
    message("combat", "Cyanide's minidragon shrieks and hides "+
      "behind Cyanide.\n", environment() );
    return 0;
}

void heart_beat() {
    if (!environment(TO)) return;

    if (sizeof(children(base_name(TO))) > 2) remove();

    if (cyanide) {
	if (environment(TO) != environment(cyanide))
	    move_player(environment(cyanide));

	if (!query("protectees"))
	    force_me("protect cyanide");

	if (cyanide->query("invisible") != query("invisible"))
	    set("invisible", cyanide->query("invisible"));
    } else {
	move_player(find_object_or_load("/u/c/cyanide/workroom.c"));
    }
}


string query_mmin() {
    return "Cyanide's minidragon flies in after her master.";
}

string query_mmout() {
    return "Cyanide's minidragon follows her master.";
}
