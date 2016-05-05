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
All around you, there is ice.  Cool, unrelenting ice.
The sky above is bleak, yet a stark blue that contrasts
the bland uniform land below it.  Nothing moves, nothing
seems to exist out here.
A trail leads to the southeast, continuing from the west.
EndText
);
	set("exits", (["northeast":M_ROOM+"waste_6.c",
	"west":M_ROOM+"waste_2.c",
	"southeast":M_ROOM+"waste_4.c"]));
set("item_desc", ([
	"ground" : "Cool to the touch, and quite solid.\n",
	"ice": "It seems the spires lessen to the southeast.\n",
	"trail": "Leading to the southeast, it looks like a wagon trail.\n",
	"land": "You can make out a trail in the snow.\n",
	"sky" : "A beautiful midnight blue sky.\n"
]));
}
