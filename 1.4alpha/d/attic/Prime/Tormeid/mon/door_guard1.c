// These door guards specifically guard the audience chamber of the King.
#include "../defs.h"

static string DIR ;
inherit GUARD ;
int set_dir(string dir) ;

create(){
    ::create() ;
    set("short", "a castle guard") ;
    set("long", @ENDLONG
The guard eyes you stonily as you move through the area.
ENDLONG
    );
    set("id", ({ "guard", "castle guard", "door guard" }) ) ;
    set("stat/constitution", 10) ;
    set_level(25) ;
    set_skill("Long Blades", 5, "strength");
    set("natt", 2) ;
    arm(WEAPONS(longswd), "sword") ;
    set_size( 6) ;
    wear(ARM(chainmail), "chainmail");
    wear(ARM(medshield), "shield") ;
    wear(ARM(lgloves), "gloves");
    set_skill("Long Blades", 2, "strength") ;
    wear(ARM(helmet), "helmet");
    wear(ARM(hlboots), "boots");
    delete("pursuing") ;
    set_dir("east") ;
}

int set_dir(string dir) {
    if (!dir) return 0 ;
    DIR = dir ;
    return 1;
}

void init() {
    add_action("stop_move", "scout") ;
    add_action("stop_move", "go") ;
    add_action("stop_move", "sneak") ;
}

int stop_move(string dir) {
    if (wizardp(TP)) return 0 ;
    if (!dir) return 0 ;
    if (dir != DIR) return 0 ;
    if (TP->query("invisible")) {
	write("Since you are invisible, you walk right past the guard.\n") ;
	return 0 ;
    }
    write("The guard says: You don't have an audience!  Wait your turn!\n");
    write("The guard stands in your way defiantly.\n") ;
    say(TPN+ " tries to move "+DIR+", but a guard stops "+
      objective(TP->query("gender")) + ".\n") ;
    return 1;
}

