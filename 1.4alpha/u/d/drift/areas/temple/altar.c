#include <mudlib.h>
#include "/u/d/drift/areas/defs.h"

inherit ROOM;

void create() {
    ::create();

    set ("light", 1);
    set ("short", "The Altar of Brinol");
    set ("long", @End
This is a large octagonal room, with torches
at each of the eight points.  In the center
of the room lies a small altar made of granite.

End );

    add ("item_desc", ([ "altar" : "A young girl is kneeling in front of the altar, weeping.\n" ]) );
    add ("item_desc", ([ "torches" : "They are the only source of light in here.\n" ]) );
    add ("item_desc", ([ "girl" : "She just sits there and stares past the altar, mumbling something.\n" ]) );

    add ("exits", ([ "drift" : "/u/d/drift/workroom.c" ]) );
}

void init() {
    add_action("comfort", "comfort");
}

void story_1 (object ob) {
    tell_object (ob, "The girl looks up at you with tears in her eyes.\n");
    tell_object (ob, "\n");
    return ;
}

void story_2 (object ob) {
    tell_object (ob, "She tells you how her brother has been kidnapped by a small band\n");
    tell_object (ob, "of thieves, and how much she misses him.\n");
    tell_object (ob, "\n");
    return ;
}

void story_3 (object ob) {
    tell_object (ob, "This is where the rest of the story goes.\n");
    tell_object (ob, "\n");
    return ;
}

int comfort (string who) {
    if (!who || who != "girl") {
	write("Comfort who?\n");
	return 1;
    }
    else {
	call_out("story_1", 2, this_player());
	call_out("story_2", 5, this_player());
	call_out("story_3", 8, this_player());
	return 1;
    }
}
