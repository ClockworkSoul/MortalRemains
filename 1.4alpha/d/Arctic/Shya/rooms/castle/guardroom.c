#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create() {
int i;

	::create();
	seteuid( getuid() );
	set("author", "shya");
	set( "light", 1 );
	set("short", "Baracks");
	set( "long", @EndText
This is the baracks of King Jared's guards.
His guards are known far and wide for their prowess in combat,
as well as their frosty personality. 
EndText
);
	set( "exits", ([
		"west": "/d/Arctic/Shya/rooms/castle/eh2.c"
	]) );

for (i = 1; i <= 6; i++) {
    object frostguard;
    frostguard=clone_object("/d/Arctic/Shya/monsters/frostguard.c");
    frostguard->move(TO);
}

}