//Coded by Zur on Fri May  9 14:31:33 1997
inherit ROOM;
#include <mudlib.h>
void create(){
	
	seteuid( getuid(this_object()) );
	set("light", 1);
	set("short", "short");
	set("long", @End
long
End);
	set("exits", ([
	   "north" : "/u/z/zur/workroom.c",
	]));
	set("item_desc", ([
	   ({"red chair","chari","stool",}) : "This is a chair.",
	]));
	set("objects", ([
	]));
	::create();
}