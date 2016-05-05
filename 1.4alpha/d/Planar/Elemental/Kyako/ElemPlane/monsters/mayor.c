// Made by Kyako on April 6, 1998
// Cyanide fixed a minor bug, 10 Apr 98

#include <mudlib.h>
#include "plane.h"

inherit MONSTER ;

void create(){
    ::create() ;
    set("author", "Kyako");
    set("short", "Mayor");
    set("long", @MayorText
This is the Mayor of the Island.
He looks well fed and happy,
but he started to look nervous when you walked in.
MayorText
    );
    set("id", ({ "Mayor", "mayor" }) );
    set("name", "mayor");
    set_name("mayor");
    set_living_name("mayor");
    enable_commands();
    set("natt", 1);
    set("no_attack", 1);
    set("gender", "male");
    set_align("le");
    set_level(10);
}

void init() {
    add_action("badger", "say");
}

int badger(string str) {
    if (str == "pirates") {
	write("Mayor tells you: What about the pirates?\n");
	write("Mayor tells you: Who ever said anything about pirates?\n");
	return 1;
    }
    if (str == "jack") {
	object statuemon, key;
	write("Mayor tells you: Jack did, eh?\n");
	write("Mayor tells you: I've been looking for an excuse to arrest him.\n");
	write("Mayor tells you: But first, I have to get rid of another problem.\n");
	write("The mayor has an evil look in his eye as he says...\n");
	write("YOU!!!\n");
	write("The mayor gets up and locks the door.\n");
	say("The mayor gets up and locks the door.\n");
        key = clone_object(PLANE+"obj/key");
        key -> move(this_object());
	command("close door");
	command("lock door with key");
        key -> remove();
	write("Mayor begins chanting arcane verses...\n");
	say("Mayor begins chanting arcane verses...\n");
	write("Suddenly, one of the statues starts to move...\n");
	say("Suddenly, one of the statues starts to move...\n");
	write("It attacks you!\n");
        write("It attacks "+TPN+"!\n");
	statuemon=clone_object(PLANE+"monsters/statuemon.c");
//      statuemon->move(this_object());     This tries to move the mon to the MAYOR.
        statuemon->move(environment(this_object()));
	statuemon->kill_ob(TP); 
	write("The mayor shouts, \"Muahahahahah!\"\n");
	say("The mayor shouts, \"Muahahahahah!\"\n"); 
	return 1;
    }
    return 0;
}

int resetcmd() {
   object key;
   key = clone_object (PLANE+"obj/key") ;
   key -> move (this_object()) ;
   command("unlock door with key");
   command("open door");
   key -> remove(this_object()) ;
   return 0;
}
