#include <mudlib.h>
inherit MONSTER ;

//this declares that an object will be cloned with the monster
object axe;
//more than 1 item would look somthing like 
//object ob1, ob2, ob3;      ///etc...

void create () {
  ::create();
  seteuid(getuid());
//short is what you see in an inventory, id is used to determine what
//it is exactally you want to look at
   set("short", "a skeleton");
   set ("long", @Foo
This is a skeleton, there is no flesh left on this body.
He looks back at you with hollow eyes.
Foo
);
//long is what is seen after an exa is used. the @Foo statement
//makes the code a bit cleaner
   set("id", ({ "skeleton" }) );
//set_level is one of Cyanide's brainstorms. what it does is 
//basically everything, you need this line if you plan to make a 
//working monster, it does hp, exp, stats, and such
   set_level(1);
//size is just what it sounds like, the size of the monster
   set_size(6);
//this line makes the file say who is hitting who
   set_name("a skeleton");
//makes sure the monster is in fact living
   set_living_name("skeleton");
//gender, female, male, neuter
   set("gender", "male");
//race can be whatever you like
   set("race", "skeleton");
//the set("undead", 1); allows for a metric buttload of shit to happen
//this sets the resistances of an undead. so far this is the only type
   set("undead", 1);
//this calls the other object and moves it to the monsters inventory
   axe = clone_object("/doc/examples/axe.c");
   axe->move(this_object());
//damage for the monster when it is barehanded
   set("damage", ({ 1,4 }) );
//this is so the monster dosen't hit you with 0
   set("weapon_name", "skeletal fists");
//verbs are what you see, verbs2 is what others see
   set_verbs( ({ "smack", "uppercut" }) );
   set_verbs2( ({ "smacks", "uppercuts" }) );
//this is for the wielding and equiping of shit.
   enable_commands() ;
//this gives a monster 1 attack per round barehanded
   set("natt", 1);
//this sets the chance that a monster actually says somthing
   set ("chat_chance", 10);
//this is what the monster says, or does outside of a combat situation
   set ("chat_output", ({
   }) );
//this is what a monster says or does in a combat situation
   set ("att_chat_output", ({
   }) );
}

//this is where the commands for the monster go
void init() {
//this makes the monster wield the axe when he is cloned
//if you wanted it to equip somthing you would use 
//command("equip cloak"); or whatever you wanted it to equip
   command("wield axe");
 }
