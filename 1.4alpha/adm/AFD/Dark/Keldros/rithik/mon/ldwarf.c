#include "../defs.h"

inherit "/u/w/waxer/fun/mon/wander.c";

void create() {
  seteuid(getuid());
  ::create();
  set("short", "Lost dwarf");

  set("long", @ENDLONG
This dwarf was once dressed nicely, but is now quite dusty and dirty.
ENDLONG
  );
  set_alignment(80);
  set_name("femsen");
  set("id", ({
    "dwarf",
    "lost dwarf",
    "femsen",
  }));

  credit(10 + random(100));
  set("damage", ({ 18, 25 }) );
  set("armor_class", 4);
  clone_object(OBJ(tmap));
  set("wander", ({ "north", "east", "south", "west" }));
  set("wander_chance", 5);
  set("forbidden_rooms",
      ({
        ROOMS(zathril3),
        ROOMS(nlane),
        ROOMS(stairs),
      }));
  set("attack_strength", 15);
  set("race", "dwarf");
  set("attrib1", "tired");  set("attrib2", "bewildered");
  set("gender", "male");
  set("weapon_name", "fists");
  set_verbs( ({
    "attempt to crush",
    "bash at",
}));
  set_verbs2( ({
    "attempts to crush",
    "bashes at",
}));
  set_skill("defense", 6, "dexterity");
  set_skill("attack", 6, "strength");
  set_level(6);
  set("chat_chance", 3);
set("chat_output", ({
    "The dwarf tries to read his map, and fails miserably.\n",
    "Femsen exclaims: \"Where in the Dark realms am I?!\"\n",
  }) );
  set("forgetful", 1);

}
