/*
	File: waste_1.c
	Desc: Wasteland, room 1.
	Date: Aug 1, 2000
*/
#include <mudlib.h>
#include <wasteland.h>

inherit ROOM;
void create(){
    ::create();
    seteuid(getuid());
    set("author", "sebastian");
    set("light", 1);
    set("short", CITY_NAME);
    set("long", @EndText
All around you, there is ice.  Cool, unrelenting ice.
The sky above is bleak, yet a stark blue that contrasts
the bland uniform land below it.  Nothing moves, nothing
seems to exist out here.
You can hear the sounds of civilization to the south.
EndText
    );
    set("listen", "You hear the hustle of city life to the south.\n");
    set("exits", (["northeast":M_ROOM+"waste_5.c",
      "northwest":M_ROOM+"waste_3.c",
	"south":M_ROOM+"steam/town1.c"]));
    set("item_desc", ([
      "ground" : "Cool to the touch, and quite solid.\n",
      "sky" : "A beautiful midnight blue sky.\n"
    ]));
}
