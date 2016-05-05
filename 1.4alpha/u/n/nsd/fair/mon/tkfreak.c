/*
** File: tkfreak.c
** Author: Lady Nsd
*/

#include <mudlib.h>

inherit MONSTER ;

int ticket();
int set_giver(string);
int told;
object giver;
void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    told = 0;
    set("author", "nsd");
    set("short", "ticket guy");
    set ("long", @EndText
This is the guy that will ask you for the ticket
everytime you want to enter to any of the attractions
of the fair. Do as he says, or he won't let you pass.
EndText);
    set("id", ({ "guy", "ticket guy"  }) );
    set_size(6);
    set_name("ticket guy");
    set("gender", "male");
    set("race", "human");
    set("undead", 0);
    set("damage", ({8,15}) );
    set("damage_type", "bludgeoning");
    set_verbs( ({"?"}) );
    set("weapon_name", "?");
    set("chat_chance", 10);
    set ("chat_output", ({
      "ticket guy says: come to the freak show!!!\n",
      "ticket guy says: tickets please!! \n",
    }) );
    set_level(8);
    set("no_attack", 1);
    set("prevent_summon", 1);
}
void init() {
}
int set_giver(string arg) {
    giver = this_player();
    return 0;
}
void heart_beat() {
    if(ticket() && !told) {
	tell_room(environment(), "The guy takes the ticket and lets "+TPN+
	  " pass\n");
	told = 1;
	giver->move_player("/u/n/nsd/clown/fair/moonwalk.c");
    }
    ::heart_beat();  
}
int ticket() {
    if(present("strawberry")) {
	return 1;
    }
    return 0;
}
/* EOF */
