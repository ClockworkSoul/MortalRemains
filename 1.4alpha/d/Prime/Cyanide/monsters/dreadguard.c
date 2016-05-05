#include "monsters.h"

#include <mudlib.h>

inherit MONSTER ;

void create () {

    object ob4;

    ::create() ;
    seteuid(getuid()) ;
    enable_commands();
    set("author", "cyanide");
    set("short", "a Dreadguard");
    set_size(7);
    set ("long", @EndText
Hovering before you is a finely crafted suit of plate, inhabited mostly
by darkness and cobwebs. In the gloom, you can faintly make out the ghastly
greenish glow that marks where flesh once was. Two red points of light,
like hot embers, stare banefully out at you from the long-ago charred
suit or armor.
EndText
    );
    set ("id", ({"guard", "dreadguard"}));
    set_name ("dreadguard");
    set ("gender", "neuter") ;

    set("race", "undead guardian");
    set("undead", 30);

    arm(OBJ+"/dsword.c");
    wear(OBJ+"/dhelp.c");
    wear("/dplate.c");
    /*
	ob4 = clone_object(OBJ+"/sooty_key.c");
	ob4 -> move (this_object()) ;
    */

    set_align("ce");
    set_living_name("dreadguard");
    set("resist_type", ([ "fire" : 50, "electricity" : 75,
      "necromantic" : -100, "cold" : 0 ]) );
    set ("damage", ({ 2, 16 }) );
    set ("weapon_name", "fists") ;

    set("stat", ([
      "dexterity" : 10,
      "strength" : 19
    ]) );

    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    set_level(24);
}

void init() {
    command("equip");
    command("wield sword");
}

int arch (string str){
    write(
      "The dreadguard moves to block the gate.\n");
    return 1;
}
