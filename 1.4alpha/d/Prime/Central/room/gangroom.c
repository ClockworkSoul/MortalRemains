// A room in the starting area, as yet unnamed.
// Blame goes to Cyanide, 8 Feb 2000

inherit ROOM;

#include <daemons.h>
#include "central.h"

void create() {
    ::create();
    set("author", "cyanide");
    set("light", 1);
    set ("short", "End of A Narrow Alleyway");
    set("long", @EndText
At the end of this alleyway appears to be a machine of some sort embedded
into the wall.
EndText
    );
    set("exits", ([
      "west" : M_ROOM+"road1_-2.c",
    ]) );
    set("smell", "It smells like a public toilet in the summertime, "+
      "only worse.\n");
    set("item_desc", ([
      "machine" : "It resembles an ATM. It has a screen that you should "+
      "probably examine.\n",
      "screen" : (@EndScreen
                     WELCOME FUTURE GANG MEMBER! 
                   -------------------------------

         If you wish to found a gang, all you need is a mere 
             200,000 credits, and to be a mere level 20!

          Just type 'found <name>', where <name> is the name
                    of the gang you wish to found!

           Be the first on YOUR block to be the leader of a 
                        gang! Found one today!
EndScreen
      ),
    ]) );
}

void init() {
    add_action("found_func", "found");
}

int found_func( string str ) {

    if (!str) {
	write("Syntax: found gangname\n");
	return 1;
    }

    write("Are you sure you wish to found a new gang called \""+
      str+"\"?\nIt will cost you 12,000 credits to do this.\n");

    write("\n{Y/N): ");

    input_to("found_func2", 0, str);

    return 1;
}

int found_func2( string str, string gang ) {
    if (!str || lower_case(str[0..0])=="n") {
	write("Request cancelled.\n");
	return 1;
    }

    if (strlen(gang) > 27) {
	write("The gang name cannot exceed 27 characters.\n");
	return 1;
    }

    if (!GANG_D->query_can_make_gang( TP )) return 1;

    if (GANG_D->gang_exists(gang)) {
	write("That gang already exists.\n");
	return 1;
    }

    if (!GANG_D->create_new_gang( gang, TP )) {
	write("Could not make the gang.\nNotify Cyanide.");
	TP->credit(12000);
    } else {
	write("Congrats! You are now the leader of "+capitalize(gang)+
	  "!\n");
    }

    return 1;
}

// EOF
