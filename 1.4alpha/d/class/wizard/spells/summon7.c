/*
** FILE: summon7.c (Monster Summoning III)
** PURPOSE: 9th level wizard conjuration spell. 
**		Summons a rank III monster.
** DURATION: 1 minute per level.
** COST : 120 SP
*/

#include <daemons.h>

inherit SPELL;

#define COST 120

int cast_summon7 (string str, int obj) {
    object monster, target;
    string name;

    seteuid(getuid());
    if (!str) str = "NONE";
    if (str=="NONE") target=TP->query_current_attacker();

    if (!obj) {
	obj = query_caster_level(TP, "wizard");
	if (!cast_spell(TP, COST)) return 1;
	write("You begin casting Monster Summoning VII...\n");
	say(TPN+" traces runes of conjuration upon the ground.\n");
    }

    monster = CATALOG_D->get_random_mon(20, 23);

    if (monster)
	monster = summon(monster, TP);
    if (!monster) {
	write("Summons failed.\n");
	return 1;
    }

    name = monster->query("short");
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
Monster Summoning VII (Level IX Wizard Spell - Summoning)

Cost: 120 Spell Points

This spell summons a monster to aid and protect the caster.
EndSpell
    );
}
