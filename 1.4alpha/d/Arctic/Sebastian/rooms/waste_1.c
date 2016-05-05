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
the bland uniform land below it.  Surrounded on three
sides by impregnable ice, your only exit is a path 
leading south.
EndText
);
set("exits",([ "south": M_ROOM+"waste_2.c"]));
set("item_desc", ([
	"ground" :"Firmly packed snow.\n",
	"sky" :"A midnight blue sky.\n",
	"ice": "Clear, and quite solid.\n",
	"path": "fairly well covered in snow, but you can see it.\n",
	"land": "A barren wasteland, nothing but snow and ice.\n"
]));
	set("objects", ([ "opus1":M_MON+"penguin.c",
	"opus2":M_MON+"penguin.c",
	"opus3":M_MON+"penguin.c",
	"Polar":M_MON+"polarbear.c"]));
	reset();
}
