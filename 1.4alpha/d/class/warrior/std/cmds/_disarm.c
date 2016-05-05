/* File: _disarm.c
** Purpose: Ability for the thief class.
** Date: August 1st, 1997  (first attempt)
** Creator: Nightmask
*/

#include <rogues.h>
#include <mudlib.h>

// Prototypes...
int drop();
int disarm();
int unwield();

inherit DAEMON;

#define POSS possessive(this_player()->query("gender"))

// Global variables.
object attkr, weap;

int cmd_disarm(string targ) {
    if (TP->query_level() < 15) {
	write("You are not yet skilled enough to do that!\n");
	return 1;
    }
    attkr = (object)TP->query_current_attacker(); 
    if (!attkr) {
	write("You may only disarm in combat.\n");
	return 1;
    }
    weap = attkr->query("weapon1");
    if (!weap) weap = attkr->query("weapon2");
    if (!weap) {
	write ("You opponent is already unarmed.\n");
	return 1;
    }


if (TP->query("power_delay")) {
	write("You can't yet find another opening...\n");
	return 1;
    }

    if (!targ) { targ = TP->query_current_attacker();
	write ("You attempt to disarm your opponent.\n");
	say (TPN+" twirls "+POSS+" blade towards "+POSS+" foe.\n");
    }

    TP->block_attack(1);

    disarm();
    return 1;
}


int drop() {
    if (weap->query("dest_at_die") || weap->query("prevent_drop") || weap->query("prevent_get")){
     unwield();
     return 1;
     }
    weap->move(environment(attkr));
    write("You disarm your foe!\n");
    say(TPN+" disarms "+POSS+" foe!\n");
TP->set("power_delay", 5);
    return 1;
}

int disarm() {
    int percy = (20);

    percy += (5*(attkr->query_thac0() - TP->query_thac0()));
    if (weap->query("nosecond")) percy -=20;

    switch((random(100)+1)+percy) {
    case -1000..100 :write("You fail to disarm your foe.\n"); break; 
    case 101..180 : unwield(); break;
    default : drop(); break;
    }
TP->set("power_delay", 5);
    return 1;
}

int unwield() {
    write("You disarm you foe!\n");
    tell_object(attkr, TPN+" knocks you weapon from your grasp!\n");
    say(TPN+" knocks "+attkr->query("cap_name")+"'s weapon from "+
      POSS+" grasp!\n", ({ attkr, TP }) );
    weap->unwield();
    return 1;
}
