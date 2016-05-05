#include <config.h>
#include <uid.h>  
#include <mudlib.h>
#include <skills.h>
#include <experience.h>
#include <daemons.h>
#include "sigil.h"
#include "/adm/daemons/propertyd.c"
inherit ROOM;

void create()
{
  ::create();
  seteuid(ROOT_UID);
  set( "light", 1 );
set("short","Fighter Proficiency Training Hall.");
  set( "long", @EndText
This is the Great hall of fighters where you can select 
your fighter proficiencies.
Commands are: list , select <prof name>, join fighter, advance
EndText
  );
  set( "exits", ([
"north" : SIGIL+"mainst3.c",
  ]) );
}
void init (){
add_action ("list_prof", "list");
add_action ("learn_prof", "select");
add_action ("become_fighter", "join");
add_action ("advance_level", "advance");
}
int list_prof() {
int i, s ;
mapping skills;
	write("Proficiency		 Slots\n");
	write("Ambidexterity		 1\n");
	write("Armorer			 2\n");
	write("Blind Fighting		 2\n");
	write("Iron Will		 2\n");
	write("Weaponsmithing		 3\n");
	write("All Around Attack	 1\n");
	write("Death Blow		 2\n");
        write("------------------------------\n") ;
return 1;
}
int learn_prof(string str) {
int i, freeslots;
string *skills;
mixed selectable;
freeslots = this_player()->query("nwp_free");
skills=explode(str, " ");
selectable = keys(SK_FIGHTER);
for (i=0;i<sizeof(skills); i++)
	skills[i]=capitalize(skills[i]);
str = implode(skills, " ");
  i = (member_array(str, selectable));
  if (i == -1) {
 write("No such skill.\n");
 return 1;
  } 
	if (this_player()->query("CLASS") == "warrior"){
	write("welcome great lord.\n");
	}else{
   write("You must become a warrior to learn proficiencies here.\n");
 return 1;
 } 
	if ((this_player()->query_skill(str))>0){
  		write ("You already have that skill!\n");
  		return 1;
  		}
  if (freeslots<(int)values(SK_FIGHTER)[i]){
	write ("Not enough free slots.\n");
	return 1;
	}
this_player()->set_skill(str, (values(SK_FIGHTER))[i]);
this_player()->set("nwp_free", freeslots-((values(SK_FIGHTER))[i]));
tell_object(this_player(), str+" selected.\n");
return 1;
}

int become_fighter(string str) {

	int i, t;
	if (!str) {
			write ("join what?\n");
			return 1;
			}
		if (str=="fighter"){
	if (this_player()->query("CLASS")) {
			write ("We arent allowing multi-classing, yet.\n");
			return 1;
			}
	if (this_player()->query("stat/strength")<9) {
			write ("You must have a strength of at least 9 you weakling!\n");
			return 1;
			}
	this_player()->set("CLASS", "warrior");
	this_player()->set("class", "fighter");
this_player()->set_skill("One Weapon Style", 1);
this_player()->set_skill("Two Weapon Style", 1);      
this_player()->set_skill("Shield Style", 1);            
this_player()->set_skill("Two Handed Style", 1); 
/*
USE THE TITLE SHIT IN THE "SET" COMMAND!
NEVER SET TITLE!
this_player()->set("title", this_player()->query("cap_name")+" The Recruit");       
*/
this_player()->set_env("TITLE", "the Recruit\t("+this_player()->query("al_title")+")");
	this_player()->query_link()->set("level", 1 );
	this_player()->set("wp_free", 4);
	this_player()->set("saves", 16);
	i = (this_player()->query("stat/intelligence") - 11);
	t =	this_player()->query("stat/intelligence");
	if (i < 5){
			if (t < 16) i = 4;
			if (t < 14) i = 3;
			if (t < 12) i = 2;
			if (t < 9) i = 1;
			}

	this_player()->set("nwp_free", (i + 3));
	
	write ("You become a warrior.\n");
			return 1;
			}else{
			write ("join what?\n");
			return 1;
			}
					}

void advance_level(){
	int i, xpneeded, conbonus;
	mixed selectable, titles;

	if (this_player()->query("CLASS")=="warrior") {
	i = (this_player()->query_level())+1;
	if (i > 30) {
		write("you can only raise to level 30.\n");
		return 1;
		}
	if (this_player()->query("class")=="fighter"){
	xpneeded = (XP_FIGHTER[i]);
	
	}
		if (xpneeded < 1){
			write("er, you have no class!\n");
			return 1;
			}
	if ((this_player()->query("experience")) < xpneeded) {
			write ("You do not have enough experience!\n");
			write ("You need " + xpneeded + " experience to advance to level "+ i+"\n");
			return 1;
			}
//here is where you actually raise!
		write ("You advance to level " + i +"!\n");
		this_player()->query_link()->set("level", i );
			conbonus =  (PROPERTY_D->query_con_hp_bonus(this_player()) * 3);
				this_player()->set("max_hp", (this_player()->query("max_hp") + conbonus + random(9) + random(9) + random(9) + 3));	
	if ((i%3)==0){
				this_player()->set("nwp_free", this_player()->query("nwp_free")+1);
			this_player()->set("wp_free", this_player()->query("wp_free")+1);
				}
	if ((i%2)==0){
				this_player()->set("saves" , (this_player()->query("saves")-1));
		}
		return 1;
		//yeah there's got to be an easier way... but hey, it works.
			}else{
				write ("you must be a warrior to advance here.\n");
			return 1;
			}
				}
