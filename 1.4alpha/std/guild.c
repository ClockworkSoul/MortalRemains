/*
** Inheritable guild code - Cyanide 1 August 97.
** Changes:
**    18 Feb 98   Cyanide fixed a few little things.
**    28 Jun 98   Cyanide fixed MORE stuff, specifically
**                with join, dual, and advance.
**    24 Nov 98   Cyanide added an "ARE YOU SURE?" dialog to dual.
*/

#include <mudlib.h>
#include <daemons.h>

inherit ROOM;

int get_exp (object guild, int lvl, object player);
static int member_guild (object);

void init(){
    add_action("c_advance", "advance");
    add_action("c_join", "join");
    add_action("c_dual", "dual");
    add_action("c_register", "register");
    add_action("c_title", "title");
}


static int c_join() {
    string gname, title;
    object guild;

    if (TPN=="Guest") {
	write("Sorry - the guest character may not join a class.\n");
	return 1;
    }

    guild = GUILD_D->get_guild_path(this_player());

    if (guild) {
	gname = file_name(guild);
    } else {
	return 1;
    }

    if (!GUILD_D->check_registry(guild)) return 1;

    if (TP->query_class() && TP->query_class() != "peasant") {
	write("You already have a class.\n");
	return 1;
    }

    if (!guild->join()) return 1; 
    if (!GUILD_D->d_join(this_player())) return 1;  

    title = guild->titles(TP);
    GUILD_D->do_title(TP, title);
    return 1;
}


int c_dual() {
    string gname, str, str2;
    object guild;

    guild = GUILD_D->get_guild_path(this_player());

    if (guild) {
	gname = file_name(guild);
    } else {
	return 1;
    }

    write("Dual classing has been reviewed and removed from the game.\n");
    return 1;

    if ((TP->query_class() && TP->query_class() == "peasant") ||
      (!TP->query_class()) ) {
	write("You must have a previous class in order "+
	  "to dual-class.\n");
	return 1;
    }

    if (!guild->query("class") || !guild->query("group")) {
	write("Error in guild, notify admin!\n");
	return 1;
    }

    str = guild->query("class");
    str = article(str)+" "+str;

    str2 = keys(TP->query_levels())[0];
    str2 = article(str2)+" "+str2;

    write(wrap("If you choose to dual class, you will permanantly "+
	"become "+str+", and will never again be able to advance "+
	"as "+str2+".")+"Are you SURE you wish to do this? (Y/N) > ");

    input_to("c_dual2", 0, guild);

    return 1;
}

static int c_dual2(string str, object guild) {
    string title;

    if (!str) str = "N";
    str = capitalize(str[0..0]);
    if (str != "Y") {
	write("Dual classing aborted.\n");
	return 1;
    }

    if (!GUILD_D->d_dual(TP)) return 1;  
    if (!guild->join()) return 1;
    if (!GUILD_D->d_dual2(TP)) return 1;   

    title = guild->titles(TP);
    GUILD_D->do_title(TP, title);
    return 1;
}


static int set_sp (object ob, int sp) {  
    return GUILD_D->set_sp(ob, sp);
}


static int set_tp (object ob, int tp) {  
    return GUILD_D->set_tp(ob, tp);
}


int add_hp (object ob, int hp) {
    hp+=PROPERTY_D->query_con_hp_bonus(ob);
    return GUILD_D->add_hp(ob, hp);
}


static int c_advance() {
    object guild, link;
    string c, c_old, title;
    int lvl, exp;

    guild = GUILD_D->get_guild_path(this_player());

    if (!guild->query("class") || !guild->query("group")) {
	write("Error in guild, notify admin!\n");
	return 1;
    }

    if (!member_guild(TP)) return 1;

    c = guild->query("class");

    lvl = TP->query_level(c);
    if (lvl==0){
	write("Mere peasant! Join or begone!\n");
	return 1;
    }

    lvl++;

    exp = get_exp(guild, lvl, TP);

    if (!exp || exp==-1) {
	write("Error in experience array!\n"+
	  "Notify guildmaster immediately!\n");
	return 1;
    }

    if (GUILD_D->d_advance(TP, exp)) {
	title = guild->titles(TP);
	GUILD_D->do_title(TP, title);

	tell_object(TP, "Congratulations! You advance to level "+  
	  lvl+"!\nYour new title is "+TP->query("short")+".\n");

	guild->advance();
    }
    return 1;
}


static int member_guild (object ob)  {
    string c, *classes;
    object guild = GUILD_D->get_guild_path(ob);

    if (!ob->query_levels()) {
	write("You haven't even joined a class yet!\n");
	return 0;
    }

    classes = keys(ob->query_levels());
    c = guild->query("class");

    if (!guild->query("class") || !guild->query("group")) {
	write("Error in guild, notify admin!\n");
	return 0;
    }

    if (member_array(c, classes) == 0)
	return 1;
    else {
	write("You're not even a member of this class!\n");
	return 0;
    }
}

int c_title(string str){

    if (!member_guild(TP)) {
	write("You can only change your title if you belong to the class.\n");
	return 1;
    }
    if (TP->query_level() < 30){
	write("You can only change your title if you are lvl 30 or more.\n");
	return 1;
    }

    GUILD_D->do_title(TP, ("$N "+str+" ($A)"));
    write("Your new title is: "+TP->query_title()+".\n");
    return 1;
}

static int c_register() {
    object guild;
    string title;

    if (!member_guild(TP)) {
	return 1;
    }

    guild = GUILD_D->get_guild_path(TP);
    if (!GUILD_D->check_registry(guild)) return 1;

    title = guild->titles(TP);
    GUILD_D->do_title(TP, title);

    guild->register();
    write("Your title is now "+TP->query("short")+".\n");
    return 1;
}

// This func figures out how much experience the player needs to
// advnace.
int get_exp (object guild, int lvl, object player) {
    int exp;
    string Klass, race;
    object link;

    link = player->query_link();

    if ((int)link->query("level_old")>lvl){
	//Klass = (values(link->query("Class_old"))[0]);
	//yeah we want to send the new class but the old lvl if it is higher -ilz
	Klass = (values(link->query("Class"))[0]);
	lvl = (int)link->query("level_old");
    }
    else 

	Klass = (values(link->query("Class"))[0]);

    exp = PROPERTY_D->query_xp_needed(Klass, lvl);

    // Reusing lvl to be the xp penalty percentage.
    race = player->query("race");
    switch (race) {
    case "drow" : lvl = 20; break;
    case "githzerai" :
	if (player->query_level("wizard")) lvl = 0;
	else lvl = 10;
	break;
    case "aasimar" :
	if (player->query_level("wizard")) lvl = 10;
	else lvl = 5;
	break;
    case "half-giant" : lvl = 30; break;
    case "ogre" : lvl = 10; break;
    case "half-ogre" : lvl = 5; break;
    default: lvl = 0; break;
    }

    return exp;
}

/* EOF */
