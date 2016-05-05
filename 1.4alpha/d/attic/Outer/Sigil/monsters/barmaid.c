// (12-17-98) Chronos rewrites some shit.  He also notices that someone
//            added a buy() function to his barmaid bitch.

#include <mudlib.h>
#include "defs.h"
inherit MONSTER ;


void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("short", "a busty barmaid") ;
    set("long", @ENDLONG
A very well-endowed barmaid with pretty blonde braids and enormous 
buckteeth.  She smiles shyly at you as you look her over.
ENDLONG
    );
    set("id", ({ "barmaid", "maid" }) ) ;
    set_name("barmaid") ;
    set("race", "human" ) ;
    set ("gender", "female") ;
    enable_commands() ;
    set_level(3) ;
    set("CLASS", "warrior");
    set ("damage", ({ 1,4 }) ) ;
    set ("weapon_name", "fists") ;
    set("wealth", 10) ;
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    arm(OBJ(fork), "fork") ;
    set("chat_chance", 10) ;
    set("chat_output", ({
      "The barmaid adjusts her dress.\n",
      "The barmaid cleans up a table.\n",
      "The barmaid smiles at you.\n",
      "The barmaid wipes something up.\n",
      "The barmaid cleans methodically.\n",
      "The barmaid hums a little tune as she wipes off a table.\n",
    }) ) ;
    set("att_chat_output", ({
      "The barmaid screams in terror!\n",
      "The barmaid throws a dish at you!\n",
      "The barmaid tries to scratch out your eyes!\n",
    }) ) ;
    call_out("move_yer_ass", 10 + random(20) ) ;
}

void init() {
    add_action("buy", "buy");
}


// Move yer pretty little ass honey.
int move_yer_ass(int count) {
    if (!environment(TO)) remove() ;
    if (count == 0) count = 1;
    if (!query_current_attacker()) {
	if (count == 1) command("go west") ;
	if (count == 2) command("go north") ;
	if (count == 3) command("go south") ;
	if (count == 4) command("go south") ;
	if (count == 5) command("go north") ;
	if (count == 6) command("go down") ;
	if (count == 7) command("go up") ;
	if (count == 8) command("go east") ;
	count++;
	if (count == 9) count = 0 ;
	command("get all") ;
    }
    call_out("move_yer_ass", 10 + random(20), count) ;
    return 1;
}

void remove() {
    // This is just good practice.  need to clean up after ourselves.
    remove_call_out("move_yer_ass") ;
    ::remove(); 
}

// Eh, we only clone one of her at a time, so i don't mind being
// generous with the variables.  *shrug*
void die() {
object arm, wep1, wep2;
if (!random(12)) {  // not too often.. should surprise players. :D
    wep1 = query_current_attacker()->query("weapon1") ;
    wep2 = query_current_attacker()->query("weapon2") ;
    if ((wep1 || wep2) && (
	(string)wep1->query("damage_type")=="slashing" ||
	(string)wep2->query("damage_type")=="slashing") ) {
	message("combat",
	  "The barmaid's arm is lopped off violently in the heat of battle!\nHer screams are deafening.\n",
	  environment(TO), ({ TO }) ) ;
	arm = clone_object("/d/Outer/Sigil/parts/severed_arm") ;
	if (!arm) arm = clone_object("/d/Outer/Sigil/items/severed_arm") ;
	if (arm) {
	    arm->move(environment(TO)) ;
	    arm->begin_blood("blood") ;
	}
    }
}
::die() ;
}

int buy(string str) {
    string name;
    object pack;

    if (str != "butts" && str != "pack" && str != "smokes" && str != "cancer sticks") {
	return 0;
    }

    if (!TP->debit(10)) {
       command("to "+TPN+" They cost 10 coins, which you don't have.") ;
	return 1;
    }

    name = TP->query("name");
    pack = clone_object("/d/Outer/Sigil/toys/tumors.c");
    if (!pack) {
	command("to "+name+" Sorry - all out.");
	return 1;
    }

    pack->move(TP);

    write("You give Barmaid 10 coins.\n") ;
    say(TPN+" gives Barmaid 10 coins.\n") ;
    say("The barmaid digs around in the front of her blouse and pulls something out.\n");
     say("She hands something to "+TPN+"\n") ;
    write("The barmaid sets her tray down and digs down deep in the front of her blouse.\nShe pulls out a pack of Tumors(tm) and tosses them to you.\n") ;
    command("to "+name+" Here ya go, addict!");
    return 1;
}

// Chronos added this since this mud doesn't seem to have command()
// for monsters.
//                    ??
int command(string str) {
  force_me(str) ;
  return 1;
}

/* EOF */
