#include <mudlib.h>
#include <where.h>

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("author","cattt");
    set("light", 1);
    set("short", "Further into the basement");
    set("long", "@@query_long");
    set("item_desc", ([
      "door" : "The door looks heavy, the metal looks strong.\n",
      "chain" :"A thick steel chain. It is about 5 feet long and attached to the wall near the door.\n",
      "bowls":"Large bowls with the word <Killer> on them. \n",
      "bones":"The bones are in various sizes.\n",
    ]) );
    set("exits", ([
      "north" : M_ROOM+"basement.c",
      "door" : M_ROOM+"sewer.c",
    ]) );
    set("pre_exit_func", ([
      "door" : "dog_check" 
    ]) );
    set("objects", ([
      "killer" : M_MON+"killer.c",
    ]) );
    reset();

}

void init () {
    add_action ("search", "search");
}

int search (string str) {
    object dirty_key;

    if (!str || present("dog", this_object()) ) {
	return 0;
    }

    dirty_key = clone_object(M_OBJ+"dirty_key.c");

    if (str=="bones" && dirty_key) {
	write ("You move a few of the bones and find a key.\n");
	say(wrap(TPN+" moves a few bones and finds a key."));
	dirty_key->move( this_player() );
    } else {
	write ("You search around but find nothing of intrest.\n");
    }

    return 1;
}

int dog_check() {
    if (present("dog", TO)) {
	write("The dog blocks your way! He would rather give his life than let you pass.\n");
	return 1;
    }

    return 0;
}

string query_long() {
    string str = 
    "Entering this room a large door catches your eye.  "+ 
    "A couple of bowls are visible in the corner and bones are "+ 
    "scattered about. Next to the door a strong chain is attached to "+
    "the wall.  ";

    if (present("dog", TO)) 
	str += "A large dog is chained up here guarding the door.";

    if (!present("dog", TO))
	str += "The chain dangles as if something was once attached."; 
    return wrap(str);
}
