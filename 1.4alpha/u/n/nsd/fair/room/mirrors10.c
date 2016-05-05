/*
** File: mirrors10.c
** Author: Lady Nsd
*/

#include <config.h>
#include <mudlib.h>
#include "fair.h"

int image_flag = 0;

inherit ROOM;

void create() {
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "nsd");
    set("short", "Inside the House of Mirrors");
    set( "long",@EndText
This is the biggest chamber. It's full of mirrors
in all directions (even in the ceiling). Everywhere
You see you... Doh!
Nothing else to expect, the room is full of them.
EndText);
    image_flag = 1;
    set( "exits", ([
      "southwest" : FAIR_ROOM+"mirrors8.c",
      "southeast" : FAIR_ROOM+"mirrors9.c",
    ]) );
    image_flag = 0;
    set("item_desc", ([
      "mirror" : "A large mirror that will distort your image if\n"+
      " you type 'reflect me'.\n",
    ]) );
    set("objects", ([
    ]) );
}
void init() {
    add_action("reflect_me", "reflect");
}
int reflect_me (string str) {
    object image;
    if (!image_flag) {
	for (int i = 0;i<8;i++) {
	    image = clone_object(FAIR_MON+"image.c");
	    image->move(this_object() );
	    image->kill_ob(this_player() );
	}
	write("All your images gang up on you!!\n");
	say("An awful lot of images gang up on "+TPN+"!!\n");
	image_flag = 1;
    }
    else
	write("Nothing but multiple you's!\n");
    say(TPN+" looks at "+POSS+" image on the mirror.\n");
    return 1;
}
int reset() {
    image_flag = 0;
    return ::reset();
}

/* EOF */
