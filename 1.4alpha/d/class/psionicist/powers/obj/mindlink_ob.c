/*
** Mindlink_ob.c
** For the mindlink psionic power.
**
** Credits:
**  27 Oct 98   Cyanide created the file. A little complex for 
**              the first psionic power on the MUD, don't ya think?
*/

#include <psionics.h>
#include "/u/c/cyanide/debug.h"

// Prototypes
nomask int send_func(string, int);
nomask void dest_all_links();
object * all_links();

// Global vars.
object env, owner;
int mass_dest = 0;
int active = 0;

inherit "/std/psionics.c";

/**************************************************************/

void create() {
    seteuid(getuid());
    set("id", ({ "#MINDLINK#" }) );
    set("prevent_drop", 1);
    set("dest_at_die", 1);
}

/**************************************************************/

void init() {
    add_action("send", "send");
}

/**************************************************************/

varargs int activate(object ownr, int lvl) {
    owner = ownr;

    if (environment()) {
	env = environment();
    } else {
	remove();
	tell_object(owner, "Error");
	return 0;
    }

    set("owner", owner);
    set("name", owner->query("name") );
    set("owner_name", owner->query("name") );

    if (!lvl)
	set("level", owner->query_level("psionicist") );
    else
	set("level", lvl);

    if (ownr!=env) {
	send_func("*MINDLINK* "+env->query("cap_name")+
	  " has joined the mindlink.", 1);
    }

    active = PSI_MASTER->add_object(TO, "minute");
    return active;
}

/**************************************************************/

int upkeep() {
    int i, sz;
    object *obs;

    if (!owner || !interactive(owner)) remove();

    if (!maintain(owner, 3)) {
	obs = children(base_name(TO));
	sz = sizeof(obs);

	dest_all_links();        
	return 0;
    }

    return 1;
}

/**************************************************************/

nomask int send_func(string str, int ignore_me) {
    int i, sz;
    object *obs = users();

    sz = sizeof(obs);
    for (i=0; i<sz; i++) {
	object mlink;

	if (ignore_me && obs[i]==env) continue;
	mlink = present("#MINDLINK#", obs[i]);
	if (!mlink) continue;
	if (mlink->query("name") != query("name")) continue;
	tell_object(obs[i], iwrap(str) );
    }

}

/**************************************************************/

int send(string str) {
    string outstr;

    outstr = ("*MINDLINK* "+TPN+" sends: ");
    send_func(outstr+str, 1);

    write(iwrap("*MINDLINK* You send: "+str));
    return 1;
}

/**************************************************************/

int remove() {
    if ((env) && living(env)) {
	// If the owners link goes, they all go.
	if (env==owner) {
	    object *links = all_links();
	    int i, sz = sizeof(links);

	    tell_object(env, "Your mindlink ends. Your mind "+
	      "feels very empty.\n");
	    send_func("The mindlink has ended.", 1);
	    sz--;
	    for (i=sz; i>=0; i--) {
		if (links[i]==TO) continue;
		links[i]->set_mass_dest();
		links[i]->remove();
	    }
	} else {
	    send_func("*MINDLINK* "+env->query("cap_name")+
	      " has left the mindlink.\n", 1);            
	}
    }

    ::remove();
    return 1;
}

/**************************************************************/

nomask void dest_all_links() {
    int i, sz;
    object *links;

    links = all_links();
    sz = sizeof(links);
    for (i = --sz; i>=0; i++) {
	if (links[i]==TO) continue;
	links[i]->remove();
    }
    TO->remove();
}

/**************************************************************/

object * all_links() {
    int i, sz;
    object *obs, *links = ({});

    if (!owner) return ({});

    obs = children(base_name(TO));
    sz = sizeof(obs);
    for (i=0; i<sz; i++) {
	if (owner != obs[i]->query("owner"))
	    continue;

	links += ({ obs[i] });
    }

    return links;
}

int set_mass_dest() { env = 0; }

/**************************************************************/

int query_psionic() { return 1; }

/**[ End of File ]*********************************************/
