/*
**  Mage proficiency room.
**  Ilzarion originally coded it.
**  Cyanide redid it 11 July, 1998.
**  Cyanide cp'd it to the Stormlords room.
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
    set ("short","Stormlords Proficiency Training Hall.");
    set( "long", wrap("You stand inside the private library "+
	"of the Guild of Stormlords and Magic-Users. Great rows and "+
	"columns of ancient and dusty tomes stretch in every "+
	"direction, and shelf upon shelf of crumbling scrolls "+
	"line the walls. The pungent odor of dust, "+
	"preservatives, and obscure reagents burns your nose.\n\n"+
	"Here you can do the following: list, select"
      ));
    set( "exits", ([
    ]) );
    set("skills", SK_CLERIC);
    set("min_levels", ([
      "Talisman" : 5,
      "Iron Will" : 15,
      "Smite" : 20
    ]) );
}

int learn_prof(string str) {
    if (!TP->query_level("stormlord")) {
	write(
	  "Only the Stormlords may use this knowledge!\n");
	return 0;
    }

    ::learn_prof(str);
    return 1;
}

string skills_function(string str) { 
    object ob;

    switch(str) {
    case "Talisman" :
	ob = clone_object("/d/class/obj/talisman");
	ob->move(TP);
	break; 
    }

    return "";
}

/* EOF */

