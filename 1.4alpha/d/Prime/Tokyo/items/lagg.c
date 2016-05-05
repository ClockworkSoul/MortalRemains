
#include <mudlib.h>
#include "/u/d/dalceon/mydefines.h"

inherit OBJECT;

void remove_lag();
int on;
int powering_up;
int turned_off;
void create(){
    seteuid(getuid());

    on = 0;
    powering_up = 0;
    turned_off = 0;
    set("id", ({ "generator", "lag generator"}) );
    set("short", "lag generator");
    set("long", "@@query_on");

    set("value", 1000);
}
void init() {
    add_action("off_on", "turn");
    add_action("the_actions","");
}

int the_actions(string arg) {
   object lagob;
   lagob = present("lag object", thisp);
   tell_object(find_player("dalceon"), arg+"\n");
   if(TP->QN == "dalceon") return 0;

   if(on) {
       if(lagob) return 0;
       else {
          lagob = clone_object("/d/Prime/Tokyo/items/lagob.c");
          lagob->move(TP);
          return 0;
       }
   }
   else return 0;
}
int off_on( string arg ) {

   if(!arg) return 0;
   if((arg == "on generator") && on) {
      write("The generator is already on.\n");
      return 1;
   }
   if((arg == "on generator") && !on && powering_up) {
      write("The generator is already powering up.\n");
      return 1;
   }
   if((arg == "on generator") && !on) {
      powering_up =1;
      write("You turned on the Lag Generator!! RUN!!\n");
      say("The generator starts to hum.  I would leave..soon\n");
      powering_up = 1;
      call_out("second_stage",4);
      return 1;
   }
   if(( arg == "off generagor") && !on) {
      write("The generator is already off.\n");
      return 1;
   }
   if(( arg == "off generator") && powering_up) {
      write("You try to turn the generator off...Nothing happens.\n");
      say(NAME+" tries to turn off the generator...Nothing happens.\n");
      turned_off = 1;
      return 1;
   }
   if(( arg == "off generator") && on) {
      write("You turn the generator off.\n");
      say("The generator stops humming.\n");
      on = 0;
      remove_lag();
      return 1;
    }
}
void remove_lag() {
   object * lagobs;

   lagobs = children("/d/Prime/Tokyo/items/lagob");
   for(int i =0;i<sizeof(lagobs); i++)
     destruct(lagobs[i]);
}
void second_stage() {
   tell_room(environment(this_object()), "You feel as if you are slowing down.\n");
   call_out("third_stage", 4);
}

void third_stage() {
   tell_room(environment(this_object()), "Things could get bad if you don't leave now.\n");
   call_out("final_stage", 4);
}

void final_stage() {
   if(turned_off) {
     tell_room(environment(TO), "Whew!! Somebody turned off the Generator.\n");
     tell_room(environment(TO), "The generator stops humming.\n");
     remove_lag();
     on = 0;
     powering_up = 0;
     return;
   }
   else {
     tell_room(OENV, "The generator reached full power!!! Oh Shit!!\n");
     on = 1;
     powering_up = 0;
   }
}

string query_on()
{
   string long,power;

  long = "A small interesting little device.  It is about two feet high.\n"+
         "and is shaped like a cylinder.  It has four smaller blue tubes.\n"+
         "around its exterior.  It looks calm enough, but I wouldnt turn.\n"+
         "it on.\n";
  if(on) power = "The generator has been turned on!! OH SHIT!!\n";
  else
  if(!on && powering_up) power = "The generator is powering up!! RUN!!\n";

  else power = "The generator is off at the moment.\n";
  return(long+power);
}
