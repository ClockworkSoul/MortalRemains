#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{ int i;
    ::create();
    seteuid( getuid() );
    set("author", "shya");
    set( "light", 1 );
    set("short", "Castle Guard's Recroom");
    set( "long", @EndText
This is a Recreation room for the castle guards.
Guards come here to relax and shake off snow and their troubles.
Chairs and tables scatter the room with guards drinking and playing cards.     
EndText
    );
    for (i = 1; i <= 6; i++) {
	object frostguard;
	frostguard=clone_object("/d/Arctic/Shya/monsters/frostguard.c");
	frostguard->move(TO);
    }
    set( "exits", ([
      "north" : "/d/Arctic/Shya/rooms/castle/wall13.c"
    ]) );
    set("item_desc", ([
      "tables" : "Ordinary tables laden with empty glasses and cards.\n",
      "chairs" : "Wooden high back chairs, big enough for these guards.\n",
      "glasses" : "Empty glasses that were once filled with some odd spirit.\n",
      "cards" : "Deck of these strewn across the tables, looks like war.\n"
    ]) );
    set("pre_exit_func", ([
      "west" : "key_check"  
    ]) );
    reset();
}

void reset()
{         
    int nGuards;

    if (!present ("gold_key", TO)) {
	object key;
	key = clone_object("/d/Arctic/Shya/rooms/castle/gold_key.c");
	key->move(TO);
    }
    if (!present("chest", TO)) {
	object chest;
	chest = clone_object("/d/Arctic/Shya/rooms/castle/chest.c");
	chest->move(TO);
    }
    nGuards = 0;
    if (present("frostguard", TO)) {
	object *inventory;
	int i;

	inventory = all_inventory (TO);
	for (i = 0; i < sizeof(inventory); i++) {
	    if (inventory[i]->id("frostguard"))
		nGuards += 1;
	}		
    }
    for (; nGuards < 6; nGuards++) {
	object frostguard;
	frostguard=clone_object("/d/Arctic/Shya/monsters/frostguard.c");
	frostguard->move(TO);
    }
}

int key_check() {
    if (present("gold key", TP)) {
	write("You can not leave with the key to the chest.\n");
	return 1;
    }
    else
	return 0;

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
