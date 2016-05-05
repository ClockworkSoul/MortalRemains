#include <mudlib.h>
inherit MONSTER ;

void create () {
  object ob1, ob2, ob3;

::create();

  seteuid(getuid());
  set("short" , "City Guard");
  set("long" , @EndText
  A city guard. Don't let him fool you, he is very proficient with the
  use of his longsword, and the armour he wears looks like its well
  taken care of.  He looks at you with disregard, he could care less
  if he saw you or not.

EndText
  );
  set("id" , ({ "guard" }) );
   set("capacity" , 1000);
  set("max_cap" , 1000);
   set("volume" , 1000);
   set("max_vol" , 1000);
   set("mass" , 1500);
  set("bulk" , 300);
  set_name("Guard");
  set("gender" , "male");
  set_living_name("Guard");
set("aggressive",1);
   enable_commands();
  set_level(5+random(5));
  set_skill("Long Blades" , 2, "Strength");
  set("damage" , ({ 1,3 }) );
  set("weapon_name" , "longsword");
  set_verbs( ({ "stick" , "slashe at" , "hack at" }) );

  ob1 = clone_object("/u/d/dilligaf/armour/garmour.c");
  ob1->move(this_object());
  ob2 = clone_object("/u/d/dilligaf/armour/gcloak.c");
  ob2->move(this_object());
  ob3 = clone_object("/u/d/dilligaf/weapons/gsword.c");
  ob3->move(this_object());
}

void init(){
  command("wield sword");
  command("equip armour");
  command("equip cloak");
}
