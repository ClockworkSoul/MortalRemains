#include <config.h>
#include <mudlib.h>

inherit ROOM;
void create()
{
::create();
seteuid(getuid());
set("light", 1);
set("short", "Steps to the library.");
set("long", @Endtext
You stand on the steps to the Duegne Library. This building is
one of the oldest in the city and in all of Krynn, housing many
anceint volumes of text. The steps lead through a gapping entrance
that looks kind of strange, and back down to the road.
Endtext
);
set("exits", ([
"down" : "/d/Prime/Krynn/Duegne/road14.c",
"west" : "/d/Prime/Krynn/Duegne/libmain.c",
]));
set("item_desc", ([
"stairs" : "Whote marble stairs which seem to shine with a light of thier own. You also notice that there is not on spec of dirt or grim on them no matter how many people are walking on them.\n",
"building" : "The building stands tall and is made from a substance similar to that of the steps. It to shines with a natural light and is also spotlessly clean.\n",
"entrance" : "The entrance is the one odd thing about the building. Large stone pieces protrude from the top of the entrance way, almost as if they were large teeth wiating to swallow the ignorant.\n",
]));
}
