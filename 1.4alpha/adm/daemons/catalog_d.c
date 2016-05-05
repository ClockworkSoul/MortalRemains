/*
** FILE:    catalog_d.c
** PURPOSE: Keeps track of all summonable monsters on the mud, and
**          organizes them by a modified level
** CHANGES:
**     Dec 1999  Cyanide created the file.
**     Mar 2000  Cyanide added run-time verification and correction.
**               Also improved notification and base name removal.
**     Jun 2000  Cyanide added get_catalog_entry(mixed). Simply
**               returns the monsters entry in the catalog. Makes 
**               no changes.
*/

#include "/u/c/cyanide/debug.h"
#include <uid.h>
#include <daemons.h>

inherit DAEMON;

#define SAVE_PATH_MAIN "/adm/etc/"
#define SAVE_PATH_ATTIC SAVE_PATH_MAIN+"attic/"
#define SAVE_NAME "catalog"           

varargs object get_random_mon( int, int );
int get_level ( object );
nomask int save_all();
int verify_level( object ob );
int remove_base_name ( string );

// Globals
mapping reg_map = ([]);

/******************************************************************/ 
/* FUNCTION:   verify_level
** RECEIVES:   object ( the monster whose level is to be checked)
** RETURNS:
**       0 - Level does not match (and has been corrected)
**       1 - Verified
*/

int verify_level( object ob ) {
    int level;
    string name;

    if (!ob) return 0;

    level = get_level( ob );
    name = base_name( ob );

    if (level == reg_map[name]) {
	return 1;
    } else {
	REGISTRY_D->admin_call(
	  "Registry entry for "+name+" corrected. (Level was "+
	  reg_map[name]+", now "+level+").");
	reg_map[name] = level;
	save_all();
	return 0;
    }
}

/******************************************************************/

int get_catalog_entry( mixed mon ) {
    int lvl;
    string bname;

    if (objectp(mon)) bname = base_name((object)mon);

    if (member_array(bname, keys(reg_map)) != -1) {
	lvl = reg_map[ bname ];
    } else {
	lvl = -1;
    }

    return lvl;
}

/******************************************************************/

int catalog_monster ( mixed mon ) {
    object ob;
    string *base_names, name;
    int level;

    if (stringp(mon)) {
	ob = clone_object((string)mon);
    } else {
	if (objectp(mon)) ob = (object)mon;
	else return 0;
    }

    if (strsrch(base_name(ob), "/attic") != -1) {
	remove_base_name(base_name(ob));
	return 0;
    }

    if (ob->query("prevent_summon")) {
	remove_base_name(base_name(ob));
	return 0;
    }

    base_names = keys(reg_map);
    name = base_name(ob);

    if (member_array(name, base_names) != -1)
    {
	verify_level(ob);
	return 0;
    }

    level = get_level(ob);

    reg_map += ([ name : level ]);

    REGISTRY_D->admin_call(
      name+" has been added to the summoning registry "+
      "as rank "+level+"."
    );

    save_all();

    return 1;
}

/******************************************************************/

varargs object get_random_mon( int lvl1, int lvl2 ) {
    string *base_names, *names = ({});
    int *lvls, i, num;
    object ob = 0;

    if (!lvl1) lvl1 = 0;
    if (!lvl2) lvl2 = lvl1;

    base_names = keys(reg_map);
    lvls = values(reg_map);

    names = ({});
    for (i = 0; i < sizeof(lvls); i++) {
	if (lvls[i] >= lvl1 && lvls[i] <= lvl2)
	    names += ({ base_names[i] });
    }

    num = sizeof(names);
    if (num > 0) {
	num = random(num);
	ob = clone_object(names[num]);

	if (!ob) remove_base_name(names[num]);
	if (!verify_level(ob)) {
	    ob = get_random_mon(lvl1, lvl2);
	} else {
	    if (!ob || ob->query("prevent_summon")) {
		remove_base_name(names[num]);

		ob = get_random_mon(lvl1, lvl2);
	    }
	}
    }

    return ob;
}

/******************************************************************/

int get_level ( object ob ) { 
    int hd, counter;
    object wep;

    hd = ob->query_level();

    wep = ob->query("weapon1");
    if (wep && !living(wep)) {
	hd++;
	if (ob->query("weapon2")) hd++;
	switch (ob->query_skill(wep->query("weapon_type"))) {
	case 3..4 : hd++; break;
	case 5 : hd+=2; break;
	}
    } else {
	wep = ob;
    }

    counter = 0;
    if (pointerp(wep->query("damage"))) 
	counter = ((int *)wep->query("damage"))[1];

    if (!counter || counter < 0) counter = 0;

    counter /= 15;
    hd+= counter;

    if ((int)ob->query("stat/constitution") > 14) hd++;

    if ((int)ob->query("armor_class")<0) hd++;
    if ((int)ob->query("natt")>3) hd++;

    /*   Summoned monsters don't get this anymore.
	if (ob->query("weap_resist"))
	    hd+=(ob->query("weap_resist"));
    */

    /*
	if (ob->query("magic_resist")) {
	    if ((int)ob->query("magic_resist") > 120)
		ob->set("magic_resist", 120);
	    hd+=((ob->query("magic_resist"))/20);
	}
    */

    if (ob->query("special")) 
	hd += ob->query("special");

    /*
	for (counter=0; 
	  counter<sizeof(keys(ob->query("resist_type")));
	  counter++) 
	{
	    int val = (values(ob->query("resist_type")))[counter];

	    if (val <= 50) hd++;
	}
    */

    return hd;

}  // end get_level()

/******************************************************************/

nomask int save_all() {
    save_object(SAVE_PATH_MAIN+SAVE_NAME);
    save_object(SAVE_PATH_ATTIC+SAVE_NAME);
}

/******************************************************************/

int remove_base_name ( string base ) {

    if (member_array(base, keys(reg_map))!=-1) {
	map_delete(reg_map, base);

	REGISTRY_D->admin_call(base+" has been removed from "+
	  "summon registry.");

	save_all();
    }

    return 1;
}

/******************************************************************/

nomask void load_saved_data() 
{
    if (!restore_object(SAVE_PATH_MAIN+SAVE_NAME)) 
    {
	REGISTRY_D->admin_call("ERROR: Failure in loading catalog "+
	  "registry! Attempting to load from backup copy.");
	if (!restore_object(SAVE_PATH_ATTIC+SAVE_NAME)) {    
	    REGISTRY_D->admin_call("ERROR: Fatal failure loading "+
	      "backup copy. Catalog is loading a null mapping.");
	    reg_map = ([]);
	}
    }

    return;
}

/******************************************************************/

mapping dump_catalog() { return reg_map; }

/******************************************************************/

void create() 
{
    int i, sz;
    string *bases;

    seteuid( ROOT_UID );
    load_saved_data();

    bases = keys(reg_map);
    sz = sizeof(bases);

    for (i=0; i<sz; i++) 
	if (!file_exists(bases[i] + ".c"))
	    remove_base_name(bases[i]);
}

/* EOF */
