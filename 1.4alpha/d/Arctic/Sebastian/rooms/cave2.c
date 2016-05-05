#include <mudlib.h>
#include <wasteland.h>

inherit ROOM;
	void create(){
	::create();
	seteuid(getuid());
	set("author", "sebastian");
	set("short", "A cavern");
	set("long", @Foo
As you creep into the cave, you can hear breathing.
Heavy, and hungry, breathing.  The walls have been 
scratched smooth, most likely by powerful claws.
Small bones litter the floor, and the air is heavy
with musk.  You can see the cave continues.....
Foo
);
set("exits", (["up":M_ROOM+"cave1.c",
	"down":M_ROOM+"cave3.c"]));
set("item_desc", ([
	"walls": "Smoothed, with deep gouges here and there.\n",
	"bones": "Small, bird skeleton bones.\n",
	"floor": "Heavily trodden, stamped flat.\n"]));
set("smell", "It smells like rotting flesh, blended with animal fur.\n");
set("objects", ([
	"tiny":M_MON+"whitedragon.c"]));
reset();
}
