#include <mudlib.h>
inherit MONSTER ;

object ob1, ob2;

void create () {
  ::create();
  seteuid(getuid());
  set("short" , "a mugger");
  set("long" , @EndText
  A mugger, he has a long scar down his right cheek and his eye on that
  side is whitened over and glassy. He looks like a mean bastard.

EndText
);
set("id" , ({ "mugger" }) );
  set_level(5+random(2));
  set("wealth" , 1000);
  set_size(3);
  set("aggressive" , 9);
  set_name("a mugger");
  set_living_name("mugger");
  set("gender" , "male");
  set("race" , "halfling");
  ob1 = clone_object("/d/Prime/Dagaard/dilligaf/weapons/dagger.c");
  ob1->move(this_object());
  ob2 = clone_object("/d/Prime/Dagaard/dilligaf/armour/leather.c");
  ob2->move(this_object());
  set("damage" , ({ 2,5 }) );
  set("stat/dexterity" , 20);
  set_skill("Short Blades" , 3,"Strength");
  set("weapon_name" , "fists");
  set_verbs( ({ "smack" , "uppercut" }) );
  set_verbs2( ({ "smacks" , "uppercuts" }) );
  enable_commands() ;
  set("natt" , 1);
}

void init() {
  command("wield dagger");
  command("equip armour");
 }
