#include <mudlib.h>
inherit ROOM;

void create(){
seteuid(getuid());
set("light", 1);
set("short", "Drache Lane");
set("long", @Endtext
You stand on Drache Lane, one of the former main roads through
the town of Duegne. On wither side or tall buildings that you
think were once shops with apartments in which the owners stayed. 
These building are nowempty, the inhabitants long since vanished. 
Hanging between buildings are what seems like old cloths lines, and
you are not sure but there seems to still be some cloths hanging
out to dry. The road continues to the north and south from here.
Endtext
);
set("item_desc", ([
"road" : "Paved road running through the town. It is worn from many years of use.\n",
"buildings" : "Large shops and dweelings once used by the inhabitants of the town. They seem to have been empty for years.\n",
"shops" : "Once filled with goods and stuf, these shops have long since been empty.\n",
"cloths" : "The cloths are too high up to really look at but you can still make out that they are cloths of some kind.\n",
]));
set("search_desc", ([
"road" : "You find nothing but old wagon tracks.\n",
"buildings" : "You look inside and do not see anything of interest.\n",
"shops" : "You look inside and do not see anything of interest.\n",
"cloths" :"They are too high up for you to search them. Nice try though.\n",
]));
set("exits", ([
"north"  :  "/d/Dark/Duegne/Ruin/town3.c",
"south"  :  "/d/Dark/Duegne/Ruin/town1.c",
]));
::create();
}
