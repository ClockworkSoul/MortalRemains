#include <config.h>
#include <mudlib.h>

inherit ROOM;

object mug;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("short", "Nightmask's Chambers");
    set( "long", @EndText
This is the central chamber of Nightmask's Tower. There is a rather
large ornate desk centered in the room, loaded with papers. A huge
redwood bookcase dominates the west wall filled with books and tomes.
There is a strange object on a smaller table set to the west wall.
There are no exits here, and you wonder why.
EndText
    );
    set( "exits", ([
    ]) );
    set("item_desc", ([
      "bookcase" : "A huge redwood bookcase carved in runes.\n",
      "object" : "It looks like a Dr. Coffee. You could fill your mug if you had one.\n",
     "books" : "Books on creation, Legands, Lore, and History.\n",
      "desk" : "The desk is made of onyx with golden runes.\n",
     "papers" : "Written in some strange language, you wonder what"+
            " they say, some look like names.\n",
     "tomes" : "Various books on Law and Mortal Remains.\n",
    ]) );
}
void init () {
    add_action("camel", "fill");
}

int camel(string str) {
    if(!str) {
	write ("Syntax: fill mug.\n");
	return 1;
    }
    if (str == "mug"){
	if(!present("#MUG#", this_object())){
	    write("You don't have a coffee mug, dope.\n");
	    say(TPN+" spills coffee all over themselves.\n");
	    return 1;
	}else{
	    write("You fill your mug with piping hot coffee, from the machine.\n");
	    say(TPN+" fills their mug from the Dr. Coffee.\n");
	    mug = clone_object("/u/n/nightmask/private/mug2.c");
	    mug->move(this_object());
	    return 1;
	}
    }
}
