// 22 May 98   Cyanide created the file.


inherit MONSTER;

void create() {
    ::create();
    seteuid(getuid());

    set("author", "cyanide and modified by abyss");
    set("short", "Grok, the wannabe Arms Dealer");
    set("long", wrap(
          "Grok looks like he was babied all his life.  He "+
          "has neatly combed hair, white sparkly teeth, and a"
          "has neatly combed hair, white sparkly teeth, and a"+
          "nicely pressed suit.  He doesn't look like the "+
          "nicely pressed suit.  He doesn't look like the armsdealer"+
" type.  He reminds you of Grik over in Decatur."
      ) );
    set("id", ({ "salesman", "salesperson", "grok" }) );
    set_name("Grok");
    set("race", "half-orc");
    set("weapon_name", "claw");
    set_verbs( ({ "swing at" }) );
    set("damage", ({ 2, 8 }) );
    credit(random(140) + 10);
    set("gender", "male");
    set("ammo", ([ ".44" : 10000 ]) );
    set("attrib1", "grisly");
    set("attrib2", "battle-scarred");
    set_level(25);
    set_skill("Small Arms", 4, "strength");
    set_skill("Unarmed", 2, "strength");
arm("/d/Prime/Central/weap/magnumrev.c","magnum");

    set("chat_chance", 7);
    set("chat_output", ({
      "Grok eyes you warily.\n",
      "Grok watches you with his one good eye.\n",
      "Grok cleans the counter.\n",
      "Grok spits.\n",
"Grok says:  Have you met my brother Grik.  He works over in Decatur."+
"  He has his own gun shop there.",
      "Grok slowly cleans his gun.\n",
    }) );
    set("att_chat_output", ({
      "Grok attacks you with immense pleasure.\n",
    }) );
}

