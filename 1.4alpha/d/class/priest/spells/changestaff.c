/*
**ilz
*/

#define COST 80

inherit SPELL;

int invoke_changestaff (string str, int obj) {
    object monster, target;

    seteuid(getuid());
    if (!str) str = "NONE";
    if (str=="NONE") target=TP->query_current_attacker();

    if (!obj) {
	if (!invoke_spell(TP, COST)) return 0;
	write("You kneel in prayer to "+TP->query("deity")+".\n");
	say(TPN+" kneels in prayer to "+TP->query("deity")+".\n");
    }

    monster=clone_object("/d/Planar/Elemental/monsters/treant.c");
    if (!monster) {
	write("Summons failed. Please notify Cyanide.\n");
	return 1;
    }
    monster = summon(monster, TP);

    TP->add("followers", ({ monster}) ); 
    monster->set("following", TP);
    TP->add("protectors", ({ monster }) );
    monster->add("protectees", ({ TP }));

    monster->move(environment(TP));
    if (target) monster->kill_ob(target);

    if (!obj) {
	write(wrap("The power of your deity transforms your staff "+
	    "into a mighty living tree!"));
	say(wrap("The power of "+TPN+"'s deity transforms "+
	    possessive(TP->query("gender"))+" into a mighty living tree!"));
    }

    return 1;
}

string spellcraft() {
    return (@EndSpellcraft
Changestaff (Priest - Level VII - Plant, Creation)

Duration: permanent 	
Cost: 80 TP

This mighty prayer transforms the priest's staff into a mighty
living tree to protect the priest, and do his bidding. 
EndSpellcraft
    );
}
