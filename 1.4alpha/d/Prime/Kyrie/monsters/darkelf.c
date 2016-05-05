#include <mudlib.h>

inherit MONSTER ;

void create () {
    object sword ;
    ::create();
    seteuid(getuid());
    enable_commands() ;

    set("author", "valkyrie");
    set("short", "a dark elf");
    set ("long", @EndText 
This dark-haired, charcoal-skilled elf may seem slight, but he is quick and
fairly strong, so beware. He looks very unhappy at your intrusion into
Kyrie forest. His genetically enhanced eyes glow a soft green, you can
sense the malice he seems to feel for intruders like yourself.
EndText
    );
    set("id", ({"monster","elf","dark elf"}) );
    set_size(4);
    set_name("dark elf");
    set("gender","male");
    set("race","elf");
    set("undead",0);
    set("damage", ({1,5}) );
    set("weapon_name","fists");
    set_verbs( ({"attack","throw a punch at","swing at"}) );
    set("natt", 2);
    set("chat_chance",3);
    set("chat_output",({
      "The elf glares at you.\n",
      "The dark elf gives you a dirty look and mutters something under his breath.\n",
    }) );
    set("att_chat_output",({
      "The dark elf mutters something under his breath.\n",
    }) );

    sword=clone_object("/d/Prime/Kyrie/weapons/elven_sword.c");
    if(sword)
	set("base_stat",([
	  "strength" : 15,
	  "constitution" :14,
	  "dexterity" :20,
	]) );

    arm( sword );
    set_level(10);
}
