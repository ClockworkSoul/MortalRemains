// File: /cmds/std/_drop.c
// based on TMI-2 version
// completely rewritten...cleaned up...modified
// by Zeus, 13-03-1993
// Fixed dropping nothing (no objs or no droppable objs)
// Leto 26/5/95
//  1 Jun 97 Cyanide fixed to the single coin system.
//  2 Jul 97 Cyanide allowed support for "drop all sword" and 
//      "drop sword 4".
// 23 May 99 Cyanide completed the conversion over to credits.
// 20 Jun 99 Cyanide added support for ammunition.

#include <mudlib.h>
#include <money.h>
#include <move.h>

#define CAP_NAME this_player()->query("cap_name")

inherit DAEMON;

string help();

string *num_names = ({ "zeroth", "first", "second", "third", "fourth",
"fifth", "sixth", "seventh", "eighth", "ninth", "tenth" });

int cmd_drop(string str) {
    mapping ammo;
    object *inv, ob, env;
    int res, amount, capac, i, money, dropped;
    string short, *types, type, word, tmp;

    if (!str) {
	write(help());
	return 1;
    }
    if (!(env = environment(this_player()))) {
	notify_fail("You can't drop anything in the void!\n");
	return 0;
    }

    /* Check for form "get 30 9mm rounds"  */
    if( sscanf( str, "%d %s %s", capac, type, tmp ) == 3 ) {
	if (TP->query("ammo")) ammo = TP->query("ammo");
	else ammo = ([]);

	amount = ammo[type];

	if (capac < 1) {
	    write("You can't drop non-positive amounts.\n");
	    return 1;
	}

	amount -= capac;

	if (amount < 0) {
	    write("You don't have that many "+type+" rounds.\n");
	    return 1;
	}

	ob = clone_object(AMMO);
	ob->set_type(type);
	ob->set_number(capac);
	ob->move(environment(TP));
	TP->set("ammo/"+type, amount);

	say(TPN+" drop some "+type+" rounds.\n");
	write("You drop "+capac+" "+type+" rounds.\n");

	return 1;
    }

    type = "";
    amount = 0;

    // This handles the dropping of any money.
    if (str=="all credits" ||
      (sscanf(str, "%d %s", amount, type) == 2)) {

	// This is how we tell if the player wanted to
	// "drop all credits"
	money = TP->total_wealth();
	if (!amount) {
	    amount = money;
	    type = "credits";
	}

	if (type!="credits" && type!="credit")  return 0;
	if (amount<1) {
	    notify_fail("That would cause a spacial "+ 
	      "anomoly that would likely destroy you.\n");
	    return 1 ;
	}

	if(money < amount) {
	    notify_fail("You don't have that many credits.\n");
	    return 1;
	}

	this_player()->debit(amount);
	ob = clone_object(COINS);
	ob->set_number(amount);
	res = ob->move(environment(this_player()));
	if(res != MOVE_OK) {
	    this_player()->credit(amount);
	    ob->remove();
	    notify_fail("You can't drop that.\n");
	    return 0;
	}
	if(amount == 1) word = "credit"; else word = "credits";
	write("You drop "+amount+" "+word+".\n");
	say(CAP_NAME+" drops some "+word+".\n");
	return 1;
    }

    // Syntax:  Drop all ammo
    if (str=="all ammo" || str=="all ammunition" ||
      str=="all rounds") {
	ammo = this_player()->query("ammo");
	if(!mapp(ammo) || !sizeof(keys(ammo)) ) {
	    write("You have no ammo on you.\n");
	    return 1;
	}
	types = keys(ammo);
	if(!pointerp(types) || sizeof(types) == 0) {
	    write("You have no ammo on you.\n");
	    return 1;
	}
	for(i = 0; i < sizeof(types); i++) {
	    if(ammo[types[i]] == 0) continue;
	    this_player()->set("ammo/"+types[i], 0);
	    ob = clone_object(AMMO);
	    ob->set_type(types[i]);
	    ob->set_number(ammo[types[i]]);
	    res = ob->move(environment(this_player()));
	    if(res != MOVE_OK) {
		this_player()->set("ammo/"+types[i], ammo[types[i]]);
		this_player()->set("capacity", capac);
		ob->remove();
		continue;
	    }
	    if(ammo[types[i]] == 1) word = "round"; else word = "rounds";
	    write("You drop "+ammo[types[i]]+" "+types[i]+" "+word+".\n");
	    say(CAP_NAME+" drops some "+types[i]+" "+word+".\n");
	}
	return 1;
    }

    /* Check for "drop all" */
    if(str == "all") {
	inv = all_inventory(this_player());
	//if(!pointerp(inv) && sizeof(inv) < 1) {
	if(sizeof(inv) < 1) {
	    notify_fail("You are not carrying anything.\n");
	    return 0;
	}
	for(i = 0; i < sizeof(inv); i++) {
	    if(!inv[i] || inv[i]->query("prevent_drop"))  continue;
	    res = inv[i]->move(environment(this_player()));
	    if(res != MOVE_OK) continue;
	    if(inv[i])
		short = (string)inv[i]->query("short");
	    if(!short) short = "something";
	    say(CAP_NAME+" drops "+short+".\n");
	    dropped++;
	}
	if(dropped)
	{
	    write("You drop your whole inventory on the ground.\n");
	    return 1;
	}
	else notify_fail("You are not carrying anything you wish to part with.\n");
	return 0;
    }

    if (sscanf(str,"all %s", type) == 1) {
	if (environment(TP)) {
	    inv = all_inventory(TP);
	    inv = filter_array(inv,"filter_short");
	    inv = filter_array(inv, "filter_droppable");
	}
	if (sizeof(inv)<=0) {
	    write("There is nothing of that type to drop.\n");
	    return 1;
	}
	money = 0;    // Using as a counter...
	for (i=0;i<sizeof(inv);i++) {
	    if (!inv[i]->id(type)) continue;
	    if (inv[i]->query("prevent_drop")) continue;
	    res = (int)inv[i]->move(environment(TP));
	    if (res==MOVE_OK) {
		short = inv[i]->query("short");
		if (!short) short = "something";
		write("You drop "+short+".\n");
		say(CAP_NAME+" drops "+short+".\n");
		money++;
	    }
	}
	if (!money)
	    write("There's nothing of that type to drop.\n");
	else
	    write(money+" items dropped.\n");
	return 1;
    }

    /* Check for format "drop sword 3"*/
    if (sscanf(str,"%s %d", str, amount) == 2) {
	if (amount < 1) {
	    write("Only philosophers can stipulate"+
	      " as to the nature of negative quantity.\n");
	    return 1;
	}
	inv = all_inventory(this_player());
	res = 0; i = 0;    // Initializing variables...
	while ((res!=amount)&&(sizeof(inv)>0)&&(i<sizeof(inv))) {
	    ob = inv[i];
	    if (member_array(str, (string)ob->query("id")) != -1 )
		res++;
	    i++;
	}
	if ((res==0) || (i<amount)) {
	    if ((amount<=10) && (amount>=0))
		write("There is no "+num_names[amount]+" "+
		  str+" in your inventory.\n");
	    else 
		write("There is no "+amount+"th "+str+
		  " in your inventory.\n");
	    return 1;
	}
    } else {
	ob = present(str, this_player());
    }

    if(!ob) {
	notify_fail("You don't have that on you.\n");
	return 0;
    }

    if(ob->query("prevent_drop")) {
	notify_fail("You can't drop that object.\n");
	return 0; }

    res = ob->move(environment(this_player()));
    if(res != MOVE_OK) {
	notify_fail("You can't drop that.\n");
	return 0;
    }
    short = (string)ob->query("short") ;
    if(!short) short = "something";
    write("You drop "+short+".\n");
    say(CAP_NAME+" drops "+short+".\n");
    return 1;
}

static int filter_short(object ob) {return (ob->query("short")!=0);}

static int filter_droppable(object ob) {
    return !(ob->query("prevent_drop")); } 

string help() {
    return("Syntax: drop <item | all>\n\n"+
      "This makes your character try to drop the specified\n"+
      "item.  If all is used then your character drops all\n"+
      "items carried. If you type \"drop all gold\" or other\n"+
      "type, then all of your credits of that type are dropped.\n"+
      "\"Drop all credits\" drops all your money.\n"+
      "\nSee also: get, put\n");
}
