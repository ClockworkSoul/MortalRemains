/*
** File: locate.c (Locate Creature)
** Purpose: 4th level wizard divination spell
** Cost: 30 SP
** Credits:
**   24 Nov 97  Cyanide created the spell.
*/

#define SYNTAX "Syntax: cast gate <target>\n"
#define COST 100

#include <magic.h>
#include <m_spells.h>
#include <teleport.h>

inherit SPELL;

int cast_gate(string str) {
    object where, here, target, gate;
    int found, lvl;

    seteuid(getuid());

    if (!str) {
	write(SYNTAX);
	return NO_TARGET;
    } 

    str = lower_case(str);
    target = find_player(str);

    if (!target || !visible(target, TP)) {
	write(SYNTAX);
	return NO_TARGET;
    }

    if (wizardp(target)) {
	write("You cannot summon the gods!\n");
	return NO_TARGET;
    }

    if (!TP->cast_spell(COST)) return NO_STRENGTH;
    lvl = query_caster_level(TP, "wizard");

    write("You begin casting Gate...\n");
    say(TPN+" begins uttering arcane words of power...\n"); 

    found = 1;
    where = environment(target);
    here = environment(TP);

    if (target->query_skill("nondetection")) found = 0;
    if (present("#NONDETECTION#", target)) found = 0;

    if (!where) {
	write(target->query("cap_name")+" is lost in the Void.\n"); 
	return SPELL_CAST;
    }

    if (!found) {
	write("That target cannot be located.\n");
	return SPELL_CAST;
    }

    // Sorry - reusing 'found'
    found = where->query("no_teleport") + 
    here->query("no_teleport");

    if (where->query("no_magic") || found) {
	write("The spell fails.\n");
	say("Nothing happens.\n");
	return 1;
    }

    if (where==here) {
	str = target->query("cap_name")+" is in the same room as you are!\n";
    } else {
	gate =  clone_object ("/d/class/priest/obj/gate_ob.c") ;
	gate->set("destination", base_name(here));
	gate->move(where);

	gate =  clone_object ("/d/class/priest/obj/gate_ob.c") ;
	gate->set("destination", base_name(where));
	gate->move(here);

	if (target->query_save()){
	    str = target->query("cap_name")+" resists the force of your will!\n";
	    tell_object(target, wrap("A shimmering gate pulls you "+
		"toward it, but you resist."));
	} else {
	    str = wrap(target->query("cap_name")+" is forced to "+
	      "step through the gate by your force of will!");
	    tell_object(target, wrap("A shimmering gate appears "+
		"and you are magically forced through."));
	    target->move_player(here, "SNEAK");
	}
    }

    write(str);
    return SPELL_CAST;
}

string spellcraft() {
    string str = (@EndSpellcraft
Gate (Priest - Level VII - Summoning)

Duration: 1 minute 		Area of Effect: 1 Player
Cost: 100 TP

EndSpellcraft
    );

    str += wrap("This spell opens a portal to the target player "+
      "and attempts to force them to step through. The portal "+
      "is two-way, and lasts 1 minute.");

    return str;
}

/* EOF */
