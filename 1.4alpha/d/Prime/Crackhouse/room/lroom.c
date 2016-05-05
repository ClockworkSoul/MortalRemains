// QC Passed - Cyanide

#include "where.h"

inherit ROOM;

int pipeflag;

void create() {
    ::create();

    // Remember to call this line in anything that clones an object.
    seteuid(getuid());
    set("author","cattt");
    set("light", 1);
    set("short", "The living room");
    set("long", wrap(
	"The furniture looks like the rest of the house, fully trashed. The "+
	"couch's springs almost show through the worn coverings. A coffee "+
	"table stands beside the couch. A barstool stands as a makeshift "+
	"chair. "
      ) );
    set("item_desc", ([
      "furniture" : "A couch, barstool, and table are all thats here.\n",
      "couch" : "This poor couch looks overused and over burdened.\n",
      "springs":"The springs are begging to escape!\n",
      "coverings":wrap("The ugliest shade of green you've ever "+
	" seen covers what's left of this couch."),
      "table": wrap("A long table in front of the couch. A "+
	"little of this and that cover it."), 
      "barstool":wrap("You wonder what a barstool is doing here. "+
	"You can see a label on one of the legs."), 
      "label":"The label reads: Property of the Bitter End.\n",
      "chair":"The chair is really just a barstool.\n",
    ]) );
    set("exits", ([
      "south" : M_ROOM+"hall2.c",
    ]) );
    set("objects", ([
      "pimp" : M_MON+"pimp.c",
    ]));
    reset();
}
void reset(){
    ::reset();
    pipeflag = 1;
}
void init () {
    add_action ("search", "search");
}

int search (string str) {
    object pipe;

    if (!str) {
	/* Very nice!   But I would do this SLIGHTLY differently...
		write ("Search what?\n");
		return 1;
	If we let it return 0, the 'search' will continue, so we can
	search other things, too...
	*/
	return 0;
    }

    if (str=="couch" && pipeflag) {
	pipe = clone_object(M_OBJ+"crackpipe.c");
	write ("You rummage through the couch and find a pipe.\n");
	say(wrap(TPN+" rummages through the couch and finds something."));
	pipe->move( this_player() );  
	pipeflag = 0;
    } else {
	write ("You search around but find nothing of intrest.\n");
    }
    return 1;
}
