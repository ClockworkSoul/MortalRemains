#include <teleport.h>
#include "baator.h"

inherit ROOM;

void populate();

void create() {
    ::create();
    seteuid(getuid());
    set("author", "cyanide");
    set("no_teleport", NO_IN_OR_OUT);
    set("light", 1);
    set("smell", ([
      "default" : "This entire part of Baator stinks of sulfur, blood, "+
      "and excement.\n"
    ]) );
}

int reset() {
    if (undefinedp(query("objects"))) populate();
    return ::reset();
}

void populate() {
    int i, num;
    object ob;

    if (random(4) || present("#BLAH#", TO)) return;

    switch( random(15) ) {
    case  1..4  :   // Hamatulae 2-5 aggressive
	num = random(3) + 2;
	for (i=0; i<num; i++) {
	    ob = clone_object(BAATOR+"monsters/hamatula.c");
	    if (ob) {
		set("aggressive", 9);
		add("id", ({ "#BLAH#" }) );
		ob->move(TO);
	    }
	}
	break;
    case  5..6  :   // Fire elemental
	ob = clone_object("/d/Planar/Elemental/monsters/fireelem.c");
	if (ob) {
	    set("wandering", 1);
	    set("aggressive", 9);
	    add("id", ({ "#BLAH#" }) );
	    ob->move(TO);
	}
	break;
    case  7..10 :   // Hellhounds
	num = random(10) + 2;
	for (i=0; i<num; i++) {
	    ob = clone_object(BAATOR+"monsters/hellhound.c");
	    if (ob) {
		set("aggressive", 9);
		add("id", ({ "#BLAH#" }) );
		ob->move(TO);
	    }
	}
	break;
    case 11..14 :   // Salamanders
	num = random(4) + 1;
	for (i=0; i<num; i++) {
	    ob = clone_object(BAATOR+"monsters/salamander.c");
	    if (ob) {
		set("aggressive", 9);
		add("id", ({ "#BLAH#" }) );
		ob->move(TO);
	    }
	}
	break;
    default     :   // Magma golem
	ob = clone_object(BAATOR+"monsters/magmagolem.c");
	if (ob) {
	    set("wandering", 1);
	    add("id", ({ "#BLAH#" }) );
	    ob->move(TO);
	}
	break;
    }

    return;
}
