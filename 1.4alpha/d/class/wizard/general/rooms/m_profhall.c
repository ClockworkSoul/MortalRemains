/*
**  Mage proficiency room.
**  Ilzarion originally coded it.
**  Cyanide redid it 11 July, 1998.
*/

#include <config.h>
#include <mudlib.h>
#include <skills.h>
#include "guildhall.h"

inherit "/std/profroom.c";

void create()
{
    ::create();
    seteuid(getuid());
    set( "light", 1 );
    set ("short","Mages Proficiency Training Hall.");
    set( "long", wrap("You stand inside the private library "+
	"of the Guild of Mages and Magic-Users. Great rows and "+
	"columns of ancient and dusty tomes stretch in every "+
	"direction, and shelf upon shelf of crumbling scrolls "+
	"line the walls. The pungent odor of dust, "+
	"preservatives, and obscure reagents burns your nose.\n\n"+
	"Here you can do the following: list, select"
      ));
    set( "exits", ([
      "north" : RM_MAGES+"m_lobby.c",
    ]) );
    set("skills", SK_MAGE);
    set("min_levels", ([
      "Talisman" : 5,
      "Signature Spell" : 20
    ]) );
}

int learn_prof(string str) {
    if (!TP->query_level("wizard") &&
      !TP->query_level("dragon")) {
	write(
	  "The library refuses to educate non-wizards.\n");
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

