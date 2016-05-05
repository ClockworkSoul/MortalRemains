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
seems to exist here.  The wind picks up a bit, as it whirls
from the eastern trail, bringing the scent of a fresh kill
to your nostrils.  To the north and west, the path leads on.
EndText
);
set("exits",(["north":M_ROOM+"waste_7.c",
	"east":M_ROOM+"waste_9.c",
	"west":M_ROOM+"waste_5.c"]));
set("item_desc", ([
	"ground" : "Cool to the touch, and quite solid.\n",
	"sky": "A beautiful midnight blue sky.\n",
	"ice": "Cold, just like ice should be.\n",
	"path": "fairly well covered in snow, but you can see it.\n",
	"land": "A barren wasteland, nothing but snow and ice.\n"
]));
}
