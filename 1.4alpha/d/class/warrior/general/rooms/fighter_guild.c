/*
**Fighter's guild
** based upon cy's and ilz code
*/

#define FIND find_player("ilzarion")
#define DEBUG(x) if (FIND) tell_object(FIND, x)



#include <daemons.h>
#include <mudlib.h>
#include <c_warriors.h>
#include <config.h>
#include <uid.h>  
#include <skills.h>
#include <daemons.h>
#include "/adm/daemons/propertyd.c"
inherit GUILD;

void create() {
  ::create();
  seteuid(getuid());
  set( "light", 1 );
set("short","Fighter Proficiency Training Hall.");
  set( "long", @EndText
This is the Great hall of fighters where you can select 
your fighter proficiencies.
Commands are: list , select <prof name>, join fighter, advance
EndText
  );
  set("light", 1);
  set("class", "fighter");
  set("group", "warrior");
  set("experience", WARRIOR_XP);
}

void init (){
::init();
add_action ("list_prof", "list");
add_action ("learn_prof", "select");
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
	if (this_player()->query_level("warrior") ){
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
string titles (object ob) {
  string str;
  int lvl;

  lvl = ob->query_level("fighter");
     str = ({
      "$N the Peasant ($A)",
      "$N the Recruit ($A)",
      "$N the Trainee ($A)",
      "$N the Fodder ($A)",
      "$N the Green Soldier ($A)",
      "$N the Novice Soldier ($A)",
      "$N the Soldier ($A)",
      "$N the Veteran Soldier ($A)",
      "$N the Sergeant ($A)",
      "$N the Veteran Sergeant ($A)",
      "$N the Captain ($A)",
      "$N the Warrior ($A)",
      "$N the Mercenary ($A)",
      "$N the Myrmidon ($A)",
      "$N the Mercenary Captain ($A)",
      "$N the General ($A)",
      "$N the Lord of Arms ($A)",
      "$N the Baron of Arms ($A)",
      "$N the King of Arms ($A)",
      "$N the Emperor of Arms ($A)",
      "$N the Armsmaster ($A)",
      "$N the Lord of Conflict ($A)",
      "$N the Baron of Battle ($A)",
      "$N the King of Carnage ($A)",
      "$N the Emperor of Evisceration ($A)",
      "$N the Deathmaster ($A)",
      "$N the General of War ($A)",
      "$N the Lord of War ($A)",
      "$N the Baron of War ($A)",
      "$N the King of War ($A)",
      "$N the Emperor of War ($A)",
      "$N the Warmaster ($A)" 
    })[lvl];
 
  return str;
}                


int join() {
  object badge;
	int i, t;
  if (TP->query("base_stat/strength") < 9) {
    write("You are too puny to join us!\n");
    return 0;
  }

  write("A voice says, \"Welcome ...\"\n");
 

  badge = clone_object(FIGHTER+"obj/badge.c");
  if (!badge) {
    write("\nA voice says, \"Forgive us child. You cannot join us"+
      " now.\"\nPlease notify Cyanide.\n");
    return 1;
  }
  badge->move(this_player());
 this_player()->set_skill("One Weapon Style", 1);
this_player()->set_skill("Two Weapon Style", 1);      
this_player()->set_skill("Shield Style", 1);            
this_player()->set_skill("Two Handed Style", 1); 
this_player()->query_link()->set("level", 1 );
	this_player()->set("wp_free", 4);
i = (this_player()->query("stat/intelligence") - 11);
	t =	this_player()->query("stat/intelligence");
	if (i < 5){
			if (t < 16) i = 4;
			if (t < 14) i = 3;
			if (t < 12) i = 2;
			if (t < 9) i = 1;
			}

	this_player()->set("nwp_free", (i + 3));

  return 1;
}

int advance() {
 
  int level, hp, max;
 object guild;
  string c, title;
  int lvl, exp;
 level = (TP->query_level("warrior"));
   

  if(level%3==0) TP->add("nwp_free", 1);
  if(level%3==0) TP->add("wp_free", 1);


  hp = WAR_HP_ROLL;
 
   add_hp(TP, hp);
  return 1;
}
