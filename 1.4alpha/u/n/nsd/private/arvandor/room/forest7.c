/*
** File: forest7.c
** Author: Lady Nsd
** Other comments: To secure peace is to prepare for war!!!
*/

#include <config.h>
#include <mudlib.h>
#include "arv.h"

inherit ROOM;

void create() {
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "nsd");
    set("short", "Dense Forest");
    set( "long", @EndText
You're in a dense forest. Only few strands of sunlight
find their way between the branches of the pine trees.
Your senses tell you that the river must be closer, but
this is a dead end. The forest is too dense here to
continue.
EndText);
    set( "exits", ([
      "west" : ARV_ROOM+"forest6.c",
    ]) );
    set("item_desc", ([
      "trees" : wrap(
	"Broad pine trees full of branches. One of the trees has\n"+
	"a broken branch..."),
      "branch" : wrap(
	"Seems like someone broke this branch in order to 'enter'\n"+
	"the 'forest'."),
    ]) );
    set("listen", wrap(
	"The wind stopped completely. You hear no more sounds\n"+
	"other than the cascade. You chill suddenly...\n"));
}
void init() {
    add_action("enter_forest", "enter");
}
int enter_forest(string str) {
    write("You move the branch aside to enter the forest.\n");
    say(TPN+" suddenly vanishes through the forest...\n");
    this_player()->move_player(ARV_ROOM+"riverway.c");
    say(TPN+" tresspasses the secret forest and gets in.\n");
    return 1;
}

/* EOF */
