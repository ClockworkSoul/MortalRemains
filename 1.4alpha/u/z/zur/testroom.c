//Coded by Ilzarion on Wed May  7 13:53:58 1997
inherit ROOM;
#include <mudlib.h>
void create(){
	
	seteuid( getuid(this_object()) );
	set("light", 1);
	set("short", "Ilz's test room in Zur's directory cause he forgot to cd out.");
	set("long", @End
Alas It is space...
not void per se,
but wasted space none the less.
,
End);
	set("exits", ([
	   "north" : "/u/i/ilzarion/workroom.c",
	]));
	set("item_desc", ([
	   ({"speck","dirt","a speck of dirt",}) : "it had to be here so, hey, there it is a particle.",
	]));
	set("objects", ([
	]));
	::create();
}
