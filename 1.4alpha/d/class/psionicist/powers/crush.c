/*
**  File: crush.c (Psychic Crush)
**  Purpose: Single target damage spell.
**  Cost: Undecided.
**  Credits:
**    11 Aug 97  Cyanide created the file as bolt.
**    21 Nov 97  Cyanide edited to be just "coldcone"
**    30 Oct 98  Cyanide corrupted into the first psionic
**               offensive power.  (Happy Halloween)
*/

#define ROLL random(12)+1
#define COST 16
#define SYNTAX "Syntax: psi crush (at target)\n"  

#include <magic.h>

// Prototypes:
int do_crush(object, int);

int lvl;
object room, caster, *targs;

inherit "/std/psionics.c";

varargs int psi_crush (string str, int obj) {   
    object target;
    int x;

    if (!str) str = "NONE";
    if (str=="NONE") target = TP->query_current_attacker();
    if (!target) target = present(str, environment(TP));
    if (!target) {
	write(SYNTAX);
	return 0;
    }     

    if (!check_valid_targ(TP, target)) return INVALID_TARGET;
    if (!obj) {
	if (!initiate(TP, COST)) return NO_STRENGTH;

	lvl = TP->query_level("psionicist");
	obj = lvl;
	write("You gather your energies for a mental assault.\n");
	say(TPN+" begins uttering arcane words...\n", ({ target }) );
	tell_object(target, TPN+" stares intently at you.\n");
    } else {
	lvl = obj;
    }

    caster = TP;

    room = environment(this_player());
    return do_crush(target, obj);
}

int do_crush (object victim, int level) {
    int dam=0, x;
    string name;

    for (x=0; x<level; x++) dam+=ROLL;

    if (!victim) return;
    name = victim->query("cap_name");

    x=0;
    // x = query_save_mod(caster,victim, ({"evocation"}) );
    x = victim->save_throw(x);

    dam = victim->receive_damage(dam, "mental", caster, TP);
    victim->kill_ob(caster);

    tell_room(environment(TP), TPN+" blasts a cone of freezing cold at "+
      victim->query("cap_name")+"!\n", ({ caster, victim }) );
    write("You focus your will upon "+victim->query("cap_name")+
      ", crushing "+possessive(victim->query("gender"))+" mind!\n");
    tell_object(victim, "An intense pain fills your mind!\n");

    victim->set("last_attacker", TP);
    return SPELL_CAST;
}

/* EOF */
