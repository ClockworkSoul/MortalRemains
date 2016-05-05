
inherit "/inherit/undead.c";
#include "/players/zanzibar/include/area.h"
object haxe, rags;

void reset (status arg) {
  ::reset (arg);
  if(!rags){
    rags = clone_object(PATH+"armour/rags.c");
    move_object(rags, this_object());
    init_command("wear rags");
  }
  if(!haxe){
    haxe = clone_object(PATH+"weapons/h-axe.c");
    move_object(haxe, this_object());
    init_command("wield all");
  }
  if(!arg) {
	set_name("skeleton");
        set_alias("fighter");
        set_alt_name("skeleton fighter");
        set_short("A skeleton fighter");
        set_long (
" This is the skeleton of a long dead fighter that has been animated by some\n"+
" dark magics. Tiny greenish flames burn where his eyes once were. There \n"+
" seems to be hatred and evil eminating from its entire being. It moves with\n"+
" unearthly speed and agility. It wields a broadsword.\n");
        set_aggressive(0);
        set_level(11 +(random(4)));
        set_multi_attack(3);
        set_alignment(-300);
        set_race("undead");
        set_random_pick(30);
        set_ac(20);
        set_money(100);
  }
}
