/*
** File: nsd_mon.c
** Author: Lady Nsd
*/

#include <mudlib.h>
inherit MONSTER ;
void create () {
    object ob1, ob2;
    ::create() ;
    seteuid(getuid()) ;
    enable_commands() ;
    set("author", "nsd");
    set ("short", "Lady Nsd, Mistress of Darkness (Mind Seductress)");
    set ("long",@EndText
Lady Nsd is a delicate petitte beauty of noble blood, but still
dangerous as well. Her beautiness alone seduces and conducts men
to their doom. She wears a tight corset with a really wide skirt.
Her long hair is losened in dark brown curls, and her dark eyes
stare at you deeply, and empty...
EndText);
    set ("id", ({ "Nsd", "nsd", "lady nsd", "succubus", "wizard" }) );
    set_size(5);
    set_name ("Nsd");
    set ("gender", "female");
    set ("race", "succubus");
    enable_commands() ;
    set_living_name("Nsd");
    set("stat/charisma", 25);
    set("stat/dexterity", 20);
    set("stat/wisdom", 20);
    set("stat/constitution", 20);
    set("stat/intelligence", 20);
    set("stat/strength", 20);
    set ("natt", 2);
    set("chat_chance", 30);
    set("chat_output", ({
      "Nsd grins like the evil fuck she is.\n",
      "Nsd knocks at your head to realize it has echo...\n",
      "Nsd licks her finger and it melts, becoming a strawberry basket.\n",
      "Nsd offers you a strawberry basket.\n",
      "Nsd eats her strawberry in a sinful way...\n",
      "Nsd says: I'm in charge of coding toys...\n",
      "Nsd blushes.\n",
      "Nsd rolls on the floor laughing.\n",
      "Nsd licks her lips.\n",
    }) );
    set("alive", 1);
    set("damage", ({100, 200}) );
    set("CLASS", "mage");
    set("mage_spells", ({ "enlarge", "stoneskin", "missile", "invisibility", "fireshield", "light", "dispell"}) );
    set("magic_resist", 30);
    set("resist_type", ([ "cold" : 50, "fire" : 50, "electricity" : 30,
      "poison" : 30 ]) );
    set("weapon_name", "fists");
    set("base_ac", 5);
    set("armor_class", 5);
    set("damage_type", "force");
    set_verbs( ({ "attack", "swing at", "peer at", "bite" }) );
    ob1 = clone_object("/d/class/wizard/general/obj/book.c");
    ob1->move(this_object());
    ob2 = clone_object("/d/class/obj/talisman.c");
    ob2->move(this_object() );
    set_level(200);
    set("prevent_summon", 1);
}
