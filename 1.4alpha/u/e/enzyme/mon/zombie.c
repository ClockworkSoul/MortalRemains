
#include <mudlib.h>
object rags;

inherit UNDEAD;
#define PATH "/players/zanzibar/area/"

void reset(status arg) {
  ::reset(arg);
  if(!rags){
    rags = clone_object(PATH+"armour/rags.c");
    move_object(rags, this_object());
    init_command("wear rags");
  }
  if(!arg) {
        set_name ("A Zombie");
        set_alias("zombie");
        set_short("A decaying Zombie");
  set_long(
" You see before you what was obviously a rather large and burly being. The\n"+
" skin and most of the tissue having long decayed, is still hanging off\n"+
" its bones in loose chunks. Somehow it looks very upset at being\n"+
" disturbed!\n");
    set_level(7 + random(5));
    set_random_pick(35);
    set_race ("undead");
    set_alignment(-100);
    set_multi_attack(1);
    set_attack_msg(({
      "scratches", "on the arm",
      "kicks",     "in the leg",
      "bites",     "on the hand",
      "claws",     "across the face",
      "pummles",   "in the abdomen",
      "smashes",   "with its large fists",
    }));
    set_aggressive(0);
    set_dead_ob(this_object());
  }
}
status monster_died(){
        object corpse;
        tell_room(environment(),"The lifeless corpse crumbles to dust.\n");
  if((corpse=present("corpse",environment())))destruct(corpse);
  return 0;
}
