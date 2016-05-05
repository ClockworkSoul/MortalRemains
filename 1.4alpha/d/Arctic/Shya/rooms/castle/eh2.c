#include <config.h>
#include <mudlib.h>

inherit ROOM;

object frostguard;

void create()
{
    ::create();
    seteuid( getuid() );
    set("author", "shya");
    set( "light", 1 );
    set("short", " Entrance Hall (e,w,)");
    set( "long", @EndText
This is the eastern portion of the extremely large entrance hallway.
The hallway continues to the west, and to the east are a pair of 
impressive looking doors.
EndText        
 );
set( "item_desc", ([
     "doors":"These doors are 15 feet tall and solid oak.\n",
     "door" : "This door is 15 feet tall and solid oak.\n",
     "hallway" : "This hallway is extremely large for an entrance.\n"
                ]) );

         set( "exits", ([
      "east" : "/d/Arctic/Shya/rooms/castle/guardroom.c",
      "west" : "/d/Arctic/Shya/rooms/castle/eh1.c",
	"south" : "/d/Arctic/Shya/rooms/castle/library.c"
    ]) );
    frostguard = clone_object("/d/Arctic/Shya/monsters/frostguard.c");
    frostguard->move(this_object());

}