

#define COST 44
#define SYNTAX "Syntax: invoke shift <destination>\n"

#include <m_spells.h>
#include <mudlib.h>
#include <magic.h>

string *get_msg(string);

inherit SPELL;

varargs int invoke_shift (string str, int obj) {
    string targ;
    int num;

    if (!str) {
	write(SYNTAX);
	return NO_TARGET;
    }



    switch (str){

    case "sigil" : targ = "/d/Outer/Sigil/mainst1.c";break;
    case "baator" : targ = "/d/Outer/Baator/avernus/room1.c";break;
    case "toril" : targ = "/d/Prime/Toril/arabel/mainst1.c";break;
    default : targ = "not";break;
    }
    if (targ == "not"){
	write ("Known planes are: sigil, baator, toril.\n");
	return 1;
    }


    if (!obj) {
	if (!TP->invoke_spell(COST)) return NO_STRENGTH;

	write("You Shift through reality...\n");
	say(TPN+" begins to shift...\n");
    }


    TP->move_player(targ);
    return SPELL_CAST;
}



string spellcraft() {
    return (@SPELLCRAFT
Plane Shift (Priest - Level V - Astral)
Syntax: shift <destination>
Cost: 44 TP

When this spell is used, the priest instantly transports himself, along
with a certain amount of additional weight that is on the spellcaster,
to a chosen plane.
Know planes of existence at this time are:
sigil, baator, toril
SPELLCRAFT
    );
}
