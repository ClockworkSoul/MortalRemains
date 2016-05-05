
#include <config.h>
#include <mudlib.h>
#include <skills.h>
#include "sigil.h"

inherit "/std/profroom.c";

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set ("short","Thief Proficiency Training Hall.");
    set( "long", @EndText
This is where thieves can learn all their skills.
Commands are: list, select <prof name>
EndText
    );
    set( "exits", ([
      "north" : SIGIL+"mainst4.c",
      "south" : "/d/class/rogue/thief/room/sigil_thief_guild.c",
    ]) );
    set("skills", SK_THIEF);
    set("min_levels", ([
      "Evasion" : 15,
      "Nondetection" : 20
    ]) );
}

int learn_prof(string str) {
    if (!TP->query_level("rogue")) {
	write(
	  "You must become a rogue to learn proficiencies here.\n");
	return 1;
    }

    ::learn_prof(str);
    return 1;
}

/* EOF */
