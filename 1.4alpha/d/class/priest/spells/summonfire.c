/*
**ilz
*/

#define COST 60

#define ELEM_PATH "/d/Planar/Elemental/monsters/fireelem.c"

inherit SPELL;

int invoke_summonfire (string str, int obj) {
    object monster, target;

    seteuid(getuid());
    if (!str) str = "NONE";
    if (str=="NONE") target=TP->query_current_attacker();

    if (!obj) {
	obj = query_caster_level(TP, "priest");
	if (!TP->invoke_spell(COST)) return 1;
    }

    monster = clone_object(ELEM_PATH);

    if (!monster) {
	write("Summons failed. Please notify Cyanide.\n");
	return 1;
    }

    monster->set_level(random(13)+ 12);
    monster = summon(monster, TP);        

    TP->add("followers", ({ monster}) ); 
    TP->add("protectors", ({ monster }) );

    monster->move(environment(TP));
    if (target) monster->kill_ob(target);

    write("You summon "+monster->query("short")+"!\n");
    say(TPN+" summons "+monster->query("short")+"!\n");
    return 1;
}
string spellcraft() {
    return (@EndSpellcraft
Summon Fire Elemental (Priest - Level VI - Summoning, Fire)

Duration: permanent 	
Cost: 60 TP

	This spell summons a fire elemental to aid
and protect the caster.
EndSpellcraft
    );
}
