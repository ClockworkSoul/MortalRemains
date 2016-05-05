/*
** File: _spellcraft.c
** Purpose; Essentially, a help file for mage and priest spells.
** Credits:
**	20 Jan 98   Cyanide created the file, again.
*/

#define MAGE_SPELLS "/d/class/wizard/spells/"
#define PRIEST_SPELLS "/d/class/priest/spells/"
#define FLORAL \
   "=--=[ Arcanology ]=----------------------------------------------------=\n"
#define FLORAL2 \
   "=----------------------------------------------------------------------=\n"


int cmd_spellcraft(string str) {
    string file, *spells;
    int flag = 0;

    seteuid(getuid());

    if (!str) {
	write("What spell do you wish the lore of?\n");
	return 1;
    }

    if (base_name(environment(TP)) == 
      "/d/class/wizard/general/rooms/mage_guild") 
	flag = 1;
    if (TP->query_skill("Arcanology")) flag = 1;
    if (!flag && TP->query("mage_spells")) {
	spells = TP->query("mage_spells");
	if (member_array(str, spells)!=-1) flag = 1;
    }
    if (!flag && TP->query("priest_spells")) {
	spells = TP->query("priest_spells");
	if (member_array(str, spells)!=-1) flag = 1;
    }

    file = MAGE_SPELLS+str+".c";
    if (!file_exists(file)) {
	file = PRIEST_SPELLS+str+".c";
	if (!file_exists(file)) {
	    flag = 0;
	}
    }

    if (!flag) {
	write("You know of no such spell.\n");
	return 1;
    }

    str = call_other(file, "spellcraft");
    if (!str) {
	write("A spell by that name exists, but it has no lore.\n");
	return 1;
    }

    str = FLORAL + str + FLORAL2;
    write(str);
    return 1;
}

string help() {
    return(@EndHelp
Usage: spellcraft <spell name>

This command returns information on a given spell. Note that you can only
get info on a spell if,  a) You know the spell, or b) You have the
"arcanology" skill.

See also: spells
EndHelp
    );
}
