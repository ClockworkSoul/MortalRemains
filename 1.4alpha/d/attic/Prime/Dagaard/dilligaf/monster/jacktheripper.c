#include <mudlib.h>
inherit MONSTER ;

object ob1, ob2, ob3;

void create () {
  ::create();
  seteuid(getuid());
  set("short" , "jack the Ripper");
  set("long" , @EndText
  Jack the Ripper, a ledgendary slasher from the streets of old London.
  The gleam in his eye is reflected in the glint of the dagger he holds
  in his hand. He wears a smokey old coat, and a ratty old hat...but
  their appearances could be very decieving and they make you wonder.
  His demeanor and appearance strike you as an insane man, who would
  do just about anything to KILL you.

EndText
);
  set("id" , ({ "jack" , "jack the ripper" , "ripper" }) );
  set("aggressive" , 10);
  set("base_ac" , 4);
  set_level(20);
  set_size(6);
  set_name("jack the ripper");
  set_living_name("ripper");
  set("gender" , "male");
  set("race" , "human");
  set("CLASS" , "thief");
  set("stat/constitution" , 20);
  set("stat/dexterity" , 20);
  set("stat/strength" , 25);
  set_skill("Short Blades" , 5, "Strength");
  ob1 = clone_object("/d/Prime/Dagaard/dilligaf/armour/tophat.c");
  ob1->move(this_object());
  ob2 = clone_object("/d/Prime/Dagaard/dilligaf/armour/jacket.c");
  ob2->move(this_object());
  ob3 = clone_object("/d/Prime/Dagaard/dilligaf/weapons/razordagger.c");
  ob3->move(this_object());
  enable_commands();
  set("natt" , 1);
  set("weapon_name" , "fists");
  set("damage" , ({ 4,10 }) );
  set_verbs2( ({ "smacks" , "uppercuts" }) );
  set_verbs( ({ "smack" , "uppercut" }) );
}

void init() {
  command("wield dagger");
  command("equip jacket");
  command("equip hat");
  command("say Welcome to the last day of your life.");
 }
