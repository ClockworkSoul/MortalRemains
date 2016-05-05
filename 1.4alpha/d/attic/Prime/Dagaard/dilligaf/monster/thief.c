#include <mudlib.h>
inherit MONSTER ;

object ob1, ob2;

void create () {
  ::create();
  seteuid(getuid());
  set("short" , "a thief");
  set("long" , @EndText
  This thief seems to be at the end of his ropes. His despair is worn
  on his face as he stares at you with cold eyes, quickly he wields
  his dagger and is ready to take you on, and steal your coins.

EndText
);
  set("id" , ({ "thief" }) );
  set_level(3+random(5));
  set_size(3);
  set("aggressive" , 5);
  set("stat/dexterity" , 19);
  set_skill("Short Blades", 2,"Strength");
  set_name("a thief");
  set_living_name("thief");
  set("gender" , "male");
  set("race" , "halfling");
  ob1 = clone_object("/d/Prime/Dagaard/dilligaf/weapons/dagger.c");
  ob1->move(this_object());
  ob2 = clone_object("/d/Prime/Dagaard/dilligaf/armour/leather.c");
  ob2->move(this_object());
  set("damage" , ({ 1,4 }) );
  set("weapon_name" , "fists");
  set_verbs( ({ "smack" , "uppercut" }) );
  set_verbs2( ({ "smacks" , "uppercuts" }) );
  enable_commands() ;
   set("natt", 1);
}

void init() {
  command("wield dagger");
  command("equip armour");
 }
