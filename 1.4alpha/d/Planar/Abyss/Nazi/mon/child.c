/*
** File: child.c
** Author: Lady Nsd
** Special Thanks: Dalceon for doing the set_giver fuction.
*/

#include <mudlib.h>
#include "nazi.h"

inherit MONSTER ;

int seven_keys();
int set_giver(string);
int told;
object giver;
void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;

    told = 0;
    set("author", "nsd");
    set("short", "A crying girl");
    set ("long", @EndText
A cute brunnette with long curls and large brown eyes.
Judging her youth, you can say she's five years old.
She's wearing a white dress with fluffy sleeves. She
looks sad and scared.
EndText
    );
    set("id", ({ "child", "girl" }) );
    set_size(4);
    set_name("girl");
    set("gender", "female");
    set("race", "ghost");
    set("undead", 1);
    set("damage", ({0, 0}) );
    set("damage_type", "piercing");
    set_verbs( ({"?"}) );
    set("weapon_name", "?");
    set("chat_chance", 40);
    set ("chat_output", ({
      "The girl bursts into tears\n",
      "The girl stops crying and stares at you.\n",
      "The girl says: I am the stolen innocence...\n",
      "The girl says: It's been long since I don't see the light.\n",
      "The girl says: I can't recall what the light looks like...\n",
      "The girl sniffs and sheds a tear.\n",
      "The girl looks at you and asks: Are you my savior?\n",
      "The girl says: Will you show me the light again?\n",
      "The girl says: Did you come to rescue me?\n",
      "The girl looks at you with innocent eyes...\n",
      "The girl swings in her rocking chair, producing a crackling sound.\n",
      "The girl asks you: Do you have something for me?\n",
      "The girl asks: Did you bring the keys that will set me free?\n",
    }) );
    set_level(1);
    set("no_attack", 1);
    set("prevent_summon", 1);

}

void init() {
    add_action("set_giver", "give");
}

int set_giver(string arg) {
    giver = this_player();
    return 0;
}
void heart_beat() {
    if(seven_keys() && !told) {
	tell_room(environment(), "The child uses the keys to open the portal...\n");
	told = 1;
	giver->move_player(LUST+"light.c");
    }
    ::heart_beat();   // Cyanide added this.  VERY important not to forget!
}
int seven_keys() {
    if(present("key of obsession") && present("key of desire")
      && present("key of possession") && present("key of perversion")
      && present("key of pleasure") && present("key of passion")
      && present("key of seduction") ) {
	return 1;
    }
    return 0;
}
/* End of File */
