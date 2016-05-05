#include <mudlib.h>
#include <steamtown.h>

inherit ROOM;
void create(){
	::create();
	seteuid(getuid());
	set("author", "sebastian");
	set("light", 1);
	set("short", CITY_NAME+", Ballast Rd.\n");
	set("long", @Foo
Foo
);
	set("item_desc",([
	]));
	set("safe", 1);
	set("exits",([
	"north":M_ROOM+"town2.c",
	"east":M_ROOM+"stshop.c",
	"south":M_ROOM+"stpub.c"
	]));
}
