#include <mudlib.h>
inherit MONSTER ;

object ob1, ob2;

void create () {
  ::create();
  seteuid(getuid());
  set("short" , "traveler"),
  set("long" , @EndText
  A man, walking down the path...heading towards Dagaard probably. He nods his head
  at you as you path...perhaps as a warning, perhaps as a note of respect...and perhaps
  he is scared that you'll bloody him up.

EndText
);
  set("id" , ({ "traveler" }) );
  set("base_ac" , 5);
  set_skill("Short Blades", 3,"Strength");
  set("CLASS" , "rogue");
  set("stat/dexterity" , 20);
  set("wealth" , 1500+(random(1000)) );
  set_level(3+random(3) );
  set_size(6);
  set_name("a traveler");
  set_living_name("traveler");
  set("gender" , "male");
  set("race" , "human");
  ob1 = clone_object("/d/Prime/Dagaard/dilligaf/armour/trench.c");
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
      "The traveler starts screaming like a stuck pig...hopefully no one is listening!\n",
      "The traveler looks at you with contempt and bellows: Dickhead...I will KILL YOU!\n",
   }) );
}

void init() {
    command("say Hi there, nice day isn't it?");
    command("wear coat");
    command("wield dagger");
 }
