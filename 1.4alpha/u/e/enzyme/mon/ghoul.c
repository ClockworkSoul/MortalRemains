
inherit "/inherit/undead.c";
object cloak;


#define PATH "/players/zanzibar/area/"

void reset(status arg) {
  ::reset(arg);
  if(!cloak){
    cloak = clone_object(PATH+"armour/robe.c");
    move_object(cloak, this_object());
    init_command("wear cloak");
  }
  if(!arg) {
  set_name("ghoul");
  set_alias ("figure");
  set_alt_name("ghoulish figure");
  set_short ("A Ghoulish figure");
  set_long (
" You see a misty figure of what appears to be a decaying man dressed in a\n"+
" runed hooded robe.  His form seems to shift in and out of focus as he slowly\n
"+
" moves toward you. Two small greenish flames burn where his eyes once were.\n"+
" You begin to wonder if you should let yourself be seen by such a thing!\n");
  set_level(11);
  set_random_pick(1);
  set_race ("undead");
  set_multi_attack(2);
  set_alignment(-350);
  set_attack_msg(({
        "nudges", "with slight force",
        "hits" , "with spectral energy",
        "slams" , "with unholy power",
        "burns" , "with ghoulish fire",
	}));
  set_aggressive(0);
  }
}
