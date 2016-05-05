#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("long", @EndLong
You are at the eastern terminus of a mile-long plush red carpet, which
ends at the base of a very ominous-looking tower. It appears stange, 
however, that the tower looks more like it was grown than constrcted.
EndLong
    );
    set ("short","The End of the Great Red Road");
    set ("exits", ([
      "north" : BAATOR+"dis/dcity13.c",
      "south" : BAATOR+"dis/dcity23.c",
      "east" : BAATOR+"dis/dtower3.c",
      "west" : BAATOR+"dis/dcity17.c"]));
    set("item_desc", ([
      "carpet" : "It ends at the base of the tower.\n",
      "tower" : "It is to your direct east.\n",
    ]) );
    reset();
    set("pre_exit_func", ([
      "east" : "checkd"
    ]) );
}

void reset() {
    int i;
    object ob;
    string str;

    if (!present("#BLAH#", TO)) {
	for (i=0; i<6; i++) {
	    if (random(2))
		str = BAATOR+"monsters/red_abishai";
	    else
		str = BAATOR+"monsters/cornugon";

	    ob = clone_object(str);
	    if (ob) ob->add("id", ({ "#BLAH#" }) );

	    ob->move(TO);
	}
    }
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
