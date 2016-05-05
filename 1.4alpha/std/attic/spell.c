/*
** Spell.c - inherited by most spells.
**   01 Aug 97 Cyanide added check_valid_targs().
**   11 Oct 97 Cyanide added query_caster_level() and get_level().
**   06 Nov 97 Cyanide finally moved cast_spell to here, and out of USER!
**   06 Jan 98 Cyanide added support for MR of attacks vs reflexive
**      spells.
**   23 Jan 98 Cyanide added the "summon" function.
**   28 Jan 98 Cyanide added "max_followers".
**   03 Jun 98 Cyanide updated summoning code for new follow
**             stuffs.
*/

#define FIND find_player("cyanide")
#define DEBUG(x) if (FIND) tell_object(FIND, x)

int query_caster_level (object player, string klass);
int get_caster_lvl(string klass, string group, int lvl);
int max_followers(object);

#include <magic.h>
#include <m_spells.h>

// This function determines whether or not a target is an invalid one
// for whatever reason.

int check_valid_targ (object caster, object targ) {

    if (!targ) {
	write("You can't find that here.\n");
	return 0;
    }

    if (!living(targ)) {
	write("That target isn't aliave.\n");
	return 0;
    }

    if (targ->query("no_attack")) {
	write("You aren't permitted to attack that.\n");
	return 0;
    }

    if (environment(targ) != environment(caster)){
	write("That's not even in the same room as you are!\n");
	return 0;
    }

    if (environment(targ)->query("safe")) {
	write("You cannot cast that here.\n");
	return 0;
    }

    if (targ==caster) {
	write("Are you sure you want to cast that at yourself?\n");
	return 0;
    }

    if (!visible(targ, caster)) {
	write ("You can't even see that!\n");
	return 0;
    }

    return 1;
}


// Check_magic_resist() shooud be called by ANY wizard spell that has a target!

varargs int check_magic_resist(int level, object targ, int sp, int dam) {
    int flag=1, mr;
    object ob, caster;

    caster=this_player();
    if (!caster) caster = environment(this_object());
    if (dam && (caster==targ))
	caster = targ->query_current_attacker();

    mr = targ->query("magic_resist");
    if (!level) level = (caster->query_level());
    if (mr) mr-= ((level-12)*5);
    else (mr=0);

    ob = present("#MAGIC_REFLEX#", targ);
    if (ob && sp>0) flag = ob->spell_reflex(caster, targ, sp, dam);

    if (random(100)<mr && flag) {
	flag = 0;
	tell_object(caster, wrap("The spell flows right over "+
	    targ->query("cap_name")+", leaving "+objective(targ->query("gender"))+
	    " completely unaffected."));
	tell_object(targ, wrap(caster->query("cap_name")+"'s spell washes over"+
	    " you, leaving you totally unaffected."));
	tell_room(environment(targ), wrap(caster->query("cap_name")+"'s spell"+
	    " flows over "+targ->query("cap_name")+" leaving "+ 
	    objective(targ->query("gender"))+" completely unaffected!\n"),
	  ({ targ, caster }) );
    }

    if (dam>0) targ->kill_ob(caster);
    return flag;
}

int query_caster_level (object player, string klass) {
    int lvl = 0, tmp = 0, i;
    string *class_type = ({ });

    klass = lower_case(klass);

    switch(klass) {
    case "wizard" : class_type = (string *)MAGE_TYPES; break;
    case "priest" : class_type = (string *)PRIEST_TYPES; break;
    default : return 0;
    }

    if (player->query_level("dragon"))
	return player->query_level("dragon");

    for (i=0;i<sizeof(class_type);i++) {
	tmp = player->query_level(klass);
	lvl = get_caster_lvl(class_type[i], klass, tmp);
	if (tmp>lvl) lvl = tmp;
    }

    return lvl;
}


int get_caster_lvl(string klass, string group, int lvl) {

    switch(group) {
    case "wizard" : 
	switch(klass) {
	case "bard" : lvl = (lvl * 2)/3; break;
	default: break;
	}
	break;
    case "priest" :
	switch(klass) {
	case "ranger" : lvl-=7; break;
	case "knight" :
	case "paladin" : lvl-=8; break;
	}
	break;
    }

    return lvl;
}

// This is the function that determines if a spell-using character has
// enough spell points to cast a desired spell, and then inflicts the
// appropriate costs, etc.

int cast_spell (object caster, int cost) {
    int sp;

    sp = (int)caster->query("spell_points");

    if (cost>sp) {
	tell_object(caster, NOT_ENOUGH_SP);
	return 0;
    }

    caster->set("spell_points", (sp-cost) );

    switch (cost) {
    case 0..15 : sp = 1; break;   //Reusing sp - sorry.
    case 16..35 : sp = 2; break;
    case 36..70 : sp = 3; break;
    default : sp = 4; break;
    }

    caster->add("power_delay", sp);
    caster->block_attack(1);
    return 1;
}


// Cyanide added for ease of determining spell obs. 06 Jan 98.

int query_spell() { return 1; }

// This is the func used by summoning spells to summon a monster.
// It automatically parses off atricles like "a" and "an" and 
// renames it something like "Cyanide's rat".

object summon (object ob, object summoner) {
    string name, short;
    int num;
    object *obs, sum_ob;

    if (!ob) return 0;
    obs = summoner->query("followers");
    if (!obs || !sizeof(obs)) obs = ({});
    obs = filter_array(obs, "filter_following", this_object(), ob);

    num = sizeof(obs);
    if (num >= max_followers(summoner)) {
	tell_object(summoner, "You cannot have "+
	  "any more followers at this time.\n");
	return 0;
    }

    if (!living(ob)) return 0;
    short = ob->query("short");
    short = lower_case(short);
    sscanf(short, "a %s", short);
    sscanf(short, "an %s");

    num = 0;

    if (summoner) {
	name = summoner->query("cap_name")+"'s ";
	name = name + short;
	num = query_caster_level(summoner, "wizard");
	if (query_caster_level(summoner, "priest") > num)
	    num = query_caster_level(summoner, "priest");

	// Turn num into (generally) an number from 1 to 10
	num /= 3;
    }

    ob->delete("weap_resist");
    ob->delete("aggressive");
    ob->set("xpv", 0);

    ob->set("short", name);
    ob->set("summoned", 1);
    ob->set("speed", 16 - num);
    ob->set("following", summoner);

    sum_ob = present("#SUMMON_OB#", summoner);
    if (!sum_ob) {
	sum_ob = clone_object("/adm/obj/summon_ob.c");
	sum_ob->move(summoner);
	sum_ob->begin();
    }
    sum_ob->add_follower(ob);
    return ob;
}


// This func tell the max num of summoned monsters.
// It's external from "summon" so other things can
// use it too.  (Cyanide, 28 Jan 98)

int max_followers( object caster ) {
    int num = 1;

    if (caster->query_level("wizard")) {
	if (caster->query_level("conjurer")) num = 3;
	else num = 2;
    }

    if (caster->query_skill("Animal Handling")) num++;

    return num;
}


int filter_following(object ob, object player) {
    int flag = 0;

    if (!ob || ob==0) return 0;

    if (environment(player) == environment(ob)) flag = 1;
    if (living(ob)) flag = 1;
    return flag;
}


int spell_mult(int dam) {
    dam = (5*dam)/3;

    return dam;
}
/* EOF */
