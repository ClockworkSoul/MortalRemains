/*
** Assassin's Guild
** Begun by Cyanide, 10 Aug 97
** Stolen by Nightmask; Ribbed for her pleasure
*/

#define FIND find_player("nightmask")
#define DEBUG(x) if (FIND) tell_object(FIND, x)


#include <daemons.h>
#include <mudlib.h>
#include <rogues.h>

inherit GUILD;

void create() {
   ::create();
   seteuid(getuid());
   set("objects", ([ "thadius" : A_MON+"guild_master.c" ]) );
   reset();
   set("short", "Guild");
   set("long", @Thief
You stand in a great hall made of pure Ivory and Jade. Pillars stand
a full 12 feet tall and hold up the massive roof that depicts a scene
of the most famous of all Assassin's in action. To the north is a common
place, where Assassins may go to rest or talk of rummors.
Commands: <join> and <advance>.
Thief
 );
  set("light", 1);
  set("class", "assassin");
  set("group", "rogue");
  set("experience", ROGUE_EXP);
   set("exits", ([
   "east" : "/d/class/rogue/thief/room/P_hall.c",
 ]));
}

void init() {
  ::init();
}

string titles (object ob) {
  string str;
  int lvl;

  lvl = ob->query_level("assassin");
  if ((string)ob->query("gender")=="female") {
    str = ({
      "$N the Assassin ($A)",
    })[lvl];
  } else {
    str = ({
      "$N the Assassin ($A)",
    })[lvl];
    }
  return str;
}                


int join() {
  object belt;

  if (TP->query("base_stat/dexterity") < 12) {
    write("You are not nimble enough to be an assassin!\n");
    return 0;
  }
  if (TP->query("base_stat/strength") < 12) {
    write("You are not strong enough to be an assassin!\n");
    return 0;
  }
  if (TP->query("base_stat/intelligence") < 11) {
    write("You are not smart enough to be an assassin!\n");
    return 0;
  }
   write("Thadius says, \"Welcome to the family.\n");
   write("He hands you somthing, then wishes you fame and fortune.\n");

  belt = clone_object(A_OBJ+"bandana.c");
  if (!belt) {
    write("\nA voice says, \"Yer fucked!\n"+
      "Please notify Nightmask.\n");
    return 1;
  }
  belt->move(this_player());
  return 1;
}

int advance() {
  int level, hp, max;

  level = TP->query_level("assassin");
  write("You advance to level "+level+".\n");

  if(level%3==0) TP->add("nwp", 1);
  if(level%6==0) TP->add("wp", 1);


  hp = ROGUE_HP_ROLL;
  hp += PROPERTY_D->query_con_hp_bonus(TP);
  add_hp(TP, hp);
  return 1;
}
