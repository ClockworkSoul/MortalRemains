/*
** FILE: summon2.c (Monster Summoning II)
** PURPOSE: 4th level wizard conjuration spell. Summon a rank II monster.
** DURATION: 1 minute per level.
** COST : 30 SP
** CREDITS:
**   15 Nov 97  Cyanide created the very first true monster summoning
**              spell.
*/

#include <daemons.h>

inherit SPELL;

#define COST 30

int cast_summon2 (string str, int obj) {
    object monster, target;
    string name;

    seteuid(getuid());
    if (!str) str = "NONE";
    if (str=="NONE") target=TP->query_current_attacker();

    if (!obj) {
	obj = query_caster_level(TP, "wizard");
	if (!cast_spell(TP, COST)) return 1;
	write("You begin casting Monster Summoning II...\n");
	say(TPN+" traces runes of conjuration upon the ground.\n");
    }

    monster = CATALOG_D->get_random_mon(3, 7);
    name = monster->query("short");

    monster = summon(monster, TP);
    if (!monster) {
	write("Summons failed.\n");
	return 1;
    }

    TP->add("followers", ({ monster}) ); 
    monster->set("following", TP);
    TP->add("protectors", ({ monster }) );
    monster->add("protectees", ({ TP }));

    write("You summon "+name+"!\n");
    say(capitalize(name)+ " appears!\n");

    monster->move(environment(TP));
    if (target) monster->kill_ob(target);
    //target = clone_object("/adm/obj/summon_ob.c");

    return 1;
}
string spellcraft() {
    return (@EndSpell
Monster Summoning II (Level IV Wizard Spell - Summoning)

Cost: 30 Spell Points

This spell summons a monster to aid and protect the caster.
EndSpell
    );
}
