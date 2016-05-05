/*
**  Thief proficiency room.
**  Ilzarion originally coded it.
**  Cyanide redid it 11 July, 1998.
*/

#include <config.h>
#include <mudlib.h>
#include <skills.h>

inherit "/std/profroom.c";

void create()
{
    ::create();
    seteuid(getuid());
    set( "light", 1 );
    set ("short","Thieves Proficiency Training Hall.");
    set( "long", wrap(
	"Thieves come here when they want to gain a new proficiency. "+
	"You may get a list of available skills by typing \"list\". "+
	"To pick a proficiency you need to type \"select <letter>\". "+
	"There seedy looking man in the corner watching you."
      ));
    set( "exits", ([
      "north" : "/d/class/rogue/thief/room/thief_guild.c",
    ]) );
    set ("skills", SK_THIEF );
    set("min_levels", ([
      "Evasion" : 15,
      "Nondetection" : 20,      
    ]) );
}

int learn_prof(string str) {
    if (!TP->query_level("thief")) {
	write(
	  "The thieves won't teach non-rogues the arts!\n");
	return 1;
    }

    ::learn_prof(str);
    return 1;
}                           

/* EOF */

