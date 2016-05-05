/*
** File:    /std/psionics.c
** Purpose: Contains several functions used by all psionic powers.
** Credits:
**  27 Oct 98   Cyanide created the file. Much of its code is 
**              taken from /std/spell.c
*/

#include <messages.h>

// Standard psionics object

inherit OBJECT;

// We use the check_valid_targ() from spell.c
int check_valid_targ (object psi, object targ) {
    seteuid(getuid());
    return ("/std/spell.c"->check_valid_targ(psi, targ));
}

int maintain(object ob, int cost) {
    int psp = ob->query("psionic_points");

    if (psp >= cost) {
	ob->add("psionic_points", -1 * cost );
	return 1;
    } else {
	message(SPELL, "You do not have the energy to "+
	  "maintain that power.\n", ob);
	return 0;
    }
}

int initiate(object ob, int cost) {
    int psp = ob->query("psionic_points");

    if (psp >= cost) {
	ob->add("psionic_points", -1 * cost );
	return 1;
    } else {
	message(SPELL, "You do not have the energy to "+
	  "initiate that power.\n", ob);
	return 0;
    }

    ob->add("power_delay", 1);
    ob->block_attack(1);
    return 1;
}

int query_psionic() { return 1; }

/* EOF */

