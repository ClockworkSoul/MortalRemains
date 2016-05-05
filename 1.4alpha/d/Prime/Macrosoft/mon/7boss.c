// BILL GATES HIMSELF!

#include "macrosoft.h"

inherit MONSTER;

void create() {
    object badge;

    ::create();
    set("short", "Bill Gates, Ruler of the World");
    set("long", wrap(
	"Mr. Bill Gates, Chief Executive of The Macrosoft Corporation, "+
	"and de facto ruler of the world. He has been the world's "+
	"richest man for almost 200 years now, having been kept alive "+
	"by a combination of cybernetic implants and biological "+
	"re-engineering."
      ) );
    set("id", ({ "gates", "bill", "ruler", "bill gates" }) );
    set_name("Bill Gates");
    set("author", "cyanide");
    set("damage", ({ 1, 15 }) );
    set("attrib1", "devil-worshipping");
    set("attrib2", "bespectacled");
    set("race", "demon borg");
    set("weapon_name", "claws");
    set_verbs( ({ "slash at" }) );

    // Some MACK fucking stats, eh?
    set("stat", ([
      "strength" : 24,
      "constitution" : 23,
      "dexterity" : 24,
      "intelligence" : 20,
      "wisdom" : 18,
      "charisma" : 18
    ]) );

    set_skill("Unarmed", 5, "strength");
    set_skill("Long Blades", 5, "strength");

    set_size(7);

    set("prevent_summon", 1);
    arm(MS_WEAP("billsword.c") );

    set("chat_chance", 15);
    set("chat_output", ({   
      "Bill says: Windows kicks ass!\n",
      "Bill says [to you] : What, do you want MONEY or something?!\n",
      "Bill says: Windows 98 IS faster than Win95...  honest!\n",
      "Bill pushes his back glasses up his nose.\n",
      "Bill says [to you]: Resistance is futile.\n",
      "Bill says [to you]: You will be assimilated.\n",
    }));
    set("att_chat_output", ({
      "Bill says [to you]: Is that the best you can do?\n",
      "Bill says [to you]: Resistance is futile.\n",
      "Bill says [to you]: You will be assimilated.\n",
    }));

    badge = clone_object(MS_OBJ("id_badge"));
    badge->set_color(8);
    wear(badge);
    set_level(48);
}

/* EOF */
