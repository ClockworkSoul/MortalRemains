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
set("exits", (["out":M_ROOM+"waste_7.c",
	"down":M_ROOM+"cave2.c"]));
set("item_desc", ([
	"walls": "Smoothed, with deep gouges here and there.\n",
	"bones": "Small, bird skeleton bones.\n",
	"floor": "Heavily trodden, stamped flat.\n"]));
set("smell", "It smells like rotting flesh, blended with animal fur.\n");
set("objects", ([
	"wolf1":M_MON+"wolf.c",
	"wolf2":M_MON+"wolf.c",
	"wolf3":M_MON+"wolf.c"]));
reset();
set("pre_exit_func", (["down": "checkd"]));
}
int checkd(){
	if(adminp(TP)){
		write("The wolves bare their teeth, as you pass.\n");
		say("The wolves growl at"+TPN+", but let him pass.\n");
		return 0;
	}
	if(present("wolf",TO)){
		write("The wolves block your way, growling and baring teeth.\n");
		return 1;
	}
return 0;
}
