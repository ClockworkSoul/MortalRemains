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
seems to exist out here.  The path you've been follow-
ing seems to disappear into a snow drift to the south.
Although it does remain quite clear to your west.
Upon closer inspection, you can see a cave mouth to the north.
EndText
);
set("exits", ([ "south":M_ROOM+"waste_8.c",
	"cave":M_ROOM+"cave1.c",
	"west":M_ROOM+"waste_6.c"]));
set("item_desc", ([
	"ground" : "Cool to the touch, and quite solid.\n",
	"sky": "A beautiful midnight blue sky.\n",
	"ice": "Cold, just like ice should be.\n",
	"path": "fairly well covered in snow, but you can see it.\n",
	"land":"A barren wasteland, nothing but snow and ice.\n",
	"cave mouth": "A rather large opening into a mountain.\n",
	"mouth": "A rather large opening into a mountain.\n"
]));
}
