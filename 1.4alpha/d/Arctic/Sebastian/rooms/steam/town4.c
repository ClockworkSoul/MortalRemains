#include <mudlib.h>
#include <steamtown.h>

inherit ROOM;
void create(){
	::create();
	seteuid(getuid());
	set("author", "sebastian");
	set("light", 1);
	set("short", CITY_NAME+", Pistons St.\n");
	set("long", @Foo
Foo
);
	set("item_desc",([
	]));
	set("safe", 1);
	set("exits",([
	"west":M_ROOM+"town1.c",
	"south":M_ROOM+"town5.c"
	]));
}
