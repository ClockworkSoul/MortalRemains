#include "macrosoft.h"

inherit MONSTER;

void create() {
    string *guns;
    object ob;

    ::create();
    set("short", "Macrosoft executive");
    set("long", wrap("This man is the definition of executive. "+
	"He glares condescendingly at you, his black suit and "+
	"power tie mocking you."
      ) );
    set("id", ({ "exec", "executive" }) );
    set_name("Executive");
    set("gender", "male");
    set("attrib1", "perfectly groomed");
    set("race", "human");
    set("author", "cyanide");
    set("damage", ({ 1, 5 }) );
    set("weapon_name", "fists");
    set_verbs( ({ "swing at" }) );
    set("stat/constitution", 13);

    // Neat trick, huh?
    guns = get_dir(MS_WEAP("L_*.c"));

    ob = clone_object (MS_WEAP(guns[ random(sizeof(guns)) ]) );
    if (ob) {
	set_skill(ob->query("weapon_type"), 2, "strength");
	set("ammo", ([ ob->query("ammo_type") : 100 ]) );
	arm(ob);
    }

    set_skill("Unarmed", 2, "strength");

    set_level(8);
}

// Cheating, I know.
int ammo_debit(int i) { return 1; }

/* EOF */
