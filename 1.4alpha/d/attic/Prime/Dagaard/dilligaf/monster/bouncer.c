#include <mudlib.h>
inherit MONSTER ;

object ob1;

void create () {
  ::create();
  seteuid(getuid());
  set("short" , "a bouncer");
  set("long" , @EndText
  This is just a muscle-bound freak. Huge rips appear in his shirt
  as he flexes, in his hand he holds a sap and is ready to jump at
  any sign of trouble.

EndText
);
  set("id" , ({ "bouncer" }) );
  set_level(5+random(5));
  set_skill("Clubbing Weapons", 2, "Strength");
  set("stat/strength" , 25);
  set("CLASS" , "warrior");
  set("wealth" , 1000);
  set_size(7);
  set_name("bouncer");
  set_living_name("bouncer");
  set("gender" , "male");
  set("race" , "human");
  ob1 = clone_object("/d/Prime/Dagaard/dilligaf/weapons/sap.c");
  ob1->move(this_object());
  set("damage" , ({ 5,10 }) );
  set("base_ac" , 0);
  set("weapon_name" , "fists");
  set_verbs( ({ "smack" , "uppercut" }) );
  set_verbs2( ({ "smacks" , "uppercuts" }) );
}

void init() {
  command("wield sap");
 }
