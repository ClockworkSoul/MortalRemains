#include <config.h>
#include <mudlib.h>
#include <skills.h>
#include "sigil.h"

inherit GUILD;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set ("short","Clerical Proficiency Training Hall.");
    set( "long", @EndText
This is where Priests come to select proficiencies.
Commands are: list, select <prof name>
EndText
    );
    set( "exits", ([
      "north" : SIGIL+"mainst6.c",
      "tempus" : "/d/class/priest/battleguard/rooms/priest_guild.c",
      "oghma" : "/d/class/priest/lorekeeper/rooms/priest_guild.c",
    ]) );
}
void init (){
    add_action ("list_prof", "list");
    add_action ("learn_prof", "select");
}
int list_prof() {
    int i, s ;
    mapping skills;
    write("Proficiency		 Slots\n");
    write("Healing			 2\n");
    write("Herbalism		 2\n");
    write("Iron Will		 2\n");
    write("Eminence		 1\n");
    write("Loan Health		 1\n");
    write("Talisman		 2\n");
    write("Smite			 2\n");
    write("------------------------------\n") ;
    return 1;
}
int learn_prof(string str) {
    int i, freeslots;
    object tal;
    string *skills;
    mixed selectable;
    freeslots = this_player()->query("nwp_free");
    skills=explode(str, " ");
    selectable = keys(SK_CLERIC);
    for (i=0;i<sizeof(skills); i++)
	skills[i]=capitalize(skills[i]);
    str = implode(skills, " ");
    i = (member_array(str, selectable));
    if (i == -1) {
	write("No such skill.\n");
	return 1;
    } 
    if (this_player()->query_class("priest")){
	write("welcome great holy one.\n");
    }else{
	write("You must become a cleric to learn proficiencies here.\n");
	return 1;
    } 
    if (str == "Iron Will"){
	if (TP->query_level("priest") < 15){
	    write("You must be level 15 for that skill!\n");
	    return 1;
	}
	if ( TP->query_skill("Iron Will")){
	    write ("You already have that skill!\n");
	    return 1;
	}
	add_hp(TP, (TP->query("stat/constitution")));
    }

    if ((this_player()->query_skill(str))>0){
	write ("You already have that skill!\n");
	return 1;
    }
    if (freeslots<(int)values(SK_CLERIC)[i]){
	write ("Not enough free slots.\n");
	return 1;
    }

    if (str == "Talisman"){
	tal = clone_object("/d/class/obj/talisman");
	tal->move(TP);
    }  
    this_player()->set_skill(str, (values(SK_CLERIC))[i]);
    this_player()->set("nwp_free", freeslots-((values(SK_CLERIC))[i]));
    tell_object(this_player(), str+" selected.\n");
    return 1;
}
