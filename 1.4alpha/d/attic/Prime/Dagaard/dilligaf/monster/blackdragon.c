#include <mudlib.h>
inherit MONSTER ;

object key;

void create () {
  ::create();
  seteuid(getuid());
  set("short" , "a large black dragon");
  set("long" , @EndText
  A large blackdragon, here to guard Soth's Keep. You can only imagine
  the kind of damage that he can hit you with. However the only way 
  into the next room...is through him.

EndText
);
  set("id" , ({ "dragon" }) );
  set_level(30);
  set("armor_class" , -20);
  set_size(20);
  set_name("black dragon");
  set_living_name("dragon");
  set("gender" , "male");
  set("wealth" , 59000+random(10000) );
  set("race" , "dragon");
  key = clone_object("/d/Prime/Dagaard/dilligaf/keys/soth_key.c");
  key->move(this_object() );
  set("damage" , ({ 15,30 }) );
  set("weapon_name" , "scaly fists");
  set_verbs( ({ "smack" , "drill" }) );
  set_verbs2( ({ "smacks" , "drills" }) );
  set("natt" , 2);
  set ("chat_chance" , 10);
   set ("chat_output", ({
    "The dragon says: Welcome small one, have you come to seek an audience with me?\n",
    "The dragon stretches his large black wings, leathery flaps fill the room and you are almost bowled over with a wind gust.\n",
   }) );
   set ("att_chat_output", ({
    "The dragon screams: MUHAHA! You have come to seek your peril...do not fear...you shall meet your ancestors and mine....very soon.\n",
    "The dragon pulls you close and whispers to you: Have some fucker.\n",
   }) );
}
