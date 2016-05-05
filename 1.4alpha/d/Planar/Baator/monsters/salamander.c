// Cyanide fixed this, 21 Nov 98.

#include <messages.h>
#include "baator.h"

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("author", "cyanide");
    set ("short", "a salamander") ;
    set ("long", @EndText
Salamanders are natives of the elemental plane of Fire, and thus they
thrive in hot places. The head and torso of this monster is copper 
colored and has a humanlike appearance, with flaming beard and moustache
and glowing yellow eyes. The lower torso is that of a large snake, with
orange coloring shading to dull red at the tail end.
EndText
    ) ;
    set ("id", ({ "salamander" }) ) ;
    set("stat", ([
      "constitution" : 14,
    ]) );
    set_align("ce");
    set_size(7);
    set_name ("salamander") ;
    set ("race", "salamander");
    set ("gender", "male") ;
    enable_commands() ;
    set_living_name("salamander") ;
    set("resist_type",([ "cold": 110, "fire":0 ]));
    set("weap_resist", 1);
    set ("base_ac", 5);
    set ("armor_class", 5);
    set("CLASS", "warrior");
    set ("damage", ({ 2, 12 }) ) ;
    set("damage_type", "bludgeoning");
    set ("weapon_name", "fiery fists") ;
    set_verbs( ({ "crush", "pummel" }) ) ;
    set("chat_chance", 5);
    set("chat_output", ({
      "The salamander sharpens his spear, eyeballing your warily.\n",
      "The salamader stares at you, unmoving.\n",
      "The salamander's heat is starting to be too much for you to bear.\n"
      "The salamander throws his heavy steel spear over his shoulder.\n",
      "The salamander switches his spear to his other shoulder.\n",
    }) );

    set_level(8);
    arm(ITEM+"salaspear.c");
    credit( query("hit_points") / 3 ); 
}

/* EOF */
