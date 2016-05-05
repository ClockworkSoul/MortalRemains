// 28 May 2000   Cyanide created the file.

#include "school.h"

inherit MONSTER;

void create() {
    ::create();
    set("author", "cyanide");
    set("short", "Earl the security guard");
    set("long",  @EndText
Earl is a big man, more than a little puffy around the middle, in a strange
pseudo-official-looking tan uniform and bizarre "Terminator" style
sunglasses he's never without, and is even rumored to sleep in.
EndText
    );
    set("stat", ([
      "strength" : 15,
      "dexterity" : 15
    ]) );
    set("prevent_summon", 1);
    set("id", ({ "earl", "guard" }) );
    set_name("Earl");
    set("race", "human");   
    set("weapon_name", "fists");
    set_verbs( ({ "swing at" }) );
    set("damage", ({ 1, 4 }) );
    credit(random(40) + 10);
    set("gender", "male");
    set_level(10);

    set("chat_chance", 8);
    set("chat_output", ({
      "Earl says: Hey, you!   You don't belong here!\n",
      "Earl says: Got any donuts?\n"
    }) );
    set("att_chat_output", ({
      "Earl exclaims: You bastard!\n"
    }) );
    set("attrib1", "overconfident");
    set("attrib2", "overweight");
    arm("/d/Prime/Central/weap/club.c");
}
