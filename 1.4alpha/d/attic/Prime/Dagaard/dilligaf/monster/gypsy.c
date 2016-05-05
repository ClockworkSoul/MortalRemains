#include <mudlib.h>
inherit MONSTER ;

object ob1, ob2;

void create () {
  ::create();
  seteuid(getuid());
  set("short" , "gypsy");
  set("long" , @EndText
  This old woman sits in the middle of the road moaning in appreciation
  to the sun beating down on her withered brown face. Cracks of age
  appear close to her mouth, and she has crows feet at the sides of her
  eyes. Deep in a trance, she doesn't notice you...

EndText
);
  set("id" , ({ "gypsy" }) );
  set("base_ac" , 7);
  set_skill("Short Blades" , 3,"Strength");
  set("CLASS" , "rogue");
  set("stat/dexterity" , 20);
  set("wealth" , 1000+(random(500)) );
  set_level(3+random(3) );
  set_size(4);
  set_name("a gypsy");
  set_living_name("gypsy");
  set("gender" , "female");
  set("race" , "human");
  ob1 = clone_object("/d/Prime/Dagaard/dilligaf/armour/grobes.c");
  ob1->move(this_object());
  ob2 = clone_object("/d/Prime/Dagaard/dilligaf/weapons/dagger.c");
  ob2->move(this_object());
  set("damage" , ({ 1,4 }) );
  set("weapon_name" , "fists");
  set_verbs( ({ "smack" , "uppercut" }) );
  set_verbs2( ({ "smacks" , "uppercuts" }) );
   enable_commands() ;
   set("natt", 1);
   set ("chat_chance", 10);
   set ("chat_output", ({
   }) );
   set ("att_chat_output", ({
   }) );
}

void init() {
    command("wear coat");
    command("wear robes");
    command("wield dagger");
 }
