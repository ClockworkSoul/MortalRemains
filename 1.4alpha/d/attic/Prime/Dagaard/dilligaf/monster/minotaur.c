#include <mudlib.h>
inherit MONSTER ;

object ob1, ob2;

void create () {
  ::create();
  seteuid(getuid());
  set("short" , "Kar");
  set("long" , @EndText
  Kar looks at you as you enter. His large minotaur head trying to
  scope you out and see if he should kill you or not for intruding
  upon his home. He is a disgraced minotaur who wronged his bretheren
  by disgracing them on the battle field. Instead of being killed he
  surrendered and spared the lives of his children and wife, for this
  he was cast out of his clan..and now wanders the countryside looking
  for a place to die...and redemption. The battle axe he wields is
  absolutely huge and you know he can do some damage with it.

EndText );
  set("id" , ({ "kar" , "minotaur" }) );
  set_skill("Axes", 4, "Strength");
  set_skill("Two Handed Style" , 2, "Strength");
  set_level(20+random(5));
  set_size(9);
  set_name("kar");
  set_living_name("kar");
  set("gender" , "male");
  set("race" , "minotaur");
  ob1 = clone_object("/d/Prime/Dagaard/dilligaf/weapons/hbattleaxe.c");
  ob1->move(this_object());
  ob2 = clone_object("/d/Prime/Dagaard/dilligaf/armour/chainmail2.c");
  ob2->move(this_object());
  set("damage" , ({ 6,15 }) );
  set("weapon_name" , "huge fists");
  set("wealth" , 5000);
  set("CLASS" , "warrior");
  set("stat/strength" , 25);
  set("stat/constitution" , 22);
  set("base_ac" , 3);
  set_verbs( ({ "punch" , "uppercut" }) );
  set_verbs2( ({ "punches" , "uppercuts" }) );
   enable_commands() ;
   set("natt", 1);
}

void init() {
  command("wear armour");
  command("wield axe");
 }
