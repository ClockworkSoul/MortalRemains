
// A generic monster.
// Ilz coded 28 Jan 98

#include <mudlib.h>
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("prevent_summon", 1);
    set("author" , "herself");
    set("short" , "bondage man");
    set("long" , "This man is dressed in a full body leather\n"+
      "bondage suit. You can make out every curve and bulge \n"+
      "through the skin-tight leather. All you can see of \n"+
      "his flesh is a small circle around his eyes. He \n"+
      "looks at you passionately. Can you feel that strange \n"+
      "surge of hormones? \n");
    set("id" , ({"man" , "bondage" , "bondage man" }) );
    set_size(8);
    set_name("bondage man");
    set ("gender" , "male") ;
    set("race", "human");
    set_align("le");
    enable_commands() ;
    set ("base_ac", 2);
    set ("natt", 2);
    set("chat_chance", 10);
    set("chat_output", ({
      "Bondage man reaches for a leather whip. \n",
      "Bondage man says: Can you handle this? \n",
      "Bondage man flexes.\n",
    }) );
    set("att_chat_output", ({
    }) );
    set ("damage", ({ 8,12 }) );
    set("weapon_name" , "cat o' nine tails");
    set_verbs( ({"whip" , "swat" , "spank"}) );
    set_level(25);
arm("/u/h/herself/mall/sextoys/nines.c");
}

