#include <config.h>
#include <mudlib.h>
#include <skills.h>
#include "sigil.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
set ("short","Mages Proficiency Training Hall.");
  set( "long", @EndText
This is where mages can select proficiencies.
Commands are: list, select <prof name>
EndText
  );
  set( "exits", ([
	"north" : SIGIL+"mainst5.c",
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
	write("Alchemy			 2\n");
	write("Arcanology		 1\n");
	write("Herbalism		 2\n");
	write("Mental Resistance	 1\n");
	write("Tactics Of Magic	 1\n");
	write("Thaumaturgy		 1\n");
	write("Talisman		 2\n");
	write("Signature Spell		 2\n");
        write("------------------------------\n") ;
return 1;
}
int learn_prof(string str) {
int i, freeslots;
string *skills;
mixed selectable;
freeslots = this_player()->query("nwp_free");
skills=explode(str, " ");
selectable = keys(SK_MAGE);
for (i=0;i<sizeof(skills); i++)
	skills[i]=capitalize(skills[i]);
str = implode(skills, " ");
  i = (member_array(str, selectable));
  if (i == -1) {
 write("No such skill.\n");
 return 1;
  } 
	if (this_player()->query("CLASS") == "wizard"){
	write("welcome great master.\n");
	}else{
   write("You must become a mage to learn proficiencies here.\n");
 return 1;
 } 
	if ((this_player()->query_skill(str))>0){
  		write ("You already have that skill!\n");
  		return 1;
  		}
  if (freeslots<(int)values(SK_MAGE)[i]){
	write ("Not enough free slots.\n");
	return 1;
	}
this_player()->set_skill(str, (values(SK_MAGE))[i]);
this_player()->set("nwp_free", freeslots-((values(SK_MAGE))[i]));
tell_object(this_player(), str+" selected.\n");
return 1;
}
