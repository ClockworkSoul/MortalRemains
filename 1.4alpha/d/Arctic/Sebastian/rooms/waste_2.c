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
the bland uniform land below it.  A path continues
from the north, to the west.
EndText
);
	set("exits", (["north":M_ROOM+"waste_1.c",
	"east":M_ROOM+"waste_3.c"]));
set("item_desc", ([
	"ground":"It seems to be firmly compressed snow and ice.\n",
	"ice" :"Tall swirling spires, touching the sky.\n",
	"land": "Rarely traversed, you cannot make out any footprints.\n",
	"path":"Well worn to the east, barely visible to the north.\n",
	"sky":"A midnight blue sky.\n"
]));
set("objects", ([
	"fox1":M_MON+"fox.c",
	"fox2":M_MON+"fox.c",
	"fox3":M_MON+"fox.c"]));
reset();
}
