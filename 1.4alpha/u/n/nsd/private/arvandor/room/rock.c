/*
** File: river.c
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
    set("short", "At the rock");
    set( "long", @EndText
You arrive to the rock finally. It's a large one
indeed. Large enough for you and someone else...
it's a nice plain surface to rest and
lay down. The water looks temptingly inviting.
'Enter' the 'water' and enjoy it...
EndText);
    set( "exits", ([
    ]) );
    set("item_desc", ([
      "trees" : "Evergreen pine trees. Here they grow broad and healthy.\n",
    ]) );
    set("listen", wrap(
      ));
}
void init () {
    add_action("enter_water", "enter");
    add_action("swim", "swim");
    add_action("lay_down", "lay");
}
int enter_water(string str) {
    say(TPN+" cringes at the contact with the cold river water.\n");
    write(wrap(
	"yaeeeiii!!! the water is too cold. You blush when you\n"+
	"notice the phisical reaction it causes you. Well, now\n"+
	"you're adapted to it's coldness. You're ready to 'swim'.\n"));
    return 1;
}
int swim (string str) {
    say(TPN+" swims back to the shore...\n");
    this_player()->move_player(ARV_ROOM+"river.c");
    say(TPN+" has followed you to the shore.\n");
    return 1;
}
int lay_down (string str) {
    say(TPN+" lays down on the rock.\n");
    write("You lay down on the rock. Pleasant thoughts come to mind...\n");
    return 1;
}
/* EOF */
