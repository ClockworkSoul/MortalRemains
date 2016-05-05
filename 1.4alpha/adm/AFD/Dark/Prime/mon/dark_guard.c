/*
**  FILE:  dark_guard.c
**  PURPOSE:  Guard in the City of Darkmir.
**      Autoattacks anybody with a partiular object.
**  CHANGES:
**    9-24-96  Cyanide	  Wrote the file.
*/

#include "../Prime.h"
#include <mudlib.h>

inherit MONSTER;

void create() {
  int levelint;

  seteuid(getuid());
  levelint = (random(10));
  switch (levelint) {
    case 0..3 : levelint=(random(10)+1);break;
    case 4..6 : levelint=(random(7)+11);break;
    case 7..8 : levelint=(random(5)+18);break;
    case 9 : levelint=(random(3)+23);break;
    default : levelint = (random(25));break;
   }
  set_level(levelint);
  set ("id", ({ "guard", "demon guard" }) );
    set_name("Guard of Darkmir");
  set("short", "a demon guard");
  set ("long", @ENDLONG
This is a member of the guard of the city of Darkmir. It is
a hideous product of evil magics, combining the best aspects
of human and demons.
ENDLONG
   );
}

void init() {
  object marker;

  marker = present("#MARKER#", TP);
  if (marker) {
    kill_ob(TP);
    write ("A guard shouts: That's the one!\n");
    say ("A guard shouts: That's the one!\n");
   }
  add_action("kill_func", "kill");
}

void kill_func() {
  object marker;

  write ("The guard raises an alarm, and draws its weapon!\n");
  say("The guard raises an alarm, and draws its weapon!\n");
  marker = clone_object(D_PRIMEO+"/marker.c");
  marker->move(TP);
 }

void weapon_func() {
  int *sndobs, lvl, n;
  object weap, ob2;

  lvl = (query_level/2)-1;
  lvl = lvl + (random(3)-1) + (random(5)-2);
  if (lvl<0) lvl=0;
  if (lvl>14) lvl=14;


say ("testing say");
write ("testing write");
}
