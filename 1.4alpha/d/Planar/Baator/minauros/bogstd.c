#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {    
    ::create();
    seteuid(getuid()) ;
    set("author", "cyanide");
    set ("light", 1) ;
    set ("short","The Stinking Bogs of Minauros");
    set ("long", @EndText
You find yourself wandering through a vast, stinking bog. Foul rain, oily
sleet, and razor-sharp hail sweep across you. Decayed bodies gurgle to the
surface of the black water, filling the air with disease. The thick mud
sucks at your feet while you walk, and blood-sucking insects the size of
flashlight batteries torment you mercilessly.
EndText
    );
    set("item_desc", ([
    ]) );
    set("smell", "The stench of rotting material is overwhelming.\n");
    reset();
}

void populate() {
    int i, num = 1;
    object ob, ob2;
    string str;

    if (random(3)) return;

    seteuid(getuid());

    switch( random(9) ) {
    case 0..1 :     // Dragon turtles
	if (!random(4)) num = random(3) + 1;
	for (i = 0; i < num; i++) {
	    ob = clone_object(BAATOR+"monsters/dragturtle.c");
	    if (ob) ob->move(TO);
	}
	break;
    case 2..3 :
	if (!random(3)) num = random(4) + 1;
	for (i=0; i < num; i++) {
	    ob = clone_object(BAATOR+"monsters/troll.c");
	    ob->move(TO);
	}
	break;
    default :       // Hamatula tormenting petitioners
	num = random(3) + 1;
	for (i = 0; i < num; i++) {
	    ob = clone_object(BAATOR+"monsters/cornugon.c");
	    if (ob) {
		ob->set("short", "cornugon slaver");
		ob->set("chat_chance", 13);
		ob->set("chat_output", ({
		  "The cornugon brutally whips one of the slaves.\n",
		  "The cornugon pushes a slave's face into the mud.\n",
		  "The cornugon holds a slaves head under water "+
		  "until he stops breathing.\n",
		  "The cornugon laughs gleefully.\n",
		  "The cornugon idly pulls the limbs from a dead slave.\n"
		}) );
		ob->move(TO);
		ob2 = clone_object(BAATOR+"monsters/slave.c");
		ob2->move(TO);
		ob2 = clone_object(BAATOR+"monsters/slave.c");
		ob2->move(TO);
	    }
	}
	break;
    }
    return 1;
}

int reset() {
    int i, flag = 0;
    object *stuff = all_inventory(this_object());

    for (i=0; i < sizeof(stuff); i++)
	flag += (living(stuff[i]) && !userp(stuff[i]));

    if (!flag) populate();

    return 1;
}
