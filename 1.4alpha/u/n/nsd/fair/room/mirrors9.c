/*
** File: mirrors9.c
** Author: Lady Nsd
*/

#include <config.h>
#include <mudlib.h>
#include "fair.h"

int image_flag;

inherit ROOM;

void create() {
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "nsd");
    set("short", "Inside the House of Mirrors");
    set( "long",@EndText
This is one of the mirror chambers. It's nice and
dark. Lightning is enough to see the mirror and
your image on it.
A large mirror stands before you.
EndText);
    image_flag = 1;
    set( "exits", ([
      "west" : FAIR_ROOM+"mirrors7.c",
      "northwest" : FAIR_ROOM+"mirrors10.c",
    ]) );
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
    image = clone_object(FAIR_MON+"image.c");
    if(image && image_flag) {
	say(TPN+"'s image suddenly comes to life and attacks "+
	  objective(TP->query("gender") )+" !!\n");
	write("Your image suddenly comes to life and attacks you!!\n");
	image->move(environment(this_player() ) );
	image->kill_ob(this_player() );
	image_flag = 0;
    }
    else
	write("WOAH! You're two headed...LOL!!\n");
    say(TPN+" looks at "+POSS+" image on the mirror.\n");
    return 1;
}
void fix_flag() { image_flag = 1; }
/* EOF */
