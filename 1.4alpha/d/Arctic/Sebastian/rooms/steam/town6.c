#include <mudlib.h>
#include <steamtown.h>

inherit ROOM;
void create(){
	::create();
	seteuid(getuid());
	set("author", "sebastian");
	set("light", 1);
	set("short", "The Great Doors to "+CITY_NAME);
	set("long", @Foo
Foo
);
	set("item_desc",([
	]));
	set("safe", 1);
	set("exits",([
	]));
}
