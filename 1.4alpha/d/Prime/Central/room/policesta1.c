// A room in the starting area, as yet unnamed.
// Blame goes to Cyanide, 22 May 1999

inherit ROOM;

#include <daemons.h>
#include "central.h"

string query_posters();

void create() {
    ::create();
    seteuid(getuid());
    set("author", "cyanide");
    set("light", 1);
    set ("short", CITY_NAME+" First Precinct - Admissions");
    set("long", wrap(
	"You are in the main admission room to the "+CITY_NAME+
	" First Precinct. The old room's only noteworthy features "+
	"are the numerous 'Wanted' posters here, some dating back "+
	"several years, and an elderly and decrepit couch, here for "+
	"your convenience, it would seem."
      ) );
    set("exits", ([
      "east" : M_ROOM+"road0_1.c",
    ]) );
    set("item_desc", ([
      "couch" : "It's a nasty rasberry color, and is ancient, at best.\n",
      "posters" : "@@query_posters",
    ]) );
    set("objects", ([ "clerk" : M_MON+"p_clerk.c" ]) );
    reset();
}

string query_posters() {
    int i;
    string str, *convicts = LAW_D->query_suspects();

    switch (sizeof(convicts)) {
    case 0 : 
	str = "Most are quite old. Nobody you know.\n";
	break;
    case 1 :
	str = "There is a new poster here:\n\t"+
	"Wanted: "+capitalize(convicts[0])+"\n";
	break;
    default: 
	str = "There are a couple new ones, with pictures of ";
	for (i=0; i<(sizeof(convicts)-1); i++)
	    str += capitalize(convicts[i]) + ", ";
	str += "and "+capitalize(convicts[i])+".";
	str = iwrap(str);
    }

    return str;
}

/* EOF */
