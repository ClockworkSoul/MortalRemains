#include "baator.h"

inherit BAATOR+"phlegethos/phstd.c";

void create() {
    ::create();
    set("short", "Outside the City");
    set("long", @EndText
You are standing on a vast black stone bridge just outside the city of
Abriymoch. From here the true might of the city is visible: it is suspended
by dozens of vast iron chains several hundred meters above the caldera of
an almost extinct volcano. The bridge continues to the east.
EndText
    );
    set("item_desc", ([        
      "bridge" : "It crosses the space between the rim of the volcano "+
      "and the city. It seems\nto have been carved from black volcanic "+
      "basalt.\n",
      "city" : "It is directly to your west.\n",
      "chains" : "Each link is at least 30 feet in length and "+
      "must weigh tons.\n",
      "caldera" : "The mouth of the volcano is several "+
      "meters wide.\n",
      "volcano" : "It is truly massive.\n"
    ]) );
    set("exits", ([
      "west" : PHLEGETHOS+"city15.c",
      "east" : PHLEGETHOS+"out02.c"
    ]) );
    reset();
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
	  "The cornugon says [to you]: You got a cigarette, bub?\n",
	}) );
	ob->set("short", "a cornugon guard");
	ob->add("long", "It has been charged with defending these gates.\n");
	ob->add("id", ({ "guard" }) );

	ob->move(this_object());
    }

    return 1;
}


void populate() {;}

