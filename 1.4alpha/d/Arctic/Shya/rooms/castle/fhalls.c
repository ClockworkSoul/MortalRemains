
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
	set("short", "King Jared's Feasthall");
	set( "long", @EndText
This room is decorated in various skins and antlers,
it has decorative shields and swords on the walls. 
Running the length of the room is a large table with
many chairs around it.
EndText
);
	set ("objects", ([ 6 : "frostguard" ]) ) ;
	set( "exits", ([
		"west" : "/d/Arctic/Shya/rooms/castle/library.c",
	      "south" : "/d/Arctic/Shya/rooms/castle/eh1.c"	
	]) );
	set("item_desc", ([
		"table" : "It is a huge oaken table which can seat dozens.\n",
		"chairs" : "Wooden high back chairs, big enough for these guards.\n",
            "antlers" : "Trophies from Jared's many kills.",
            "skins" : "Trophies from Jared's many kills.",
	      "swords" : "Totally useless as the real thing.",
		"shields" : "Totally useless as the real thing.",    
	      "walls" : "Decorated as only a true Knight could.",
            "trophies" : "Skins and Antlers."
		]) );
}

void reset()
{         
	if (! frostguard) {
		frostguard = clone_object("/d/Arctic/Shya/monsters/frostguard.c");
		frostguard->move(TO);
	}
}

void init() {
 add_action("sit_func", "sit");
}

int sit_func ( string str )
{
string dowhat;
string towhat;

if (!str) {
    write("Sit towhat?\n");
    return 1;
}
if (sscanf(str, "%s %s", dowhat, towhat) ==2 ) {
    if (towhat == "chair") {
        if (dowhat == "on")
            write ("You sit on the chair.\n");
        else if (dowhat == "in")
            write ("You sit in the chair.\n");
        return 1;
    }
    else if (towhat == "table") {
        if (dowhat == "on")
            write ("You clammer onto the table.  After a moment you get bored and return to the floor.\n");
        else if (dowhat == "at")
            write ("You pull up a chair and take a seat at the table.\n");
        return 1;
    }
}
return 0;
}

