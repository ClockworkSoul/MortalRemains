// _qc.c - Idea stolen from Cyanide.  Quality control quick check.
// (28 Aug 99) Chronos reinvents the wheel.
// (26 Jun 00) Cyanide makes this to scan ANYTHING.

#include "/u/c/cyanide/debug.h"
#include <daemons.h>
#include <body.h>
#include <commands.h>
#include <teleport.h>

#define PUNCTUATION ({ ".",",","!","*",";",":" })
#define DEPRECATED "** This property is deprecated and should be removed. **"
#define NORMAL "Appears to be set."
#define ERROR "[!] THIS VALUE IS SET INCORRECTLY"
#define NULL "** NOT SET **"

inherit DAEMON ;

void scan_armor( object );
void scan_weapon( object );
void generic_scan_primary( object );
void generic_scan_secondary( object );

string title, msg;

// This allows us to reconfigure output fields at will.
void sysout( string title, string msg ) {
    msg = sprintf("%-12s : %-=60s\n", title, msg);
    write(msg);
}

void scan_living( object ob ) {
    // Primary stats
    generic_scan_primary( ob );
    if (userp(ob)) {
	msg = "*This is a USER* ";
	if (wizardp(ob)) {
	    if (adminp(ob)) {
		msg += "(Administrator)";
	    } else {
		msg += "(Wizard)";
	    }
	}
	sysout("USER", msg);
    }

    switch (ob->query_level()) {
    case -100..0 : msg = " "+NULL+" (call set_level() !!)"; break;
    case 1..9 : msg = " (Very low level)"; break;
    case 10..13 : msg = " (Low level)"; break;
    case 14..16 : msg = " (Medium level)"; break;
    case 17..26 : msg = " (High level)"; break;
    case 27..35 : msg = " (Very high level)"; break;
    default : msg = " [! Get QC permission]"; break;
    }
    msg = "" + ob->query_level() + msg;
    sysout("Level", msg);

    msg = ob->query("race");
    msg = ((msg && msg!="generic monster") ? NORMAL : NULL);
    sysout("Race", msg);

    if (userp(ob) || ob->query("prevent_summon")) {
	msg = "This monster is not summonable by summon spells.";
    } else {
	int c = CATALOG_D->get_catalog_entry(ob);

	if (c == -1) msg = "Not a member of the summoning registry.";
	else msg = "Summoning rank: "+c;
    }
    sysout("Summonable", msg);

    scan_weapon( ob );

    // Secondary stats

    generic_scan_secondary( ob ) ;

    if (ob->query("natt"))
	sysout("Natt", DEPRECATED);
    if (ob->query("weap_resist")) 
	sysout("Weap_resist", "This monster can only be hit by +"+
	  ob->query("weap_resist")+" weapons or greater.");
    if (ob->query("no_attack"))
	sysout("No_attack", "This monster may not be attacked.");
    if (ob->query("undead"))
	sysout("Undead", "This monster is undead.");
    if (!undefinedp(ob->query("lore"))) 
	sysout("Lore", "This monster has a lore defined.");
    if (ob->query("lore_type")) {
	msg = CMD_LORE->is_valid_skill(ob->query("lore_type"));

	if (!msg || !strlen(msg))
	    msg = "[! Invalid skill type: "+
	    ob->query("lore_type")+" ]";

	sysout("Lore_type", msg);
    }

    if (ob->query("moving")) {
	int s = ob->query("speed");

	if (undefinedp(s)) 
	    msg = "ERROR: 'speed' property undefined!";
	else
	    msg = "Monster wanders once every "+s+" heartbeats.";

	sysout("Moving", msg);
    }
}

void scan_room( object room ) {
    object y;
    object * inv, * roominv, * inv2;
    mapping Map;
    string x;
    int i, j ;
    room = environment(TP) ;
    if (!room) {
	write("The void looks fine to me, dumbass.\n") ;
	return 1;
    }

    generic_scan_primary( room );
    if (!room->query("item_desc") ||
      !sizeof(keys((mapping)room->query("item_desc"))) )
	msg = NULL;
    else msg = NORMAL;
    sysout("ItemDesc", msg);

    if (!room->query("exits"))
	msg = "[!] This room has no normal exits.";
    else
	msg = NORMAL;
    sysout("Exits", msg);

    Map = room->query("objects") ;

    if (!Map) msg = "This room does not have an objects property.";
    else {
	msg = "";
	inv = values(Map) ;
	roominv=all_inventory(room) ;
	inv2 = allocate(sizeof(roominv));
	for(i=0;i<sizeof(roominv);i++) {
	    if (!userp(roominv[i])) {
		inv2[j] = roominv[i] ;  j++ ; 
	    }
	}
	if (sizeof(inv) != j) {
	    if (j<sizeof(inv)) {
		msg += " [!] Not all of the objects appear to be loading.\n         ";
		msg += "     Objects loaded from this room: "+sizeof(inv)+"\n         ";
		msg += "     Objects in room (Minus users): "+j+"\n         ";
		msg += "     NOTE: Update the room and try again.";
	    }
	    else {
		msg += " [!] There are objects in the room that are not loaded\n" ;
		msg +=  "     from the objects property.\n" ;
		msg += "     Objects loaded from this room: "+sizeof(inv)+"\n";
		msg += "     Objects in room (Minus users): "+j+"\n" ;
		msg += "     NOTE: Update the room and try again.\n" ;
	    }
	}
	else msg = "Objects appear to be loading normally.";
    }
    sysout("Objects", msg);
    write("\n[Secondary properties scan..]\n") ;
    write("-----------------------------\n");
    if (room->query("outside")) 
	sysout("Outside", "** THIS ROOM IS SET AS OUTSIDE. **");
    if (!room->query("light"))
	sysout("Light", "[!] This room is dark.");
    if (room->query("smell")) 
	sysout("Smell", "This room has a smell set.");
    if (room->query("listen"))
	sysout("Listen", "This room has a listen property set.");
    if (room->query("search_desc")) 
	sysout("Search", "This room has special search messages set.");
    if (room->query("search_func"))
	sysout("SearchFunc", "This room has a search function set.");
    if (room->query("exit_msg"))
	sysout("ExitMsg", "This room has exit messages set.");
    if (room->query("item_func")) 
	sysout("ItemFunc", "This room has item functions set.");
    if (room->query("post_exit_func"))
	sysout("PostExit", "This room has a post-exit function.");
    if (room->query("pre_exit_func"))
	sysout("PreExit", "This room has a pre-exit function.");
    if (room->query("safe"))
	sysout("Safe", "This is a safe room.");
    if (room->query("forbidden")) 
	sysout("Forbidden", "Wandering monsters may not enter this room.");
    if (room->query("no_teleport")) {
	i = (int)room->query("no_teleport");
	switch(i) {
	case NO_IN : msg = "Players may not teleport in.";
	    break;
	case NO_OUT : msg = "Players may not teleport out.";
	    break;
	case NO_IN_OR_OUT : msg = "Players may not teleport in or out.";
	    break;
	}
	sysout("Teleport", msg);
    }
    if (room->query("exit_suppress") && 
      sizeof(keys((mapping)room->query("exits"))) )
	sysout("Hidden exits", "This room has hidden exits.");
    if (room->query("underwater"))
	sysout("Underwater", "This room is an underwater area.");
    if (room->query("area_type"))
	sysout("Area_type", DEPRECATED);
    if (room->query("arena"))
	sysout("Arena", DEPRECATED);

    write("Finished.\n");
    return 1;
}

// This scan non-room objects.
// This is used to scan an object. If (prim==1), this is
// the primary check being used, and we should do the 
// generic scans.
void scan_object( object ob, int prim ) {
    mixed mix;

    if (prim)
	generic_scan_primary( ob );

    mix = ob->query("id");
    if (!undefinedp(mix) && pointerp(mix))
	msg = NORMAL;
    else
	msg = ERROR;
    sysout("ID", msg);

    if (prim)
	generic_scan_secondary(ob);
    if (ob->query("dest_at_sell"))
	sysout("Sell", "This item is destroyed when sold.");
}

void scan_armor( object ob ) {
    int a;
    if (!living(ob)) {	
	generic_scan_primary( ob );
	scan_object( ob, 0 );

	if (ob->query("type")) msg = capitalize(ob->query("type"));
	else msg = NULL+"\nDid you call set_armor_type() ?";
	sysout("Armor type", msg);
    }

    if (ob->query("armor"))
	a = (int)ob->query("armor"); 
    else
	a = 0;

    switch( a ) {
    case -5..-1 : msg = ""+a+": This armor is CURSED."; break;
    case 0 : msg = "This armor provides NO protection."; break;
    case 1..2 : msg = ""+a+": Provides minor protection."; break;
    case 3..4 : msg = ""+a+": Provides moderate protection."; break;
    case 5..6 : msg = ""+a+": Provides good protection."; break;
    case 7..8 : msg = ""+a+": Provides excellent protection."; break;
    case 9..10 : msg = ""+a+": Provides UNRIVALED protection."; break;
    default : msg = "[!] ILLEGAL VALUE ("+a+")"; break;
    }
    sysout("Armor", msg);

    if (ob->query("bonus")) {	
	int b = ob->query("bonus");

	switch(b) {
	case -1 : msg = "* This is a cursed object *"; break;
	case 0 : msg = ""; break; // Should never get here
	case 1 : msg = "(faintly magical)"; break;
	case 2 : msg = "(dimly magical)"; break;
	case 3 : msg = "(moderately magical)"; break;
	case 4 : msg = "(strongly magical - should be rare)"; break;
	case 5 : msg = "(overwhelmingly magical - VERY rare)"; break;
	case 6 : msg = "[!] ARTIFACT - Get QC permission"; break;
	default : "[!] ILLEGAL BONUS VALUE!"; break;
	}
	sysout("Bonus", ""+b+" "+msg);
    }

    if (ob->query("size")) {
	int s = (int)ob->query("size");

	if (s < -1) s = -2;

	msg = "Size to to "+s+" ";
	switch(s) {
	case -2 : msg += "( [!] ILLEGALLY SMALL SIZE! )"; break;
	case -1 : msg += "(*magically fits all*)"; break;
	case 0 : msg += "(fits NOBODY[!])"; break;
	case 1..4 : msg += "(fits small creatures)"; break;
	case 5..7 : msg += "(fits human sized creatures)"; break;
	case 8..11 : msg += "(fits large creatures)"; break;
	default : msg += "(fits huge creatures of size "+(s-1)+
	    " to "+(s+1)+")"; break;
	}
    } else {
	msg = "Not set. Defaulted to human-sized (6)";
    }
    sysout("Size", msg);

    // Start secondary properties.
    generic_scan_secondary( ob );

    if (ob->query("stat_mod")) {
	string *stats;
	int i, flag = 0;

	msg = "";
	stats = keys((mapping)ob->query("stat_mod"));
	flag = sizeof(stats);

	for (i=0; i<flag; i++) {
	    msg += sprintf( "\n%15s : %d", 
	      capitalize(stats[i]),
	      (int)ob->query("stat_mod/"+stats[i])
	    );
	}
	sysout("Stat_mod", "This armor provides stat modification:"+msg);
    }

    if (ob->query("equip_func"))
	sysout("Equip_func", "This armor has a wield function defined.");
    if (ob->query("unequip_func"))
	sysout("Unequip_func", "This armor has an unwield function defined.");
}

void scan_weapon( object ob ) {
    if (!living(ob)) {
	generic_scan_primary( ob );
	scan_object( ob, 0 );

	if (ob->query("weapon_type")) msg = ob->query("weapon_type");
	else msg = NULL+"\nDid you call set_weapon_type() ?";
	sysout("Weap type", msg);
    }

    if (living(ob)) {
	msg = (undefinedp(ob->query("weapon_name")) ?
	  NULL+" (Defaulted to \"fists\")" : NORMAL);
	sysout("Weapon_name", msg);
    } else {
	msg = (undefinedp(ob->query("name")) ? NULL : NORMAL);
	sysout("Name", msg);
    }

    if (ob->query("damage")) {
	int hi, lo;

	if (pointerp(ob->query("damage"))) {
	    int *dam = (int *)ob->query("damage");
	    hi = dam[1];  lo = dam[0];

	    msg = "Min: "+lo+", Max: "+hi;
	    if (lo > hi) msg += "\nERROR: Array inverted. Damage should "+
		"be set as ({ low, hi })";
	    if (lo < 1) msg += "\nWARNING: Low value less than 1.";
	    if (hi > 15) msg += "\nWARNING: Unusually high damage maximum (15+)";

	} else {
	    msg = ERROR;
	}
    } else {
	msg = NULL;
    }
    sysout("Damage", msg);

    if (ob->query("damage_type")) {
	string type = ob->query("damage_type");
	msg = capitalize(type);

	if (member_array(type, VALID_DAMAGE_TYPES) == -1) 
	    msg += " [INVALID DAMAGE TYPE!]";

    } else {
	msg = "Not set; defaulted to bludgeoning.";
    }
    sysout("Damage_type", msg);

    if (ob->query("to_hit_adj")) {
	int b = ob->query("to_hit_adj");

	switch(b) {
	case -1 : msg = "* This is a cursed object *"; break;
	case 0 : msg = ""; break; // Should never get here
	case 1 : msg = "(faintly magical)"; break;
	case 2 : msg = "(dimly magical)"; break;
	case 3 : msg = "(moderately magical)"; break;
	case 4 : msg = "(strongly magical - should be rare)"; break;
	case 5 : msg = "(overwhelmingly magical - VERY rare)"; break;
	case 6 : msg = "[!] ARTIFACT - Get QC permission"; break;
	default : "[!] ILLEGAL BONUS VALUE!"; break;
	}
	sysout("Bonus", ""+b+" "+msg);
    }

    sysout("Verbs", ob->has_verbs()?NORMAL:NULL);

    // Start secondary properties.
    if (!living(ob)) {
	generic_scan_secondary( ob );

	if (ob->query("nosecond"))
	    sysout("Nosecond", "This weapon can only be wielded two-handed.");

	if (ob->query("wield_func"))
	    sysout("Wield_func", "This weapon has a wield function defined.");
	if (ob->query("unwield_func"))
	    sysout("Unwield_func", "This weapon has an unwield function defined.");
    }
}

void generic_scan_primary( object ob ) {
    int v;
    string x, str;

    write("[Quality Control Quick Scan Initiated..]\n");
    write("----------------------------------------\n");

    sysout("Filename", file_name(ob));

    x = "";

    // Check for short existance and correct format.
    if (ob->query("short") && strlen(ob->query("short"))) {
	str = ob->query("short");
	v = strlen(str) - 1;
	if (member_array(str[v..v], PUNCTUATION)!=-1)
	    x += "\n[There should be NO punctuation in "+
	    "short descriptions!]";

	if (!ob->query_room()) {
	    string tmp;

	    tmp = explode(str, " ")[0];
	    if (member_array(lower_case(tmp),
		({ "a", "an" })
	      )!=-1) {
		if (tmp[0..0] != lower_case(tmp[0..0]))
		    x += "\n[Do not capitalize 'a' or 'an']";
	    }
	}
    } else {
	str = NULL;
    }
    sysout("Short", str + x);

    if (ob->query("long")) {
	string *lines;
	int flag = 0;

	lines = explode((string)ob->query("long"), "\n");
	for (v=0; v<sizeof(lines); v++) {
	    if (strlen(lines[v]) > 75) flag++;
	}
	if (flag) 
	    msg = "[ "+flag+" lines are too long. Limit "+
	    "to 75 characters or less ]";
	else
	    msg = NORMAL;
    } else {
	msg = NULL;
    }

    sysout("Long", msg);

    x = ob->query("author") ;
    if (!x) msg = NULL;
    else {
	x = capitalize(x) ;
	if (!user_exists(lower_case(x))) 
	    msg = x+" [** User does not exist **]";
	else msg = (x+".");
    }
    sysout("Author", msg);

}

// This scans secondary (non-critical) properties for
// non-room, non-living objects.
void generic_scan_secondary( object ob ) {

    write("\n[Secondary properties scan..]\n") ;
    write("-----------------------------\n");

    sysout("Mass", 
      undefinedp(ob->query("mass")) ? NULL : NORMAL);
    if (!undefinedp(ob->query("bulk")))
	sysout("Bulk", DEPRECATED);

    if (ob->query("cloned_by"))
	sysout("Cloned_by", "This object was cloned by "+
	  capitalize((string)ob->query("cloned_by"))+".");
    if (ob->query_auto_load())
	sysout("Autoload", "This object is autoloading");
    if (ob->query("prevent_clean"))
	sysout("Clean", "This object is immune to clean.");
    if (ob->query("prevent_drop"))
	sysout("Drop", "This object cannot be dropped.");
    if (ob->query("prevent_get"))
	sysout("Get", "This object cannot be taken.");
    if (!undefinedp(ob->query("value"))) {
	sysout("Value", 
	  intp(ob->query("value")) ? ""+ob->query("value")+" credits."
	  : ERROR );
    }

    if (ob->query("smell"))
	sysout("Smell", "This item has a smell set");

    if (ob->query("light"))
	sysout("Light", "This object radiates light");

    if (ob->query("invisible")) {
	switch((int)ob->query("invisible")) {
	case 1 : msg = " players."; break;
	case 2 : msg = " wizards."; break;
	default : msg = " administrators."; break;
	}

	sysout("Invisible", "This object is invisible to"+msg);
    }
}

int cmd_qc (string str) {
    object ob;

    if (!str) str = "here";

    if (str=="here") ob = environment(TP);
    else
    if (str=="me") ob = TP;
    else
	ob = present(str, TP);

    if (!ob) ob = present(str, environment(TP));
    if (!ob) {
	write("Could not located referenced object.\n");
	return 1;
    }

    str = OBJECT;
    if (ob->query_room()) str = ROOM;
    if (ob->query("weapon")) str = WEAPON;
    if (ob->query("armor_object")) str = ARMOR;
    if (living(ob)) str = LIVING;

    DEBUG("QC: "+TPN+" QCing "+file_name(ob)+"\n");
    switch(str) {
    case OBJECT : scan_object( ob, 1 ); break;
    case LIVING : scan_living( ob ); break;
    case WEAPON : scan_weapon( ob ); break;
    case ARMOR : scan_armor( ob ); break;
    case ROOM :
    default : scan_room( environment(TP) ); break;
    }

    TP->set("cwf", base_name(ob)+".c");
    return 1;
}

string help() {
    return @endlong
Usage: qc (name)

This is the quality control quick scan program, designed to speed
up the Quality Control effort on the Mud.  It does a quick check of
some of the basic things that could be discrepancies in rooms.  It
does not check the object files within the room, but does verify 
that objects in the room load.
endlong
    ;
}

