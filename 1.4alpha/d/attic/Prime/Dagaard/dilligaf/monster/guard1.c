#include <mudlib.h>
inherit MONSTER ;

object ob1, ob2;

void create () {
  ::create();
  seteuid(getuid());
  set("short" , "towne guard");
  set("long" , @EndText
  This is one of the guards that patrol Dagaard and keep the peace. His
  armour shines in the light, and the sword at his side looks deadly.

EndText
);
  set("id" , ({ "guard" }) );
  set("base_ac" , 5);
  set_skill("Long Blades", 3,"Strength");
  set("CLASS" , "warrior");
  set("stat/strength" , 20);
  set("wealth" , 500);
  set_level(8+random(5));
  set_size(6);
  set_name("a guard");
  set_living_name("guard");
  set("gender" , "male");
  set("race" , "human");
  ob1 = clone_object("/d/Prime/Dagaard/dilligaf/armour/chainmail.c");
  ob1->move(this_object());
  ob2 = clone_object("/d/Prime/Dagaard/dilligaf/weapons/longsword.c");
  ob2->move(this_object());
  set("damage" , ({ 2,8 }) );
  set("weapon_name" , "fists");
  set_verbs( ({ "smack" , "uppercut" }) );
  set_verbs2( ({ "smacks" , "uppercuts" }) );
   enable_commands() ;
   set("natt", 1);
   set ("chat_chance", 10);
   set ("chat_output", ({
    "Towne Guard says: Please move along.\n",
    "Guard fingers his sword, and eyeballs you.\n",
    "The Guard sniffs the air and says: Kinda smells like rain.\n",
   }) );
   set ("att_chat_output", ({
    "The Guard yells: VIOLATORS! You will pay for this!\n",
    "The Guard says: Ahhh, finally...someone to play with.\n",
   }) );
}

void init() {
  command("wield sword");
  command("equip armour");
   command("wield axe");
 }
