#include <mudlib.h>
#include <config.h>

inherit "/std/monster" ;


void create () {
 ::create() ;
  seteuid(getuid());
   
   set("stat/dexterity", 18);
   set("stat/strength", 20);
   set("stat/constitution", 18);
   set("armor_class", -10);
   set_size(350);
   set("short", "Great Wyrm Red Dragon");
   set("long", "This is a red dragon.\n");
   set("id", ({ "dragon", "red", "red dragon" }) );
 set("magic_resist", 60 );
   set("resist_type", ([ "fire" : 0, "poison" : 50 ]) );
   set("special", 12);
   set("natt", 2);
   set("race", "dragon");
   enable_commands();
set("damage_type", "slashing");
   set("damage", ({ 13,22 }) );
   set("weapon_name", "razor sharp claws");
   set_verbs( ({ "slash", "slice", "smite" }) );
   set_verbs2( ({ "slashes", "slices", "smites" }) );
   set_name("red dragon");
   set_living_name("red dragon");
   set_level(23);
set("wealth", (this_object()->query("hit_points")));
 }


void special_attack() {
object ob;
int sv;   
   ob = this_object()->query_current_attacker();
     if (random(3) == 0) {
     say("The Red Dragon engulfs "+ob->query("cap_name")+" in flames!\n", ob);
     tell_object(ob, "The Red Dragon engulfs you in flames!\n");
   sv = (ob->save_throw());
   if (sv){
   if ((ob->query_skill("Evasion"))>0){
     tell_object(ob, "You dive out of the way!\n");
   }else{
     ob->receive_damage((random(103)+18), "fire");
  }
   			}
   if (sv == 0){
     ob->receive_damage((random(205)+36), "fire");
   }
 }else{
     say("The Red Dragon sinks it's teeth into "+ob->query("cap_name")+"!\n", ob);
     tell_object(ob, "The Red Dragon sinks it's teeth into your flesh!\n");
     ob->receive_damage((random(31)+15), "slashing", this_object(), 1);
 	}

}
