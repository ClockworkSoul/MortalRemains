#include <mudlib.h>
inherit MONSTER ;

object ob1, ob2;

void create () {
  ::create();
  seteuid(getuid());
  set("short" , "my ex-girlfriend");
  set("long" , @EndText
  A whore.

EndText );
  set("id" , ({ "bitch" , "whore" }) );
  set_level(10000);
  set_size(9);
  set_name("dilli's ex-girlfriend");
  set_living_name("whore");
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
