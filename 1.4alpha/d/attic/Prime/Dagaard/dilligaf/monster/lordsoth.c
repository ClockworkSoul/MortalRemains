#include <mudlib.h>

inherit MONSTER;
object ob1, ob2, ob3, ob4;

void create () {
  ::create();
  seteuid(getuid());
  set("short" , "Lord Soth");
  set("long" , @EndText
  This is the famed Lord Soth. He grins evilly as you enter and he 
  stares at you with eye sockets that look to be filled with red-hot
  coals. You feel cold as you enter here, and you know you look upon
  the face of a Death Knight...run now...while you still can. In his 
  hand he wields the Katana of might, his armour glows with an unholy
  light...and the boots he wears make him seem to quiver with speed.
  If this is the treasure you seek, then you are in for a fight.

EndText
);
  set("id" , ({ "soth" , "lord soth" , "knight" }) );
  
  set("stat/strength" , 22);
  set("stat/dexterity" , 20);
  set("stat/constitution" , 23);
  set("stat/charisma" , 1);
  set("armor_class" , -2);
  set("wealth" , 1+random(10000) );
  set_skill("Long Blades",5,"Strength");
  set_skill("Two Handed Style", 2, "Strength");
  set_size(6);
  set_name("Lord Soth");
  set_living_name("soth");
  set("gender" , "male");
  set("race" , "death knight");
  set("undead" , 1);
  set("base_ac", -5);
  set("armor_class", -5);
  set("magic_resist",95);   
  set("special", 75);
  set("resist_type", ([  "slashing" : 50, "electricity" : 0, "poison" : 0, "necromancy" : -100 ]) ); 
  ob1 = clone_object("/d/Prime/Dagaard/dilligaf/armour/magicplate.c");
  ob1->move(this_object());
  ob2 = clone_object("/d/Prime/Dagaard/dilligaf/armour/magichelm.c");
  ob2->move(this_object());
  ob3 = clone_object("/d/Prime/Dagaard/dilligaf/armour/bootsofspeed.c");
  ob3->move(this_object());
  ob4 = clone_object("/d/Prime/Dagaard/dilligaf/weapons/katana.c");
  ob4->move(this_object());
  set("damage" , ({ 5,15 }) );
  set("weapon_name" , "wraithlike fists");
  set_verbs( ({ "smack" , "pummel" }) );
  set_verbs2( ({ "smacks" , "pummels" }) );
  enable_commands();
   set("chat_chance" , 10);
   set ("chat_output", ({
    "Lord Soth says: Welcome. I see you have beaten my dragon...'tis a shame.\n",
    "Soth bellows: What is it you want?\n",
    "The eyes in Lord Soth's head start to glow, you feel even colder as his gaze pierces your soul.\n",
   }) );
   set ("att_chat_output", ({
    "Soth yells: IMPUTENT COWARD! I'll show you!\n",
    "Spinning his body, Lord Soth twists his way around you...you become dizzy and he gets an extra attack.\n",
   }) );
   set_level(35);
}

void init() {
::init();
    command("close door");
    command("equip boots");
    command("equip plate");
    command("equip helm");
    command("wield katana");
 }
void special_attack() {
    //this is the doom function
    object ob;
    int sv;
    ob = this_object()->query_current_attacker();
    if (ob){
    if (ob->query("hit_points") < 181) {
        say( "Soth calls upon the power of Takhisis to doom "+ ob->query("cap_n
ame")+"'s soul to eternal torment!\n", ob);
        tell_object(ob, "Soth's eye's turn to a magma color, then as he turns his gaze to you...you feel all of your life-force leave as he calls upon the power of Takhisis's blackest spell.\n");
        ob->receive_damage(10000, "necromancy", this_object(), 0); 
       if (ob->query("hit_points") < 0) ob->set("branded_by_death", 1);
       
       return;
       }
       }
       return;
       }   
