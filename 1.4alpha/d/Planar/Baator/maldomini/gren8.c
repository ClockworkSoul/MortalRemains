#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
     set ("light", 1) ;
     set ("long",
"Maldomini, the seventh layer of Baator.\n"+
"You are the Judge's chambers.\n"+
"It seems vacant, an quiet.\n"+
"There is a desk and bookshelves here.\n"+
"Ilz note: put portal and stuff here\n");
set ("short","Grenpoli, Maldomini, the seventh hell.");
     set ("exits", ([
         "east" : BAATOR+"maldomini/gren9.c"]));
reset();
	}
