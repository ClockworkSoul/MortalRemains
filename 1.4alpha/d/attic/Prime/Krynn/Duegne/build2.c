// An example shop, which inherits the standard shop object.
// All shops that inherit the standard shop should call ::create() BEFORE
// loading shop objects, because euid is set in ::create. It's easiest to
// just make ::create() the first call in the local create proc.

#include <config.h>
#include <mudlib.h>
#include <money.h>

inherit SHOP;


void create() {
	::create() ;
	set ("light", 1) ;
        set ("short", "The village store") ;
set ("long", @Endtext
Welcome to the general store of Duegne. This is where you
can come to buy and sell equipment that you need for your
journeys through the realm of Krynn and beyond.
Endtext
);

set("exits", ([
"west"  :  "/d/Prime/Krynn/Duegne/road4.c",
"north" :  "/d/Prime/Krynn/Duegne/road6.c",
]));
}
