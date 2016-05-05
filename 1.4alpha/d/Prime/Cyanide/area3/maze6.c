#include "garden.h"
#include <mudlib.h>

inherit MAZE+"/mazex.c";

void create() {
	::create();

	set("exits", ([
		"down" : MAZE+"/maze5.c",
		"east" : MAZE+"/maze7.c",
		"up" : MAZE+"/maze9.c"
	]) );
}
