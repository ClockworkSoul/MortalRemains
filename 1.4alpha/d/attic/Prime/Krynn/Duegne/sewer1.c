#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light",0);
set("short", "The sewer.");
set("long",@Endtext
You stand in the sewers below the city of Duegne. It seems that
over the years the ceiling of the sewer has cracked leaving an
unexpected whole to the surface, that no one knew about due to the
garbage that was covering it. Water runs slowy through here and
it smells like, well, like a sewer.
Endtext
);
set("exits", ([
"south"  :  "/d/Prime/Krynn/Sewer/sewer2.c",
"north"  :  "/d/Prime/Krynn/Duegne/sewer2.c",
"up"     :  "/d/Prime/Krynn/Duegne/alley2.c",
]));
}
