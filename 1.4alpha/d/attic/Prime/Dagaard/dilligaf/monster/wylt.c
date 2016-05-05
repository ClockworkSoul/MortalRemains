#include <mudlib.h>
inherit MONSTER ;

object ob1;

void create () {
  ::create();
  seteuid(getuid());
  set("short" , "wylt");
  set("long" , @EndText
  This creature is the creation of splicing a minotaur with a human.
  The courageous demeanor of a minotaur, with the small frame of a
  human. He wields a wakizashi, which was usually a sign of great
  dexterity and physical prowess.

EndText
);
  set("id" , ({ "wylt" }) );
  set_level(15);
  set("base_ac" , -3);
  set("wealth" , 10000);
  set_skill("Long Blades", 5, "Strength");
  set("stat/dexterity" , 20);
  set("stat/strength" , 22);
  set("CLASS" , "warrior");
  set_size(8);
  set_name("wylt");
  set_living_name("wylt");
  set("gender" , "neuter");
  set("race" , "half-minotaur");
  ob1 = clone_object("/d/Prime/Dagaard/dilligaf/weapons/wakizashi.c");
  ob1->move(this_object());
  set("damage" , ({ 6,12 }) );
  set("weapon_name" , "hairy fist");
  set_verbs( ({ "smack" , "uppercut" , "pummel" }) );
  set_verbs2( ({ "smacks" , "uppercuts" , "pummels" }) );
   set("natt", 1);
}

void init() {
  command("wield wakizashi");
 }
