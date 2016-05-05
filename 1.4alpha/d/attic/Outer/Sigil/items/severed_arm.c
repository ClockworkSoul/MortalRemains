/*
** Severed_arm.c - Cyanide's coolest weapon.
** An old idea, finally brought to life, 26 Sep 97.
** When cloned in a monster, include a call to begin_blood().
** It isn't done in the clone to be nicer to the CPU.
** (04-15-98) Chronos made it so that it eventually dries up.
*/
#include <mudlib.h>

#define DIR "/d/Outer/Sigil/items/"
#define ENV_TO environment(this_object())

// This defines how many quarts of blood the arm will drip.
#define MAX_QUARTS_LOST 5

int quarts ;            // Quarts of blood! :D

void begin_blood();

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "a bloody severed arm");
  set("long", @BLOOD
The severed arm of what seems to have been a young woman.  It is still
somewhat warm, and is bleeding slightly.
BLOOD
  );
  set("name", "bloody stump");
  set_weapon_type("club");
  set("author", "cyanide");
  set("id", ({ "arm", "severed arm", "stump" }) );
  set_verbs( ({ "swing at", "attack", "bat at", "lunge at" }) ) ;
  set("value", 45) ;
}

void init() {
  add_action("blood_cmd", "begin");
}

int blood_cmd (string str) {
  if (!str || str!="blood") return 0;
  write("The stump begins bleeding profusely!\n");
  begin_blood();
  return 1;
}

void begin_blood() {
  // Note this function is never called by create()
  object ob, blood;
  if (!environment(this_object())) return;
  blood = clone_object(DIR+"blood.c");
  if (living(environment(this_object()))) {
    ob = present("pool of blood", environment(ENV_TO));
    if (ob) ob->remove();
    blood->move(environment(ENV_TO));
  } else {
    ob = present("pool of blood", ENV_TO);
    if (ob) ob->remove();
    blood->move(ENV_TO);
  }
  quarts++;
  blood->begin_evaporate(ENV_TO);
  if (quarts != MAX_QUARTS_LOST) call_out("begin_blood", 5 + random(10) );
  else message("shit",
   "The severed arm finally seems to stop bleeding so profusely.\n",
   environment() ) ;
  return;
}

/* EOF */
