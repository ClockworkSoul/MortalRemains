/*
	File: waste_1.c
	Desc: Wasteland, room 1.
	Date: Aug 1, 2000
*/
#include <mudlib.h>
#include <wasteland.h>
#include <config.h>

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
seems to exist here.  You are all alone.  Here, the path
splits into four forks.  To the northwest, you can see a 
rather large mountain, with what look to be large birds
circling it.  To your north and east, the path continues
unabated.  To the southwest, the trail becoems more apparent.
EndText
);
set("exits", (["southwest":M_ROOM+"waste_4.c",
		"northwest":M_ROOM+"/mount/entrance.c",
	"north": M_ROOM+"waste_6.c",
	"east":M_ROOM+"waste_8.c"]));
set("item_desc", ([
	"ground" : "Cool to the touch, and quite solid.\n",
	"sky": "A beautiful midnight blue sky.\n",
	"ice": "Cold, just like ice should be.\n",
	"path": "fairly well covered in snow, but you can see it.\n",
	"land": "A barren wasteland, nothing but snow and ice.\n"
]));
	set("objects", ([
	"cat":M_MON+"sleopard.c",
	"cat2":M_MON+"sleopard.c",
	"cat3":M_MON+"sleopard.c"]));
reset();
}
