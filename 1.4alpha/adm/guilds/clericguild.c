#include <config.h>
#include <mudlib.h>
#include <uid.h>
#include <skills.h>
#include "sigil.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( ROOT_UID );
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
"nerull" : "/d/class/priest/shriven/rooms/priest_guild.c",
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
string *skills;
mixed selectable;
object tal;
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
	write("Welcome great priest of "+TP->query("deity")+".\n");
	}else{
   write("You must become a cleric to learn proficiencies here.\n");
 return 1;
 } 
	if ((this_player()->query_skill(str))>0){
  		write ("You already have that skill!\n");
  		return 1;
  		}
  if (freeslots<(int)values(SK_CLERIC)[i]){
	write ("Not enough free slots.\n");
	return 1;
	}
if ( (str == "Iron Will") && (this_player()->query_level("priest") > 15) ){
if ( TP->query_skill("Iron Will")){
	write ("You already have that skill!\n");
	return 1;
	}
  TP->set("max_hp" , (TP->query("stat/constitution") + TP->query("max_hp")) );
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
