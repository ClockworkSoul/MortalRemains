#include <mudlib.h>
#include "sigil.h"
inherit "/u/i/ilzarion/factionhall2.c";

void create() {
     ::create();
    	seteuid(getuid());
    
     set ("objects", ([ "skall" : "/d/Outer/Sigil/monsters/skall",
     "glabrezu" : "/d/Outer/Sigil/monsters/glabrezu" ]) );
	reset();
     set("faction", "Dustmen");
     set ("light", 1) ;
     set ("long",
"You are in the office of skall.\n"+
	"It is extremely cold and unpleasant here.\n"+
	"If you would like to join the ranks of the Dustmen, simply type join.\n"+
	"And if you know another Dustmen then type thier name too ex: <join skall>\n"+
	"Undead will never pick a fight with you again, However, you will reach\n"+
	"true death (removal) twice as easily.\n"+
	"Commands: join <sponsor> , store <item> , retrieve , listing\n") ;
     set ("short", "Skall's Chambers, Dustmen HQ") ;
     set ("exits", ([
     	"portal"	: SIGIL+"mortuary1.c" ]) ) ;

     	}


void do_ability(){

//the dustmen's ability (undead dont auto attack) is found in user.c
// the hinderance (1/2 ress surv) is found in the death object

return;
}
