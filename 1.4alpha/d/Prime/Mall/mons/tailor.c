
// A generic monster.
// Ilz coded 28 Jan 98

#include <mudlib.h>
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("prevent_summon", 1);
    set("author" , "herself");
    set("short" , "A Tailor");
    set("long", "An Italian man of short stature. \n"+
      "He has a tiny mustache that looks somewhat \n"+
      "out of place cradled under his huge nose. \n");
    set("id", ({ "tailor" , "man" , "italian man"}) ) ;
    set("smell" , "He smells like spaghetti. \n");
    set_size(5);
    set_name ("tailor") ;
    set ("gender" , "male") ;
    set("race", "human");
    set_align("le");
    enable_commands() ;
    set_living_name("tailor") ;
    set ("base_ac", 2);
    set ("armor_class", 2);
    set("chat_chance", 10);
    set("chat_output", ({
      "The tailor reaches for his measuring tape. \n",
      "Tailor says: Hey i just want to measure your inseam. \n",
      "Tailor says: Trust me, this is the way they do it in the old country. \n",
      "The tailor touches your genitals! \n",
    }) );
    set("att_chat_output", ({
    }) );
    set("damage" , ({3,6}) );
    set ("weapon_name", "sewing scissors") ;
    set ("CLASS", "warrior");
    set_verbs( ({ "stab at" , "poke at" , "point at" }) );
    arm("/d/Prime/Mall/weap/scissors.c");
    set_level(19);
}

