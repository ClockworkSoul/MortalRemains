/*
** The first psionic power.
** Essentially, a chat line.
**
** This will function a bit differently than AD&D mindlink. This
** version will allow the psionicist to link together as many
** people as desired into a chat line. 
**
** Cost: 3 psp/minute/person.
*/

#include <psionics.h>
#include <move.h>

#define SYNTAX "psi mindlink <name>\n"
#define COST 3

inherit "/std/psionics.c";

varargs int psi_mindlink(string str, int ob) {
    object target, link;
    int found = 1;

    if (!str) {
	write(SYNTAX);
	return 0;
    } 

    seteuid(getuid());

    str = lower_case(str);
    target = find_player(str);
    if (!target) found = 0;

    if (!maintain(TP, COST)) {
	write("You lack the strength to initiate the power.\n");
	return 0;
    }

    if (present("#MINDLINK#", target)) {
	write(target->query("name")+" is already mindlinked.\n");
	return 1;
    }

    link = present("#MINDLINK#", TP);
    if (!link) link = clone_object(PSI_OBJ+"mindlink_ob.c");
    if (!link) {
	write("Error in cloning mindlink object!\n");
	return 0;
    }
    link->move(TP);
    link->activate(TP);

    link = clone_object(PSI_OBJ+"mindlink_ob.c");
    if (!link) {
	write("Error in cloning mindlink object!\n");
	return 0;
    }

    if (link->move(target) != MOVE_OK) {
	link->remove();
	write("Error in moving mindlink ob to target!\n");
	return 0;
    }

    if (link->activate(TP)) {
	write("Your thoughts enter the mind of "+
	  target->query("name")+".\n");
	message("spell", wrap("You feel the presence of "+TPN+
	    " in your mind."), target);
    } else {
	write("Attempt to mindlink has failed.\n");
	link->remove();
    }

    return 1;
}

/* EOF */
