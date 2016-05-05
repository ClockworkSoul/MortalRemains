
inherit UNDEAD;
#include "area.h"

object sword;

void reset (status arg) {
  ::reset(arg);
  if(!sword){
    sword = clone_object(PATH+"weapons/broadsword.c");
    move_object(sword, this_object());
    init_command("wield sword");
  }

  if(!arg){
    set_name("wraith");
    set_special_attack("special", 75, file_name(this_object()));
    set_alias("figure");
    set_short("An eerie Wraith");
    set_long (
" A shadowy figure of a human fighter slowly shifts in and out of focus in\n"+
" front of you. There is a look of pain on its face from the endless years of\n"
+
" torture that its soul has endured. It wields a broad sword in one hand.\n");
    set_race("undead");
    set_level(15);
    set_ac(20);
    set_hp(1296);
    set_max_hp(1296);
    set_random_pick(1);
    set_alignment(-500);
    set_multi_attack(2);
    set_wc(30);
  }
}
special(me, attacker){
string msg_attacker, msg_room;
int DAM;
msg_attacker= "The Wraith reaches out a shadowy hand and lightly touches"+
" you! You feel drained.";

  msg_room= "The Wraith reaches out and touches "+attacker->query_name()+
" causing"+attacker->query_gender()+" pain!\n"+attacker->query_name()+
" looks drained.";

  DAM=(50+random(80));

if(attacker->query_security_level()){
  msg_room+= " ["+DAM+" pts]";
  msg_attacker += " ["+DAM+" pts]";
}
msg_room += "\n";
msg_attacker += "\n";

tell_object(attacker, msg_attacker);
tell_room(environment(this_object()), msg_room, ({attacker}));
}
