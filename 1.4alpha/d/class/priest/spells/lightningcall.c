/*
** FILE:        enlarge.c
** PURPOSE:     2st level alteration spell.
** COST:        12 SP
** EFFECTS:     Increases subject's strength by an abount from 1-4 to
**              1-6, depending on level (max 18)
** DURATION:    1 minute/level.
** CREDITS: 
**    29 Sep 97  Cyanide wrote the spell.
*/               

#include <m_spells.h>
#include <mudlib.h>

#define COST 25

int invoke_lightningcall () {
    object targ, ob;
    int lvl = 0;

    seteuid(getuid());


    targ = TP;

    if (present("#LIGHTNINGCALL_OB#", targ)) {
	write("You already have a call lightning spell active!\n");
	return 0;
    }

    if (!TP->invoke_spell(COST)) { 
	write(NOT_ENOUGH_SP);
	return 0;
    }
    lvl = this_player()->query_level("priest");

    write("You cast lightningcall.\n");
    say (TPN+" begins crackling with electricity!\n");


    ob = clone_object("/d/class/priest/obj/lightningcall_ob.c");
    if (!ob) {
	write("Your spell fails.  Notify Cyanide.\n");
	return 0;
    }

    ob->move(targ);
    ob->begin_spell(targ);
    return 1;
}
string spellcraft() {
    return (@EndSpellcraft
Call Lightning (Priest - Level III - Weather)

Duration: 12 sec/lvl 		Area of Effect: Caster
Cost: 25 TP

	This spell gives the caster the ability to strike
his foes with bolts of lightning in adition to his
normal attacks. The caster types bolt while engaged
in combat to do this. One bolt can be called every
ten rounds.
EndSpellcraft
    );
}
