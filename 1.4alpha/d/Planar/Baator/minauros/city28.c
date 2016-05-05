#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {    
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set("long", @EndLong
You are before the entrance to the Inner Palace of Minauros. To the east
is the entrance, and to the west is the main road of the city.
EndLong
    );
    set("pre_exit_func", ([
      "east" : "checkd"
    ]) );    
    set ("exits", ([   
      "east" : BAATOR+"minauros/city29.c",
      "west" : BAATOR+"minauros/city27.c"
    ]));
}

int checkd() {
    if (adminp(TP)) {
	write("The demons bow as you pass.\n");
	say("The demons bow to "+TPN+", and let him pass.\n");
	return 0;
    }

    if (present("#BLAH#", TO)) {
	write("The demons block your way, laughing and throwing "+
	  "refuse at you.\n");
	return 1;
    }

    return 0;             
}

int reset(){
    object ob;
    int i;

    ::reset();
    seteuid(getuid()) ;  

    if (present("cornugon", this_object())) return 1;

    for (i=0; i < 3; i++) {    
	ob = clone_object(BAATOR+"monsters/cornugon");

	ob->set("chat_chance", 3);
	ob->set("chat_output", ({
	  "The cornugon ignores you, sharpening his horns.\n",
	  "The cornugon glances over at you for a second.\n",
	  "The guard looks you up and down and chuckles to itself.\n",
	  "The cornugon guard inspects its whip for signs of wear.\n",
	  "The cornugon says [to you]: You got a cigarette, bub?"
	}) );
	ob->set("short", "a cornugon guard");
	ob->add("long", "It has been charged with defending these gates.\n");
	ob->add("id", ({ "#BLAH#" }) ); 

	ob->move(this_object());
    }

    return 1;
}

