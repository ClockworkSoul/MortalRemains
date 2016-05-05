/*
	File: waste_1.c
	Desc: Wasteland, room 1.
	Date: Aug 1, 2000
*/
#include <mudlib.h>
#include <wasteland.h>

inherit ROOM;
	void create(){
	::create();
	seteuid(getuid());
	set("author", "sebastian");
	set("light", 1);
	set("short", CITY_NAME);
	set("long", @EndText
As you walk, you notice the sound of flowing water
to your east.  A thick wall of ice blocks you, however,
the sound is quite clear.  A path to the south seems to
empty out into a clearing.  To your west, the mountains
seem to grow larger as you look at them.
EndText
);
set("exits",(["west":M_ROOM+"waste_8.c",
	"south":M_ROOM+"waste_10.c"]));
set("item_desc", ([
	"wall":"A sheer wall of solid ice.\n",
	"ice":"Solid, thick and smooth.  Definitely ice.\n",
	"path":"The snow turns slightly slushy here.\n",
	"clearing":"You think, you can make out a river...\n",
	"mountains":"Large, impressive and imposing, a perfect blend of rock and ice.\n"
]));
set("listen", "You hear the distinct sound of running water.\n");
}
