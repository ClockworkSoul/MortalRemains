#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create(){
::create();
seteuid(getuid());
set("light", 1);
set("short" , "A small tunnel");
set("long", @Endtext
The tunnel runs underground here, though where exactly underground
you are not sure. To the south you see and smell what appears to
be some kind of sewerage. To the north you can see what appears
to be some strange kind of light coming from the stone in the wall.
Endtext
);
set("exits", ([
"north"  :  "/d/Prime/Krynn/Sewer/sewer1.c",
"south"  :  "/d/Prime/Krynn/Duegne/sewer1.c",
]));
}
