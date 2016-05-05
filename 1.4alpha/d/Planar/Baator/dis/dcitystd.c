#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("long", @EndLong
You are walking through the randomly twisted roads of the City of Dis.
The roads here are covered with several inches of verdegris dust.
Much of the silt stirs as you pass, getting in your eyes and coating 
your throat.
EndLong
    );
    set ("short", "The Dusty Backroads of Dis");
}

void reset() {
    int i, num;
    object ob;
    string tmp;

    num = random(3) + 1;
    if (!random(4)) num += random(3) + 1;

    if (random(3) || present("baatezu", TO)) return;

    for (i=0; i<num; i++) {
	switch(random(13)) {
	case 0..3  : tmp = "green_abishai.c"; break;
	case 5..8  : tmp = "red_abishai.c"; break;
	case 9..11 : tmp = "black_abishai.c"; break;
	case 12    : tmp = "kocrachon.c"; break;
	}
	ob = clone_object(BAATOR+"monsters/"+tmp);
	if (ob) ob->move(TO);
    }
}

/* EOF */
