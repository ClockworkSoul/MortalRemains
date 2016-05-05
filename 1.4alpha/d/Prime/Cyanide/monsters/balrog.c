// Originally by an old coder named "Gothmog" for a little MUD 
// called "Against the Fall of Darkness". When Gothmog became
// the admin called "Ilzarion", Cyanide took over this beast.

#include <mudlib.h>
#include "monsters.h"

#define FIND find_player("cyanide")
#define DEBUG(x) if (FIND) tell_object(FIND, x)

void do_stuff();

inherit MONSTER ;

object body;

void create () {
    object ob1, ob2 ;

    ::create();
    seteuid(getuid()) ;

    set("short", "Felayshono the Balrog") ;
    set("long", "Fleayshono, a demon of might!\n");
    set("id", ({"Balrog", "balrog", "Felayshono", "felayshono"}));
    set_size(12);

    set("author","Gothmog");
    set_name ("Felayshono");
    set_living_name("Felayshono");
    enable_commands() ;

    set("stat", ([
      "strength" : 24,
      "intelligence" : 18,
      "dexterity" : 18,
      "constitution" : 20,
      "charisma" : 5
    ]) );

    credit(10000);
    set("race", "balrog");
    set ("gender", "male") ;
    set("armor_class", -5);
    set_align("ce");
    set("aggressive", 9);

    set ("damage", ({ 10, 20 }) ) ;
    set ("weapon_name", "dirty claws");
    set ("damage_type", "slashing");

    set ("resist_type", ([ "cold" : 50, "electricity" : 0,
      "fire" : 0, "poison" : 0 ]) );

    set("magic_resistance", 75);

    set_verbs( ({ "maul" , "crush", "pummel" }) );
    set_verbs2( ({ "mauls", "crushes", "pummels" }) );

    set("chat_chance", 30);
    set("chat_output", ({   
      "Felayshono growls at your intrusion.\n"
    }));
    set("att_chat_output", ({
      "Felayshono bellows with rage.\n"
    }));
    set("forgetful",0);
    set("pursuing",0);
    set("moving", 0);

    set_skill("Long Blades", 4, "strength");
    set_skill("Unarmed", 4, "strength");
    set_skill("Whips", 4, "dexterity");
    set_skill("Ambidexterity", 1, "strength");
    set_skill("Two Weapon Style", 3, "strength"); 

    set_level(40);
    arm(OBJ+"/bsword", "sword");
    arm(OBJ+"/bwhip.c", "whip");
}

void
receive_message(string Class, string message) {
    string name, msg;

    if (sscanf(message, "%s laughs.", name)==1)  {
	call_out("force_me", 1, "say What are you laughing at, fucker?");
	return ;
    }

    if (sscanf(message, "%s has died.", name ) ==1) { 
	DEBUG("NAME: "+name);   
	force_me("do laugh "+lower_case(name)+", get all");
	call_out("do_stuff", random(2) + 1);
    }
}


void heart_beat() {
    force_me("get all");
    ::heart_beat();
}

void do_stuff() {
    string name;

    force_me ("get all");

    body = present("corpse",
      environment( this_object() ) );
    if (!body) body = present("corpse",
	  this_object() );

    if (body && environment(body)==TO) {

	DEBUG("In do_stuff(): got body correctly");
	force_me ("unlock north door");
	force_me ("open door");
	force_me ("go north");
	call_out ("do_stuff2", 1);
    } else
	DEBUG("In do_stuff(): got NO body");
}

void do_stuff2() {
    DEBUG("In do_stuff2()\n");

    if (body && environment(body)==TO) {
	force_me ("close door");
	force_me ("lock door");
    } else {
	force_me ("go south");
    }

    call_out ("do_stuff3", 3);
}

void do_stuff3() {
    object mith_skull;

    DEBUG ("In do_stuff3()\n");	
}

/* EOF */
