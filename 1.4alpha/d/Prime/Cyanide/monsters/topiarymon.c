#include <mudlib.h>
// The tree creature found in DARK+"/topiary.c"

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid()) ;
    enable_commands ();

    set("author", "cyanide");

    //All the happy stuff concernming identification:
    set("short", "living topiary");
    set("long", @EndText
It is a topiary of some kind. Originally, it looked like some kind
of dragon, but now it shifts between forms rapidly.
EndText
    );
    set("id", ({ "topiary","shrub","tree","living topiary" }) );
    set_name("living topiary");
    set("gender","neuter");
    set("lore_type", "arcanology");
    set("lore", wrap(
	"All that is known of these monsters is that they are intensely "+
	"wicked, and that they were created eons ago by a mysterious "+
	"being from the Dark known only as \"The Obsidian Enchanter\".") );

    //Mass and all related stats:
    set_size(12);

    //Just about everything related to combat:
    set("killer", 1);
    set("aggressive", 1);
    set("damage", ({ 5, 16 }) );
    set("weapon_name", "branches") ;
    set_verbs(({ "swing at", "pummel", "thrash" }));
    set("forgetful", 0);
    set_align("ce");

    //Stats + skills:
    set("stat/strength", 18);
    set("stat/dexterity", 15);
    set("stat/constitution", 25);

    //Movement and whatnot:
    set("pursuing", 0);
    set("moving", 0);
    set("speed", 6);

    set_level(23);  //Always last!
}
