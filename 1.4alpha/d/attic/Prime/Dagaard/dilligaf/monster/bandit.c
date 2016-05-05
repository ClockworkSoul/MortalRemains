#include <mudlib.h>
#include "mons.h"
inherit MONSTER ;

object ob1, ob2;

void create () {
  ::create();
  seteuid(getuid());
  set("short" , "a bandit");
  set("long" , @EndText
  A small man with a blacked dagger in his hand. He seems to be at the
  end of his ropes and would do anything for your coinpurse.

EndText
);
  set("id" , ({ "bandit" }) );
  set_level(5+random(3));
  set_size(3);
  set_name("a bandit");
  set("aggressive" , 5);
  set_living_name("bandit");
  set("gender" , "male");
  set("race" , "halfling");
  set("stat/dexterity" , 19);
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
  set_skill("Short Blades", 2,"Strength");
}

void init() {
  command("wield dagger");
  command("equip armour");
 }
