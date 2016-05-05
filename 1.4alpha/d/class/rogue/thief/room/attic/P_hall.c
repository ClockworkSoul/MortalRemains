#include <config.h>
#include <mudlib.h>
#include <skills.h>

inherit ROOM;

void create()
{
  ::create();
   seteuid(getuid());
   set("light", 1);
   set("short", "Training Room");
   set("long", @YoMomma
Thieves come here when they want to gain a new proficiency.
You may get a list of proficiencies by typeing list.
To pick a proficiency you need to type select <and the proficiency).
There seedy looking man in the corner watching you.
YoMomma
  );
  set( "exits", ([
   "north" : "/d/class/rogue/thief/room/thief_guild.c",
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
	write("Ambidexterity		 1\n");
	write("Blind Fighting		 2\n");
	write("Read Lips		 2\n");
	write("Ventriloquism		 1\n");
	write("Evasion			 1\n");
	write("Nondetection		 2\n");
     write("------------------------------\n") ;
return 1;
}
int learn_prof(string str) {
int i, freeslots;
string *skills;
mixed selectable;
freeslots = this_player()->query("nwp_free");
skills=explode(str, " ");
selectable = keys(SK_THIEF);
for (i=0;i<sizeof(skills); i++)
	skills[i]=capitalize(skills[i]);
str = implode(skills, " ");
  i = (member_array(str, selectable));
  if (i == -1) {
 write("No such skill.\n");
 return 1;
  } 
	if ((this_player()->query_skill(str))>0){
  		write ("You already have that skill!\n");
  		return 1;
  		}
  if (freeslots<(int)values(SK_THIEF)[i]){
	write ("Not enough free slots.\n");
	return 1;
	}
this_player()->set_skill(str, (values(SK_THIEF))[i]);
this_player()->set("nwp_free", freeslots-((values(SK_THIEF))[i]));
tell_object(this_player(), str+" selected.\n");
return 1;
}
